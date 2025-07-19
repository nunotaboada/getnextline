/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:25:07 by nmoreira          #+#    #+#             */
/*   Updated: 2025/07/19 13:42:28 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int *fds;
    char *line;
    int i;
    int files_read;
    int num_files;

    if (argc < 2)
    {
        printf("Não existem ficheiros.\n");
        return (0);
    }
	
    num_files = argc - 1;
    fds = malloc(sizeof(int) * num_files);
	
    if (!fds)
        return (1);
    i = 0;
	
    while (i < num_files)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        if (fds[i] == -1)
            printf("Erro ao abrir o ficheiro %s.\n", argv[i + 1]);
        i++;
    }
	
    files_read = 0;
	
    while (files_read < num_files)
    {
        files_read = 0;
        i = 0;
        while (i < num_files)
        {
            if (fds[i] != -1)
            {
                line = get_next_line(fds[i]);
                if (line)
                {
                    printf("[Arquivo %s]: %s", argv[i + 1], line);
                    free(line);
                }
                else
                {
                    close(fds[i]);
                    fds[i] = -1;
                    files_read++;
                }
            }
            else
                files_read++;
            i++;
        }
    }
    free(fds);
    return (0);
}