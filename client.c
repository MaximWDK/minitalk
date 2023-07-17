/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:43:42 by mleonet           #+#    #+#             */
/*   Updated: 2023/07/17 17:43:14 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void	send_signal(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Erreur !\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || pid == 0)
	{
		ft_printf("Erreur de PID");
		return (0);
	}
	while (argv[2])
		send_signal(argv[2][i++], pid);
	send_signal('\n', pid);
	return (0);
}
