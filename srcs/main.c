#include "rush01.h"

int	main(int argc, char **argv)
{
	t_run	*run;
	size_t	i;

	if (argc < 13 || argc > 37 || (argc - 1) % 4 != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	run = new_run(argc, argv);
	run = init_map(run);
	run = resolve_minmax(run);
	i = 1;
	while (run && i < run->map.size - 1)
		run = check_row(run, i++);
	i = 1;
	while (run && i < run->map.size - 1)
		run = check_col(run, i++);
	print_run(run);
	return (0);
}
