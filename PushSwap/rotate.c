#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	*stack = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
