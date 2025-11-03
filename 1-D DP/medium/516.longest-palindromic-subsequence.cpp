/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
/*
Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

// Initial questions: define/verify constraints, would any spaces be allowed? (assume no)'
                        //    i      j
// Walk-through example: s = 'ajcnjbap' = 5 --> 'ajnja'
// Initial thought: don't solve the whole problem at once; instead, find way to evaluate small instances of the problem based on the criteria
// --> break down any problem (instance of s) into smaller subproblems easier to evaluate
// DP Problem: 1) Subproblem definition, 2) define bases cases, 3) define recursive cases, 
//              4) define memoization structure, 5) define evaluation order & solution location
//              6) analyze runtime and space complexity

// 1) Subproblem definition: 
//    LPS(i,j) as the length of the longest palindromic subsequence starting at index i and ending at index j

// 2) Base cases: i = j --> 1, i > j or i < 0 or j < |s - 1| --> 0

// 3) Recursive cases: 
// Invalid case: s[i] != s[j] --> max(LPS(i+1,j), LPS(i,j-1))
// Valid case: s[i] = s[j] --> max(2 + LPS(i+1,j-1), max(LPS(i+1,j), LPS(i,j-1)))

// 4) Memoization structure: 2D array of dimensions n+1 * n+1
// 5) Evaluation order: i ->|s| to 0, j -> i to |s|
// 6) Solution Location: LPS(0, |s| - 1)
// 7) 

#include <stdlib.h>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.length() == 1) return 1;
        int n = s.length();
        vector<vector<int>> LPS(n+1, vector<int>(n+1, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i+1; j < n; j++) {
                cout<<"(i,j) = ("<<i<<","<<j<<")"<<endl;
                cout<<"s[i]: "<<s[i]<<", s[j] = "<<s[j]<<endl;
                if (s[i] == s[j]) {
                    int skip = max(LPS[i+1][j], LPS[i][j-1]);
                    int skipp = max(skip, LPS[i+1][j-1]);
                    LPS[i][j] = max(2+LPS[i+1][j-1], skipp);
                } else {
                    int skip = max(LPS[i+1][j], LPS[i][j-1]);
                    int skipp = max(skip, LPS[i+1][j-1]);
                    LPS[i][j] = skipp;
                }
            }
        }
        return LPS[1][n];
    }
};
// @lc code=end

