#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        for (auto n : operations)
        {
            for (auto i = 0; i < nums.size(); ++i)
            {
                if (nums[i] == n[0])
                {   
                    nums[i] = n[1];
                }
            }
        }
        return nums;
    }
};

void printChangedVector(vector<int> &nums)
{
    for (auto n : nums)
    {
        cout << n << " ";
    }
}

int main()
{
    Solution modArray;

    // Test 1
    vector<int> nums = {1, 2, 4, 6};
    vector<vector<int>> operations = {{1, 3}, {4, 7}, {6, 1}};

    vector<int> changedArray = modArray.arrayChange(nums, operations);

    vector<int> expected = {3, 2, 7, 1};
    string pass = (changedArray == expected) ? "true" : "false";
    cout << pass << endl;

    // Test 2
    nums = {1, 2};
    operations = {{1, 3}, {2, 1}, {3, 2}};

    changedArray = modArray.arrayChange(nums, operations);

    expected = {2,1};
    pass = (changedArray == expected) ? "true" : "false";
    cout << pass << endl;

    // Test 3
    nums = {1, 2, 4, 6};
    operations = {{1, 3}, {4, 7}, {6, 1}};

    changedArray = modArray.arrayChange(nums, operations);

    expected = {3, 2, 7, 1};
    pass = (changedArray == expected) ? "true" : "false";
    cout << pass << endl;

    return 0;
}
