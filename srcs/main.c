#include "../includes/so_long.h"

void	info_init(t_config *info)
{
	info->map_info = NULL;
	info->player_info = NULL;
	info->filename = NULL;
}

int	main(int argc, char **argv)
{
	t_config	*info;

	info_init(info);
	info = malloc(sizeof(t_config *));
	info->filename = argv[1];
	(void)argc;
	read_map(info);

}
