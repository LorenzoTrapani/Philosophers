/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/10 22:13:36 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

# define RESET "\033[0m"
# define CYAN "\033[1;36m"   
# define GREEN "\033[1;32m"

# define EAT "is eating 🍝\n"
# define SLEEP "is sleeping 💤\n"
# define THINK "is thinking 💭\n"
# define FORK "has taken a fork 🍴\n"
# define DEAD "is dead 💀\n"

//////////
//STRUCT//
//////////

typedef struct s_philo	t_philo;
typedef struct s_data
{
	int		nbr_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_meals;
	bool	is_ended;
	unsigned long	start_time;
	struct s_philo *philo;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	pthread_mutex_t meals;
	pthread_mutex_t last_meal;
	pthread_mutex_t death;
}	t_data;

struct s_philo
{
	int			id;
	int 		r_fork;
	int			l_fork;
	int			personal_meals;
	int			last_meal;
	bool		is_dead;
	pthread_t	philo;
	t_data		*table;
};

/////////////
//FUNCTIONS//
/////////////

/*-------------------INIT-------------------*/
int				data_init(char **av, t_data *table);
int				philo_init(t_data *table);
void			philo_set(t_data *table);
int				philo_create(t_data *table);
int				philo_join(t_data *table);
/*-------------------ROUTINE-------------------*/
void			*routine(t_philo *philo);
void			philo_print(t_philo *philo, char *action);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
/*-------------------MUTEX-------------------*/
int				mutex_init(t_data *table);
void			mutex_destroy(t_data *table);
/*-------------------UTILS-------------------*/
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
bool			syntax_check(char *str);
void			ft_putstr_fd(char *s, int fd);
/*-------------------TIME-------------------*/
void			ft_usleep(unsigned long ms);
unsigned long	get_time(void);
/*-------------------MONITOR-------------------*/
int				monitor(t_data *table);
bool 			is_full(t_data *table);
bool			is_dead(t_philo *philo);

#endif