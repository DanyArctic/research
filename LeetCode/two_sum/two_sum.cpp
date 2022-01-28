/* https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> answer;
        std::unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            if (table.find(target - nums[i]) != table.end())
            {
                answer.push_back(table[target - nums[i]]);
                answer.push_back(i);
                return answer;
            }
            table[nums[i]] = i;
        }
        return answer;
    }
};

int main()
{
	Solution one;
    std::vector<int> numbers = { 2,7,11,15 };
    int target = 9;
    std::vector<int> ans = one.twoSum(numbers, target);
    for (auto it : ans)
    {
        std::cout << it << std::endl;
    }
	return 0;
}
