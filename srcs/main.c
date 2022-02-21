#include "../includes/so_long.h"

void	info_init(t_config *info)
{
	info->filename = NULL;
	info->images.image_size = PIXEL_SIZE;
}

int	main(int argc, char **argv)
{
	t_config	info;
	(void)argc;

	info_init(&info);
	info.filename = argv[1];
	read_map(&info);
	display_map(&info);
//	set_event(&info);
	mlx_loop(info.mlx);
}
