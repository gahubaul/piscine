#include <unistd.h>
#include <stdlib.h>

int 		print_square(char **tab, int result)
{
	int 	i;
	int 	j;
	char	tmp;

	if (result == -1)
	{
		i = -1;
		while(tab[++i])
		{
			j = -1;
			while(tab[i][++j])
			{
				tmp = (j < 8) ? ' ' : '\n';
				write(1, &tab[i][j], 1);
				write(1, &tmp , 1);
			}
		}
		result = 1;
	}
	return (result);
}