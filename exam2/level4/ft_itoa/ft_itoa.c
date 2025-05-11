#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_count_int(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int	len;
	long	nb;

	nb = nbr;
	len = ft_count_int(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if  (!str)
		return NULL;
	str[len] = '\0';
	len -= 1;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len >= 0 && str[len] != '-')
	{
		str[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

int	main(void)
{
	char	*str;

	str = ft_itoa(12345);
	if (!str)
		return (0);
	printf("result: %s\n", str);
	free(str);
	return (0);
}
