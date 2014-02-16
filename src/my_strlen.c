/*
** my_strlen.c for my_strlen.c in /home/mathon_j/rendu/Piscine-C-Jour_04
**
** Made by Jeremy Mathon
** Login   <mathon_j@epitech.net>
**
** Started on  Thu Oct  3 12:03:18 2013 Jeremy Mathon
** Last update Sun Dec 22 22:45:44 2013 Jérémy MATHON
*/

int	my_strlen(int *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a++;
  return (a);
}
