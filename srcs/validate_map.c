#include "../includes/so_long.h"

void	validate_map(t_config *info)
{
	validate_map_rectangle(info);
	validate_map_smooth(info);
	validate_characters(info);
	validate_enclose_wall(info);
}

void	validate_map_rectangle(t_config *info)
{
	if (info->map_info.width == info->map_info.height)
		error_message_and_free("map is not rectangle.", info);
	if (info->map_info.width <= 2 || info->map_info.height <= 2)
		error_message_and_free("map is narrow", info);
}

void	validate_map_smooth(t_config *info)
{
	int i;

	i = 0;
	while (i < info->map_info.height)
	{
		if ((int)ft_strlen(info->map_info.map[i]) != info->map_info.width)
			error_message_and_free("map is not smooth.", info);
		i++;
	}
}

void	validate_characters(t_config *info)
{
	char	*tmp_address;
	int		i;
	int		j;

	i = 0;
	while (i < info->map_info.height)
	{
		j = 0;
		while (j < info->map_info.width)
		{
			if (info->map_info.map[i][j] == 'C')
			{
				// printf("\x1b[36m[i = %d, j = %d]\033[m\n", i, j);
				// printf("\x1b[36m[%d]\033[m\n", info->map_info.collectible_count);
				info->map_info.collectible_count++;

			}
			else if (info->map_info.map[i][j] == 'P')
				info->map_info.player_count++;
			else if (info->map_info.map[i][j] == 'E')
				info->map_info.exit_count++;

			tmp_address = ft_strchr("10CEP", info->map_info.map[i][j]);
			if (tmp_address == NULL)
				error_message_and_free("map has invalid character.", info);
			j++;
		}
		i++;
	}
	if (info->map_info.player_count != 1 || info->map_info.collectible_count == 0)
		error_message_and_free("map lacks elements.", info);
	// printf("\x1b[36m[%d]\033[m\n", info->map_info.collectible_count);
}

void	validate_enclose_wall(t_config *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_info.height)
	{
		j = 0;
		while (j < info->map_info.width)
		{
			if ((j == 0 || j == (int)(ft_strlen(info->map_info.map[i]) - 1)) && info->map_info.map[i][j] != '1')
				error_message_and_free("map is not enclosed wall.", info);
			if ((i == 0 || i == info->map_info.height - 1) && info->map_info.map[i][j] != '1')
				error_message_and_free("map is not enclosed wall.", info);
			j++;
		}
		i++;
	}
}
