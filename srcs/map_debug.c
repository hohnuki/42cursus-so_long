#include "../includes/so_long.h"

void	print_map(t_config *info)
{
	t_list	*node;

	node = info->map_info.guard_node;
	while (1)
	{
		node = node->next;
		if (node == NULL)
			break ;
		printf("\x1b[36m[%s]\n\033[m", node->content);
	}
	printf("\x1b[36m[height = %d]\n\033[m", info->map_info.height);
	printf("\x1b[36m[width = %d]\n\033[m", info->map_info.width);
}
