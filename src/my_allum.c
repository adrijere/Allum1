/*
** my_allum.c for my_allum in /home/mathon_j/rendu/Allum1/src
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Tue Feb  4 23:59:46 2014 Jérémy MATHON
** Last update Thu Feb 20 14:26:21 2014 Jérémy MATHON
*/

#include	<termios.h>
#include	<unistd.h>
#include	<curses.h>
#include	<term.h>
#include	"my.h"

char    *check_env(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "TERM=", 5) == 0)
	return (env[i] + 5);
      i++;
    }
  return (NULL);
}

int		modify_terminal(struct termios *t)
{
  if (tcgetattr(0, t) == -1)
    return (1);
  t->c_lflag &= ~ECHO;
  t->c_lflag &= ~ICANON;
  if (tcsetattr(0, TCSANOW, t) == -1)
    {
      my_putstr("Error : tcsetattr failed.\n");
      return (1);
    }
}

char		**loop_map(int dec, int i, char **allum)
{
  int		a;
  int		b;

  a = 0;
  b = 0;
  while (dec != -1)
    {
      allum[a] = my_malloc(sizeof(char) * (i + 1));
      allum[a][i] = '\0';
      while (b < i)
	{
	  if (b > dec - 1 && b < (i - dec))
	    allum[a][b] = '|';
	  else
	    allum[a][b] = ' ';
	  b++;
	}
      my_putstr(allum[a]);
      a++;
      b = 0;
      dec--;
      my_putchar('\n');
    }
  return (allum);
}

void		my_game(struct termios *t)
{
  char		buffer[1000000];
  char		**allum;
  int		i;
  int		dec;
  int		cpt;

  cpt = 0;
  while (cpt == 0)
    {
      my_putstr("Number of lines ? (min : 4 / max : 52) ");
      read(0, buffer, 1000000);
      my_putchar('\n');
      if (my_getnbr(buffer) < 4 || my_getnbr(buffer) >= 53)
	my_putstr("The number of lines is not correct.\n");
      else
	cpt = 1;
    }
  allum = my_malloc(sizeof(char*) * (my_getnbr(buffer) + 1));
  allum[(my_getnbr(buffer))] = NULL;
  i = my_getnbr(buffer) + (my_getnbr(buffer) - 1);
  dec = my_getnbr(buffer) - 1;
  allum = loop_map(dec, i, allum);
  check_map(allum, buffer);
}

int		main(int ac, char **av, char **envp)
{
  int		fd;
  char		**env;
  char		*term;
  struct	termios	*t;
  struct	termios *e;

  t = my_malloc(sizeof(struct termios));
  e = my_malloc(sizeof(struct termios));
  tcgetattr(0, e);
  if (envp[0] == NULL)
    {
      my_putstr("Can not display.\n");
      return (1);
    }
  env = my_envdup(envp);
  term = check_env(env);
  if (tgetent(NULL, term) == -1)
    {
      my_putstr("Error : tgetent failed.\n");
      return (1);
    }
  my_game(t);
  tcsetattr(0, TCSANOW, e);
}
