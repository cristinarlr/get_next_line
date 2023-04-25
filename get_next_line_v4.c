/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:47:07 by crramire          #+#    #+#             */
/*   Updated: 2023/04/25 11:37:42 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_clean_stash(char *stash)
{
    char *rest_stash;
    
    rest_stash = ft_strdup(ft_strchr(stash, '\n') + 1);
    free(stash);
    
    return(rest_stash);
    //return(rest_stash);      
}

char *ft_extract_line(char *stash)
{
    char *line;
    char *aux;
    int len;
    
    if(!stash)
        return (0);
    if(!ft_strchr(stash, '\n'))
    {
        return (stash);
    }
    aux = ft_strchr(stash, '\n') + 1;
    len = ft_strlen(stash) - ft_strlen(aux) + 1;
    line = (char *)malloc((len + 1) * sizeof(char));
    if (!line)
        return (0);
    ft_strlcpy(line, stash, len);
    return(line);  
}

static void ft_fill_with_zero(char *buffer)
{
    size_t  count;
    
    count = 0;
    while (count <= BUFFER_SIZE)
    {
        buffer[count] = '\0';
        count++;
    }
    
}

char *get_next_line(int fd)
{
    char        *buff;
    char        *line;
    static char *stash;
    ssize_t      nbytes;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
    buff = (char *)malloc((BUFFER_SIZE + 1)*sizeof(char));
    if (!buff)
        return (NULL);
    buff[BUFFER_SIZE + 1] = '\0';
    if (!stash)
    {
        stash = strdup(buff);
        if (!stash)
            return (NULL);
    }
    ft_fill_with_zero(buff);
    while((nbytes = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        stash = ft_strjoin(stash, buff);
        ft_fill_with_zero(buff);
        if(strchr(stash, '\n'))
        {
            line = ft_extract_line(stash);
            stash = ft_clean_stash(stash);
            return (line);
        }
        if (nbytes < BUFFER_SIZE)
        {
            line = stash;
            break;
        }
    }
    if ((nbytes >= 0 && nbytes < BUFFER_SIZE) && stash)
        return(stash);
    return (NULL);
}

int main()
{
    int fd;
    char *line;

    fd = open("f_15char", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("************%s\n---------------------\n", line);
     //   printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}