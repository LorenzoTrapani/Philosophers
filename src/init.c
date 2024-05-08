/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:02:44 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/08 16:40:14 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (('0' <= c && c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long int	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * s);
}

bool	syntax_check(char *str)
{
	int	i;

	i = 0;
		
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i != 0 || str[i] == '-')
				return (false);
			else
				i++;
		}
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int data_init(char **av, t_data *data)
{
	int i;
	int nbr;

	i = 1;
	while(av[i])
	{
		if (!(syntax_check(av[i])))
			return (1);
		nbr = ft_atoi(av[i]);
		if (i == 1 && nbr > 200)
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
	int i;

	i = 0;
	mutex_init(table);
	table->philo = malloc (sizeof (t_philo)* table->nbr_philo);
	if (!table->philo)
	{
		write(2, "Error malloc\n", 6);
		return (1);
	}
	while (i < table->nbr_philo)
	{
		table->philo[i] = (t_philo){0};
		table->philo[i].table = table;
		table->philo[i].id = i;
		if(pthread_create(&table->philo[i].philo, NULL, (void *)routine, &table->philo[i]) != 0)
		{
			printf("pthread create failed\n");
			return (1);
		}
		i++;
	}
	
	///monitoring
	i = 0;
	while (i < table->nbr_philo)
	{
		//printf("philo %d\n", i);
		if (pthread_join(table->philo[i].philo, NULL) != 0)
		{
			write(2, "Error join\n", 11);
			return (1);
		}
		i++;
	}
	return (0);
}
