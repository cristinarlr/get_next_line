/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:57:14 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/19 15:46:22 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *ft_read_and_stock_in_stash(int fd, )
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
    line = ft_read_and_stock_in_buff(fd);
    return (line);
}

int main()
{
    int fd;
    char *result;

    fd = open("15char", O_RDONLY);
    if (fd == -1)
    {
     printf("Error opening file");
     exit(1);
    }
    printf("fd = %d\n", fd);
    result = get_next_line(fd);
    printf("Result = %s", result);
    close(fd);
}