#include "rush01.h"

static void	print_content(t_run *run)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (i < run->map.size && run->map.content[i])
	{
		j = 0;
		while (j < run->map.size && run->map.content[i][j])
		{
			if (run->map.content[i][j] == 0)
				write (1, " ", 1);
			else
			{
				c = run->map.content[i][j] + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
}

void	print_map(t_run *run)
{
	if (!run)
		return ;
	else if (!run->map.content)
		write(2, "No map to print\n", 16);
	else
		print_content(run);
}

void	print_args(t_run *run)
{
	char	c;
	size_t	i;

	if (!run)
		return ;
	else if (!run->args.values)
		write(2, "No args to print\n", 17);
	else
	{
		c = run->args.size + '0';
		write(1, "args.size = ", 12);
		write(1, &c, 1);
		write(1, "\n", 1);
		i = 0;
		while (i < run->args.size)
		{
			c = run->args.values[i] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

void	print_run(t_run *run)
{
	if (!run)
		write(2, "No run to print\n", 16);
	else
	{
		write(1, "-------- RUN --------\n", 22);
		print_args(run);
		write(1, "---------------------\n", 22);
		print_map(run);
		write(1, "---------------------\n", 22);
	}
}
