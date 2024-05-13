/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:32 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/13 18:21:32 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int mutex_init(t_data *table)
{
	int i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->nbr_philo);
	if (!table->fork)
		return (1);
	while (i < table->nbr_philo)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		pthread_mutex_init(&table->meals, NULL);
		i++;
	}
	pthread_mutex_init(&table->last_meal, NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->death, NULL);
	pthread_mutex_init(&table->time, NULL);
	pthread_mutex_init(&table->end, NULL);
	return (0);
}

void mutex_destroy(t_data *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		pthread_mutex_destroy(&table->meals);
		i++;
	}
	pthread_mutex_destroy(&table->last_meal);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->death);
	pthread_mutex_destroy(&table->time);
	pthread_mutex_destroy(&table->end);
	free(table->fork);
}

void mutex_unlock(t_data *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_unlock(&table->fork[i]);
		i++;
	}
}

int mutex_int_value(pthread_mutex_t *i, int *value)
{
	int get;

	pthread_mutex_lock(i);
	get = *value;
	pthread_mutex_unlock(i);

	return (get);
}

unsigned long mutex_ulong_value(pthread_mutex_t *time, unsigned long *value)
{
	unsigned long get;

	pthread_mutex_lock(time);
	get = *value;
	pthread_mutex_unlock(time);

	return (get);
}