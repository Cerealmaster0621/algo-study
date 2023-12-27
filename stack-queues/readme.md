# Stacks

Stack is an ordered collection of elements where elements are only added and removed from the same end. It is like a stack of plates in a kitchen - you add plates or remove plates from the top of the pile. Another term to call stack is LIFO, which stands for Last In, First Out. The last(most recent) element placed inside is the first element to come out.

## Implementation

Stack can be implemented in a various ways. 
Dynamic array is the most common and easiest way, and the time complexity of operations is the same as that of dynamic array. O(1)for push, pop and random access, and O(n) for search. It can also be implemented with Linked list with a tail pointer.

Stack is very abstract interface, so you can implement whatsoever with adding and removing elements from the same end. It is quite similar to recursion, this is because recursion is actually done using a stack.

### C++ Interface Guide
```cpp
// Declaration: C++ supports multiple implementations, but we will be using
// std::stack. Specify the data type
stack<int> stack;

// Pushing elements:
stack.push(1);
stack.push(2);
stack.push(3);

// Popping elements:
// Note, unlike other languages, popping here does not return the popped value
stack.pop();
stack.pop();

// Check if empty
stack.empty(); // false

// Check element at top
stack.top(); // 1

// Get size
stack.size(); // 1
```

### When to use stack?

## String Problems

STRING IS ALSO USABLE AS STACK IN C++, while it's mutable. However, some Keywords or methods can be differed from stack<char> and string.

### Stack <-> String Comparison

**Pushing back**

In stack, 
```c++
stack.push(c);
```

In string,
```c++
string.push_back(c);
```
**Popping element**

In stack,
```c++
stack.pop();
```

In string,
```c++
string.pop_back();
```

**Populating last element**

In stack,
```c++
stack.top();
```

In string,
```c++
string.back();
```

**checking size and empty are same**
```c++
stack.size();
string.size();

stack.empty();
string.empty();
```

# Queues

Queue follows FIFO(first in first out).
In a stack, elements are added and removed from the **same** side. In a queue, elements are added and removed from **opposite** sides. Like a stack, there are multiiple ways to implement a queue, but it is trickier to implement for maintaining good performance.
Operations on the front of the array(adding or removal) are O(n). Adding a queue is **enqueue** and deletions are called **dequeue**. For O(1) of these operations, this will require more sophisticated implementation.

## Queue using Doubly linked list

If there is pointer to node, adding or deleting at that location is O(1).

## Queue using deque

Short for double-ended queue, and pronounced "deck". in a deque, you can add or delete elements from both ends.

## Where to use?

In algorithm problems, queues are less common, and more difficult in general. The most common use of a queue is BFS.

## Interface guide

```c++
// Declaration: C++ supports multiple implementations, but we will be using
// std::queue. Specify the data type
queue<int> queue;

// Enqueueing/adding elements:
queue.push(1);
queue.push(2);
queue.push(3);

// Dequeing/removing elements:
queue.pop();

// Check if empty
queue.empty(); // false

// Check element at front of queue (next element to be removed)
queue.front(); // 2

// Get size
queue.size(); // 2
```

```c++

// C++ DEQUE 
deque<int> deque;

//adding elements from front/back 
deque.push_front(1);
deque.push_back(2);
deque.push_front(0);
deque.push_back(3);

//removing from front/back
deque.pop_front();
deque.pop_back();

//size
deque.size();

//empty
deque.empty();

//indexing
deque.at(2); //same as arr[2]

//front/back
deque.front();
deque.back();
```

## Monotonic

Monotonic stack or queue is one whose elements are always sorted. It can be sorted either ascending or descending. for example,
given `stack = [1,5,8,15,23]`. you want to push 14 on to the stack. for maintaining the sorted stack, you need to first pop the 23 and 15 before pushing 14. after the operations, stack will look like `stack = [1,5,8,14]`.

```c++
Pseudo Code
given an integer array nums

stack = []
for num in nums:
    while stack.length>0 AND stack.top>=num:
        stack.pop()
    add some logic depends on algorithm
    stack.push(num)
```

before pushing a num onto the stack, first check if the monotonic property would be violated, and pop elements until it meets the condition.

when adding and deletion occures in both right places - and also sometimes need deletion or add from right, use **Deque** for efficient O(1) operations.