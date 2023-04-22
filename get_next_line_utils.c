/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:58:08 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/22 23:26:02 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	//añadido if(!s)
	//if(!s)
	//	return (0);
	ccomp = (char) c;
	while (*s && *s != ccomp)
		s++;
	if (*s == ccomp)
	{
		return ((char *)s);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ccatstr;
	size_t	ccatlen;
	size_t	i;
	size_t	j;

	//if (s1 == 0 || s2 == 0)
	//	return (0);
	ccatlen = (ft_strlen(s1) + ft_strlen(s2));
	ccatstr = malloc(ccatlen + 1);
	if (ccatstr == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ccatstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
        ccatstr[i++] = s2[j++];
	}
	ccatstr[i] = '\0';
	return (ccatstr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		len;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}