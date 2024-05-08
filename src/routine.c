/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:50:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/08 16:49:58 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int current_meals = 0;

int	philo_eat(t_philo *philo)
{
	if (philo->id == 0)
	{
		philo->r_fork = philo->table->nbr_philo;
		philo->l_fork = philo->id;
	}
	else
	{
		philo->r_fork = philo->id;
		philo->l_fork = philo->id -1;
	}
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	current_meals++;
	philo_print(philo, 1);
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
	return (0);
}

int philo_print(t_philo *philo, int action)
{
	//temp in ms; id philo; cosa fa;
	pthread_mutex_lock(&philo->table->print);
	printf("ID: %d ", philo->id);
	if (action == 1)
		printf("philo is eating\n");
	else if (action == 2)
		printf("philo is sleeping\n");
	else if (action == 3)
		printf("philo is thinking\n");
	pthread_mutex_unlock(&philo->table->print);
	return (0);
}

/* int philo_sleep(t_philo *philo)
{

}

int	philo_think(t_philo *philo)
{

} */

void *routine(t_philo *philo)
{
	philo_eat(philo);
	return (NULL);
}