/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:23:34 by jtames            #+#    #+#             */
/*   Updated: 2024/11/16 14:23:36 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*dup;
	size_t		i;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	rest;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	rest = ft_strlen(s) - start;
	if (len >= rest)
		len = rest;
	sub_s = malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start] != '\0'))
		sub_s[i++] = s[start++];
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i] != '\0')
		if (s[i++] == cc)
			return ((char *)&s[i - 1]);
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			new_s[i] = s1[i];
		else if (i >= ft_strlen(s1))
			new_s[i] = s2[j++];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
