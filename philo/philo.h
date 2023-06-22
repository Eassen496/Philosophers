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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_unique
{
	int					argc;
	char				**argv;
	long long			time;
	pthread_mutex_t		mutex;
}	t_unique;

typedef struct s_utils
{
	pthread_t			thread[201];
	pthread_mutex_t		mutex[201];
	int					id;
	int					eat[201];
	int					all_eat;
}	t_utils;

typedef struct	s_time
{
	int				to_die;
	int				to_eat;
	int				to_sleep;
	long long		in_ms_start;
}	t_time;

typedef struct	s_philo
{
	int			nphilo;
	int			limit_eat;
	bool		isdead;
	t_time		time;
	t_utils		utils;
}	t_philo;

int			arg_error_0(void);
int			arg_error_1(void);
int			arg_error_2(void);
int			arg_error_3(void);
int			arg_error_4(void);

void		philosopher_thinking(t_philo *philo, int id);
int			philosopher_eating(t_philo *philo, int id);
void		philosopher_sleeping(t_philo *philo, int id);
void		philosopher_died(t_philo *philo, int id);
long long	get_ms();
void		*philosopher(void *philo);
int			thread_create(t_philo *philo);
size_t		ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_itoa(int n);
int			ft_atoi(char *str);
void		create_mutex(t_philo *philo);
void		philo_main(int argc, char **argv);
int			arg_verif(char **argv, int argc);
int			unique_case();
int			philo_unlock(t_philo *philo, int id, bool all);
void		*unique_philosopher(void *void_unique);


#endif
