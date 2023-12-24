/*
leetcode 2130 medium
reverse + fast/slow pointer
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