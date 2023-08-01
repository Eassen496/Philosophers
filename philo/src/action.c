/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:38:57 by ale-roux          #+#    #+#             */
/*   Updated: 2023/08/02 01:57:15 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philosopher_thinking(t_philo *philo, int id)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		talk(philo, id, time_in_ms, 0);
	return ;
}

int	philosopher_eating2(t_philo *philo, int id, long long time_in_ms)
{
	time_in_ms = get_ms() - philo->time.in_ms_start;
	talk(philo, id, time_in_ms, 1);
	pthread_mutex_lock(&philo->utils.die);
	if (time_in_ms + philo->time.to_die < get_ms() - philo->time.in_ms_start
		&& philo->isdead == false)
	{
		pthread_mutex_unlock(&philo->utils.die);
		philosopher_died(philo, id);
	}
	pthread_mutex_unlock(&philo->utils.die);
	talk(philo, id, time_in_ms, 2);
	while (time_in_ms + philo->time.to_eat > get_ms() - philo->time.in_ms_start)
		usleep(10);
	philo_unlock(philo, id, true);
	philo->utils.eat[id]++;
	return (time_in_ms);
}

int	philosopher_eating(t_philo *philo, int id, long long time_in_ms)
{
	pthread_mutex_lock(&philo->utils.mutex[id]);
	pthread_mutex_lock(&philo->utils.die);
	if (philo->isdead == true)
	{
		pthread_mutex_unlock(&philo->utils.die);
		return (philo_unlock(philo, id, true));
	}
	pthread_mutex_unlock(&philo->utils.die);
	time_in_ms = get_ms() - philo->time.in_ms_start;
	talk(philo, id, time_in_ms, 1);
	if (id == philo->nphilo)
		pthread_mutex_lock(&philo->utils.mutex[1]);
	else
		pthread_mutex_lock(&philo->utils.mutex[id + 1]);
	pthread_mutex_lock(&philo->utils.die);
	if (philo->isdead == true)
	{
		pthread_mutex_unlock(&philo->utils.die);
		return (philo_unlock(philo, id, true));
	}
	pthread_mutex_unlock(&philo->utils.die);
	return (philosopher_eating2(philo, id, time_in_ms));
}

void	philosopher_sleeping(t_philo *philo, int id, long long last)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == true)
		return ;
	talk(philo, id, time_in_ms, 3);
	time_in_ms += (long long)philo->time.to_sleep;
	while (time_in_ms > get_ms() - philo->time.in_ms_start)
	{
		if (dead_verif(last, philo, id) == 1)
			break ;
		usleep(100);
	}
	return ;
}

void	philosopher_died(t_philo *philo, int id)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		talk(philo, id, time_in_ms, 4);
	pthread_mutex_lock(&philo->utils.die);
	philo->isdead = true;
	pthread_mutex_unlock(&philo->utils.die);
	return ;
}
