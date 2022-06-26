/*
Question 1

3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

//Solution 
class Solution {
public:
 //Sliding Window Approach   
int lengthOfLongestSubstring(string str)
{
    int n = str.size();
    int res = 0;  
    for (int i = 0; i < n; i++) {
        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
            if (visited[str[j]] == true)
                break;
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
         visited[str[i]] = false;
    }
    return res;
  }
    
};

/*
Question 2

567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

//Solution

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.length() > s2.length()) return false;
        
        vector<int> cur(26), goal(26);
	    for(char c : s1) goal[c - 'a']++;
	    for(int i = 0; i < s2.size(); i++) 
        {
		    cur[s2[i] - 'a']++;
		    if(i >= s1.size()) cur[s2[i - s1.size()] - 'a']--;
		    if(goal == cur) return true;
	    }
	return false;
        
    }
};
