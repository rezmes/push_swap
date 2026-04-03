t_stack_node	*find_last_node(t_stack_node *stack)
{
		if(!stack)
				return (NULL);
		while (stack->next)
				stack = stack->next;
		return (stack);
}
