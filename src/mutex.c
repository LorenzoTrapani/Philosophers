/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:32 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/10 13:20:44 by lotrapan         ###   ########.fr       */
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
		i++;
	}
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->meals, NULL);
	pthread_mutex_init(&table->last_meal, NULL);
	pthread_mutex_init(&table->death, NULL);
	return (0);
}

void mutex_destroy(t_data *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->meals);
	pthread_mutex_destroy(&table->last_meal);
	pthread_mutex_destroy(&table->death);
	free(table->fork);
}