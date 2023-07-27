/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:35:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/27 02:02:50 by ale-roux         ###   ########.fr       */
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

typedef struct s_duo
{
	int					argc;
	char				**argv;
	long long			time;
	pthread_mutex_t		mutex[2];
	int					id;
	bool				dead;
}	t_duo;

typedef struct s_utils
{
	pthread_t			thread[201];
	pthread_mutex_t		mutex[201];
	pthread_mutex_t		talk;
	int					id;
	int					eat[201];
	int					all_eat;
}	t_utils;

typedef struct s_time
{
	int				to_die;
	int				to_eat;
	int				to_sleep;
	long long		in_ms_start;
}	t_time;

typedef struct s_philo
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
int			philosopher_eating(t_philo *philo, int id, long long last);
void		philosopher_sleeping(t_philo *philo, int id, long long last);
void		philosopher_died(t_philo *philo, int id);
void		eat_verif(t_philo *philo);
int			dead_verif(long long time_in_ms, t_philo *philo, int id);
void		*p(void *void_philo);
int			thread_create(t_philo *philo);
void		*unique_philosopher2(void *void_unique);
int			unique_case(int argc, char **argv);
int			philo_unlock(t_philo *philo, int id, bool all);
void		create_mutex(t_philo *philo);
void		destroy_mutex(t_philo *philo);
int			ft_atoi(char *str);
long long	get_ms(void);
size_t		ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_itoa(int n);
void		philo_eat_fill(t_philo *philo);
void		philo_main(int argc, char **argv);
int			arg_verif(char **argv, int argc);
void		duo_case(int argc, char **argv);

#endif
