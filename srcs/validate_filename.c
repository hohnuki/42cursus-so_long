#include "../includes/so_long.h"

void	validate_filename(t_config *info, char *filename)
{
	char	*dot_address;
	int 	strncmp_ret;

	if (ft_strncmp(filename, ".ber", 4) == 0)
		mlx_free(info);
	dot_address = ft_strchr(filename, '.');
	if (dot_address == NULL)
		mlx_free(info);
	strncmp_ret = ft_strncmp(dot_address, ".ber", 3);
	if (strncmp_ret != 0)
		mlx_free(info);
}