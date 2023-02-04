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

typedef struct	s_philo
{
	int		nphilo;
	timeval	ttd;
	timeval	tte;
	timeval	tts;
	int		eat;
}	t_philo;

#endif
