#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == 9 || c == 32)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	copy_word(char *str, int *i, int *y, int *j)
{	
	while (ft_isspace(str[*i]))
		(*i)++;
	*y = *i;
	while (str[*i] && !ft_isspace(str[*i]))
	{
		(*i)++;
		(*j)++;
	}
}

char	*rostring(char *str)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*ros;

	i = 0;
	j = 0;
	x = 0;
	ros = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ros)
		return (NULL);
	copy_word(str, &i, &y, &j);
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		while (str[i] && !ft_isspace(str[i]))
			ros[x++] = str[i++];
		ros[x] = 32;
		x++;
	}
	i = j + y;
	while (str[y] && y < i)
		ros[x++] = str[y++];
	ros[x] = '\0';
	return (ros);
}

int	main(int ac, char *av[])
{
	char	*str;
	char	*out;

	if (ac == 2)
	{
		str = av[1];
		out = rostring(str);
		if (!out)
			return (1);
		while (*out)
			write(1, out++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
