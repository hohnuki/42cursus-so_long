#include "../includes/so_long.h"

void	validate_filename(char *filename)
{
	char	*dot_address;
	int 	strncmp_ret;

	dot_address = ft_strchr(filename, '.');
	if (dot_address == NULL)
		exit(1);
	strncmp_ret = ft_strncmp(dot_address, ".ber", 3);
	if (strncmp_ret != 0)
		exit(1);
}