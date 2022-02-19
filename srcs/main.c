#include "../includes/so_long.h"

void	info_init(t_config *info)
{
	info->filename = NULL;
}

int	main(int argc, char **argv)
{
	t_config	info;
	(void)argc;

	info_init(&info);
	info.filename = argv[1];
	read_map(&info);
	display_map(&info);
}
