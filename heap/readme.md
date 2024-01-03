# Heap

Heap is a data structure that is an implementation of Priority Queue.

A heap is a container that stores elements, and supports the following operations:

- Add an element in ***O(log n)***
- Remove the minimum element in ***O(log n)***
- Find the minimum element in ***O(1)***
  
> A heap can also find the max elements instead of the min elements. If a heap is configured to find/remove the min element, it's called a min heap. If the opposite, it's called a max heap.

The ability to find the max/min element in constant time, while only needing log time to maintain this ability is extremely useful for this order-keeping data instructions.

## How is a heap implemented?

There are multiple ways to implement a heap, although the most popular way is called a **binary heap** using an array. In the trees and graphs chapter, we saw that binary trees are typically implemented with a `Node` object.

> Another constraint is that the tree must be a complete tree.

In many problems, using a heap can improve an algorithm's time complexity from ***O(n^2)*** to ***O(nlogn)***. A heap is a great option whenever you need to find the maximum or minimum of something repeatedly.

### C++ Interface implementation

```c++
vector<int> arr = {3,2,4,5,1,6};
//C++ priority_queue implements a max heap by default.
//this converting vector to heap will take O(nlogn)
priority_queue<int> heap(arr.begin(),arr.end());

heap.push(7);
//maximum element by default
heap.top();
//pop maximum element
heap.pop();
//get size
heap.size();
```

# Heap examples

