#include "../includes/so_long.h"

void	input_player_position(t_info *info)
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
		while (node->content[j] != '\0')
		{
			if (node->content[j] == 'P')
			{
				info->player_info.postion_y = i;
				info->player_info.postion_x = j;
				return ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
}
