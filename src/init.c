/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:02:44 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/05 17:19:57 by lotrapan         ###   ########.fr       */
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

int data_init(char **av, t_philo *philo)
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
			philo->data->nbr_philo = nbr;
		else if (i == 2)
			philo->data->time_to_die = nbr;
		else if (i == 3)
			philo->data->time_to_eat = nbr;
		else if (i == 4)
			philo->data->time_to_sleep = nbr;
		else if (i == 5)
			philo->data->nbr_eat = nbr;
		i++;
	}
	return (0);
}

void	philo_init(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_init(philo->fork, NULL);
	while (i < philo->data->nbr_philo)
	{
		pthread_create(&philo[i].philo, NULL, (void*) routine, &philo[i]);
		pthread_join(philo[i].philo, NULL);
		philo[i].id = i;
		i++;
	}
	pthread_mutex_destroy(philo->fork);
}
