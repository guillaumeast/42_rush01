#include "rush01.h"

int	main(int argc, char **argv)
{
	t_run	*run;

	if (argc < 13 || argc > 37 || (argc - 1) % 4 != 0)
	{
		write(2, "Error: invalid args\n", 20);
		return (1);
	}
	run = new_run(argc, argv);
	print_run(run);
	printf("DEBUG: before init_map\n");
	run = init_map(run);
	printf("DEBUG: after init_map\n\n");
	print_run(run);
}