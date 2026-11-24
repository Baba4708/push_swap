*This project has been created as part of the 42 curriculum by bcaresme, kbouvet*

## Description :
The goal of this project is to discover algorithmic complexity by sorting numbers using only 2 stacks and the "push swap operations" using 3 algorithms, each with a different complexity. The program need
The "push swap operations" are:
- sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.
- sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
- rrr : rra and rrb at the same time.

The algorithms used here are:
- Insertion sort (O(*n<sup>2</sup>*))
- Bucket sort (O(n$\sqrt{n}$))
- Radix sort (O(*n* log *n*))

## Instructions :
Run `make` to compile the project, if it doesn't find the `libft.a` in `libft/`, it will also compile it.
Run `make clean` to delete the `.o` files
Run `make fclean` to delete `.o` files and the executable file.
Add `LIBFT=1` to the 2 last commands to affect the lib instead.

Once compiled, run `./push_swap` to launch the program.
Add one of the flags `--simple`, `--medium`, `--complex` or `--adaptive` to select the algorithm you want. If there is no flags, the default one is `--adaptive`.
Add the flag `--bench` to activate the benchmark mode, showing the disorder of the starting pile, the strategy used and its complexity, the total number of operations and the count of each operation type.
After your flags (or no flags), you have to add your starting stack, the first value being at the top of the stack.
## Resources :
Use of AI to upgrade our understanding of some algorithm and help us find which one we wanted to use and for some debugging.




## Algorithms :
- Insertion sort :
	The algorithm sorts a list by inserting the values of the not sorted part at their place in the sorted part, with a maximum of n<sup>2</sup> comparisons.
	In push_swap's case, the sorted part is the b stack, so every values of a are inserted one by one at their place in b. To do that, the algorithm find the place and rotate the stack in the shortest way (using rb or rrb).
	When all the values are in b, they are pushed back into a, sorted.
	We chose this algorithm because we already used it on regular lists.
	
- Bucket sort :
	The bucket sort is an algorithm that allows you to sort numbers by distributing them into several groups called `buckets`.
	In our program, we start by finding the minimum and the maximum values of the A pile. This creates several ranges of values.
	Then, the numbers are sent to the buckets corresponding to their values. Once this distribution is complete, the elements are recovered by putting them back in pile A in the right order.
	The goal is to distribute the numbers to avoid having to sort them on by one with a slower algorithm.
	
- Radix sort :
	The Root Sort is an algorithm that sorts numbers by looking at their bits, that is, their binary representation.
	
	We use the LSD (Least Significant Digit) method. This means that sorting begins with the least important bit and gradually moves towards the largest bit.
	
	Before we begin, our program transforms numbers into indices. For example, the smallest number receives the 0 index, the next receives the index 1, and so on. This 
	step also allows you to manage negative numbers.
	
	Then, for each bit, we look at its value:
	- If the bit is 0, we send the number in stack B with pb.
	
	- If the bit is 1, it is left in stack A by performing ra.
	
	At the end of each passage, we put the elements of B back in A with pa. We start again until we have processed all the necessary bits.

## Roles of the group's members :

- bcaresme : stack manipulation's functions, simple algorithm (first a bubble sort, then the insertion sort), Makefile and code harmony.
- kbouvet : main, parsing system, medium algorithm (bucket sort), complex algorithm (radix sort), adaptive algorithm and bench part.