/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:02:44 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/15 12:39:59 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	data_init(char **av, t_data *data)
{
	int	i;
	int	nbr;

	i = 1;
	while (av[i])
	{
		if (!(syntax_check(av[i])))
			return (1);
		nbr = ft_atoi(av[i]);
		if (i == 1 && (nbr > 200 || nbr == 0))
			return (1);
		else if (i == 1)
			data->nbr_philo = nbr;
		else if (i == 2)
			data->time_to_die = nbr;
		else if (i == 3)
			data->time_to_eat = nbr;
		else if (i == 4)
			data->time_to_sleep = nbr;
		else if (i == 5)
			data->nbr_meals = nbr;
		i++;
	}
	return (0);
}

int	philo_init(t_data *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->nbr_philo);
	if (!table->philo)
		return (1);
	mutex_init(table);
	philo_set(table);
	philo_create(table);
	monitor(table);
	philo_join(table);
	return (0);
}

void	philo_set(t_data *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_philo)
	{
		table->philo[i] = (t_philo){0};
		pthread_mutex_init(&table->philo[i].status, NULL);
		table->philo[i].table = table;
		table->philo[i].id = i + 1;
		if (table->philo[i].id - 1 == 0)
		{
			table->philo[i].r_fork = table->nbr_philo - 1;
			table->philo[i].l_fork = table->philo[i].id - 1;
		}
		else
		{
			table->philo[i].r_fork = table->philo[i].id - 1;
			table->philo[i].l_fork = table->philo[i].id - 2;
		}
	}
}

int	philo_create(t_data *table)
{
	int	i;

	i = 0;
	table->start_time = get_time();
	while (i < table->nbr_philo)
	{
		if (pthread_create(&table->philo[i].philo, NULL, (void *)routine,
				&table->philo[i]) != 0)
		{
			printf("pthread create failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	philo_join(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_join(table->philo[i].philo, NULL) != 0)
		{
			printf("join error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
