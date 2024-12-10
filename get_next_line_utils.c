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
	int		i;
	int		j;
	size_t	len;
	char	*new_s;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(len + 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	return (new_s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;
	char	*temp;

	if (nmemb == SIZE_MAX || size == SIZE_MAX
		|| (nmemb >= 4294967296 && size >= 4294967296))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc((size_t)total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	temp = (char *)ptr;
	while (i < total_size)
		temp[i++] = '\0';
	return (ptr);
}
