#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int findMissingNumber(vector<int> &vec)
{
    sort(vec.begin(), vec.end());

    int count = vec.back(); // This variable is to help traverse the vector backward.

    for (int i = 0; i < vec.size(); i++)
    {
        // Check for missing value at beginning and end of vector
        // at the same time to speed up process
        if (vec.at(i) != i + 1)
        {
            return i + 1;
        }
        else if (vec.at(vec.size() - i - 1) != count)
        {
            // cout << to_string(i) + "-----------" << to_string(vec.at(vec.size() - i-1)) << "--------------" << to_string(count) << endl;
            return count;
        }

        count--;
    }

    return -1;
}

int main()
{
    // Test 1
    vector<int> vec = {10, 9, 6, 5, 4, 7 , 3, 2, 1};
    cout << "\nThe missing number is (expected 8): " << findMissingNumber(vec) << endl;

    // Test 2
    vector<int> vec2 = {8, 10, 9, 6, 5, 4, 7, 13, 3, 2, 1, 12};
    cout << "\nThe missing number is (expected 11): " << findMissingNumber(vec2) << endl;

    // Test 3
    vector<int> vec3 = {10, 9, 6, 5, 8, 7 , 3, 2, 1, 11};
    cout << "\nThe missing number is (expected 4): " << findMissingNumber(vec3) << endl << endl;

    // Test 4
    vector<int> vec4 = {4, 10, 9, 6, 5, 8, 7 , 3, 2, 11};
    cout << "\nThe missing number is (expected 1): " << findMissingNumber(vec4) << endl << endl;

    // Test 5
    vector<int> vec5 = {10, 9, 6, 5, 8, 7 , 3, 4, 2, 1, 11};
    cout << "\nThe missing number is (expected -1): " << findMissingNumber(vec5) << endl << endl;

    // Test 6
    vector<int> vec6 = {5, 4, 2, 1};
    cout << "\nThe missing number is (expected 3): " << findMissingNumber(vec6) << endl << endl;

    return 0;
}