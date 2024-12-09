
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
	line_substr = calloc(1, ft_strlen(text) + 1);
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

	if (!text || !readen)
		return (NULL);
	temp = ft_strjoin(text, readen);
	free(text);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*readen;
	static char	*text;
	char		*get_line;
	int			i;

	if (fd == -1)
		return (NULL);
	readen = calloc(1, BUFFER_SIZE + 1);
	if (!text)
		text = calloc(1, 1);
	while (read(fd, readen, BUFFER_SIZE) > 0)
	{
		text = text_update(text, readen);
		i = 0;
		while (readen[i] != '\0')
			readen[i++] = '\0';
		if (ft_strchr(text, '\n'))
			break;
	}
	if (text[0] == '\0')
		return (free (readen), NULL);
	get_line = substract_line(text);
	text = save_rest(text);
	free (readen);
	return (get_line);
}

int	main(void)
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
}
