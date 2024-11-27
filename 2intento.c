
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
	char		*line;
	char		*temp;

	readen = calloc(1, BUFFER_SIZE + 1);
	if (!readen)
		return (NULL);
	if (!text)
		text = calloc(1, 1);
	while (ft_strchr(readen, '\n') == NULL)
	{
		ft_bzero(readen, ft_strlen(readen));
		if (read(fd, readen, BUFFER_SIZE) == 0)
			break ;
		readen[ft_strlen(readen)] = '\0';
		text = text_update(text, readen);
	}
	if (text[0] == '\0')
		return (free (readen), free (text), NULL);
	line = ft_substract(text);
	if (ft_strchr(readen, '\n'))
		temp = ft_strchr(readen, '\n');
	else
		temp = ft_substract(ft_strchr(text + 1, '\n'));
	ft_bzero(text, ft_strlen(text));
	text = text_update(text, temp);
	free (readen);
	return (line);
}

int	main()
{
	char	*get_line;
	int		fd;
	int		i;

	get_line = "";
	fd = open("text.txt", O_RDONLY);
	i = 0;
	if (fd == -1)
		return 0;
	get_line = get_next_line(fd);
	if (get_line == NULL)
		return 0;
	printf("%s", get_line);
	free (get_line);
/* 	while (1)
	{
		i++;
		get_line = get_next_line(fd);
		if (get_line == NULL)
			return (0);
		printf("%s %d", get_line, i);
		free (get_line);
	} */
	return 0;
}
