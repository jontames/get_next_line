
#include "get_next_line.h"

char	*ft_substract(char *text)
{
	int		len;
	int		i;
	int		j;
	char	*temp;

	len = 0;
	i = 0;
	while (text[i] == '\n')
		i++;
	j = i;
	while (text[j++] != '\n')
		len++;
	temp = ft_substr(text, i, len + 1);
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
	char		*line;
	char		*temp;

	readen = calloc(1, BUFFER_SIZE + 1);
	if (!readen)
		return (NULL);
	if (!text)
		text = calloc(1, 1);
	while (ft_strchr(readen, '\n') == NULL)
	{
		if (read(fd, readen, BUFFER_SIZE) == 0)
			return (NULL);
		readen[ft_strlen(readen)] = '\0';
		text = text_update(text, readen);
	}
	line = ft_substract(text);
	if (ft_strchr(readen, '\n'))
		temp = ft_strchr(readen, '\n');
	else
		temp = readen;
	ft_bzero(text, ft_strlen(text));
	text = text_update(text, temp);
	free (readen);
	return (line);
}

int	main()
{
	char	*get_line;
	int		fd;

	get_line = "";
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return 0;
	get_line = get_next_line(fd);
	if (get_line == NULL)
		return 0;
	printf("%s", get_line);
	free (get_line);
/* 	while (1)
	{
		get_line = get_next_line(fd);
		if (get_line == NULL)
			return (0);
		printf("%s", get_line);
		free (get_line);
	} */
	return 0;
}
