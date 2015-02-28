/*
** philosophers.h for Philosophes in /home/paasch_j/rendu/PSU_2014_philo/include
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue Feb 17 01:13:05 2015 Johan Paasche
** Last update Sat Feb 28 19:14:38 2015 David Tran
*/

#ifndef		PHILOSOPHERS_H_
# define	PHILOSOPHERS_H_

# include	<unistd.h>
# include	<stdio.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	<SDL/SDL.h>
# include	<fmod.h>

/*
** Number of philosophers, influencing the number of mutexs we gonna have
*/

# define	NB_PHILO	(7)

/*
** Let's introduce a quik funy rule while stopping the game if RICE (X) falls to 0.
*/

# define	RICE		(30)

/*
**	Just for paasch_j
*/

# define	INFINITE_LOOP	(42)


# define	ACTION_TIME	(1)

typedef	char t_bool;

# define	TRUE	(1)
# define	FALSE	(0)

# define	EATING_DISPLAY		"\033[34;01mEATING\033[00m ...   "
# define	SLEEPING_DISPLAY	"\033[35;01mSLEEPING\033[00m ... "
# define	THINKING_DISPLAY	"\033[36;01mTHINKING\033[00m ... "

# define	SLEEPING_MONKEY		"./imgBank/eyes.BMP"
# define	THINKING_MONKEY		"./imgBank/ears.BMP"
# define	EATING_MONKEY		"./imgBank/mouth.BMP"
# define	MUSIC_MONKEY		"./imgBank/Gorillaz.mp3"
/*
** enum of state, we may introduce some other states ...
*/

typedef enum	e_state
{
  EATING = 0,
  SLEEPING,
  THINKING
}		t_state;

/*
** This represents a philosopher
*/

typedef	struct		s_philo
{
  pthread_t		life;
  int			nb;
  t_state		activity;
  int			chopstick;
  pthread_mutex_t	m_chopstick;
  t_bool		restored;
  int			rice;
  char			*name;
  struct s_philo	*r;
  struct s_philo	*l;
  int			clock;
  struct s_allin	*grp;
}			t_philo;

typedef struct		s_allin
{
  t_philo		*philos;
  t_bool		go_out;
  SDL_Rect		positionFond;
  SDL_Surface		*ecran;
  SDL_Surface		*imageDeFond;
  pthread_t		event;
  int			nb_philo;
  int			rice_qty;
  FMOD_SYSTEM		*system;
  FMOD_SOUND		*musique;
  FMOD_RESULT		resultat;
}			t_allin;

void	*make_them_work(void *);
void	*display_state(void *);
void	display_activity(t_state);
void	display_philosopher(t_philo *);

#endif		/* !PHILOSOPHERS_H_ */
