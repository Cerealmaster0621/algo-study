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