/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:24:55 by nmoreira          #+#    #+#             */
/*   Updated: 2025/07/19 13:24:55 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	// int i;

	
	if (argc != 2)
	{
		printf("Não existe ficheiro.\n");
		return (0);
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Não se consegue ler o ficheiro\n");
		return (0);
	}
	// i = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		// printf("Linha %d: %s", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
