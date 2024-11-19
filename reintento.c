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
	char		*readen;
	static char	*text;
	char		*line;
	char		*temp;

	readen = calloc(1, BUFFER_SIZE + 1);
	if (!text)
		text = calloc(1, 1);
	while (ft_strchr(text, '\n') == NULL)
	{
		if (read(fd, readen, BUFFER_SIZE) == 0)
			return (printf("%s", readen), free (text), free (readen), NULL);
		readen[ft_strlen(readen)] = '\0';
		text = text_update(text, readen);
	}
	line = ft_substr(text, 0, ft_strlen(text) - ft_strlen(ft_strchr(text, '\n'))); //+ 1 para incluir el salto de linea
	temp = ft_strchr(readen, '\n');
	ft_bzero(text, ft_strlen(text));
	text = text_update(text, temp);
	// printf("%s\n", text);
	// free (text);
	free (readen);
	return(line);
}

int	main()
{
	char	*get_line;
	int		fd;

	get_line = "";
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return 0;
/* 	get_line = get_next_line(fd);
	if (get_line == NULL)
		return 0;
	printf("%s", get_line);
	free (get_line); */
	while (1)
	{
		get_line = get_next_line(fd);
		if (get_line == NULL)
			return (free (get_line), 0);
		printf("%s", get_line);
		free (get_line);
	}
	return 0;
}
