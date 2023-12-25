/*
leetcode 2095 medium
Dummy node + fast/slow pointer
use dummy for generate before head node.
before - slow - after 
slow is the middle node, before and after will be
connected after delegation of slow.
Example
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* before = dummy;
        ListNode* fast = head;
        ListNode* slow = head;
        before->next = slow;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            before = before->next;
        }
        ListNode* after = slow->next;
        before->next = after;
        slow->next = nullptr;
        return dummy->next;
    }
};