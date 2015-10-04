/*
** sapin.c for sapin in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Oct  1 01:21:14 2015 Ronan Boiteau
** Last update Sun Oct  4 15:02:15 2015 Ronan Boiteau
*/

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

void	pied(int taille, int total_max_columns, int max_lines, int index_lines)
{
  int	columns;
  int	index_columns;

  if (taille % 2 == 1)
    columns = taille;
  else
    columns = taille + 1;
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

int	put_sapin(int total_max_columns, int columns, int max_columns)
{
  int	index_columns;

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
  return (columns + 2);
}

void	sapin(int taille)
{
  int	max_lines;
  int	total_max_lines;
  int	columns;
  int	index_lines;
  int	index_taille;

  if (taille == 0)
    return ;
  total_max_lines = taille + 3;
  index_taille = 1;
  while (index_taille <= taille)
    {
      columns = get_columns(index_taille);
      max_lines = index_taille + 3;
      index_lines = 1;
      while (index_lines <= max_lines)
	{
	  columns = put_sapin(get_columns(taille) + total_max_lines * 2 - 2,
			      columns, columns * max_lines * 2);
	  index_lines = index_lines + 1;
	}
      index_taille = index_taille + 1;
    }
  pied(taille, get_columns(taille) + total_max_lines * 2 - 2, taille, 1);
}
