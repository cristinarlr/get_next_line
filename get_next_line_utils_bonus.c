/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cristina <Cristina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:31:49 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/28 06:38:41 by Cristina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	ccomp;

	if (!s)
		return (NULL);
	ccomp = (char) c;
	while (*s && *s != ccomp)
		s++;
	if (*s == ccomp)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ccatstr;
	size_t	ccatlen;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	ccatlen = (ft_strlen(s1) + ft_strlen(s2));
	ccatstr = malloc(ccatlen + 1);
	if (!ccatstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ccatstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		ccatstr[i++] = s2[j++];
	ccatstr[i] = '\0';
	free (s1);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < len && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
