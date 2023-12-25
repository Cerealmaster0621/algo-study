/*
leetcode 2130 medium
reverse + fast/slow pointer
Always know what's the current Node(this question,
it changes from slow->prev
)
1. use two pointer to get exactly half Node pointer(slow)
2. from slow to end, reverse the list
3. update max head+prev
Example 1
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = nullptr;
        while(slow!=nullptr){//slow is current
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        int mx = -1;
        while(prev!=nullptr){
            mx = max(mx, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }
        return mx;
    }
};