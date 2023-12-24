/*
leetcode 141 easy
linked list basic
fast/slow pointer approaches
and hashmap approach also available but
consumes more resources
Example 1
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head!= nullptr){
            if(set.find(head)!=set.end()){
                return true;
            }
            set.insert(head);
            head = head->next;
        }
        return false;
    }
};