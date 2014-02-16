/*
** my.h for my in /home/mathon_j/rendu/Piscine-C-include
** 
** Made by Jeremy Mathon
** Login   <mathon_j@epitech.net>
** 
** Started on  Thu Oct 10 10:50:32 2013 Jeremy Mathon
** Last update Sun Feb 16 21:06:10 2014 Jérémy MATHON
*/

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src, char *src2);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_upper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	**my_envdup(char **src);
char	my_envlen(char **str);
char	**my_str_to_wordtab(char *str, char c);
char	*check_env(char **);
void	exec_command(char *, char **, char **);
void    dump_argv(char **argv);
char	**my_strdup(char **src);
void	*my_malloc(size_t size);
void	check_map(char **, char *);
int	player(char **, int *, char *);
int	ia(char **, int *, char *);
int	check_winner(int *, char *);
char	**comparaison(char **, int *, int, int);
