def IsPrime(n: int) -> bool:
    if n == 2: return True
    if n < 2 or n % 2 == 0: return False
    for i in range(3, int(n ** 0.5) + 1):
        if n % i == 0: return False

    return True

def main():
    with open("primes.txt", "r") as primeFile:
        data = primeFile.read().strip()
    entries = data.split("  ")
    for entry in entries:
        if not IsPrime(int(entry)):
            print(f"{entry} is not prime!")

    print("All Good")

if __name__ == "__main__":
    main()