/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/mathon_j/rendu/MUL_2013_fdf/SRC
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Thu Dec  5 23:38:17 2013 Jérémy MATHON
** Last update Mon Jan  6 20:01:02 2014 Jérémy MATHON
*/

#include	<stdlib.h>

int    count_words(char *str, char c)
{
  int    i;
  int    j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
        j++;
      i++;
    }
  return (i + 1);
}

int    my_strnlen(char *str, char c)
{
  int    i;

  i = 0;
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	k;
  int	j;
  int	i;
  char	**tab;

  i = 0;
  j = 0;
  tab = malloc(sizeof(char*) * (count_words(str, c) + 1));
  while (str[i])
    {
      k = 0;
      tab[j] =malloc(sizeof(char) * (my_strnlen(str, c) + 1));
      while (str[i] != c && str[i] != '\0')
	tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      if (str[i] != '\0')
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
