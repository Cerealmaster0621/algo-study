
  

# Two Pointers

  

  

Two pointers is mostly used to solve array and string problems. it involves having two integer variables commonly named i or j, or left and right, which will be used to indexing array or string.

  

  

## Instructions

  

1. start one pointer at the first index 0 and other at the last index input.length() - 1

  

2. use the while loop until the pointers are crossed or meet each other( ``while left<right `` )

  

3. Add some logic inside the loop depends on the problem. decide on one of the follow :

  

1. left++

  

2. right--

  

3. Both left ++ and right --

  

# Sliding Windows

  
  

# [Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum)

  

Prefix sum is a technique that can be used on arrays(of numbers). It is basically creating new arrays "prefix" where prefix[i] is the sum of all elements up to the index i.

  

**ex)** given arrays nums = [1,2,3,4,5], we make new arrays prefix = [1,3,6,10,15].

If we want the subarray of sum from index i to j, that would be **prefix[j] - prefix[i] + nums[i].** \

`it could also be prefix[j]-prefix[i-1] when i is not 0 (out of bounds).`

## How to build the prefix sum array

  

`| Given an array nums,`\

`|`\

`| prefix = [nums[0]]`\

`| for (int i = 1; i < nums.length; i++)`\

`| prefix.append(nums[i] + prefix[prefix.length - 1]) `

# More Common patterns

## O(n) string building

In general cases, building the length n of string requires O(n^2) operations. There are better ways to build strings in just O(n) time. This varies languages, but In C++ and JavaScript, simply using += for each character is the most effective way to build the string.

## Subarrays/substrings, subsequences, and subsets

If a problem has explicitly implying such as :

 - Sum greater than or less than K
 - Limits on what is contained, such as the maximum of K unique elements or no duplicates allowed.
 
 And/or asks for :
 
 - Minimum/maximum length
 - Number of subarrays/substrings
 - Max or minimum sum
 
Every problems with these characteristics also can be solved with sliding window, but not all sliding window problems have these characteristics.

## Generating every subsets in C++

### Bit Masking methods

1. create a set called **subsets** to store the unique subsets.
2. create the number of elements(sizes) in the given vector arr, denoted as n.
3. Make outer loops for the all posible values iteration. mask or i variable from 0 to (1<<n)-1. Each value of mask represents a subset of the elements in arr. (if the size n = 3. all possible size of subsets is 2^3 = 8. Outer loop is iterating through entire subsets that can be created.
4. For each beginning of the outer loop, initialize the empty vector called subset to store the current subset.
5. Make inner loop for the all elements from j = 0 to n-1, check if the jth bit of the mask is set(i.e., (mask>>i)&1 == 1). If it is set, add the corresponding element from nums to the set.
6. Sort the subset to ensure that duplicate subsets are considered the same, and insert it in to the subset set.
7. After processing all possible mask values, convert the set of subsets into a vector and return it.
