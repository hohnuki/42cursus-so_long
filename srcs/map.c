#include "../includes/so_long.h"

void	read_map(char *file_name)
{
	t_list	*guard_node;
	size_t	i;
	int fd;

	guard_node = ft_lstnew(NULL);
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		char *line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(&guard_node, ft_lstnew(line));
		i++;
	}
//	print_map(guard_node);
}