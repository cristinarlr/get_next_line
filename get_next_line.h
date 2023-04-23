/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:03:16 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/23 23:05:33 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/stat.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char    *get_next_line(int fd);
char    *ft_get_full_line (int fd, char *stash);
char    *ft_extract_line(char *stash);
char    *ft_clean_stash(char *stash);

#endif
