/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:27:57 by jtames            #+#    #+#             */
/*   Updated: 2024/12/10 15:28:04 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_rest(char *text)
{
	char	*temp;

	temp = ft_strchr(text, '\n');
	if (temp == NULL)
	{
		free (text);
		return (ft_strdup(""));
	}
	temp = ft_strdup(temp + 1);
	free (text);
	return (temp);
}

char	*substract_line(char *text)
{
	int		i;
	char	*line_substr;
	char	*temp;

	i = 0;
	line_substr = ft_calloc(1, ft_strlen(text) + 1);
	while (text[i] != '\0' && text[i] != '\n')
	{
		line_substr[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line_substr[i] = '\n';
	temp = ft_strdup(line_substr);
	free (line_substr);
	return (temp);
}

char	*text_update(char *text, char *readen)
{
	char	*temp;

	if (!readen)
		return (NULL);
	if (!text)
		text = ft_calloc(1, 1);
	temp = ft_strjoin(text, readen);
	free(text);
	return (temp);
}

char	*read_file(char *text, char *readen, int fd)
{
	int		i;

	while (read(fd, readen, BUFFER_SIZE) > 0)
	{
		text = text_update(text, readen);
		i = 0;
		while (readen[i] != '\0')
			readen[i++] = '\0';
		if (ft_strchr(text, '\n'))
			break ;
	}
	return (text);
}

char	*get_next_line(int fd)
{
	char		*readen;
	static char	*text;
	char		*get_line;

	if (fd == -1)
		return (NULL);
	readen = ft_calloc(1, BUFFER_SIZE + 1);
	text = read_file(text, readen, fd);
	if (!text || text[0] == '\0')
	{
		free (readen);
		if (!text)
			return (NULL);
		free (text);
		return (NULL);
	}
	get_line = substract_line(text);
	text = save_rest(text);
	free (readen);
	return (get_line);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text", O_RDWR);
	if (fd == -1)
		return (0);

	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// if (line == NULL)
	// 	return (0);
	// printf("%s", line);
	// free (line);

	i = 0;
	while (1)
	{
		i++;
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		printf("%d: %s", i, line);
		free (line);
	}

	close (fd);
	return (0);
} */
