#include "push_swap.h"

void	rotatex2(t_node **stack)
{
	t_node	*x;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	x = NULL;
	last = *stack;
	while (last->next)
	{
		x = last;
		last = last->next;
	}
	x->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rotatex2_a(t_node **stack_a)
{
	rotatex2(stack_a);
	write(1, "rra\n", 4);
}

void	rotatex2_b(t_node **stack_b)
{
	rotatex2(stack_b);
	write(1, "rbb\n", 4);
}

void	rotatex2_rr(t_node **stack_a, t_node **stack_b)
{
	rotatex2(stack_a);
	rotatex2(stack_b);
	write(1, "rrr\n", 4);
}
