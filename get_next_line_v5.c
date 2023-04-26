/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:51:18 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/26 12:49:19 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*pnewline;
	int	line_len;
	
//	printf("DENTRO DE EXTRACT_LINE\n");	
	if(ft_strchr(stash, '\n'))
	{
		pnewline = ft_strchr(stash, '\n') + 1;
		line_len = ft_strlen(stash) - ft_strlen(pnewline);
		line = ft_substr(stash, 0, line_len);
		if (!line)
		{
//			free (stash);
			return (0);
		}
	}
	else
		line = stash;
//	printf(" >> EXTRACT_LINE - stash = %s\n", stash);
//	printf(" >> EXTRACT_LINE - line = %s", line);
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	char	*rest_stash;
	char	*pnewline;
	int	rest_stash_start;
	int	rest_stash_len;
	
//	printf("DENTRO DE CLEAN_STASH\n");
	if(ft_strchr(stash, '\n'))
	{
		pnewline = ft_strchr(stash, '\n') + 1;
		rest_stash_start = ft_strlen(stash) - ft_strlen(pnewline);
		rest_stash_len = ft_strlen(pnewline);
		rest_stash = ft_substr(stash, rest_stash_start, rest_stash_len);
//		printf("antes > stash = %s\n", stash);
//		printf("rest_stash = %s\n", rest_stash);
		if (!rest_stash)
		{
			free(stash);
			return (0);	
		}
	}
	else
		rest_stash = stash;
//	printf("CLEAN_STASH - stash = %s\n", stash);
//	printf(" >> CLEAN_STASH - rest_stash = %s\n", rest_stash);
	return (rest_stash);
}

void	ft_fill_with_zero(char *s)
{
	size_t	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		s[i] = '\0';
		i++;
	}
}

char	*ft_read_and_stock(int fd, char *stash)
{
	char	*buff;
	ssize_t	nbytes;

//	printf("DENTRO DE READ & STOCK\n");
//    printf(" >>>> STASH al entrar = \n%s", stash);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff)
		return (0);
	buff[BUFFER_SIZE] = '\0';
	nbytes = 1;	
	while(!ft_strchr(stash, '\n') && nbytes != 0)
	{
//		printf("\nDENTRO DE WHILE\n");
		nbytes = read(fd, buff, BUFFER_SIZE);
        //		printf(" >> buffer >> \n%s", buff);
		if (nbytes == -1)
		{
			//duda, por qué hay que liberar stash si no la he creado con malloc?
			free (stash); 
			free (buff);
			return (0);
		}
		stash = ft_strjoin(stash, buff);
        printf ("nbytes = %zd", nbytes);
        if (nbytes < BUFFER_SIZE)
            return(0);
 //       printf("\n >> WHILE_JOIN >> \n%s", stash); 
//		ft_fill_with_zero(buff);
//		printf(" >> WHILE_BUFF >> %s\n", buff);
//		printf(" >> WHILE_JOIN >> %s\n", stash);
	}
//    printf("\n >> STASH ANTES DE SALIR DE R&S >> \n%s", stash);
    printf("\nFUERA DE WHILE\n");
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	printf("-------------------------\n");
	printf("DENTRO DE GNL\n");
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if(!stash)
			return (0);
        ft_fill_with_zero(stash);
	}
	stash = ft_read_and_stock(fd, stash);
//    printf("\n >> read_and_stock STASH >> \n%s", stash);
	if (!stash)
		return (0);
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	if (!line)
		return(0);
	else
		return (line);
}

int main()
{
	int	fd;
	char	*line;
	int	i;
	
	fd = open("f_15char", O_RDONLY);
//	fd = open("f_ley_trans", O_RDONLY);
//	fd = open("f_bigline", O_RDONLY);	
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	i = 0;
	while ((line = get_next_line(fd)) != 0 && i < 8)
	{
		printf("\nMAIN_LINE = %s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
