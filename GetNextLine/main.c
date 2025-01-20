/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:31:00 by foogungb          #+#    #+#             */
/*   Updated: 2025/01/17 20:51:37 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "string.h"
#include "stdio.h"

void	test_case00(void);
void	test_case0(void);
void	test_case1(void);
void	test_case2(void);
void	test_case3(void);
void	test_case4(void);
void	test_case5(void);
void	test_case6(void);
void	test_case7(void);
void	test_case8(void);
void	test_case9(void);
void	test_case10(void);
void	test_case11(void);

int	main(void)
{
	test_case00();
	//test_case0();
	//test_case1();
	//test_case2();
	//test_case3();
	//test_case4();
	//test_case5();
	//test_case6();
	//test_case7();
	//test_case8();
	//test_case9();
	//test_case10();
	//test_case11();
	return (0);
}

void	test_case00(void)
{
	int		fd;
	char	*str;
	char	*nl;
	size_t	counter;

	printf("\n---------------------------------\n");
	puts("### TESTCASE 00 ###");
	puts("Read from stdin.");
	counter = 0;
	fd = 0;
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", ++counter, str);
		printf("\nwake ..\n");
		nl = strchr(str, '\n');
		if (nl)
			printf("\n Nline True:[%ld] [%s]\n", counter, nl);
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
}

void	test_case0(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/non_existing.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 0 ###");
	puts("Read from a nonexisting file.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
}

void	test_case1(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/file.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 1 ###");
	puts("Read from a normal/valid file.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case2(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/multiple_nl.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 2 ###");
	puts("Read from a file with only multiple newlines.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case3(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/index.html";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 3 ###");
	puts("Read from an HTML file");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case4(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/style.css";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 4 ###");
	puts("Read from a css file.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case5(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/no_access.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 2 ###");
	puts("Read from a file with all access stripped.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case6(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/multiple_nl_and_text.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 6 ###");
	puts("Read from a file with multiple nl and texts.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case7(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/short_lines.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 7 ###");
	puts("Read from a txt file with short lines.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case8(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/longer_and_shorter_lines.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 8 ###");
	puts("Read from a file with longer and shorter lines.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}


void	test_case9(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/single_long_line.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 9 ###");
	puts("Read from a single long line text file.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}

void	test_case10(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/empty.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 10 ###");
	puts("Read from an empty file.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}

void	test_case11(void)
{
	int		fd;
	char	*filename;
	char	*str;
	size_t	counter;

	filename = "./test_files/only_nl.txt";
	printf("\n---------------------------------\n");
	puts("### TESTCASE 11 ###");
	puts("Read from a file with only newline.");
	printf("filename\t->\t'%s'\n", filename);
	counter = 0;
	fd = open(filename, O_RDONLY);
	printf("fd\t->\t'%d'\n", fd);
	printf("---------------------------------\n");
	if (fd < 0)
	{
		printf("Unable to read file!\n");
		return ;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n[%ld] [%s]\n", counter++, str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return ;
}
