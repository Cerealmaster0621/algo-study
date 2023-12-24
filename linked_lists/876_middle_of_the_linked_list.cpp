/*
leetcode 876 easy
basic fast/slow pointer
twice the gap between fast/slow. eventually slow or slow+1
becomes the middle node
Example 1
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            if(fast->next->next == nullptr) return slow->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};