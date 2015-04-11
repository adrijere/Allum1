/*
** my_strdup.c for my_strdup in /home/mathon_j/rendu/Piscine-C-Jour_08
**
** Made by Jeremy Mathon
** Login   <mathon_j@epitech.net>
**
** Started on  Wed Oct  9 08:49:26 2013 Jeremy Mathon
** Last update Thu Feb 20 14:27:12 2014 Jérémy MATHON
*/

#include	<stdlib.h>
#include	"my.h"

char    **my_strcpie(char **dest, char **src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

char	**my_envdup(char **src)
{
  char	**dest;

  dest = malloc(sizeof(char*) * (my_envlen(src) + 1));
  my_strcpie(dest, src);
  return (dest);
}
