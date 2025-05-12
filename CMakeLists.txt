CMAKE_MINIMUM_REQUIRED(VERSION 3.30)

set(C_STANDARD 17)
set(CXX_STANDARD 17)

set(CMAKE_COMPILE_WARNING_AS_ERROR)
set(CMAKE_LINK_WARNING_AS_ERROR)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

project(evenodd)
add_executable(evenodd evenodd.c)

project(vote)
add_executable(vote vote.c)

project(reverseint)
add_executable(reverseint reverseint.c)

project(palindrome)
add_executable(palindrome palindrome.c)

project(IsPrime)
add_executable(IsPrime IsPrime.c)

project(PrintPrimes)
add_executable(PrintPrimes PrintPrimes.c)

project(IsArmstrong)
add_executable(IsArmstrong IsArmstrong.c)

project(factorial)
add_executable(factorial factorial.c)

project(pyramid)
add_executable(pyramid pyramid.c)

project(LinearSearch)
add_executable(LinearSearch LinearSearch.c)

project(BubbleSort)
add_executable(BubbleSort BubbleSort.c)

project(insert)
add_executable(insert insert.c)

project(delete)
add_executable(delete delete.c)

project(MatAdd)
add_executable(MatAdd MatAdd.c)

project(MatMultiply)
add_executable(MatMultiply MatMultiply.c)

project(struct)
add_executable(struct struct.c)

project(StringRev)
add_executable(StringRev StringRev.c)

project(PrimeGen)
add_executable(PrimeGen PrimeGen.cpp)