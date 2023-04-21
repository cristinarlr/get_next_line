/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:57:14 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/21 13:18:58 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_stash_clean_for_next_GNL(char *stash)
{
    char *rest_stash;
    int i;
    
    rest_stash = ft_strchr(stash, '\n') + 1;
    i = ft_strlen(rest_stash);
    return(rest_stash);   
}

char *ft_extract_line_from_stash(char *stash)
{
    char *line;
    char *rest_stash;
    int len;
    
    rest_stash = ft_strchr(stash, '\n') + 1;
    len = ft_strlen(stash) - ft_strlen(rest_stash) + 1;
    line = (char *)malloc((len + 1) * sizeof(char));
    if (!line)
        return (0);
    ft_strlcpy(line, stash, len);
    return(line);  
}

static char *ft_read_and_stock_in_buff(int fd)
{
    char    *buff;
    ssize_t nbytes;

    buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (0);
    nbytes = read(fd, buff, BUFFER_SIZE);
    if (nbytes == -1)
    {
        printf("Error reading file");
        return(0);
    }
    buff[nbytes] = '\0';
    return (buff);
}

static char *ft_read_and_stock_in_stash(int fd)
{
    char    *buff;
    char    *line;
    static char *stash;
    ssize_t nbytes;
    
   /*  buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (0);
    nbytes = read(fd, buff, BUFFER_SIZE);
    if (nbytes == -1)
    {
        printf("Error reading file");
        return(0);
    }
    buff[nbytes] = '\0'; */
    buff = ft_read_and_stock_in_buff(fd);
    printf("buff = %s\n", buff);
    stash = (char *)malloc((BUFFER_SIZE) * sizeof(char));
    if (!stash)
        return (0);
    ft_strlcpy(stash, buff, BUFFER_SIZE + 1);
    if (ft_strchr(stash, '\n'))
    {
        line = ft_extract_line_from_stash(stash);
        stash = ft_stash_clean_for_next_GNL(stash);
        printf("stash = %s\n", stash);
        return (line);
    }
    printf("stash = %s\n", stash);
    while((nbytes = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        if (nbytes == -1)
        {
            printf("Error reading file");
            return(0);
        }
        stash = ft_strjoin(stash, buff);
        if (ft_strchr(stash, '\n'))
            {
                line = ft_extract_line_from_stash(stash);
                stash = ft_stash_clean_for_next_GNL(stash);
                return (line);
            }
    }
    return(stash);
}

char *get_next_line(int fd)
{
   char *line;

    line = ft_read_and_stock_in_stash(fd);
    return (line);
}

/* int main()
{
    int fd;
    char *line;

    fd = open("15char", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd))) // mientras haya líneas para leer
    {
        printf("dentro del while\n");
        printf("%s\n", line); // imprime la línea leída
        free(line); // libera la memoria reservada por la función get_next_line
    }
    close(fd); // cierra el archivo
    return (0);
} */


int main()
{
    int fd;
    char *line;

    fd = open("15char", O_RDONLY);
    if (fd == -1)
    {
     printf("Error opening file");
     exit(1);
    }
    line = get_next_line(fd);
    printf("%s", line);
    close (fd);
    return (0);
}


   /*  
   TESTS PARA PRINTEAR CADA CARACTER
   printf("Result = %s\n", result);
    printf("Result = %c\n", result[0]);
    printf("Result = %c\n", result[1]);
    printf("Result = %c\n", result[2]);
        result[2] = 0;
    printf("Result = %c\n", result[2]);
    printf("Result = %c\n", result[3]);
    printf("Result = %c\n", result[4]);
    printf("Result = %c\n\n", result[5]);
    printf("Result = %c\n", result[BUFFER_SIZE - 5]);
    printf("Result = %c\n", result[BUFFER_SIZE - 4]);
    printf("Result = %c\n", result[BUFFER_SIZE - 3]);
    printf("Result = %c\n", result[BUFFER_SIZE - 2]);
    printf("Result = %c\n", result[BUFFER_SIZE - 1]);
    printf("Result = %c\n", result[BUFFER_SIZE]);
    printf("Result = %c\n", result[BUFFER_SIZE + 1]);
    printf("Result = %c\n", result[BUFFER_SIZE + 2]);
    if(result[BUFFER_SIZE] == 0)
        {
        printf("El valor result[BUFFER_SIZE] es nulo.\n");
        } 
    else if (result[BUFFER_SIZE] == ' ')
        {
        printf("El valor result[BUFFER_SIZE] es un espacio.\n");
        }
    else 
    {
        printf("El valor result[BUFFER_SIZE] es %c.\n", result[BUFFER_SIZE]);
    }
    if(result[5] == 0)
        {
        printf("El valor result[5] es nulo.\n");
        } 
    else if (result[5] == ' ')
        {
        printf("El valor result[5] es un espacio.\n");
        }
    else 
    {
        printf("El valor result[5] es %c.\n", result[5]);
    } */