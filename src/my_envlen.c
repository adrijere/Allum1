/*
** my_strlen.c for my_strlen.c in /home/mathon_j/rendu/Piscine-C-Jour_04
**
** Made by Jeremy Mathon
** Login   <mathon_j@epitech.net>
**
** Started on  Thu Oct  3 12:03:18 2013 Jeremy Mathon
** Last update Sun Dec 29 23:34:33 2013 Jérémy MATHON
*/

#include	<stdlib.h>

int	my_envlen(char **tab)
{
  int	a;

  a = 0;
  while (tab[a] != NULL)
      a++;
  return (a);
}
