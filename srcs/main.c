#include "rush01.h"

int	main(int argc, char **argv)
{
	t_run	*run;

	if (argc < 13 || argc > 37 || (argc - 1) % 4 != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	run = new_run(argc, argv);
	run = init_map(run);
	run = solve(run);
	return (0);
}