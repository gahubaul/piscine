#include <unistd.h>
#include <stdlib.h>

int			ft_check_y(char **argv, int y, char who);
int			ft_check_x(char **argv, int x, char who);
int			ft_check_block(char **tab, int x, int y, int n);
char		**ft_create_tab(char **argv, int i, int j);
int			ft_check(char **tab);
int			ft_resolve(char **tab, int i, int j, int number);
int 		print_square(char **tab, int result);

int			ft_check_resolve(char **tab, int i, int j, int number)
{
	int 	res;

	res = 0;
	res = ft_check_x(tab, i, number + 48);
	res += ft_check_y(tab, j, number + 48);
	res += ft_check_block(tab, i, j, number + 48);
	return (res);
}

int			ft_while(char **tab, int i, int j, int number)
{
	int result;

	while (++number <= 9)
	{
		if (!ft_check_resolve(tab, i, j, number))
		{
			tab[j][i] = number + 48;
			result = ft_resolve(tab, 0, 0, 0);
			if (result == 0)
				tab[j][i] = '.';
			else
				return (result);
		}
	}
	return (0);
}

int			ft_resolve(char **tab, int i, int j, int number)
{
	j = -1;
	while(tab[++j])
	{
		i = -1;
		while(tab[j][++i])
			if (tab[j][i] == '.')
				return (print_square(tab, ft_while(tab, i, j, number)));
	}
	return (-1);
}

int			main(int argc, char **argv)
{
	char 	**tab;
	int 	error;

	if (argc == 10)
	{
		tab = 0;
		if (!(error = ft_check(argv)))
			write(1, "Error\n", 6);
		if (error)
		{
			tab = ft_create_tab(argv, 0, 0);
			if (tab && (!ft_resolve(tab, 0, 0, 0)))
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
