/*
** my_ia.c for my_ia in /home/mathon_j/rendu/Allum1/src
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Tue Feb 11 11:09:51 2014 Jérémy MATHON
** Last update Sun Feb 16 21:32:54 2014 Jérémy MATHON
*/

#include        <unistd.h>
#include        "my.h"

void		check_ia(char **allum, int *lines, char *buffer)
{
  int		a;

  a = 0;
  while (lines[a] <= 0)
    a++;
  lines[a] = lines[a] - 1;
}

int		ia(char **allum, int *lines, char *buffer)
{
  int		cpt;
  int		a;

  my_putstr("\n--------------------");
  my_putstr("\nIt's the turn of I.A.\n");
  a = 0;
  cpt = 0;
  while (a < (my_getnbr(buffer) - 1))
    {
      if ((lines[a] != 0) && (lines[a] <= lines[++a]))
	cpt = a;
      a++;
    }
  if (cpt == 0)
    check_ia(allum, lines, buffer);
 else
    lines[cpt] = lines[cpt] - (lines[cpt] - 1);
  show_map(allum, lines);
  if ((check_winner(lines, buffer) == 1))
    {
      my_putstr("\nI.A. won.\n");
      return (9);
    }
}

void		game2(char **allum, int *lines, char *buffer)
{
  int		a;
  int		b;

  a = 0;
  b = 0;
  while (42)
    {
      a = player(allum, lines, buffer);
      if (a == 8)
	return ;
      b = ia(allum, lines, buffer);
      if (b == 9)
	return ;
    }
}

void		check_map(char **allum, char *buffer)
{
  int		a;
  int		b;
  int		nb_allum;
  int		*lines;

  lines = my_malloc(sizeof(int) * (my_getnbr(buffer) + 1));
  lines[(my_getnbr(buffer))] = '\0';
  a = 0;
  b = 0;
  while (allum[a] != NULL)
    {
      nb_allum = 0;
      while (allum[a][b] != '\0')
	{
	  if (allum[a][b] == '|')
	    nb_allum++;
	  b++;
	}
      lines[a] = nb_allum;
      a++;
      b = 0;
    }
  game2(allum, lines, buffer);
}
