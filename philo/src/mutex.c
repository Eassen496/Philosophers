/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:46:15 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/20 02:00:39 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	philo_unlock(t_philo *philo, int id, bool all)
{
	pthread_mutex_unlock(&philo->utils.mutex[id]);
	if (all == true)
	{
		if (id == philo->nphilo)
			pthread_mutex_unlock(&philo->utils.mutex[1]);
		else
			pthread_mutex_unlock(&philo->utils.mutex[id + 1]);
	}
	return (0);
}

void	create_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nphilo)
	{
		pthread_mutex_init(&philo->utils.mutex[i], NULL);
		usleep(100);
		i++;
	}
	return ;
}

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nphilo)
	{
		pthread_mutex_destroy(&philo->utils.mutex[i]);
		usleep(100);
		i++;
	}
	return ;
}
