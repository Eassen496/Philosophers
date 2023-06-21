/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:35:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/01/19 23:01:42 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_utils
{
	pthread_t			thread[201];
	pthread_mutex_t		mutex[201];
	int					id;
}	t_utils;


typedef struct	s_philo
{
	int			nphilo;
	int			ttd;
	int			tte;
	int			tts;
	int			eat;
	t_utils		utils;
}	t_philo;

int	arg_error_0(void);
int	arg_error_1(void);
int	arg_error_2(void);
int	arg_error_3(void);

#endif
