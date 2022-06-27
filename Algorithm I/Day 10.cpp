/*
Question 1

21. Merge Two Sorted Lists
Easy

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

//Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        //Base cases
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val <= list2 ->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
            
        else
        {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
            
    }
};

//////////////////////////////////////////////////

/*
Question 2

206. Reverse Linked List
Easy

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?


*/

//Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head or !head->next)
            return head;
        
        ListNode* curr= head;
        ListNode* ptr = head;
        head = head->next;
        curr->next = NULL;
        while(head)
        {
            curr = head;
            head = head->next;
            curr->next = ptr;
            ptr = curr;
        }
        return curr;
    }
};


//////////////////////////////////////////////////
