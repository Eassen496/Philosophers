#include "philo.h"

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
	printf("./philo <number_of_philosopher> <time_to_death> <time_to_eat> <time_to_sleep> ");
	printf("<number_of_times_each_philosopher_must_eat> (optional)\n");
	return (1);
}