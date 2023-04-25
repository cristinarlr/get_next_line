/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:01:46 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/25 11:39:55 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_clean_stash(char *stash)
{
    char *rest_stash;

    if(!ft_strchr(stash, '\n'))
    {
        return (0);
    }
    rest_stash = ft_strdup(stash);
    rest_stash = ft_strchr(stash, '\n') + 1;
    return(rest_stash);      
}

char *ft_extract_line(char *stash)
{
    char *line;
    char *aux;
    int len;
    
    if(!stash)
        return (0);
    if(!ft_strchr(stash, '\n'))
        return (stash);
    aux = ft_strchr(stash, '\n') + 1;
    len = ft_strlen(stash) - ft_strlen(aux) + 1;
    line = (char *)malloc((len + 1) * sizeof(char));
    if (!line)
        return (0);
    ft_strlcpy(line, stash, len);
    return(line);  
}

char *ft_get_full_line (int fd, char *stash) 
{
    int     nbytes;
	char    *buff;
	
    nbytes = 1;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff)
        return(0);
	while(nbytes == BUFFER_SIZE || nbytes == 1)
	{
        nbytes = read(fd, buff, BUFFER_SIZE);
        if (nbytes == -1 || ((nbytes == 0) && ft_strlen(stash) == 0))
         {
            free (buff);
            return (0);
         }
        buff[nbytes] = '\0';
        stash = ft_strjoin(stash, buff);
        if (nbytes == -1 || ((nbytes == 0) && ft_strlen(stash) == 0))
        {
            free (buff);
            return (stash);
        }
        if (ft_strchr(stash, '\n') || nbytes == 0)
        {
            free (buff);
            return (stash);
        }
	}
    free (buff);
    return (0);
} 

char *get_next_line(int fd)
{
    char *line;
    static char *stash = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
    if(!stash)
        stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!stash)
            return (0);
    stash = ft_get_full_line(fd, stash);
    if (stash == NULL)
        return (NULL);
    line = ft_extract_line(stash);
    if (line == NULL)
        return (NULL);
    stash = ft_clean_stash(stash);
    if (stash == NULL)
        return (NULL);
    return (line);
} 

int main()
{
    int fd;
    char *line;

    fd = open("f_bigline", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}