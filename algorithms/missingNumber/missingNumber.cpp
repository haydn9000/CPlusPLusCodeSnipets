#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissingNumber(vector<int> &vec)
{
    int missingNumber;

    sort(vec.begin(), vec.end());

    for (int i = 0; i <= vec.size(); i++)
    {
        if (vec.at(i + 1) != i + 1)
        {
            return i + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> vec = {};

    cout << "The missing number is: " << findMissingNumber(vec) << endl;
    return 0;
}