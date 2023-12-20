# Hashing

In this article it will treat about the undrelying implementation details of data structure.

## Hash function
>Hash function is a function that takes an input and deterministically converts it in to an integer that is less than a fixed size set depends on the programmer.

### Hash algorithm for an English alphabet:
1. Declare an integer `total`.
2. iterate over the string. For each charaters, convert it in to it's position of the alphabet. For example, `a -> 1`, `c -> 3`, `z->26` 