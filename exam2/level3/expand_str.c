#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	return (0);
}	

int	main(int ac, char *av[])
{
	char	*str;
	int	word;

	word = 0;
	if (ac == 2)
	{
		str = av[1];
		while (*str)
		{
			while (ft_isspace(*str))
				str++;
			if (*str)
			{
				if (word)
					write(1, "   ", 3);
				word = 1;
				while (*str && !ft_isspace(*str))
					write(1, str++, 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
