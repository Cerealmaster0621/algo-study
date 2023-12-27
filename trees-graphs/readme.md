# Binary Trees

## Nodes and Graphs

trees and graphs are the most common type of interview question(also hashmap, but hashmap are not really a "type" of question, and "array" and "string" is too broad).

### Node

**Node** is an abstract data type with two things - node stores data(for any data types), and it has the pointer to other nodes.

### Graph

**Graph** is any collection of nodes and their pointers to other nodes. So we can say linked lists and trees are both types of graphs. However, even though a tree is a type of graph, in terms of algorithm problems, it is considered different topics. It is because graphs are more advanced/difficult topic than trees.

## Tree

Like a linked list, a **tree** is a type of graph. And just like linked list, there are many types of trees. One of the famous tree is **binary trees**.

### Binary tree

Just like start of a linked list was called the **head**, start of a binary tree is called the **root**. Just like linked list has pointers to its children, binary tree has maximum 2 children pointers.

Trees(not just binary trees) are implemented all around in real life.
- file systems
- A comment thread on reddit or twitter
- Company's organization chart

### Tree terminology

Every node in the tree is accessible starting from the root node. In most tree questions, the **root** of the tree will be given as the input, just like **head** has given in linked lists.
If you have node **A** with an edge to a node **B**, so `A->B`, we call **A** the **parent** of node **B**, and node **B** a **child** of node **A**.
If a node has no children, it is called a **leaf** node. The leaf nodes are the **leaves** of the tree.
The **depth** of a node is how far it is from the root node. The root has a depth of `0`. Every child has a depth of `parentsDepth + 1`. so if some children's parent has the depth of 1, their children has depth 2.

### Subtree

Taking a subtree of a tree is one of the most important thing to understand. **Subtree** of a tree is a node and all its descendants. Take an example of entire company, when we seperate Engineering department from rest of the company, SVP(Senior Vice President) of engineering now becomes the root of the subtree. You can take any given node and treat it as its own tree.

## Code implementation for tree

Just like linked list, binary trees are implemented with using custom clas.

```c++
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};
```

