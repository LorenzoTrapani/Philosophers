/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:50:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/10 16:34:47 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(t_philo *philo)
{
	if (philo->id == 1)
		philo->table->start_time = get_time();
	//printf("start_time: %lu\n", philo->table->start_time);
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (philo->personal_meals < philo->table->nbr_meals)
	{
		if (is_dead(philo))
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	philo_print(philo, FORK);
	if (philo->table->nbr_philo == 1)
	{
		pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	philo_print(philo, FORK);
	philo_print(philo, EAT);
	pthread_mutex_lock(&philo->table->meals);
	philo->personal_meals++;
	pthread_mutex_unlock(&philo->table->meals);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->table->last_meal);
	philo->last_meal = get_time() - philo->table->start_time;
	pthread_mutex_unlock(&philo->table->last_meal);
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
}

void philo_print(t_philo *philo, char *action)
{
	unsigned long time;

	time = get_time();
	pthread_mutex_lock(&philo->table->print);
	printf("%s ", CYAN);
	printf("%lu ", time - philo->table->start_time);
	printf("%s ", GREEN);
	printf("%d ", philo->id);
	printf("%s", RESET);
	printf("%s", action);
	pthread_mutex_unlock(&philo->table->print);
}

void philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
}
