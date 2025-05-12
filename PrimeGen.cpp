#include <iostream>
#include <fstream>
#include <chrono>
#include <memory>
#include <vector>
#include <string>
#include <future>
#include <functional>

#include <cmath>
#include <cstdint>
#include <cstring>

class Timer
{
public:
    Timer() 
        :m_Start(std::chrono::high_resolution_clock::now()){}

    ~Timer() = default;

    Timer(const Timer&) = delete;
    Timer(Timer&&) = delete;

    void Reset(void)
    {
        m_Start = std::chrono::high_resolution_clock::now();
    }
    auto GetTImeEllapsed(void) const
    {
        return std::chrono::high_resolution_clock::now() - m_Start;
    }
        
private:
    std::chrono::high_resolution_clock::time_point m_Start;
};

bool IsPrime(uint64_t n)
{
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;
    for(uint64_t i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0) return false;
    }

    return true;
}

std::vector<uint64_t> GenPrimes(uint64_t lowerLimit, uint64_t upperLimit)
{
    if(lowerLimit < 2) lowerLimit = 2;
    if(lowerLimit > upperLimit) return std::vector<uint64_t>();

    std::vector<uint64_t> primes;
    primes.reserve( upperLimit / log(upperLimit) - lowerLimit / log(lowerLimit) + 100);

    for(uint64_t i = lowerLimit; i <= upperLimit; ++i)
    {
        if(IsPrime(i)) primes.push_back(i);
    }

    return primes;
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Invalid Syntax. Provide number of threads.\n";
        return 1;
    }

    int64_t threadCount = [] (const char* str) -> int64_t {
        int64_t len = static_cast<int64_t>(strlen(str));
        if(len == 0) return -1;

        int64_t res = 0;

        for(int64_t i = len - 1, place = 1; i >= 0; --i, place *= 10)
        {
            if(str[i] < '0' || str[i] > '9') return -1;

            res += (str[i] - '0') * place;
        }

        return res;
    }(argv[1]);

    if(threadCount <= 0)
    {
        std::cout << "Tread Count must be atleast 1\n";
        return 2;
    }

    std::cout << "Thread Count: " << threadCount << '\n';

    auto getString = [] (const std::string& msg) -> std::string {
        std::cout << msg;
        std::string buffer;
        std::getline(std::cin, buffer);

        return buffer;
    };

    auto parseU64 = [] (const std::string& str) -> std::pair<bool, uint64_t> {
        if(str.length() == 0) return std::pair<bool, uint64_t>(false, 0);

        uint64_t res = 0;

        uint64_t place = 1;
        for(uint64_t i = str.length() - 1; i > 0; --i, place *= 10)
        {
            if(str[i] < '0' || str[i] > '9') return std::pair<bool, uint64_t>(false, 0);

            res += (str[i] - '0') * place;
        }
        if(str[0] < '0' || str[0] > '9') return std::pair<bool, uint64_t>(false, 0);
        res += (str[0] - '0') * place;
        

        return std::pair<bool, uint64_t> (true, res);
    };

    auto [statusL, lowerLimit] = parseU64(getString("Lower Limit: "));
    if(!statusL)
    {
        std::cout << "Invalid Input\n";
        return 3;
    }

    auto [statusU, upperLimit] = parseU64(getString("Upper Limit: "));
    if(!statusU)
    {
        std::cout << "Invalid Input\n";
        return 3;
    }

    Timer timer;

    std::unique_ptr<std::future<std::vector<uint64_t>>[]> tasks = std::make_unique<std::future<std::vector<uint64_t>>[]>(threadCount);
    const double chunkSz = static_cast<double>(upperLimit - lowerLimit + 1) / static_cast<double>(threadCount);
    double chunkRem = (upperLimit - lowerLimit + 1) % threadCount;

    uint64_t start = lowerLimit;
    for (uint64_t i = 0; i < threadCount; ++i)
    {
        uint64_t end = start + chunkSz - 1;
        if (chunkRem > 0)
        {
            ++end;
            --chunkRem;
        }
        if (end > upperLimit)
            end = upperLimit;

        tasks[i] = std::async(std::launch::async, GenPrimes, start, end);

        start = end + 1;
    }

    std::vector<uint64_t> primes;
    if(lowerLimit < 2) lowerLimit = 2;
    if(lowerLimit > upperLimit)
    {
        std::cout << "Invalid limits\n";
        return 4;
    }
    primes.reserve( upperLimit / log(upperLimit) - lowerLimit / log(lowerLimit) + 100);

    for(uint64_t i = 0; i < threadCount; ++i)
    {
        const auto& chunk = tasks[i].get();
        primes.insert(primes.end(), chunk.begin(), chunk.end());
    }

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (timer.GetTImeEllapsed()).count();

    std::ofstream file;
    file.open("primes.txt");
    for(const auto prime: primes)
    {
        file << prime << "  ";
    }

    std::cout << duration << " ms\n";
}