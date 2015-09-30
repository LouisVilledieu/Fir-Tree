/*
** sapin.c for sapin in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Oct  1 01:21:14 2015 Ronan Boiteau
** Last update Thu Oct  1 01:27:20 2015 Ronan Boiteau
*/

void	sapin(int taille)
{
  int	max_lines;

  max_lines = taille + 3;
  if (taille == 0)
    return ;
  while (max_lines)
    {
      my_putchar('*');
      my_putchar('\n');
      max_lines = max_lines - 1;
    }
}
