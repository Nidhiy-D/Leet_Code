/*
Question 1

704. Binary Search
Difficulty: - Easy

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

*/

//Solution

class Solution 
{
public:
    
    int search(vector<int>& nums, int target) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target) return i;
        }
        return -1;
    }
    
};


/*
Question 2

278. First Bad Version
Difficulty: - Easy

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:

Input: n = 1, bad = 1
Output: 1
*/

//Solution

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int low = 0;
        int high = n;
        
        while(high - low > 1)
        {
            int mid = low + (high-low)/2;
            
            if(isBadVersion(mid) == isBadVersion(n)) high = mid;
            
            else low = mid;
        }
        
        return high;
    }
};


/*
Question 3

35. Search Insert Position
Difficulty: - Easy

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

//Solution

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int i = 0;
        int n = nums.size();
        int j = n - 1;

        while(i <= j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target) i = mid + 1;
            else j = mid - 1;
        }
        
        return i;
        
    }
};

/////////////////////////////////////////////////
