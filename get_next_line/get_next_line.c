#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_free_string(char **str)
{
	if (str)
	{
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
	}
}

int	ft_free_content(char **s1, char **s2, int flag)
{
	ft_free_string(s1);
	ft_free_string(s2);
	return (flag);
}

char	*get_line(char *cache)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!cache)
		return (NULL);
	while (cache[i] && cache[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (i--)
	{
		line[j] = cache[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*clear_cache(char *cache)
{
	char	*line;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = find_symbol(cache);
	len = ft_strlen(&(cache[++i]));
	if (!cache[len])
	{
		free(cache);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (cache[i])
		line[j++] = cache[i++];
	line[j] = '\0';
	free(cache);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	char		*buf;
	int			bytes_read;
	
	if (fd < -1 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_content(&cache, NULL, -1));
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && find_symbol(cache) == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_content(&cache, &buf, -1));
		buf[bytes_read] = '\0';
		cache = ft_strjoin(cache, buf);
	}
	*line = get_line(cache);
	cache = clear_cache(cache);
	if (!cache && bytes_read < BUFFER_SIZE)
		return (ft_free_content(NULL, &buf, 0));
	return (ft_free_content(NULL, &buf, 1));
}
