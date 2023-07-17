/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:31:37 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/23 17:54:56 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

char	ft_check_is_in(char c);
int		ft_format(char c, va_list lst, size_t i);
int		ft_printf(const char *str, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
void	ft_putnbr(int n, size_t	*len);
void	ft_putnbr_unisgned(unsigned int n, size_t	*len);
void	ft_putnbr_hexa(unsigned int n, size_t	*len, char c);
void	ft_putnbr_unsign_hexa(unsigned long long int n, size_t	*len, int c);

#endif