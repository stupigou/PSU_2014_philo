/*
** main_sound.c for main_sound in /home/tran_0/rendu/PSU_2014_philo
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat Feb 28 23:05:29 2015 David Tran
** Last update Fri Apr  3 17:21:18 2015 David Tran
*/

#include "philosophers.h"

int	init_sound(t_allin *care)
{
  care->music = NULL;
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    return (-1);
  if (!(care->music = Mix_LoadMUS(MUSIC_MONKEY)))
    return (-1);
  if (Mix_PlayMusic(care->music, -1) == -1)
    return (-1);
  return (0);
}

void	init_font(t_allin *care)
{
  TTF_Init();
  care->color.r = 255;
  care->color.g = 255;
  care->color.b = 255;
  care->police = NULL;
  care->police = TTF_OpenFont(WRITE_MONKEY, 100);
}

void	intro_screen(t_allin *care)
{
  care->imageDeFond = SDL_LoadBMP(SMOKE_MONKEY);
  care->background_pos.x = 200;
  care->background_pos.y = 320;
  SDL_BlitSurface(care->imageDeFond, NULL, care->screen,
		  &care->background_pos);
  care->texte = TTF_RenderText_Blended(care->police,
				       "Even Monkeys", care->color);
  care->background_pos.x = 170;
  care->background_pos.y = 100;
  SDL_BlitSurface(care->texte, NULL, care->screen, &care->background_pos);
  care->texte = TTF_RenderText_Blended(care->police,
				       "Can Blow Your Mind", care->color);
  care->background_pos.x = 50;
  care->background_pos.y = 800;
  SDL_BlitSurface(care->texte, NULL, care->screen, &care->background_pos);
  SDL_Flip(care->screen);
  sleep(8);
  SDL_FillRect(care->screen, NULL, 0x000000);
  SDL_Flip(care->screen);
}
