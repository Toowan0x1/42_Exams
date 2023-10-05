/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:31:40 by oel-houm          #+#    #+#             */
/*   Updated: 2023/09/06 04:20:44 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// desktop 
# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd)
{
    int i = 0;
    int rd = 0;
    char character;

    if (BUFFER_SIZE <= 0)
        return (NULL);
    char *buffer = malloc(100000); // check before the current BUFFER_SIZE and then malloc
    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    buffer[i] = '\0';
    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), NULL);
    return (buffer);
}

/*
char    *get_next_line(int fd)
{
    int     i;
    int     rd;
    char    character;

    i = 0;
    rd = 0;
    if (BUFFER_SIZE <= 0)
        return (NULL);
    char *buffer = malloc(10000);
    if (!buffer)
        return (NULL);
    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    buffer[i] = '\0';
    if (rd == -1 || i == 0 || (!buffer[i -1] && !rd))
        return (free(buffer), NULL);
    return (buffer);
}

*/
