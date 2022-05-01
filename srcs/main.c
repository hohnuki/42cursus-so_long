#include "../includes/so_long.h"

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q so_long");
// }

static void	players_init(t_info *info)
{
	info->player_info.postion_x = 0;
	info->player_info.postion_y = 0;
	info->player_info.pedometer = 0;
	info->player_info.collectible_count = 0;
	info->player_info.c_x = 0;
	info->player_info.c_y = 0;
	info->player_info.n_x = 0;
	info->player_info.n_y = 0;
}

static void	info_init(t_info *info)
{
	info->mlx = NULL;
	info->mlx_win = NULL;
	info->map_info.width = 0;
	info->map_info.height = 0;
	info->map_info.player_count = 0;
	info->map_info.exit_count = 0;
	info->map_info.collectible_count = 0;
	info->map_info.guard_node = NULL;
	info->map_info.map = NULL;
	players_init(info);
	info->images.player = NULL;
	info->images.player2 = NULL;
	info->images.wall = NULL;
	info->images.collectible = NULL;
	info->images.exit = NULL;
	info->images.empty = NULL;
	info->filename = NULL;
	info->images.image_size = PIXEL_SIZE;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		exit(EXIT_FAILURE);
	info_init(&info);
	validate_filename(argv[1]);
	info.filename = argv[1];
	read_map(&info);
	display_map(&info);
	set_event(&info);
	mlx_loop(info.mlx);
}
