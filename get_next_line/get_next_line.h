#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*get_line(char *cache);
int			find_symbol(char *line);
void		ft_free_string(char **str);
#endif