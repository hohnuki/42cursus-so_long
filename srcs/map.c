#include "../includes/so_long.h"

void	display_map(t_config *info)
{

}

void	read_map(t_config *info)
{
	t_list	*guard_node;
	size_t	i;
	int fd;

	guard_node = ft_lstnew(NULL);
	info->map_info.guard_node = guard_node;
	i = 0;
	fd = open(info->filename, O_RDONLY);
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
	close(fd);
	info->map_info.height = i;
	info->map_info.width = ft_strlen(guard_node->next->content);
//	print_map(info);
}