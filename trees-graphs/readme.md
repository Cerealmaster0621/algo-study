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
    //base cases
    if(root == nullptr){
        return 0;
    }
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
            stack.push(pair(node->right, depth+1));
        }
    }
    return ans;
}

```

> Important note about iterative implementations is that we are adding `node->left` before `node->right`, and popping from stack goes opposite. Thus, we are actually visiting the right subtree first. In the recursive implementations, we visited the left first. In this specific questions, order didn't matter but it is still good to understand that the visit order **opposite** the insertion order in iterative implementations.

## Time and Space Complexity of Binary tree DFS

The time and space complexity of tree questions is usually straightforward like - almost always O(n), since every node has to visited once, and at each node, O(1) of work is done. if more than O(1) work is done at each node, let's say O(k) work, then entire time complexity will be O(k*n).
For space complexity, worst case would be when tree is just a straight line, so O(n). When tree is complete(all nodes have 0 or 2 children and each level except the last is full), then the space complexity is O(log n), but this is the best-case scenario.

When changing **recursive** function to **iterative** in DFS binary tree, pseudo code follows: 
```c++
//use pair of stack to follow current node and information you want to check with (depth, value sum etc,,,)
function(TreeNode* root) {
    if(root == nullptr){
        return baseCaseValue;
    }
    //more base cases here if needed
    stack<pair<TreeNode*, infoType>> stack;
    stack.push(pair(root, rootInfo));
    while(!stack.empty()){
        auto[node, val] = stack.top();//populate values from stack
        stack.pop();//pop from here
        //leaf logic or breakpoint logic if necessary
        if(node->left != nullptr){//if left node exists logic
            stack.push(pair(node->left, leftInfo));
        }
        if(node->right != nullptr){//if right node exists logic
            stack.push(pair(node->right, rightInfo));
        }
    }
    return something;
}
```

# Binary trees - BFS

In DFS, we prioritized depth. In breadth-first search (BFS), we prioritize breadth. In BFS, we traverse all nodes at a given depth before moving on to the next depth.

While DFS was implemented using a stack(recursive uses a stack under the hood), **BFS** is implemented **iteratively** with a **queue**.

## When to use BFS vs DFS?

In DFS, the important thing was that you just visit all nodes. preorder, inorder or postorder was crucial to know how it works but not important in solving questions.

In Binary tree problems, BFS is usually more efficient than DFS

### Main disadvantages of DFS

The main disadvantage of DFS is that you could end up wasting a lot of time looking for a value. when tree is **huge**, it could be inefficient because you have to search the entire left subtree, which could be milions of operations.

### Main disadvantages of BFS

The main disadvantage of BFS is that when the value is likely to be located bottom of the tree, you will waste a lot of time looking for a value.

### Space complexity comparison

DFS uses space linear with the height of the tree(the maximum depth), whereas BFS uses space linear with the level that has the most nodes. It depends on how tree looks like. 
For example, in **perfect binary tree**, DFS use O(log n) space, whereas BFS use O(n). The final level in a perfect binary tree has n/2 nodes, but the tree only has the depth of logn.

however, if the tree looks like lopsided(straight line), BFS will have O(1) space complexity while DFS have O(n).

## BFS code implementation

BFS implementations are very similar across different problems.

```c++
void bfs(TreeNode* root){
    queue<TreeNode*> queue;
    queue.push(root);
    //every first lines of while loop, queue contains every nodes of current depth.
    while(!queue.empty()){
        int n = queue.size();//current depth
        //some logic for current depth level
        while(n--){
            TreeNode* node = queue.front();
            queue.pop();
            //some logic for current node
            if(node->left != nullptr){
                queue.push(node->left);
            }
            if(node->right != nullptr){
                queue.push(node->right);
            }
        }
        //if there are ans vector or cnt variables to update, do it after depth iteration
    }
}
```

# Binary search Trees

BST is a type of binary tree. BST has the following property:

> For each node, all values in its left subtree are less than the value in the node, and all values in its right subtree are greater than the value in the node.

![image](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1920px-Binary_search_tree.svg.png)

In this example of BST, let's say we want to find 7. value of root node is 8, so 7 is smaller than the value, so ignore right. next is 3, 7 is greater than 3 so ignore left and go right. same as 6, 7 is greater than 6 so go right. We found the 7.

This process has an average time complexity of O(logn). In the worst case scenario, let's say if the tree is linear(basically linked list, just straight line), the time complexity would be O(n).

If you perform **inorder DFS** with BST, you will traverse in **sorted order**.

# Graphs

A graph is any collection of nodes and connections between the nodes.

> Another term for nodes is vertex(verticies), and the connection between nodes are called edges.

Binary tree is also a graph, but they just have lots of restrictions.

## Graph terminology

Edges of a node can be either directed or undirected. When there are directed connection between `A` and `B` such as, `A->B`, you can move from `A` to `B`, but not `B` to `A`. Undirected edges mean you can move either way.

Another important term as directed/undirected is connected component. Connected components are the groups of nodes that are connected by edges.

> For example, binary tree have only one connected components, because every nodes are reachable from the root component.

![img](https://qph.cf2.quoracdn.net/main-qimg-0563516a0d43b1653e59ce5c838d9b46)

In this following graph, vertex 4 has 3 **outdegrees** and 3 **indegrees**. 
vertex 7 has 2 **indegrees**, which is 4 and 5, and 1 **outdegrees**, which is 6. Vertex 7 itself is called **degree** in this case.

Nodes that are connected by the edges are called **neighbors**.

A graph can be either **cyclic** or **Acyclic**.
Not every verticies has to be connected for Cyclic graph. If the part of graph forms cycle, it is called **cyclic**.

## How are graphs given in the problems?

Unlike the Linked List or Binary tree problems, where head or root of the points are given, and it actually exists in the memory, graph problems are mostly abstract and doesn't really exist in real memories. 
Many times, nodes of a graph is labeled like `0` to `n-1`. Sometimes there might be a story, and you need to determine yourself that it is a graph problem.

With binary trees, traversal was easy because we only needed to care about node->left or node->right. 
In graph traversal, we need to do some preworks before traversal, making sure that we can access to any given `node` and it's neighbors.

### First input format : array of edges

In this input format, the input will be the 2D array. edges between two nodes going to be like `[x,y]`, which indicates that there is an edge between `x` and `y`. It can be directed or undirected. 

At every node, we would need to iterate over entire input to find the neighbors, and it is very slow. Instead, we use the data structure of Hash map of key for node, value for array of neighbors. 

>simple implementation in graph_array_of_edges.cpp in this directory.

### Second input format : adjacency list

In an adjacency list, the nodes will be numbered from 0 to n-1. The input will be a 2D integer array, and adjacency list will be printed like
`[[0th outgoing edges],[1st outgoing edges],,,,[n-1st outgoing edges]]`
We don't need preprocessing from this input format, since we can access to any neighbors with the adjacency list. Remember, **proprocessing** is necessary for making list of any possible neighbors we can access.

### Third input format : adjacency matrix

Adjacency matrix is a 2D square **n*n** shaped matrix. if graph[i][j] == 1, that means there is an outgoing edge from node i to node j.
Alternatively, you can **preprocess** the graph as we did with an array of edges. Build a hashmap and iterate over the entire graph. If graph[i][j] == 1, then perform `map[i].push_back(j)`. this way, when performing the traversal, you will not need to iterate n times at every node, instead, you can find neighbors from the map, which takes only O(1). This is especially useful when nodes have only a few neighbors and n is large.

Both of these approaches will have a time complexity of **O(n^2)**, since they all have to iterate entire map at least once.

### Last input format : matrix

This format is more subtle but very common. The input is going to be 2D matrix and the problem will describe how this matrix formed like. For example, "Each square of the matrix is a village, Villages trade with their neighboring villages, which are the villages directly above, to the left, to the right, or below them."

In this case, each square `(row, col)` of the matrix is a node, and the neighbors are `(row -1, col), (row, col -1), (row + 1, col), (row, col + 1)` (if in bounds).

## Code differences between graphs and trees



# Graph - DFS

## connected components

Just like leetcode 547 problems, one part of the graph problem is when they ask you connected components(nodes). When graph is undirected, a DFS from any given node will visit every nodes in component that they belongs to. to avoid cycle when traversing, we need to use a `hash set` to track which nodes we have already visited. After traversal with DFS, every nodes in the component will be marked in the hashset `seen`, every nodes we have already visited.

Before actually starting traversal, first build a graph that is easily accessible from any given neighbors. In C++, use hashmap of key `index` and value for `vector<int>` to store every neighbors related to the index. 

# Graph - BFS

## Bidirectional Search

Bidirectional Search is a BFS way of graph approaching used when
1. Both initial and goal states are unique and completely defined.
2. The branching factor is exactly the same in both directions.
The goal to use this Bidirectional search is to find the shortest path between a source and destination node. Basically, it operates by essentially running to simultaneous BFS, one from each node. When their searches collide, we have found a path.

# Topological Sort

## DAG - Directed Acyclic Graph
![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fe/Tred-G.svg/1024px-Tred-G.svg.png)
A Directed Acyclic Graph is a graph that starts with node A and ends with E. If the graph has the cycle or is not directed, it is not DAG and topological sort is not possible either.

## How to implement Topological sort? - Kahn's Algorithm

What we have as a input is a Directed Acyclic Graph that some node has **0 Indegree** and some **0 Outdegree**. 
First, we will count every node's Indegrees. After that, we will look up for the node that has 0 Indegree. In the above DAG example, that would be `A`. Then, we pop `A` from the graph, and enqueue `A` to the queue. After pop from the graph, we have to update every indegrees value since we don't have `A` from the graph anymore. Any nodes that had `A` as an Indegree has to be updated. After that, we will do the same procedure(Find the node where it's Indegree is 0, pop it, push to queue and update the outdegree's Indegree value) until we face the node that has 0 Indegree **AND** 0 Outdegree. That would be `E` in the above example.
```c++
function TopologicalSort( Graph G ):
  for each node in G:
    calculate the indegree
  start = Node with 0 indegree
  G.remove(start)
  topological_list = [start]
  While node with O indegree present:
    topological_list.append(node)
    G.remove(node)
    Update Indegree of present nodes
  Return topological_list
```

