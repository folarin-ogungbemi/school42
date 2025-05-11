#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == *reject)
			return (i);
		i++;
	}
	return (i);
}

int	main(int ac, char *av[])
{
	if (ac == 3)
		printf("result: %ld\n", ft_strcspn(av[1], av[2]));
	return (0);
}
