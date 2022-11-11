/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:12:31 by nmoreira          #+#    #+#             */
/*   Updated: 2022/10/08 16:12:31 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	GET_NEXT_LINE
 *	-------------
 *	DESCRIPTION
 *	This function takes an opened file descriptor and returns its next line.
 *	This function has undefined behavior when reading from a binary file.
 *	PARAMETERS
 *	#1. A file descriptor
 *	RETURN VALUES
 *	If successful, get_next_line returns a string with the full line ending in
 *	a line break (`\n`) when there is one.
 *	If an error occurs, or there's nothing more to read, it returns NULL.
 *	----------------------------------------------------------------------------
 *	AUXILIARY FUNCTIONS
 *	-------------------
 *	READ_TO_LEFT_STR
 *	-----------------
 *	DESCRIPTION
 *	Takes the opened file descriptor and saves on a "buff" variable what readed
 *	from it. Then joins it to the cumulative static variable for the persistence
 *	of the information.
 *	PARAMETERS
 *	#1. A file descriptor.
 *	#2. The pointer to the cumulative static variable from previous runs of
 *	get_next_line.
 *	RETURN VALUES
 *	The new static variable value with buffer joined for the persistence of the info,
 *	or NULL if error.
 */

#include "get_next_line.h"


// retorno a linha lida se tiver /n
static char *ft_read_line(int fd, char *buf, char *backup)
{
    int bytesread;
    char *tempbuf;

    bytesread = 1;
	while (bytesread != 0)
    {
    // read returns
    // return Number of bytes read on success
    // return 0 on reaching end of file
    // return -1 on error
    // return -1 on signal interrupt
    bytesread = read(fd, buf, BUFFER_SIZE);
    if (bytesread == -1)
        return (0); // ou será NULL
    if (bytesread == 0)
        break;
    buf[bytesread] = '\0'; //testar com printf se é bytesread ou bytesread -1
    if (!backup)
        backup = ft_strdup("");
    tempbuf = backup;
    backup = ft_strjoin(tempbuf, buf);
    free(tempbuf);
    tempbuf = NULL;
    if (ft_strchr(buf, '\n'))
        break;
    }
    return (backup);
}

//vai retornar o backup

static  char    *ft_get_line(char *line)
{
    size_t count;
    char *backup;

    count = 0;
    while(line[count] != '\n' && line[count])
        count++;
    if (line[count] == '\0')
        return (0);
    backup = ft_substr(line, count + 1, ft_strlen(line) - count); //count + 1 porque The returned line should include the ’\n’, só quando chega ao fim do ficheiro é que este não está incluído.
    if (*backup == '\0') //este ciclo verifica se as linha acabaram
    {
        free(backup);
        backup = NULL;
    }
    line[count + 1] = '\0';
    return (backup);
    
}

char *get_next_line(int fd)
{
    char *line;
    char *buf;
    static char *resto;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    // buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    buf = malloc(sizeof *buf * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    line = ft_read_line(fd, buf, resto);
    free(buf);
    buf = NULL;
    if(!line)
        return (NULL);
    resto = ft_get_line(line);
    return (line);
    
}

// Most of the responses have focused on preventing a double free, but setting the pointer to NULL has another benefit. Once you free a pointer, that memory is available to be reallocated by another call to malloc. If you still have the original pointer around you might end up with a bug where you attempt to use the pointer after free and corrupt some other variable, and then your program enters an unknown state and all kinds of bad things can happen (crash if you're lucky, data corruption if you're unlucky). If you had set the pointer to NULL after free, any attempt to read/write through that pointer later would result in a segfault, which is generally preferable to random memory corruption.


//para compilar gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c main.c -o a.exe

// ./a.exe longtext.txt | cat -e