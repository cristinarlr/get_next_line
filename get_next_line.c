/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:25:20 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/27 15:39:04 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*pnewline;
	int		line_len;

	if (stash[0] == '\0')
		return (NULL);
	if (ft_strchr(stash, '\n'))
	{
		pnewline = ft_strchr(stash, '\n') + 1;
		line_len = ft_strlen(stash) - ft_strlen(pnewline);
		line = ft_substr(stash, 0, line_len);
		if (!line)
			return (NULL);
	}
	else
		line = ft_strdup(stash);
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	char	*rest_stash;
	char	*pnewline;
	int		rest_stash_start;

	if (stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (ft_strchr(stash, '\n'))
	{
		pnewline = ft_strchr(stash, '\n') + 1;
		rest_stash_start = ft_strlen(stash) - ft_strlen(pnewline);
		rest_stash = ft_substr(stash, rest_stash_start, ft_strlen(pnewline));
		if (rest_stash == NULL)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		return (rest_stash);
	}
	free(stash);
	return (NULL);
}

static char	*ft_read_and_stock(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	*buff = '\0';
	nbytes = 1;
	while (!ft_strchr(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (stash);
			return (0);
		}
		buff[nbytes] = '\0';
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	stash = ft_read_and_stock(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line (stash);
	stash = ft_clean_stash(stash);
	return (line);
}

/* int main(int argc , char** argv)
{
	int	fd;
	char	*line;
	
    if (argc != 2)
        return 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != 0)
	{
		printf("hola%s\n", line);
        free (line);
	}
	close(fd);
	return (0);
} */
