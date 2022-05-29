#include "../includes/so_long.h"

void	validate_map(t_info *info)
{
	validate_map_rectangle(info);
	validate_map_smooth(info);
	validate_characters(info);
	validate_enclose_wall(info);
}

void	validate_map_rectangle(t_info *info)
{
	if (info->map_info.width <= 2 || info->map_info.height <= 2)
		error_message_and_exit("Error\nmap is narrow");
}

void	validate_map_smooth(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.height)
	{
		if ((int)ft_strlen(info->map_info.map[i]) != info->map_info.width)
			error_message_and_exit("Error\nmap is not smooth.");
		i++;
	}
}

void	validate_characters(t_info *info)
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
				info->map_info.collectible_count++;
			else if (info->map_info.map[i][j] == 'P')
				info->map_info.player_count++;
			else if (info->map_info.map[i][j] == 'E')
				info->map_info.exit_count++;
			tmp_address = ft_strchr("10CEP", info->map_info.map[i][j]);
			if (tmp_address == NULL)
				error_message_and_exit("Error\nmap has invalid character.");
			j++;
		}
		i++;
	}
	check_num_element(info);
}

void	validate_enclose_wall(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map_info.height)
	{
		j = 0;
		while (j < info->map_info.width)
		{
			if ((j == 0 || j == (int)(ft_strlen(info->map_info.map[i]) - 1)) \
			&& info->map_info.map[i][j] != '1')
				error_message_and_exit("Error\nmap is not enclosed wall.");
			if ((i == 0 || i == info->map_info.height - 1) && \
			info->map_info.map[i][j] != '1')
				error_message_and_exit("Error\nmap is not enclosed wall.");
			j++;
		}
		i++;
	}
}
