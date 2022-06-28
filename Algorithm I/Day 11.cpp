/*

Question 1

77. Combinations
Medium

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
Accepted
546,209
Submissions
844,300
*/

//Solution

//iterative
class Solution {
public:   
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp(k, 0);
        int itr = 0;
        while(itr > -1){
            temp[itr]++;
            if(temp[itr] > n) itr--;
            else if(itr == k-1) res.push_back(temp);
            else{                
                itr++;
                temp[itr] = temp[itr-1];
            }
        }
        return res;
    }
};

///////////////////////////////////////////////

/*

Question 2

46. Permutations
Medium

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

//Solution

class Solution {
private:
    vector<vector<int>> result;
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0, (int)nums.size() - 1);
        
        return result;
    }
    
    void helper(vector<int> num_arr, int l, int r) {
        if (l == r){
            result.push_back(num_arr);
        } 
        else {  
            for (int i = l; i <= r; i++) {
                swap(num_arr[l], num_arr[i]);

                helper(num_arr, l + 1, r); 

                swap(num_arr[l], num_arr[i]);  
            }  
        }
    }  
};

///////////////////////////////////////////////

/*

Question 3

784. Letter Case Permutation
Medium


Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
 

Constraints:

1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.

*/

//Solution

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtrack(S, 0, ans);
        return ans;
    }
    
    void backtrack(string &s, int i, vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        // save initial value
        char c = s[i];
        // path1: toggle lower/upper case
        s[i] = islower(c) ? toupper(c) : tolower(c);
        backtrack(s, i + 1, ans);
        // path2: reset back(NOT go to this path if c is digit)
        if (isalpha(c)) {
            s[i] = c;
            backtrack(s, i + 1, ans);
        }
    }
};

///////////////////////////////////////////////
