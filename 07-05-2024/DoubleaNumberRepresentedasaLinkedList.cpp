// 2816. Double a Number Represented as a Linked List
// Medium

// 1072

// 27

// Add to List

// Share
// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

 

// Example 1:


// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:


// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

// Constraints:

// The number of nodes in the list is in the range [1, 104]
// 0 <= Node.val <= 9
// The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.


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
    
    int doubleUtil(ListNode* head) {
        if(head == NULL)
            return 0;
        
        
        int carry  = doubleUtil(head->next);
        int newVal = (head->val)*2 + carry;
        head->val = newVal%10;
        
        
        return newVal/10;
        
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        int lastCarry = doubleUtil(head);
        
        if(lastCarry > 0) {
            ListNode* newHead = new ListNode(lastCarry);
            newHead->next = head;
            return newHead;
        }
        
        return head;
        
    }
};