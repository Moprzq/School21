/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:28:34 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/20 18:37:53 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_validate_pid(const char *str);
int		ft_valid_arg(int argc, char **argv);
int		ft_atoi(char const *str);
void	ft_putnbr(int nb);
void	ft_get_len(int signum, pid_t server_pid, int *len);
int		ft_strlen(const char *str);
void	ft_send_len(pid_t server_pid, int len);
void	ft_send_signal(pid_t pid, int signum);
void	ft_write_str(char *str);
int		ft_if_not_str(int *index, char **str, pid_t client_pid, \
			int len);
void	ft_write_and_free(char **str);
void	*ft_calloc(int len, int size);

#endif