<h1 align="center">
PUSH_SWAP - 42 PROJECT
</h1>

## Index

- [Index](#index)
- [Description](#description)
- [Operation :wrench:](#operation-wrench)

## Description
<p>
Optimized data sorting algorithm. The goal of this project is to sort in ascending order a stack with X amount of random different integers using a limited set of movement operations with the lowest possible count of movements.

All the functions used in this program are created by myself except for `write()`, `malloc()`, `free()` and `exit()`. For more information about the project check the subject here. My code was written following a bunch of rules and syntaxes formatting described in the 42 Norme. To check the Norme click here.
</p>

## Operation :wrench:

<p>
Displays on the standard output the smallest program, made of Push swap language instructions,
that sorts the integers received as arguments.
At the beginning stack A has all the unsorted numbers and stack B is empty. At the end of the program stack A has to be in ascending order and stack B empty. For sorting we are allowed to use only the following moves:

| Movements              | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------------- |
| sa (swap a)            | swap the first 2 elements at the top of stack A                                 |
| sb (swap b)            | swap the first 2 elements at the top of stack B                                 |
| ss                     | execute sa and sb at the same time                                              |
| pa (push a)            | take the first element at the top of stack B and put it at the top of stack A   |
| pb (push b)            | take the first element at the top of stack A and put it at the top of stack B   |
| ra (rotate a)          | shift up all elements of stack A by 1. The first element becomes the last one   |
| rb (rotate b)          | shift up all elements of stack B by 1. The first element becomes the last one   |
| rr                     | exec ra and rb at the same time                                                 |
| rra (reverse rotate a) | shift down all elements of stack A by 1. The last element becomes the first one |
| rrb (reverse rotate b) | shift down all elements of stack B by 1. The last element becomes the first one |
| rrr                    | exec rra and rrb at the same time                                               |

</p>