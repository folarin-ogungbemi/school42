#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	x1;
	int	x2;
	int	x3;

	x1 = (*stack_a)->value;
	x2 = (*stack_a)->next->value;
	x3 = (*stack_a)->next->next->value;
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

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	assign_indices(*stack_a);
	while (list_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_b(stack_a, stack_b);
		else
			rotate(stack_a);
	}
	sort_3(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap_b(stack_b);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}

void	radix_sort(t_node **a, t_node **b, int *max)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	assign_indices(*a);
	max_bits = 0;
	while ((((*max) - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < (*max))
		{
			if (((*a)->index >> i) & 1)
				rotate(a);
			else
				push_a(a, b);
			j++;
		}
		while (*b)
			push_b(b, a);
		i++;
	}
}

void	sort_by_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, &size);
}
