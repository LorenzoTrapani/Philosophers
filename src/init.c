/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:02:44 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/04 20:21:00 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


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

void philo_init(char **av)
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
		i++;
	}
}