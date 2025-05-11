#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(void)
{
	char	src[8] = "Folarin";
	char	dest[sizeof(src)];
	char	*result;

	result = ft_strcpy(dest, src);
	write(1, result, sizeof(src));
	write(1, "\n", 1);
	return (0);
}
