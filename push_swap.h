#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack_node
{
		int					value;
		int					index;
		int					cost_a;
		int					cost_b;
		struct s_stack_node *target_node;
		struct s_stack_node	*next;
		struct s_stack_node *prev;
} t_stack_node;

// Swap
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
// Push
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_b, t_stack_node **stack_a);
// Rotate
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
// Reverse rotate
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
//Util
t_stack_node	*find_last_node(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);

// Algorithm
void	sort_three(t_stack_node **stack_a);
void	turk_sort(t_stack_node **a, t_stack_node **b);

// Parser & Memory
void	init_stack_a(t_stack_node **a, char **argv);
void	free_stack(t_stack_node **stack);
void	error_exit(t_stack_node **stack);
void	free_split(char **args);

// Target & Position Utils
void			set_current_position(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*get_target_in_a(t_stack_node *stack_a, int b_value);
void			set_target_a_to_b(t_stack_node *stack_a, t_stack_node *stack_b);

// Cost & Execution
void			calculate_cost_a_to_b(t_stack_node *stack_a, t_stack_node *stack_b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);

#endif
