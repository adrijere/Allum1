/*
** my_strncmp.c for my_strncmp.c in /home/mathon_j/rendu/Piscine-C-Jour_06/ex_06
** 
** Made by Jeremy Mathon
** Login   <mathon_j@epitech.net>
** 
** Started on  Mon Oct  7 19:13:34 2013 Jeremy Mathon
** Last update Mon Oct  7 19:24:45 2013 Jeremy Mathon
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
    i++;
  return (s1[i] - s2[i]);
}
