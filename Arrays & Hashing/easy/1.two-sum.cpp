/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
/*
Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
*/

// Initial Questions:
// -- Can we assume there is always a solution? If not, what would we return?
// -- Can we assume there will always be atleast two elements in nums? Or could there be 0 or 1

#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Map from number to its index
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (map.find(target - nums[i]) != map.end()) {
                return vector<int>{ map[diff], i};
            } else {
                map[nums[i]] = i;
            }
        }
    }
};

// Runtime: .find() on a hashmap is O(1) and inserting into a hash map is O(1). So we have n subproblems with O(1) work in each subproblem, giving us O(n) runtime.
// Space: Our hashmap will have n elements in the worst case and our diff variable and vector are both constant space since they're size 1 or 2 respectively. So our space is domainted by the map which is O(n).
// Intuition: Because at any given number we can calculate the exact difference to our target, a hashmap will allow us to search if that target exists in O(1) time.
// This works also due to constraints and problem definition (there will only ever be one solution so we don't need to worry about tie-breaking or duplicates).
// @lc code=end

