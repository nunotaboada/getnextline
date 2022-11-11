/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:54:52 by nmoreira          #+#    #+#             */
/*   Updated: 2022/10/08 15:54:52 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* No BUFFER_SIZE? No Problem!
*
* So, what happens if we compile without defining a BUFFER_SIZE at all? This is a
* question that isn’t asked in the get_next_line subject, but it might be a good 
* idea to take a look at it, especially if we plan to use this function later on, in * other projects.
*
* We could decide to let the compiler grumble in that case. But we could also define * a small command to give the preprocessor a default value to use for the
*  BUFFER_SIZE. We can say 1, or 42, or 4000. But we could also use the BUFSIZ (no
* final E!) of the stdio.h library. Its value varies depending on the compiler
* (typically 1024 on MacOS, 8129 on Linux), but it is a defined constant:
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

// # if BUFFER_SIZE > 9223372036854775806
# if BUFFER_SIZE > 2147483646 // para lidar com o overflow do malloc no get_next_line
#  undef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

/* utils*/
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char *ft_strdup(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char *get_next_line(int fd);

# endif
