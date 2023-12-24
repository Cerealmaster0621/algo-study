/*
leetcode 206 easy
reverse linked list
use two pointer - one from null, one from head
store next pointer for temporily.
Example 1
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* nextNode = curr->next; // tmp for store next node
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};