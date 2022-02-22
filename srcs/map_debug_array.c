#include "../includes/so_long.h"

void	print_map_array(t_config *info)
{
	int i;

	i = 0;
	while (info->map_info.line[i] != NULL)
	{
		printf("\x1b[36m[%s]\n\033[m", info->map_info.line[i]);
		i++;
	}
}