#include "../includes/so_long.h"

void	read_map(char *file_name)
{
	int fd;
	size_t	i;

	fd = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		char *line = get_next_line(fd);
		if (line == NULL)
			break ;
		else
			ft_lstnew(line);
		i++;
	}
}