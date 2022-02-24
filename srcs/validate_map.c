#include "../includes/so_long.h"

void	validate_map_rectangle(t_config *info)
{
	if (info->map_info.width == info->map_info.height)
		exit(1);
	if (info->map_info.width <= 2 || info->map_info.height <= 2)
		exit(1);
}

void	validate_map_smooth(t_config *info)//TODO:底面のガタガタチェックがまだ
{
	int i;

	i = 0;
	while (i < info->map_info.height)
	{
		if (ft_strlen(info->map_info.map[i]) != info->map_info.height)
			exit(1);
		i++;
	}
}
