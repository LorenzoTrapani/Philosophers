/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:50:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/08 18:32:43 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	philo->personal_meals++;
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
	ft_sleep();
} */
/*
int	philo_think(t_philo *philo)
{

} */

void *routine(t_philo *philo)
{
	philo_eat(philo);
	//philo_sleep(philo);
	//philo_think(philo);
	return (NULL);
}