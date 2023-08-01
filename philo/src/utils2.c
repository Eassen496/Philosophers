/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:53:32 by ale-roux          #+#    #+#             */
/*   Updated: 2023/08/02 01:58:07 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	talk(t_philo *philo, int id, long long time_in_ms, int action)
{
	pthread_mutex_lock(&philo->utils.talk);
	if (philo->isdead == false)
	{
		if (action == 0)
			printf("%lld %d is thinking\n", time_in_ms, id);
		else if (action == 1)
			printf("%lld %d has taken a fork\n", time_in_ms, id);
		else if (action == 2)
			printf("%lld %d is eating\n", time_in_ms, id);
		else if (action == 3)
			printf("%lld %d is sleeping\n", time_in_ms, id);
		else if (action == 4)
			printf("%lld %d died\n", time_in_ms, id);
	}
	pthread_mutex_unlock(&philo->utils.talk);
}
