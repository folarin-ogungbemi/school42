#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int	len;

	if (argc == 2)
	{
		str = argv[1];
		len = ft_strlen(str) - 1;
		while (0 <= len)
		{
			write(1, &str[len], 1);
			len--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
