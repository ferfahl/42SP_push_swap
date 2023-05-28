# 42SP_push_swap
The <b>push_swap</b> program is a project from école 42. There are stickt rules to follow.

[![feralves's 42 push_swap Score](https://badge42.vercel.app/api/v2/cli7l4sim001108mvngbgwmeh/project/2922598)](https://github.com/JaeSeoKim/badge42)

## Main goal
Sort the stack A in an ascending order numbers(from smallest to largest) with the least amount of moves possible. 
<br>During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated.
<br>You have some limitations: you only have a stack B you can use. 
<br>Also, there's some specific moves you can do:

* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
* rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
* rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

## Some other instructions

* Must be according to the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf);
* Must be written in the C language;
* Must have a Makefile that compiles, delete and recompile the project;
* In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates
* External functions that are allowed: read, write, malloc, free, exit


### Project approved with 96/100 score.
