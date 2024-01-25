# Greedy algorithms

A greedy algorithm is any algorithm that makes the locally optimal decision at every step.

What is **optimal**? It depends on the problem. For example, if we are choosing some elements and the problem wants us to find the maximum sum of elements we take, then given a choice between two numbers, it is **optimal** to take the larger one.

Second, what is **local**? when a decision is local, it considers only the current step. The decision you're making on this step should not be influencing on the next step. 

> Most greedy problems will be asking for the maximum/minimum of something, but not always.

> heaps also can be considered greedy. A heap gives us a maximum or minimum element, and generally greedy approaches will be choosing max/min elements at each "step".

> Another thing to note is that in many greedy problems, you will be sorting the input at the start. It is because sorting the element makes decision easier.

Implementing greedy algorithm is very easy. The hard part is realizing/proving that a greedy strategy actually works. TSP is a good example.

Greedy isn't a datastructure and it isn't any single algorithm either, but more of a way to approach a problem. It is important for you to realize that this problem is a greedy problem.

# Example greedy problems

Core concept of the greedy algorithm is that it has to be ensured that smaller chunks of procedure can solve the bigger problems.

1. Approximation Algorithm