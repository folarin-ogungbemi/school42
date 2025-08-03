#include "push_swap.h"

int	has_in_range(t_node *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_max_pos(t_node *stack)
{
	int		pos;
	int		max_pos;
	int		max;
	t_node	*tmp;

	pos = 0;
	max_pos = 0;
	max = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (max_pos);
}

int	position_in_stack(t_node *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	find_max_index(t_node *stack)
{
	int	max;

	max = -1;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	position_of_index(t_node *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
