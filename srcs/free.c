#include "../includes/so_long.h"

void	error_message_and_free(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	mlx_free();
}

int	mlx_free()
{
	exit (1);
	return (0);
}
