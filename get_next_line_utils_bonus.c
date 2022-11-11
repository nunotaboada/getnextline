/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:17:32 by nmoreira          #+#    #+#             */
/*   Updated: 2022/10/09 12:17:32 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while (*str)
    {
        str++;
        i++;
    }
    return (i);
}

/*The strchr() function locates the first occurrence of c (converted to a
 *	char) in the string pointed to by s. The terminating null character is
 *	considered to be part of the string; therefore if c is `\0', the functions
 *	locate the terminating `\0'.
*/
char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

/*
* outra solução para ft_strchr
*
* char	*ft_strchr(const char *str, int c)
* {
*	if (!str)
*		return (NULL);
*	while (*str)
*	* and ++ operators have same precedence but right to left associativity. So * *   first ++ operator will be applied which is post-increment in this case therefore *   first a will be printed then str will point to character b
*		if (*str++ == (char)c)
*			return ((char *)(str - 1));
*	if (*str == (char)c)
*		return ((char *)str);
*	return (NULL);
*}
*/


 /*	DESCRIPTION
 *	The strdup() function allocates sufficient memory for a copy of the string
 *	s1, does the copy, and returns a pointer to it.
*/
char *ft_strdup(const char *str)
{
    int i = 0;
    char *res;

    while (str[i])
        i++;
    res = (char *)malloc(sizeof(char) * (i + 1));
    if (res == NULL)
        return NULL;
    i = 0;
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

/*	DESCRIPTION
 *	Allocates (with malloc(3)) and returns a new string, which is the result of
 *	the concatenation of ’s1’ and ’s2’.
 *	PARAMETERS
*/

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len = 0;
    size_t i = 0;
    size_t j = 0;
    char *str;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

/*
*	DESCRIPTION
*	Allocates (with malloc()) and returns a substring from the string ’s’.
*	The substring begins at index ’start’ and is of maximum size ’len’.
*	PARAMETERS
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int i; //usar os unsigned int está relacionado com os intervalos de representação
    unsigned int j;
    char *res;

    i = 0;
    j = 0;
    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
            return (ft_strdup("")); //temos que usar esta função porque temos que criar o resultado com malloc.
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    while (s[i])
    {
        if (i >= start && j < len )  // é < que len porque é uma string e começa em 0
        {
            res[j] = s[i];
            j++;
        }
        i++;
    }
    res[j] = '\0';    
    return (res);    
}