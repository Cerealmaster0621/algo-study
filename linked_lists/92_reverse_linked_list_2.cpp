/*
leetcode 92 medium
reversed linked list ii
use sentinel node(dummy node) for edge case handling
sentinel node is right before head, so if left is 1,
before node will indicate sentinel node instead nullptr.

1. place before node right before the left
2. use prev-curr-next for reverse left to right nodes
3. link before->n->n = curr(after recursion, it indicates
right next node of after nodes of recu.)

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* before = dummy;
        for(int i = 1; i<left; i++){
            before = before->next;
        }
        ListNode* prev = before;
        ListNode* curr = prev->next;
        for(int i = left; i<=right; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        /*
        1-2-3-4-5. left - 2 right - 4 일때,
        before->next는 2를 가리킴. 
        2는 순서 바뀐뒤에 subarray의 마지막이됨.
        그러나 원래 노드들과 연결이 끊어졌음. 
        curr은 subarray 마지막인 prev의 다음을 가리킴.
        위의 예시의 경우 prev - 4, curr - 5.
        before->next->next = curr 을 함으로서
        2와 5의 연결을 만들어줌.
        before->next = prev를 함으로써 1과 4의
        연결을 만들어줌. 
        최종적으로 1-4-3-2-5 가됨.
        이 두줄의 순서가 바뀌면 안됨. before->next
        가 처음에 2를 가르키고 있는게 중요
        */
        before->next->next = curr;
        before->next = prev;

        return dummy->next;
    }
};