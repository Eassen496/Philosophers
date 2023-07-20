/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:53:14 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/20 02:00:34 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	arg_error_4(void)
{
	printf("Error ! too many philosophers\n");
	return (1);
}

int	arg_error_3(void)
{
	printf("Error ! Null philosopher\n");
	return (1);
}

int	arg_error_2(void)
{
	printf("Error ! You gave incorrect value (negative value)\n");
	return (1);
}

int	arg_error_1(void)
{
	printf("Error ! You gave non-number character\n");
	return (1);
}

int	arg_error_0(void)
{
	printf("You need 4 or 5 arguments\n");
	printf("./philo <number_of_philosopher> ");
	printf("<time_to_death> <time_to_eat> <time_to_sleep> ");
	printf("<number_of_times_each_philosopher_must_eat> (optional)\n");
	return (1);
}
