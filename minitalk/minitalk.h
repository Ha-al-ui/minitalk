/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:43:35 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/01 14:58:50 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_error(char *str);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_isdigit(int c);

#endif
