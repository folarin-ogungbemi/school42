#include "push_swap.h"

int	list_size(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	assign_indices(t_node *stack)
{
	int		size;
	int		i;
	t_node	*min;
	t_node	*curr;

	size = list_size(stack);
	i = 0;
	while (i < size)
	{
		min = NULL;
		curr = stack;
		while (curr)
		{
			if (curr->index == -1 && (!min || curr->value < min->value))
				min = curr;
			curr = curr->next;
		}
		if (min)
			min->index = i++;
		else
			break ;
	}
}

int	is_sorted(t_node *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->index > stack_a->next->index)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	has_duplicate(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	min_index_pos(t_node *stack_a)
{
	t_node	*curr;
	t_node	*min;
	int		i;
	int		pos;

	if (!stack_a)
		return (-1);
	i = 0;
	pos = 0;
	curr = stack_a;
	min = stack_a;
	while (curr)
	{
		if (curr->index < min->index)
		{
			min = curr;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}
