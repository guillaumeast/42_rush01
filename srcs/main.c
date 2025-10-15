#include "rush01.h"

int	main(int argc, char **argv)
{
	t_run	run;
	int		*args_int;
	int		i;

	if (argc < 13 || argc > 37 || (argc - 1) % 4 != 0)
	{
		write(2, "Error: invalid args\n", 20);
		return (1);
	}
	run = init_run(argc, argv);
	parse(args_int, argc - 1, run);
}