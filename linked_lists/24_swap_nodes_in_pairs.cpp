/*
leetcode 24 medium
Linked List 
what to return? - head nodes(when head is
modified, make dummy pointer to save head)
how to make node point each other?
- curr.next.next = curr
In this question, 
1. connect 1 and 2 each other and break the 
connection between 3 and 2
2. before that, save 3 (rest of the node) connec-
tion for later
3. move curr to connected 3, 3 pointer to 5(
    3 = 3.next.next 
)
4. if prev is not nullptr, point prev.next
to curr.next (1->4, 3->6..) and move prev to curr
Example 1
Input: head = [1,2,3,4]
Output: [2,1,4,3]
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
class Solution {//2,1,4,3,6,5,8,7
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* dummy = head->next;
        while(head!=nullptr && head->next!= nullptr){
            if(prev != nullptr){
                prev->next = head->next;
            }
            prev = head;
            ListNode* nextNode = head->next->next;
            head->next->next = head;
            head->next = nextNode;
            head = nextNode;
        }
        return dummy;
    }
};