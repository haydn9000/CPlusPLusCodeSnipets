#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<string> substrings;
        string longest;
        string tempSubstring = s;

        if (s.size() == 1)
        {
            return 1;
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                for (int ii = 0; ii < tempSubstring.length(); ii++)
                {
                    if (tempSubstring.at(ii) == s.at(i) and ii != 0)
                    {
                        break;
                    }
                    else
                    {
                        longest.append(1, tempSubstring.at(ii));
                    }
                }

                tempSubstring = tempSubstring.substr(longest.size());

                if (longest != s)
                {
                    substrings.push_back(longest);
                }
                else
                {
                    tempSubstring = s;
                }
                longest = "";
                i = 0;

                if (tempSubstring.size() < 2)
                {
                    break;
                }
            }
            return lengthOfLongestStringInVector(substrings);
        }
    }

    int lengthOfLongestStringInVector(vector<string> &vec)
    {
        int longestStringLength = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            if (longestStringLength < vec.at(i).size())
            {
                longestStringLength = vec.at(i).size();
            }
        }
        // cout << longestStringLength << endl;
        return longestStringLength;
    }
};

int main()
{
    Solution longestSubstring;

    // Test 1
    string str = "abcabcbb";
    int length = longestSubstring.lengthOfLongestSubstring(str);

    int expected = 3;
    string pass = (length == expected) ? "true" : "false";
    cout << pass << endl;

    // Test 2
    str = "bbbbb";
    length = longestSubstring.lengthOfLongestSubstring(str);

    expected = 1;
    pass = (length == expected) ? "true" : "false";
    cout << pass << endl;

    // Test 3
    str = "pwwkew";
    length = longestSubstring.lengthOfLongestSubstring(str);

    expected = 3;
    pass = (length == expected) ? "true" : "false";
    cout << pass << endl;

    // Test 4
    str = " ";
    length = longestSubstring.lengthOfLongestSubstring(str);

    expected = 1;
    pass = (length == expected) ? "true" : "false";
    cout << pass << endl;

    // Test 5
    str = "au";
    length = longestSubstring.lengthOfLongestSubstring(str);

    expected = 2;
    pass = (length == expected) ? "true" : "false";
    cout << pass << endl;

    return 0;
}