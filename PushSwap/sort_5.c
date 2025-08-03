#include "push_swap.h"

void	sort_5(t_node **a, t_node **b)
{
	int	last;

	while (list_size(*a) > 4)
	{
		last = list_last(*a)->index;
		if (is_sorted(*a))
			break ;
		if ((*a)->next->index == 0 && (*a)->index == 1)
			swap_a(a);
		else if (last == 0 && (*a)->index == 1)
			rotatex2_a(a);
		else if ((*a)->index == 0 || (*a)->index == 1)
			push_b(a, b);
		else if ((*a)->next->index == 0 || (*a)->next->index == 1)
			swap_a(a);
		else
			rotatex2_a(a);
	}
	if (list_size(*a) == 4)
	{
		sort_4(a, b);
		push_a(a, b);
		if ((*a)->index == 1)
			swap_a(a);
	}
}
