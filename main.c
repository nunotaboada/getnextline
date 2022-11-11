/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:17:37 by nmoreira          #+#    #+#             */
/*   Updated: 2022/10/08 20:17:37 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
// #include <limits.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	
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
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
        if (line == NULL)
            printf("%s", "");
        else    
		    printf("%s", line);
	}
	return (0);
}
