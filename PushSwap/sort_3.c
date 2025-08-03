#include "push_swap.h"

void	sort_3(t_node **stack_a)
{
	int	x1;
	int	x2;
	int	x3;

	x1 = (*stack_a)->index;
	x2 = (*stack_a)->next->index;
	x3 = (*stack_a)->next->next->index;
	if (x1 > x2 && x2 < x3 && x1 < x3)
		swap_a(stack_a);
	else if (x1 > x2 && x2 > x3)
	{
		swap_a(stack_a);
		rotatex2_a(stack_a);
	}
	else if ((x1 > x2) && (x2 < x3) && (x1 > x3))
		rotate_a(stack_a);
	else if ((x1 < x2) && (x2 > x3) && (x1 < x3))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((x1 < x2) && (x2 > x3) && (x1 > x3))
		rotatex2_a(stack_a);
}
