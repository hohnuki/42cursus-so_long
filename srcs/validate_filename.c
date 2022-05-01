#include "../includes/so_long.h"

void	validate_filename(char *filename)
{
	char	*dot_address;
	int		strncmp_ret;

	if (ft_strncmp(filename, ".ber", 4) == 0)
		error_message_and_free("Error\nfilename is bad.");
	dot_address = ft_strchr(filename, '.');
	if (dot_address == NULL)
		error_message_and_free("Error\nfilename is bad.");
	strncmp_ret = ft_strncmp(dot_address, ".ber", 3);
	if (strncmp_ret != 0)
		error_message_and_free("Error\nfilename is bad.");
}
