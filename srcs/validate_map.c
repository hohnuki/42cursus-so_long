#include "../includes/so_long.h"

void    input_player_position(t_config *info)
{
	t_list	*node;
	int		i;
	int		j;

	node = info->map_info.guard_node;
	node = node->next;
	i = 0;
	while (node != NULL)
	{
		j = 0;
		while (node->content[j])
		{
			if (node->content[j] == 'P')
			{
				info->player_info.postion_x = i;
				info->player_info.postion_y = j;
				return ;
			}
			j++;
		}
		i++;
		node = node->next;
	}
}