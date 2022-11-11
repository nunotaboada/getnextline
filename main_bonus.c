/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:00:19 by nmoreira          #+#    #+#             */
/*   Updated: 2022/10/09 13:00:19 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
    int i;
	int	fd;
	char	*line;

	
	if (argc < 2)
	{
		printf("Pas de fichier a lire.\n");
		return (0);
	}
    i = 1;
	while (i < argc )
    {
	    fd = open(argv[i], O_RDONLY);
	    if (fd == -1)
	    {
		    printf("Fichier impossible a lire.\n");
		    return (0);
	    }
	    line = "";
		line = get_next_line(fd);
        if (line == NULL)
            // printf("%s", "");^
            break;
        else    
		    printf("%s", line);
        i++;
	return (0);

}
