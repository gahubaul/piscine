#include <unistd.h>
#include <stdlib.h>

int			ft_check_y(char **argv, int y, char who)
{
	int		xx;
	int		tmp;

	xx = -1;
	tmp = 0;
	while(argv[y][++xx])
		if (argv[y][xx] == who)
			tmp++;
	return (tmp);
}

int			ft_check_x(char **argv, int x, char who)
{
	int		yy;
	int		tmp;

	yy = -1;
	tmp = 0;
	while(argv[++yy])
		if (argv[yy][x] == who)
			tmp++;
	return (tmp);
}

int			ft_check_block(char **tab, int x, int y, int n)
{
	int		tmp_x;
	int		tmp_y;
	int		tmp_x2;
	int		tmp_y2;
	int 	tmp;

	tmp_x = x - (x % 3);
	tmp_y = y - (y % 3);
	tmp_y2 = tmp_y - 1;
	tmp = 0;
	while (++tmp_y2 < tmp_y + 3)
	{
		tmp_x2 = tmp_x - 1;
		while (++tmp_x2 < tmp_x + 3)
			if (tab[tmp_y2][tmp_x2] == n)
				tmp++;
		tmp_y2++;
	}
	return (tmp);
}

int			ft_check(char **tab)
{
	int		i;
	int 	j;

	i = 0;
	while(tab[++i])
	{
		j = -1;
		while(tab[i][++j])
		{
			if (tab[i][j] != '.' && (tab[i][j] > '9' || tab[i][j] < '1'))
				return (0);
			if (tab[i][j] != '.')
				if ((ft_check_y(tab, j, tab[i][j]) > 1) || 
				 	(ft_check_x(tab, i, tab[i][j]) > 1) || 
					(ft_check_block(tab, i, j, tab[i][j]) > 1))
					return (0);
		}
		if (j != 9)
			return (0);
	}
	return (1);
}

char		**ft_create_tab(char **argv, int i, int j)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 9);
	j = -1;
	while (++j < 9)
	{
		tab[j] = (char *)malloc(sizeof(char) * 9);
		i = -1;
		while (argv[j + 1][++i])
			tab[j][i] = argv[j + 1][i];
		tab[j][9] = '\0';
	}
	return (tab);
}
