#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == 32 ||  c >= 7 && c <= 13)
		return (1);
	return (0);
}

int	ft_count_word(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			counter++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (counter);
}

char	*copy_word(char *str)
{
	int	i;
	char	*start;
	char	*word;

	i = 0;
	while (ft_isspace(*str))
		str++;
	start = str;
	while (*str && !ft_isspace(*str))
		str++;
	word = (char *)malloc(sizeof(char) * (str - start + 1));
	if (!word)
		return (NULL);
	while (i < (str - start))
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*free_split(int *i, char **split)
{
	int	j;

	j = 0;
	if (!split[*i])
	{
		while (j < *i)
		{
			free(split[j]);
			j++;
		}
		free(split);
		return (NULL);
	}
}
	
char	**ft_split(char *str)
{
	char	**split;
	int	word_count;
	int	i;

	i = 0;
	word_count = ft_count_word(str);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			split[i] = copy_word(str);
			free_split(&i, split);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	split[i] = NULL;
	return (split);
}

int	main(int ac, char *av[])
{
	int	i;
	char	**words;

	i = 0;
	if (ac == 2)
	{
		words = ft_split(av[1]);
		while (words[i])
		{
			printf("word[%d]: %s\n", i, words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	return 0;
}
