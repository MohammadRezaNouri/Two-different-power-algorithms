#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long power1(long x, long  y) // The first power function
{
    long k = 1;
    int count = 0; // To count the number of multiplication operations
    for (long n = 1; n <= y; n++)
    {
        count += 1; // Add a multiplication operation
        k *= x;
    }
    return count; // Returns the number of multipled operations
}                 // end function 1

int main()
{

    return 0;
}