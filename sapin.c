/*
** sapin.c for sapin in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Oct  1 01:21:14 2015 Ronan Boiteau
** Last update Thu Oct  1 03:07:14 2015 Ronan Boiteau
*/

#include <stdio.h>

int	get_columns(int taille)
{
  int	index_taille;
  int	index_lines;
  int	max_lines;
  int	columns;

  columns = 1;
  index_taille = 1;
  while (index_taille < taille)
    {
      max_lines = index_taille + 3;
      index_lines = 1;
      while (index_lines < max_lines)
	{
	  columns = columns + 2;
	  index_lines = index_lines + 1;
	}
      index_taille = index_taille + 1;
      columns = columns - (index_taille / 2) * 2;
    }
  return (columns);
}

void	pied(int taille, int total_max_columns)
{
  int	max_lines;
  int	columns;
  int	index_lines;
  int	index_columns;

  max_lines = taille;
  if (taille % 2 == 1)
    columns = taille;
  else
    columns = taille + 1;
  index_lines = 1;
  while (index_lines <= max_lines)
    {
      index_columns = 1;
      while (index_columns < (total_max_columns - columns + 2) / 2)
	{
	  my_putchar(' ');	      
	  index_columns = index_columns + 1;
	}
      index_columns = 1;
      while (index_columns <= columns)
	{
	  my_putchar('|');
	  index_columns = index_columns + 1;
	}
      my_putchar('\n');
      index_lines = index_lines + 1;
    }
}

void	sapin(int taille)
{
  int	max_lines;
  int	total_max_lines;
  int	max_columns;
  int	total_max_columns;
  int	columns;
  int	index_lines;
  int	index_columns;
  int	index_taille;

  if (taille == 0)
    return ;
  total_max_lines = taille + 3;
  total_max_columns = get_columns(taille) + total_max_lines * 2 - 2;
  index_taille = 1;
  while (index_taille <= taille)
    {
      columns = get_columns(index_taille);
      max_lines = index_taille + 3;
      max_columns = columns * max_lines * 2;
      index_lines = 1;
      while (index_lines <= max_lines)
	{
	  index_columns = 1;
	  while (index_columns < (total_max_columns - columns + 2) / 2)
	    {
	      my_putchar(' ');	      
	      index_columns = index_columns + 1;
	    }
	  index_columns = 1;
	  while (index_columns <= columns && columns <= max_columns)
	    {
	      my_putchar('*');
	      index_columns = index_columns + 1;
	    }	  
	  my_putchar('\n');
	  columns = columns + 2;
	  index_lines = index_lines + 1;
	}
      index_taille = index_taille + 1;
    }
  pied(taille, total_max_columns);
}
