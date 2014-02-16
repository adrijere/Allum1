/*
** my_malloc.c for my_malloc in /home/mathon_j/rendu/MUL_2013_fdf/SRC
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Thu Dec  5 23:55:46 2013 Jérémy MATHON
** Last update Fri Dec  6 00:31:23 2013 Jérémy MATHON
*/

#include	<stdlib.h>

void	my_putchar(char);
int	my_putstr(char*);

void	*my_malloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_putstr("Can't perform malloc");
      my_putchar('\n');
      exit(-1);
    }
  return (ptr);
}
