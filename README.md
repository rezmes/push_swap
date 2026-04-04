*This project has been created as part of the 42 curriculum by mmesgari.*

## Description

`push_swap` is an algorithmic project at 42 school that requires sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The project utilizes two stacks (`a` and `b`).

This implementation uses the **Turk Algorithm**, a highly optimized cost-based approach. It calculates the cheapest sequence of operations (rotations and reverse rotations) required to push elements to stack `b` in descending order, and then pushes them back to stack `a` in their final ascending order.

## Instructions

### Compilation

To compile the project, navigate to the root directory and run:

```bash
make
This will generate the push_swap executable.

Execution
Run the program with a list of unique integers as arguments. The first argument will be at the top of stack a.

Bash
./push_swap 2 1 3 6 5 8
Or using a single string format:

Bash
./push_swap "4 67 3 87 23"
Validation
To verify the sequence of instructions, you can pipe the output to the provided OS checker:

Bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
Resources
Algorithm Logic: The sorting structure is based on the Turk Algorithm concept, which prioritizes dynamic cost calculation over hardcoded chunking methods.

Tools: Occasional use of AI tools strictly for interpreting ld linker errors and referencing 42's Norminette formatting rules.
