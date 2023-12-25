/*
leetcode 234 easy
palindrome linked list
same as 2130, use two pointers + reverse
1. slow/fast pointers for middle check
2. reverse from slow to end
3. compare prev/head
Example 1
Input: head = [1,2,2,1]
Output: true
*/

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast= head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = nullptr;
        while(slow!=nullptr){
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        while(prev!=nullptr){
            if(prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};