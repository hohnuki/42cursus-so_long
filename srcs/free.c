#include "../includes/so_long.h"

void	error_message_and_exit(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	mlx_free_ret_int(void)
{
	exit (EXIT_FAILURE);
	return (0);
}
