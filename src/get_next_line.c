#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	r;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	r = 1;
	while (!ft_gnl_strchr(stash, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[r] = '\0';
		stash = ft_gnl_strjoin(stash, buf);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_gnl_getline(stash);
	stash = ft_gnl_newstash(stash);
	return (line);
}
