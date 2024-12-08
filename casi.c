
#include "get_next_line.h"

char	*ft_substract(char *text)
{
	int		len;
	int		i;
	char	*temp;

	len = 0;
	i = -1;
	if (text == NULL)
		return ("");
	while (text[++i] == '\n')
		len++;
	while (text[i] != '\n' && text[i++] != '\0')
		len++;
	temp = ft_substr(text, 0, len);
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
	size_t		b_read;
	char		*line;
	char		*temp;
	size_t		i;

	if (fd == -1)
		return (0);
	readen = calloc(1, BUFFER_SIZE + 1);
	if (!readen)
		return (NULL);
	if (!text)
		text = calloc(1, 1);
	b_read = BUFFER_SIZE;
	while (ft_strchr(readen, '\n') == NULL && b_read == BUFFER_SIZE)
	{
		i = ft_strlen(readen);
		while (i > 0)
			readen[i--] = '\0';
		b_read = read(fd, readen, BUFFER_SIZE);
		if (b_read != 0)
			text = text_update(text, readen);
	}
	if (text[0] == '\0')
		return (free (readen), free (text), NULL);
	line = ft_substract(text);
	temp = ft_strdup(text + ft_strlen(line));
	free (text);
	text = text_update(temp, "");
	free (readen);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*get_line;
	int		i;

	fd = open("text", O_RDWR);
	if (fd == -1)
		return (0);
/* 	get_line = get_next_line(fd);
	if (get_line == NULL)
		return (0);
	printf("%s", get_line);
	free (get_line); */
	i = 0;
	while (1)
	{
		i++;
		get_line = get_next_line(fd);
		if (get_line == NULL)
			return (0);
		printf("%s %d", get_line, i);
		free (get_line);
	}
	close (fd);
	return (0);
}
