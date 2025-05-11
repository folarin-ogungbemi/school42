#include <stdio.h>

static void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	char	*str;
	char	*src = "flo";


	printf("str[%s]\n", str); 	
	ft_memmove(str, src, 5);
	printf("result[%s]\n", str); 	
	return (0);
}

static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = dest;
	s = src;
	if (s > d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
