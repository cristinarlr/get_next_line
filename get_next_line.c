/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:57:14 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/19 12:42:55 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_reserve_memory_heap(size_t count)
{
    char    *ptr;

    printf("dentro de función ft_reserve_memory_heap\n");
    ptr = (char *)malloc(count * sizeof(char));
    if (!ptr)
    {
        printf("*******SE TRUNCÓ EL MALLOC********\n");
        return (0);
    }
    return (ptr);
}

static char *ft_read_and_stock_in_buff(int fd, size_t buff_size)
{
    char    *buff;
    ssize_t nbytes;

    printf("dentro de función ft_read_and_stock_in_buff\n");
    printf("buff_size es = %zu\n", buff_size);
    buff = ft_reserve_memory_heap(buff_size + 1);
    nbytes = read(fd, buff, buff_size);
    if (nbytes == -1)
    {
      perror("Error reading file");
       exit(1);
    }
    
    printf("salió de read, nbytes = %zd\n", nbytes);
    printf("salió de read, buff = %s\n", buff);
    return (buff);
}

/* static char *ft_pass_buff_content_to_stash(char *buffer)
{
    static char *stash;

    return (stash);
}

static  char *ft_stash_extract_for_next_GNL()

static char *ft_concat_clean_stash_to_line(char *stash)
 */

char *get_next_line(int fd)
{
   char *line;

    printf("BUFFER_SIZE es = %d\n", BUFFER_SIZE);
    line = ft_read_and_stock_in_buff(fd, BUFFER_SIZE);
    return (line);
}

int main()
{
    int fd;
    char *result;

    fd = open("41_no_nl", O_RDONLY);
    if (fd == -1)
    {
     perror("Error opening file");
     exit(1);
    }
    printf("fd = %d\n", fd);
    result = get_next_line(fd);
    printf("%s", result);
    close(fd);
}