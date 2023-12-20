# Hashing

This article will treat about the undrelying implementation details of data structure.

## Hash function
>Hash function is a function that takes an input and deterministically converts it in to an integer that is less than a fixed size set depends on the programmer.

### One example of Hash algorithm for English alphabet:
1. Declare an integer `total`.
2. iterate over the string. For each charaters, convert it in to it's position of the alphabet. For example, `a -> 1`, `c -> 3`, `z->26` .
3. Take that value, and multiply it by the current position in the string(index +1). For example, inside the string `cba`, the `c` is at position 3 in the alphabet and position `1` in the string, so it would contribute `3 * 1 = 3` towards `total`.
4. After going through every character, total is the converted value.

However, this algorithm is not a good example of hash function. It is better to module `total` by `x`, and the `x` is the limit we set for fixed size `total`. With this converted `total` value, final converted value will be in the range `[0, x-1]`.

### What is the point?
When a hash function is combined with an array, it creates a **hash map**. also known as a **hash table** or **dictionary**.

with arrays, we **map** indicies to values. For example, in arr = [1,2,3], arr[0] = 1. With hash maps, we map **keys** to values, and a key can be almost anything. However, key of the hash map has to be **immutable**. Values can be anything.

**Hash map** is a very powerful data structures. The following operations are all O(1):

 - Add and Delete an element
 - Check if an element exists.
 - Find length/number of elements
 - Updating values
 - Iterate over elements

### Disadvantages of using hash maps

- O(1) is a constant but not always faster than any other non-constants like O(n).
- Every key in a hash map needs to be processed through a hash function. It can introduce a non-trivial amount of processing time.
- When two different keys produce the same hash value, collision might happened.
- Resizing hash table is much more expensive because every existing key has to be re-hashed.

## Collisions

When different keys converted to the same integer, it is called a collision. There are multiple ways to handle collisions, but **chaining** is the most famous method.

### Chaining

## Sets

A set is another data structure that is very similar to a hash table. They have same mechanism for hashing keys into  integers. The difference between set and hash table is that sets do not map their keys to values. So Sets are more convenient to use when only have to care about checking if elements exists.

Sets also don't allow multiple instances of the same value. If same element `1` is added 100 times in to set, only first `1` will be added and next 99 don't.

### Arrays as keys
keys of has map has to be immutable, but Arrays also can be keys even if it is mutable. In C++, built-in implementations convert array to string, for example, `[1, 51, 163] -> "1,51,163"`.

