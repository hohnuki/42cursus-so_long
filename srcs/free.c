#include "../includes/so_long.h"

void	error_message_and_exit(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	execute_exit(void)
{
	exit (EXIT_FAILURE);
}
