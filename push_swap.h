#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack_node
{
		int					value;
		int					index;
		struct s_stack_node	*next;
		struct s_stack_node *prev;
} t_stack_node;

// Swap
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
// Push
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pa(t_stack_node **stack_b, t_stack_node **stack_a);
// Rotate
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
// Reverse rotate
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
//Util
t_stack_node	*find_last_node(t_stack_nod *stack);
int				stack_len(t_stack_node *stack);

#endif
