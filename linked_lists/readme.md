# Linked Lists

## What to return?

return head Node in Linked list, that will show entire Linked lists. however, if head is directly modified, save first node with variable (dummy) and return dummy.

## Conventional LL techniques

**Sentinel(Dummy) Node**
Using Dummy node can be helpful for many situations. 

**Fast/Slow pointer**
getting mid of the list - update fast pointer to fast->next->next and slow to slow->next. when fast or fast->next is nullptr, slow ptr is the middle node.
checking recursion - differenciate fast/slow pointer movement speed and when they meet, it's on recursion.


**Pointer for the previous node**

**making single-linked list to point each other**
curr->next->next = curr (break the connection to the rest of the linked list. save the curr->next->next to variable before for connecting later)

