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

long power2(long x, long y) // The second power function
{
    long  k = 1;
    int count = 0; // To count the number of multiplication operations
    while (y > 1)
    {
        count += 2; // Add a multiplication and division operation
        if (y % 2 == 0)
        {
            x = x * x;
            y = y / 2;
        }
        else
        {
            k = k * x;
            x = x * x;
            y = (y - 1) / 2;
        }
    }
    x *= k;
    return count; // Return the number of operations multipled and diided
}                 // end function 2

int main()
{

    int numbers_for_test[14] = { 1, 5, 10, 15, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };           // numbers for test
    for (int index = 0; index < 14; index++)                                                                  // index = To move in the array
    {                                                                                                         // Start for
        cout << "2^" << numbers_for_test[index] << " :" << endl;                                              // The practical printing on which the work is to be done
        cout << "   Function power1 : " << endl;                                                              // Print the function to be called
        cout << "      number of multiplication operations : " << power1(2, numbers_for_test[index]) << endl; // Print multiplied number of operations for power1
        auto start = steady_clock::now();                                                                     // Save process start time for power1
        power1(2, numbers_for_test[index]);                                                                   // Call the power1
        auto end = steady_clock::now();                                                                       // Save process end time for power1
        auto diff = end - start;                                                                              // Calculate process execution time for power1
        cout << "      runtime : " << duration_cast<nanoseconds>(diff).count() << " ns" << endl;              // Print runtime for power1
        cout << "   Function power2 :" << endl;                                                               // Print the function to be called
        cout << "      number of multiplication operations : " << power2(2, numbers_for_test[index]) << endl; // Print multiplied number of operations for power2
        start = steady_clock::now();                                                                          // Save process start time for power2
        power2(2, numbers_for_test[index]);                                                                   // Call the power2
        end = steady_clock::now();                                                                            // Save process end time for power2
        diff = end - start;                                                                                   // Calculate process execution time for power2
        cout << "      runtime : " << duration_cast<nanoseconds>(diff).count() << " ns" << endl               // Print runtime for power2
            << endl;
    }          // End for
    getchar(); // System pause :)
    return 0;  // Bye Bye
}