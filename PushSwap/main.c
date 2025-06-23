#include "push_swap.h"

int	str_is_digit(char *str)
{
	if (!*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac > 1)
	{
		i = 1;
		stack_a = NULL;
		stack_b = NULL;
		while (i < ac)
		{
			if (!str_is_digit(av[i]))
				return (write(1, "Error\n", 6), 1);
			append_node(&stack_a, create_node(ft_atoi(av[i])));
			i++;
		}
		print_stack(stack_a, "Stack A");
		sort_by_stack(&stack_a, &stack_b);
		print_stack(stack_a, "Stack A");
		free_stack(stack_a);
	}
	else
		write(1, "\n", 1);
	return (0);
}
