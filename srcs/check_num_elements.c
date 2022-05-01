#include "so_long.h"

void	check_num_element(t_info *info)
{
	if (info->map_info.player_count != 1 || \
	info->map_info.collectible_count == 0)
		error_message_and_free("Error\nmap lacks elements.");
}
