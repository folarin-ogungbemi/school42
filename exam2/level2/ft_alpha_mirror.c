#include <unistd.h>
#include <stdio.h>

void	ft_alpha_mirror(const char *str)
{
	char	x;

	while (*str)
	{
		if (*str >= 65 && *str <= 90)
			x = *str - ((*str - 65) * 2) + 25;
		else if (*str >= 97 && *str <= 122)
			x = *str - ((*str - 97) * 2) + 25;
		else
			x = *str;
		write(1, &x, 1);
		str++;
	}	
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		ft_alpha_mirror(str);
	}
	write(1, "\n", 1);
	return (0);
}
