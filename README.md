<h1 align="center">
PUSH_SWAP - 42 PROJECT
</h1>

## Index

- [Index](#index)
- [Description :clipboard:](#description-clipboard)
- [Allowed movements](#allowed-movements)
- [Operation :wrench:](#operation-wrench)
- [Author](#author)

## Description :clipboard:
<p>
Optimized data sorting algorithm. The goal of this project is to sort in ascending order a stack with n random different numbers using a limited set of movements operations with the lowest possible count of movements.

The subject says that the program must have 2 stacks named A and B. While running, displays on the standard output the current movement followed by a new line. For more information about the project subject check it [here](https://github.com/pedromessetti/push_swap/blob/master/subject.pdf). All the functions were coded by myself and written following the rules described in the 42 Norme. To check the Norme click [here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).

External functions used: `write()`, `malloc()`, `free()` and `exit()`.
</p>

## Allowed movements

For sorting the stacks the program is allowed to use only the following moves:

| Movement               | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------------- |
| sa (swap a)            | Swap the first 2 elements at the top of stack A                                 |
| sb (swap b)            | Swap the first 2 elements at the top of stack B                                 |
| ss                     | Execute sa and sb at the same time                                              |
| pa (push a)            | Take the first element at the top of stack B and put it at the top of stack A   |
| pb (push b)            | Take the first element at the top of stack A and put it at the top of stack B   |
| ra (rotate a)          | Shift up all elements of stack A by 1. The first element becomes the last one   |
| rb (rotate b)          | Shift up all elements of stack B by 1. The first element becomes the last one   |
| rr                     | Execute ra and rb at the same time                                              |
| rra (reverse rotate a) | Shift down all elements of stack A by 1. The last element becomes the first one |
| rrb (reverse rotate b) | Shift down all elements of stack B by 1. The last element becomes the first one |
| rrr                    | Execute rra and rrb at the same time                                            |



## Operation :wrench:

<p>
First of all the program checks if the count of arguments is bigger than 1 and if they are acceptable arguments. In case of an invalid arguments such as: non integers, duplicated, bigger than INT_MAX or smaller than INT_MIN, the program displays "Error" followed by a new line on the standard error and terminate with EXIT_FAILURE exit status.

If the arguments are correct, the program starts to push all the numbers to stack A in the exact order they are passed (this doesn't count as a movement, is just initializing stack A). If the arguments are passed already in ascending order the program terminate with EXIT_SUCESS exit status. If doesn't, it calls `define_sort()` function that will choose based on the size of stack A wich sorting algorithm the program will use.

If the stack only have 2 numbers simple execute a `sa()` and it is sorted. If have 3 numbers, uses kind of a brute force algorithm for cover all the 5 possible cases:
</p>

<h4 align="center">

1º case:

    2, 3, 1 => rra() => 1, 2, 3

2º case:

    3, 1, 2 => ra() => 1, 2, 3

3º case:

    2, 1, 3 => sa() => 1, 2, 3

4º case:

    3, 2, 1 => sa() => 2, 3, 1 => 1º case scenario

5º case:

    1, 3, 2 => sa() => 3, 1, 2 => 2º case scenario
</h4>

<p>

For 5 random numbers, the algorithm is pretty simple: send the first 2 numbers to stack B using `pb()`, sort the stack A using the logic for sort 3 numbers, calcultes and choose the correct rotation for stack A to recive the numbers in stack B in the correct order, then `pa()` and stack A is sorted.

When the stack A has more than 5 numbers the program always use the same algorithm. Basically it's a cost calculation that choose the best movement to execute given the numbers on stack A and B. At start the algorithm will calculate a medium value between all the numbers in the stack A and send all the numbers that are inferior to this medium value to stack B using `pb()` and the numbers that are higher are send to the bottom of stack A using `ra()`, constantly repeating this process until stack A has only 5 elements. Then sort the stack A using the algorithm for sorting 5 numbers. After stack A is sorted the program starts to calculate the best cost for choose the best movement inside of a while loop until stack B is empty. Then just correct choose the best rotate movement depending on the position of the biggest element on the stack. At the end, the stack A is sorted in ascending order and stack B is empty.
</p>

## Complexity 

<p>

This algorithm sorts:
- 100 numbers with an average of 600 moves.
- 500 numbers with an average of 5000 moves.
- 1000 numbers with an average of X moves.

It's a perfect algorithm for numbers in a range, while the input number is higher the complexity changes.
</p>

## Author
| [<img src="https://avatars.githubusercontent.com/u/105685220?v=4" width=115><br><sub>Pedro Vinicius Messetti</sub>](https://github.com/pedromessetti) |
| :---------------------------------------------------------------------------------------------------------------------------------------------------: |