#include "../includes/so_long.h"

void	error_message_and_free(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	mlx_free();
}

void	mlx_free(void)
{
	exit (1);
}

int	mlx_free_ret_int(void)
{
	exit (1);
	return (0);
}
