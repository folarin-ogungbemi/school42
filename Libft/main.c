/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:49 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/05 19:54:32 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 // FT_ISALPHA
int     test_ft_isalpha(char c)
{
        if (isalpha(c) > 0 && ft_isalpha(c) > 0)
                return (1);
        else if ((isalpha(c) > 0 && ft_isalpha(c) <= 0)
                || (isalpha(c) <= 0 && ft_isalpha(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;

        c = 0;
        while (c <= 127)
        {
                if (test_ft_isalpha(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}*/

/*
 // FT_ISDIGIT
int     test_ft_isdigit(char c)
{
        if (isdigit(c) > 0 && ft_isdigit(c) > 0)
                return (1);
        else if ((isdigit(c) > 0 && ft_isdigit(c) <= 0)
                || (isdigit(c) <= 0 && ft_isdigit(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;

        c = 0;
        while (c <= 127)
        {
                if (test_ft_isdigit(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}*/

/*
 // FT_ISALNUM
int     test_ft_isalnum(char c)
{
        if (isalnum(c) > 0 && ft_isalnum(c) > 0)
                return (1);
        else if ((isalnum(c) > 0 && ft_isalnum(c) <= 0)
                || (isalnum(c) <= 0 && ft_isalnum(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;

        c = 0;
        while (c <= 127)
        {
                if (test_ft_isalnum(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}*/

/*
 // FT_ISASCII
int     test_ft_isascii(char c)
{
        if (isascii(c) > 0 && ft_isascii(c) > 0)
                return (1);
        else if ((isascii(c) > 0 && ft_isascii(c) <= 0)
                || (isascii(c) <= 0 && ft_isascii(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;

        c = 0;
        while (c <= 254)
        {
                if (test_ft_isascii(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}*/

/*
 // FT_ISPRINT
int     test_ft_isprint(char c)
{
        if (isprint(c) > 0 && ft_isprint(c) > 0)
                return (1);
        else if ((isprint(c) > 0 && ft_isprint(c) <= 0)
                || (isprint(c) <= 0 && ft_isprint(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;

        c = 0;
        while (c <= 254)
        {
                if (test_ft_isprint(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}*/

/*
// FT_STRLEN
#include <stdio.h>
#include <string.h>
static int     test_ft_strlen(char *s)
{
	if (!s)
		return (-1);
        if (strlen(s) == ft_strlen(s))
		return (1);
	return (-1);
}

int     main(void)
{
        char   *str[] = {"  -12", "memory", "", "\0", "+", NULL};
	size_t	i;

	i = 0;
        while (str[i])
        {
                if (test_ft_strlen(str[i]) == -1)
                {
                        write(1, "One function disagree: ", 24);
                        write(1, str[i], ft_strlen(str[i]));
                        write(1, "\n", 1);
                        return (1);
                }
                i++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/

/*
// FT_MEMSET
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int	test_ft_memset(char *s, int c, size_t n)
{
	char *memset_copy = strdup(s);
	char *ft_memset_copy = strdup(s);

	memset(memset_copy, c, n);
	ft_memset(ft_memset_copy, c, n);
	if (memcmp(memset_copy, ft_memset_copy, n) == 0)
	{
		free(memset_copy);
		free(ft_memset_copy);
		return (1);
	}
	free(memset_copy);
	free(ft_memset_copy);
	return (-1);
}

int	main(void)
{
	char	*str[] = {"   -12", "memory", "", "\0", "+", NULL};
	size_t i = 0;

	while (str[i])
	{
		int result = test_ft_memset(str[i], 0, sizeof(str[i]));
		if (result == -1)
		{
			write(1, "One function disagrees: ", 24);
			write(1, str[i], ft_strlen(str[i]));
			write(1, "\n", 1);
			return (1);
		}
		i++;
	}
	write(1, "Both functions agree", 20);
	write(1, "\n", 1);
	return (0);
}
*/

/*
// FT_BZERO
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int      test_ft_bzero(char *s, size_t n)
{
        char *bzero_copy = strdup(s);
        char *ft_bzero_copy = strdup(s);

        bzero(bzero_copy, n);
        ft_bzero(ft_bzero_copy, n);
        if (memcmp(bzero_copy, ft_bzero_copy, n) == 0)
        {
                free(bzero_copy);
                free(ft_bzero_copy);
                return (1);
        }
        free(bzero_copy);
        free(ft_bzero_copy);
        return (-1);
}

int     main(void)
{
        char    *str[] = {"   -12", "memory", "", "\0", "+", NULL};
        size_t i = 0;

        while (str[i])
        {
                int result = test_ft_bzero(str[i], sizeof(str[i]));
                if (result == -1)
                {
                        write(1, "One function disagrees: ", 24);
                        write(1, str[i], ft_strlen(str[i]));
                        write(1, "\n", 1);
                        return (1);
                }
                i++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/

/*
// FT_MEMCPY
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int      test_ft_memcpy(char *d, char *s, size_t n)
{
        char *memcpy_copy = strdup(d);
        char *ft_memcpy_copy = strdup(d);

        memcpy(memcpy_copy, s, n);
        ft_memcpy(ft_memcpy_copy, s, n);
        if (memcmp(memcpy_copy, ft_memcpy_copy, n) == 0)
        {
                free(memcpy_copy);
                free(ft_memcpy_copy);
                return (1);
        }
        free(memcpy_copy);
        free(ft_memcpy_copy);
        return (-1);
}

int     main(void)
{
        char    *dst[] = {"hello, ", "test, ", "", "\0", "+", NULL};
        char    *src[] = {"world!", "memory", "", "\0", "+", NULL};
        size_t i = 0;

        while (src[i])
        {
		char *dst_copy = strdup(dst[i]);
        	if (!dst_copy)
		{
            		write(1, "Memory allocation failed for dst\n", 32);
            		return 1;
        	}
                int result = test_ft_memcpy(dst_copy, src[i], ft_strlen(src[i]));
                if (result == -1)
                {
                        write(1, "One function disagrees: ", 24);
                        write(1, src[i], ft_strlen(src[i]));
                        write(1, "\n", 1);
			free(dst_copy);
                        return (1);
                }
		else
		{
			printf("dest before: %s\n", dst_copy);
        		ft_memcpy(dst_copy, src[i], sizeof(dst[i]));
        		printf("dest after: %s\n", dst_copy);
		}
		free (dst_copy);
                i++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/

/*
// FT_MEMMOVE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int      test_ft_memmove(char *d, char *s, size_t n)
{
        char *memmove_copy = strdup(d);
        char *ft_memmove_copy = strdup(d);

        memmove(memmove_copy, s, n);
        ft_memmove(ft_memmove_copy, s, n);
        if (memcmp(memmove_copy, ft_memmove_copy, n) == 0)
        {
                free(memmove_copy);
                free(ft_memmove_copy);
                return (1);
        }
        free(memmove_copy);
        free(ft_memmove_copy);
        return (-1);
}

int     main(void)
{
        char    *dst[] = {"hello, ", "test, ", "", "wonderful", "+", NULL};
        char    *src[] = {"world!", "memory", "", "world!", "+", NULL};
        size_t i = 0;

        while (src[i])
        {
                char *dst_copy = strdup(dst[i]);
                if (!dst_copy)
                {
                        write(1, "Memory allocation failed for dst\n", 32);
                        return 1;
                }
                int result = test_ft_memmove(dst_copy, src[i], ft_strlen(src[i]));
                if (result == -1)
                {
                        write(1, "One function disagrees: ", 24);
                        write(1, src[i], ft_strlen(src[i]));
                        write(1, "\n", 1);
                        free(dst_copy);
                        return (1);
                }
                else
                {
                        printf("dest before: %s\n", dst_copy);
                        ft_memmove(dst_copy, src[i], sizeof(dst[i]));
                        printf("dest after: %s\n", dst_copy);
                }
                free (dst_copy);
                i++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);                                                                                     }
*/

/*
// FT_STRLCPY
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int      test_ft_strlcpy(char *d, char *s, size_t n)
{
        char *strlcpy_copy = strdup(d);
        char *ft_strlcpy_copy = strdup(d);

        strlcpy(strlcpy_copy, s, n);
        ft_strlcpy(ft_strlcpy_copy, s, n);
        if (memcmp(strlcpy_copy, ft_strlcpy_copy, n) == 0)
        {
                free(strlcpy_copy);
                free(ft_strlcpy_copy);
                return (1);
        }
        free(strlcpy_copy);
        free(ft_strlcpy_copy);
        return (-1);
}

int     main(void)
{
        char    *dst[] = {"hello, ", "test, ", "", "\0", "+", NULL};
        char    *src[] = {"world!", "memory", "", "\0", "+", NULL};
        size_t i = 0;

        while (src[i])
        {
                char *dst_copy = strdup(dst[i]);
                if (!dst_copy)
                {
                        write(1, "Memory allocation failed for dst\n", 32);
                        return 1;
                }
                int result = test_ft_strlcpy(dst_copy, src[i], ft_strlen(src[i]));
                if (result == -1)
                {
                        write(1, "One function disagrees: ", 24);
                        write(1, src[i], ft_strlen(src[i]));
                        write(1, "\n", 1);
                        free(dst_copy);
                        return (1);
                }
                else
                {
                        printf("dest before: %s\n", dst_copy);
                        ft_strlcpy(dst_copy, src[i], sizeof(dst[i]));
                        printf("dest after: %s\n", dst_copy);
                }
                free (dst_copy);
                i++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/

/*
 // FT_STRLCPY
int     main(void)
{
        char    dst[2] = {'\0'};
        char    src[10] = "memory!";

        printf("custom: %ld\n", ft_strlcpy(dst, src, sizeof(dst)));
        printf("dst size: %ld\n", sizeof(dst));
        printf("dst len: %ld\n", ft_strlen(dst));
        printf("result: %s\n", dst);
        //printf("library: %ld\n", strlcpy(dst, src, sizeof(dst)));
        return (0);
}*/

/*
 // FT_STRLCAT
int     main(void)
{
        char    dst[7] = "hello, ";
        char    src[10] = "memory!";

        printf("custom: %ld\n", ft_strlcat(dst, src, sizeof(dst)));
        printf("dest: %s\n", dst);
        return (0);
}
*/

/*
 // FT_TOUPPER
#include <unistd.h>

int     test_ft_toupper(char c)
{
        if (toupper(c) > 0 && ft_toupper(c) > 0)
                return (1);
        else if ((toupper(c) > 0 && ft_toupper(c) <= 0)
                || (toupper(c) <= 0 && ft_toupper(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;
        
	c = 0;
        while (c <= 127)
        {
                if (test_ft_toupper(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/

/*
// FT_TOLOWER
#include <unistd.h>
int     test_ft_tolower(char c)
{
        if (tolower(c) > 0 && ft_tolower(c) > 0)
                return (1);
        else if ((tolower(c) > 0 && ft_tolower(c) <= 0)
                || (tolower(c) <= 0 && ft_tolower(c) > 0))
                return (-1);
        return (0);
}

int     main(void)
{
        unsigned char   c;

        c = 0;
        while (c <= 127)
        {
                if (test_ft_tolower(c) == -1)
                {
                        write(1, "One function disagree on char: ", 31);
                        write(1, &c, 1);
                        write(1, "\n", 1);
                        return (1);
                }
                c++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/
/*
// FT_STRCHR
#include <stdio.h>
#include <string.h>
int     test_ft_strchr(const char *str)
{
        char    test[13] = "atestzingb!!";
        char    *ptr;

        ptr = test;
        while (*ptr)
        {
                if (ft_strchr(str, *ptr) != strchr(str, *ptr))
                {
                        printf("result: %s\n", ft_strchr(str, *ptr));
                        return (0);
                }
                printf("------------------------------\n");
                printf("result: %s\n", ft_strchr(str, *ptr));
                ptr++;
        }
        return (1);
}

int     main(void)
{
        char    str[10] = "testing!!";

        if (test_ft_strchr(str))
                printf("\nResults are Equal\n\n");
        else
                printf("\nresults are not equal\n\n");
        printf("custom: %s\n", ft_strchr(str, '\0'));
        printf("library: %s\n", strchr(str, '\0'));
        return (0);
}
*/

/*
// FT_STRRCHR
#include <stdio.h>
#include <string.h>
int     test_ft_strrchr(const char *str)
{
        char    test[13] = "atestzingb!!";
        char    *ptr;

        ptr = test;
        while (*ptr)
        {
                if (ft_strrchr(str, *ptr) != strrchr(str, *ptr))
                {
                        printf("result: %s\n", ft_strrchr(str, *ptr));
                        return (0);
                }
                printf("------------------------------\n");
                printf("cust: %s\n", ft_strrchr(str, *ptr));
                printf("libr: %s\n", strrchr(str, *ptr));
                ptr++;
        }
        return (1);
}

int     main(void)
{
        char    str[10] = "testing!!";

        if (test_ft_strrchr(str))
                printf("\nResults are Equal\n\n");
        else
                printf("\nresults are not equal\n\n");
        printf("custom test (null): %s\n", ft_strrchr(str, '\0'));
        printf("librar test (null): %s\n", strrchr(str, '\0'));
        return (0);
}
*/
/*
// FT_STRNCMP
#include <string.h>
#include <stdio.h>
int     test_ft_strncmp(const char *s1, const char *s2)
{
        if (ft_strncmp(s1, s2, 3) != strncmp(s1, s2, 3))
        {
                printf("result custom: %d\n", ft_strncmp(s1, s2, 3));
                printf("result lib: %d\n", strncmp(s1, s2, 3));
                return (0);
        }
        printf("\n------------------------------------\n");
        printf("result custom: %d\n", ft_strncmp(s1, s2, 3));
        printf("result lib: %d\n", ft_strncmp(s1, s2, 3));
        printf("------------------------------------\n");
        return (1);
}

int     main(void)
{
        char    s1[10] = "abcdef!";
        char    s2[10] = "ab";

        if (test_ft_strncmp(s1, s2))
                printf("\nResults are equal\n\n");
        else
                printf("\nResults are not equal\n\n");
        return (0);
}
*/

/*
// FT_MEMCHR
#include <string.h>
#include <stdio.h>
int     test_ft_memchr(const char *str)
{
        char    test[13] = "atestzingb!!";
        char    *ptr;

        ptr = test;
        while (*ptr)
        {
                if (ft_memchr(str, *ptr, 15) != memchr(str, *ptr, 15))
                {

                        printf("\n------------------------------\n");
                        printf("Fcus: %s\n", (char *)ft_memchr(str, *ptr, 15));
                        printf("Flib: %s\n",(char *)memchr(str, *ptr, 15));
                        printf("------------------------------\n");
                        return (0);
                }
                printf("\n------------------------------\n");
                printf("Tcus: %s\n", (char *)ft_memchr(str, *ptr, 15));
                printf("Tlib: %s\n",(char *)memchr(str, *ptr, 15));
                printf("------------------------------\n");
                ptr++;
        }
        return (1);
}

int     main(void)
{
        char    str[10] = "testing!!";

        if (test_ft_memchr(str))
                printf("\nResults are Equal\n\n");
        else
                printf("\nresults are not equal\n\n");
        //printf("library: %s\n", memchr(str, '\0'));
        //printf("custom: %s\n", ft_memchr(str, '\0'));
        return (0);
}
*/

/*
// FT_MEMCMP
#include <string.h>
#include <stdio.h>
int     test_ft_memcmp(const char *s1, const char *s2)
{
        if (ft_memcmp(s1, s2, 3) != memcmp(s1, s2, 3))
        {
                printf("result custom: %d\n", ft_memcmp(s1, s2, 3));
                printf("result lib: %d\n", memcmp(s1, s2, 3));
                return (0);
        }
        printf("\n------------------------------------\n");
        printf("result custom: %d\n", ft_memcmp(s1, s2, 3));
        printf("result lib: %d\n", ft_memcmp(s1, s2, 3));
        printf("------------------------------------\n");
        return (1);
}

int     main(void)
{
        char    s1[10] = "abcdef!";
        char    s2[10] = "abd";

        if (test_ft_memcmp(s1, s2))
                printf("\nResults are equal\n\n");
        else
                printf("\nResults are not equal\n\n");
        return (0);
}
*/

/*
// FT_STRNSTRN
#include <string.h>
#include <stdio.h>
int     main(void)
{
        const char *largestring = "Foo Bar Baz";
        const char *smallstring = "Bar";
        char    *cptr;
        //char  *lptr;

        cptr = ft_strnstr(largestring, smallstring, 7);
        //lptr = strnstr(largestring, smallstring, 4);
        printf("custom: %s\n", cptr);
        //printf("library: %s\n", cptr);
        return (0);
}
*/

/*
// FT_ATOI
#include <stdio.h>
#include <stdlib.h>
static int     test_ft_atoi(char *s)
{
	if (!s)
		return (-1);
        if (atoi(s) == ft_atoi(s))
		return (1);
	return (-1);
}

int     main(void)
{
        char   *str[] = {"  -12", "-0", "invalid", "0123456789", "+1", NULL};
	size_t	i;

	i = 0;
        while (str[i])
        {
                if (test_ft_atoi(str[i]) == -1)
                {
                        write(1, "One function disagree: ", 24);
                        write(1, str[i], ft_strlen(str[i]));
                        write(1, "\n", 1);
                        return (1);
                }
                i++;
        }
        write(1, "Both functions agree", 20);
        write(1, "\n", 1);
        return (0);
}
*/

/*
// FT_CALLOC
#include <stdio.h>
#include <stdlib.h>
int     main(void)
{
        int     *arr;
        int     i;

        i = 0;
        arr = (int *)ft_calloc(5, sizeof(arr));
        if (!arr)
                return (1);
        while (i < 5)
        {
                printf("%d: %d\n", i, arr[i]);
                i++;
        }
        free(arr);
        return (0);
}*/

/*
// FT_STRDUP
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int     main(void)
{
        char    src[9] = "folarin!";
        char    *dest;

        dest = ft_strdup(src);
        printf("custom: %s\n", dest);
        printf("library: %s\n", strdup("folarin!"));
        free(dest);
        return (0);
}*/

/*
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int     main(void)
{
    char *result;

    result = ft_substr("Hello, World!", 7, 5);
    printf("Result 1: %s\n", result); // Expected: "World"
    free(result);

    result = ft_substr("Hello, World!", 0, 5);
    printf("Result 2: %s\n", result); // Expected: "Hello"
    free(result);

    result = ft_substr("Hello, World!", 15, 5);
    printf("Result 3: %s\n", result); // Expected: ""
    free(result);

    result = ft_substr(NULL, 0, 5);
    printf("Result 4: %s\n", result); // Expected: "(null)"
    free(result);

    return 0;
}*/

/*
// FT_STRJOIN
#include <stdlib.h>
#include <stdio.h>

int     main(void)
{
        char    s1[10] = "Hello, ";
        char    s2[10] = "World!";
        char    *result;

        result = ft_strjoin(s1, s2);
        printf("result: %s\n", result);
        free(result);
        return (0);
}*/
/*
// FT_STRTRIM
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int     main(void)
{
        char    s1[] = ",.:!<hello, world!>;:.";
        char    *set = "!,:;.";
        char    *trimmed = ft_strtrim(s1, set);

        if (trimmed != NULL)
        {
                printf("Trimmed string: '%s'\n", trimmed);
                free(trimmed);
        }
        else
                printf("Memory allocation failed or invalid input\n");
        return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int     main(void)
{
        char **result;
        int i = 0;

        result = ft_split("Hello,,flo,this,is,C,World,!", ',');
        if (result)
        {
                while (result[i])
                {
                        printf("result[%d]: %s\n", i, result[i]);
                        free(result[i]);
                        i++;
                }
                free(result);
                result = NULL;
        }
        return (0);
}
*/

/*
// FT_ITOA
int     main(void)
{
        int     x[] = {-0, 0, 12345, -12345, 789};
        char    *result;
        int     i;
        int     size = sizeof(x) / sizeof(x[0]);

        i = 0;
        while (i < size)
        {

                printf("result[%d] : %d\n", i, x[i]);
                result = ft_itoa(x[i]);
                if (result == NULL)
		{
			printf("Error for %d\n", x[i]);
                        return (1);
		}
                printf("result[%d] : %s\n", i, result);
                free(result);
                i++;
        }
        return (0);
}
*/

/*
//FT_STRMAPI
#include <stdio.h>
#include <stdlib.h>
char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c)
		return (ft_toupper(c));
	return (c);
}

int     main(void)
{
        char    s[10] = "testing!";
        char    *result;

        result = ft_strmapi(s, to_upper);
        if (!result)
                return (-1);
        printf("result: %s\n", result);
        free(result);
        return (0);
}
*/

/*
// FT_STRITERI
#include <stdio.h>
#include <stdlib.h>

void    to_uppercase(unsigned int index, char *ch)
{
	(void)index;
        if (ch && *ch)
                *ch = ft_toupper(*ch);
}

int     main(void)
{
        char    str[14] = "hello, world!!";

        ft_striteri(str, to_uppercase);
        printf("result: %s\n", str);
        return (0);
}*/

#include <unistd.h>
#include <fcntl.h>
/*
// FT_PUTCHAR_FD
int     main(void)
{
        int     fd;

        fd = open ("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
                return (1);
        ft_putchar_fd('C', fd);
        return (0);
}*/

/*
// FT_PUTSTR_FD
int     main(void)
{
        int     fd;
        char    s[10] = "andre";

        fd = open("str.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
                return (1);
        ft_putstr_fd(s, fd);
        close(fd);
        return (0);
}*/

/*
// FT_PUTENDL_FD
int     main(void)
{
        int     fd;
        char    s[10] = "folarin!";

        fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
                return (1);
        ft_putendl_fd(s, fd);
	close(fd);
        return (0);
}*/

/*
// FT_PUTNBR_FD
int     main(void)
{
        int     nbr;
        int     fd;

        nbr = -12;
        fd = open("int.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
                return (1);
        ft_putnbr_fd(nbr, fd);
        close(fd);
        return (0);
}*/
