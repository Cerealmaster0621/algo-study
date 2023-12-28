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

# Binary trees - DFS

Tree traversal is how we access the elements of a tree, and mandatory for solving tree problems.

In linked list, we traversed a linked list using following code: 
```c++
int getSum(ListNode* head){
    int sum = 0;
    while(head!=nullptr){
        sum+=head->val;
        head = head->next;
    }
    return sum;
}
```

in Linked list, we have the `head` variable referencing the node. We traversed entire node using the `->next` attribute.

Traversing a binary tree follows the same idea. We start the `root` and traverse by using the child pointers `->left` and `->right`. However, unlike we did iteratively in Linked lists using loop(while), with **binary trees**, we usually do it **recursively**. 

## Depth-first search DFS

In a DFS, we prioritize depth by traversing as far as possible in one direction (until it reaches to the leaf node, let's say `->left` this time). when we meet the leaf node, we explore the right subtrees after that.

Because we need to backtrack up the tree after reaching the end of a branch, DFS is typically implemented using **recursion**, but sometimes also looping over **stack** iteratively.

### DFS code implementation

```c++
void dfs(TreeNode* root){
    if(root == nullptr){
        return;
    }
    dfs(root->left);
    dfs(root->right);
    return;
}
```

The structure for performing a DFS is very similar to all problems. It goes follows:
1. Handle all the base case(s), usually an empty tree(`node == nullptr`) is a base case.
2. Do some logic for the current node
3. Recursively call on the current node's children
4. Return the answer

> However, depends on some questions, Step 2 and 3 may happen in different orders. 

The most important thing to understand is that each function calls focused on a **subtree**. if there are some logic added on step 2, that will be equally adapted in entire tree, however, step 2 itself is used for solving smaller sections(subtrees). You gradually build up the solution to the larger problem. So, this logic differs to the problem.

There are three types of DFS. Each of the tree types differs only in the order they execute steps 2 and 3.

## Three types of DFS traversal

### Preorder traversal

![image](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/Binary_tree_v2.svg/1126px-Binary_tree_v2.svg.png)

When logic is done on the current node **BEFORE** moving to the children, let's say this time we just want to print the value of each node in the tree to the console,

```c++
void preorderdfs(TreeNode* root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<endl;
    preorderdfs(root->left);
    preorderdfs(root->right);
    return;
}
```

In this example, we would see the nodes printed in this order : `1, 7, 2, 6, 5, 11, 9, 9, 5`

Because the logic(printing) is done immediately at the start of each function call, preorder handles nodes in the **same order** that the function calls happen.

### Inorder traversal

For inorder traversal, we first incursively call the left child, then perform logic(printing) on the current node, and then recursively call the right child. This means no logic will be done until we reach a node without a left child because it doesn't get called until we reach to the left end.

```c++
void inorderdfs(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inorderdfs(root->left);
    cout<<root->val<<endl;
    inorderdfs(root->right);
    return;
}
```

In this example, we would see the nodes printed in this order : `2 7 5 6 11 1 9 9 5`.

Notice that for any given node, it's value is not printed until all values in the left subtree are printed, and right subtree are not printed until after that.

### Postorder traversal

In postorder traversal, we recursively call on the children first and then perform logic on the current node. This means no logic will be done until we reach a leaf node since calling on the children takes priioriy over performing logic. `The last logic will be done in root`.

```c++
void postorderdfs(TreeNode* root){
    if(root == nullptr){
        return;
    }
    postorderdfs(root->left);
    postorderdfs(root->right);
    cout<<root->val<<endl;
    return;
}
```

Running the above code will be printed:
`2 5 11 6 7 5 9 9 1`

`
pre -> starting from node, logic will be worked on calling every left childs => right childs after that.

in -> starting from left end leaf child, after every node in next left has excecuted, right will be excecuted from top to bottom.

post -> edges are all called first, when edges have common parent, after two edges called, parents will be called.
`

## Solving problems with DFS

Most of the questions don't even require to use adequate traversal methods. Important thing is to traverse around every nodes.

### Finding the depth of Binary tree using DFS

When recursive function is returning something, you can also allocate recursive function to the variable. in leetcod 104. Maximum Depth of Binary Tree problems, where you have to write function that returns the maximum depth, you can allocate recursive function in the variable left and right. 
```c++
int maxDepth(TreeNode* root){
    //base cases where root is nullptr
    if(root == nullptr){
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    // return max + 1 because of requirements on 
    // questions
    return max(left, right) +1;
}
```

This solution is doing a **postorder** traversal because the logic for the current node(max() function) happens after the calls.

## DFS iterative implementation

All three types of DFS can be implemented iteratively, but postorder and inorder are more complicated to implement than preorder. However, most of the problems doesn't require specific type of DFS.

For iterative DFS implementation, we use a stack. We don't return values to store the depths just like we did on recursive, so instead we bind the current Node - current depth on the stack. in C++, `stack<pair<TreeNode*, int>>` will do it.

In this implementation, we will use the **preorder** DFS instead of postorder since in/post order implementation in iteratives are harder than recursive.

```c++
//implementation on TreeNode from most of the problems
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val), left(left), right(right){}
};

//max depth using iterative
int maxDepth(TreeNode* root){
    stack<pair<TreeNode*, int>> stack;
    int ans = 0;
    stack.push(pair(root, 1));
    while(!stack.empty()){
        auto [node, depth] = stack.top();
        stack.pop();
        ans = max(ans, depth);

        if(node->left){
            stack.push(pair(node->left, depth+1));
        }
        if(node->right){
            stack.push(pai(node->right, depth+1));
        }
    }
    return ans;
}

```