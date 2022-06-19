#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissingNumber(vector<int> &vec)
{
    int missingNumber;

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) != i + 1)
        {
            return i + 1;
        }
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

    return 0;
}