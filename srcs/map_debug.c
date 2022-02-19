#include "../includes/so_long.h"

void	print_map(t_list *node)
{
	while (1)
	{
		node = node->next;
		if (node == NULL)
			return ;
		printf("\x1b[36m[%s]\n\033[m", (char *)node->content);
	}
}