/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:44:25 by jtames            #+#    #+#             */
/*   Updated: 2024/11/14 17:44:30 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*text_update(char *text, char *readen)
{
	char	*temp;

	if (!text || !readen)
		return (NULL);
	temp = ft_strjoin(text, readen);
	free(text);
	return (temp);
}

char	*get_next_line(int fd)
{
	char	*text;
	char	*get_line;
	size_t	line_size;
	char	readen[BUFFER_SIZE + 1];
	int 	i;

	text = calloc(1, 1);
	i = 0;
	while (ft_strchr(text, '\n') == NULL)
	{
		read(fd, readen, BUFFER_SIZE);
		readen[BUFFER_SIZE] = '\0';
		text = text_update(text, readen);
		i++;
	}
	line_size = ft_strlen(text) - ft_strlen(ft_strchr(text, '\n'));
	get_line = calloc(1, line_size);
	ft_memcpy(get_line, text, line_size);
	free (text);
	return (get_line);
}

int	main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text", O_RDONLY);
	if (fd == -1)
		return (0);
	line = "";
	i = 0;
	while (i <= 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
		i++;
	}
	return 0;

/* 	char *a = calloc(1, 3);
	char *b = "hola";

	memcpy(a, b, 3);
	printf("%s", a); */
}
