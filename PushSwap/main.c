#include "push_swap.h"

static int	str_is_digit(const char *str)
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

static int	validate(const char *str)
{
	long	val;

	if (!str_is_digit(str))
		exit_error();
	val = ft_atol(str);
	return ((int)val);
}

int	main(int ac, char *av[])
{
	int		i;
	int		val;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			val = validate(av[i]);
			append_node(&stack_a, create_node(val));
			i++;
		}
		if (has_duplicate(stack_a))
			exit_error();
		sort_by_stack(&stack_a, &stack_b);
		free_stack(stack_a);
	}
	else
		write(1, "\n", 1);
	return (0);
}
