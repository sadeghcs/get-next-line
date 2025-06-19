/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snasiri <snasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:09 by makhudon          #+#    #+#             */
/*   Updated: 2025/06/16 13:04:26 by snasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>      // open
#include <stdio.h>      // printf, perror
#include <stdlib.h>     // free, exit
#include <unistd.h>     // close
#include "get_next_line.h"

void test_file(const char *filename)
{
	char	*line;
	int		fd;
	int		line_num = 1;

	printf("----- Testing: %s -----\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		return;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%02d] %s", line_num++, line);
		if (line[0] && line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
	close(fd);
	printf("----- End of %s -----\n\n", filename);
}

void test_invalid_fd()
{
	char *line;

	printf("----- Testing invalid FD -----\n");
	line = get_next_line(1);
	if (line == NULL)
		printf("get_next_line(-1) returned NULL as expected.\n");
	else
	{
		printf("Unexpected result: %s\n", line);
		free(line);
	}
	printf("----- End of invalid FD test -----\n\n");
}

int main()
{
	// test_invalid_fd();
	// test_file("test_files/empty.txt");
	// test_file("test_files/only_nl.txt");
	// test_file("test_files/no_nl.txt");
	// test_file("test_files/with_nl.txt");
	// test_file("test_files/multiple_lines.txt");
	// test_file("test_files/long_line.txt");
	// test_file("test_files/mixed.txt");
	// test_file("test_files/multiple_nl.txt");
	// test_file("test_files/pride_and_prejudice.txt"); 
    char *line;
    int fd = open("test_files/mixed.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		return (0);
	}
    for (int i = 0; i < 100; i++)
    {
        line = get_next_line(fd);
        printf("%s", line);
    }

	
	return (0);
}
