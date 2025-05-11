#include <unistd.h>

int	is_space(char *str)
{
	if (*str == 32 || *str == 9)
		return (1);
	return (0);
}

void	first_word(char *str)
{
	while (is_space(str))
		str++;
	while (!is_space(str) && *str)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*result;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	first_word(str);
	write(1, "\n", 1);
	return (0);
}
