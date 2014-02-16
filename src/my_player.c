/*
** my_player.c for my_player in /home/mathon_j/rendu/Allum1/src
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Feb 14 18:14:15 2014 Jérémy MATHON
** Last update Sun Feb 16 21:05:42 2014 Jérémy MATHON
*/

#include	<unistd.h>
#include	"my.h"

int		check_winner(int *lines, char *buffer)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = lines[i] + lines[i + 1];
  i = 1;
  while (i < (my_getnbr(buffer) - 1))
    {
      cpt = cpt + lines[i + 1];
      i++;
    }
  if (cpt == 1)
    return (1);
  return (0);
}

char		**comparaison(char **allum, int *lines, int a, int b)
{
  int		cpt_allum;

  cpt_allum = 0;
  while (allum[a][b] != '\0')
    {
      if (allum[a][b] == '|')
	cpt_allum++;
      b++;
    }
  if (cpt_allum > lines[a])
    {
      b = 0;
      while ((allum[a][b] != '\0') && (cpt_allum != lines[a]))
	{
	  if (allum[a][b] == '|')
	    {
	      allum[a][b] = ' ';
	      cpt_allum--;
	    }
	  b++;
	}
    }
  return (allum);
}

void		show_map(char **allum, int *lines)
{
  int		a;
  int		b;

  a = 0;
  while (allum[a] != NULL)
    {
      b = 0;
      allum = comparaison(allum, lines, a, b);
      my_putstr(allum[a]);
      a++;
      my_putchar('\n');
    }
}

int		result(int *lines, char *buffer)
{
  if ((check_winner(lines, buffer) == 1))
    {
      my_putstr("\nPlayer won.\n");
      return (8);
    }
}

int		player(char **allum, int *lines, char *tab)
{
  int		nb_allum;
  int		nb_line;
  char		buffer[3];
  int		cpt;

  cpt = 0;
  my_putstr("\n--------------------");
  my_putstr("\n It's YOUR turn.\n");
  while (cpt == 0)
    {
      my_putstr("\nHow many matches do you wanna remove ?\n");
      read(0, buffer, 3);
      nb_allum = my_getnbr(buffer);
      my_putstr("Which line ?\n");
      read(0, buffer, 3);
      nb_line = my_getnbr(buffer);
      if ((lines[(nb_line - 1)] >= nb_allum) &&
	  (nb_allum >= 1 && nb_allum <= 103))
	{
	  lines[(nb_line - 1)] = lines[(nb_line - 1)] - nb_allum;
	  cpt++;
	}
    }
  show_map(allum, lines);
  result(lines, tab);
}
