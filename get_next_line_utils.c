/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:58:08 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/20 11:50:54 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*ft_strdup(const char *s)
{
	unsigned char    *saux
    unsigned char    *scpy;

    saux = (unsigned char *) s;
	scpy = (unsigned char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (scpy == NULL)
		return (NULL);
	ft_memcpy(scpy, s, ft_strlen(s) + 1);
	return (scpy);
} */

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;
	printf("**** FT - dentro de ft_strlcpy ****\n");
	size_src = BUFFER_SIZE + 1;
	i = 0;
	if (dstsize == 0)
		return (size_src);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
			dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (size_src);
}

char	*ft_strchr(const char *s, int c)
{
	char	ccomp;

	ccomp = (char) c;
	while (*s && *s != ccomp)
		s++;
	if (*s == ccomp)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ccatstr;
	size_t	ccatlen;
	size_t	i;
	size_t	j;

    printf("**** FT - dentro de ft_strjoin ****\n");
	if (s1 == 0 || s2 == 0)
		return (0);
	ccatlen = (ft_strlen(s1) + ft_strlen(s2));
	printf("ft_strlen(s1) = %zu\n", ft_strlen(s1));
	printf("ft_strlen(s1[0]) = %c\n", s1[0]);
	printf("ft_strlen(s2) = %zu\n", ft_strlen(s2));
    printf("ccatlen = %zu\n", ccatlen);
	ccatstr = malloc(ccatlen + 1);
	if (ccatstr == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
        printf("dentro de ft_strjoin WHILE-s1 \n");
		ccatstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		printf("dentro de ft_strjoin WHILE-s2 \n");
        ccatstr[i++] = s2[j++];
	}
	ccatstr[i] = '\0';
    printf("ccatstr = %s\n", ccatstr);
	return (ccatstr);
}