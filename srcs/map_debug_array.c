#include "../includes/so_long.h"

void	print_map_array(t_config *info)
{
	int i;

	i = 0;
	while (i < info->map_info.height)
	{
		printf("\x1b[36m[%s]\n\033[m", info->map_info.map[i]);
		i++;
	}
}