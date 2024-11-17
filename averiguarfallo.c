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
	char	readen[BUFFER_SIZE + 1];
	char	*text;
	char	*line;
	size_t	line_size;
	int		i;

	text = calloc(1, 1);
	i = 0;
	while (ft_strchr(text, '\n') == NULL)
	{
		if (read(fd, readen, BUFFER_SIZE) == 0)
			return (ft_strdup(readen), free (text), NULL);
		readen[BUFFER_SIZE] = '\0';
		text = text_update(text, readen);
		i++;
	}
	line_size = ft_strlen(text) - ft_strlen(ft_strchr(text, '\n'));
	line = calloc(1, line_size);
	memcpy(line, text, line_size);
	free (text);
	ft_bzero(readen, BUFFER_SIZE + 1);
	return (line);
}

int	main()
{
	int		fd;
	char	*get_line;

	get_line = "";
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return 0;
	while (1)
	{
		get_line = get_next_line(fd);
		if (get_line == NULL)
			return 0;
		printf("%s\n", get_line);
		free (get_line);
	}
/* 	get_line = get_next_line(fd);
	printf("%s", get_line);
	free (get_line);
	get_line = get_next_line(fd);
	printf("%s", get_line);
	free (get_line);
	get_line = get_next_line(fd);
	printf("%s", get_line);
	free (get_line);
	get_line = get_next_line(fd);
	printf("%s", get_line);
	free (get_line); */
	return (0);
}