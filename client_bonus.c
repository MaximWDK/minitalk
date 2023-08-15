/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:43:42 by mleonet           #+#    #+#             */
/*   Updated: 2023/08/15 23:38:13 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/minitalk.h"

static void	send_signal(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c & (0x01 << i)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
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
		ft_printf("Erreur de PID !\n");
		return (0);
	}
	while (argv[2][i])
		send_signal(argv[2][i++], pid);
	send_signal('\n', pid);
	return (0);
}
