
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

**ex)** given arrays nums = [1,2,3,4,5], we  make new arrays prefix = [1,3,6,10,15]. 
If we want the subarray of sum from index i to j, that would be prefix[j] - prefix[i] + nums[i]. 
`it could also be prefix[j]-prefix[i-1] when i is not 0 (out of bounds).`
## How to build the prefix sum array

` |  Given an array nums,`
`| `  
`|  prefix = [nums[0]]`
`| for (int i = 1; i < nums.length; i++)`
`|   prefix.append(nums[i] + prefix[prefix.length - 1]) `

