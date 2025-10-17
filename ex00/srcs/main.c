#include "rush01.h"

int	print_error();

int	main(int argc, char **argv)
{
	t_run	*run;

	if (argc != 2)
		return (print_error());
	run = malloc(sizeof(t_run));
	if (!run)
		return (print_error());
	run->args = get_args(argv[1]);
	if (!run->args)
		return (print_error());
	// print_args(run->args);
	run->map = init_map(run);
	if (!run->map)
		return (print_error());
	// print_map(run->map);
	solve(run);
	if (run->map->is_complete)
		print_map(run->map);
	else
		print_error();
	free_run(&run);
	return (0);
}

int	print_error()
{
	write(2, "Error\n", 6);
	return (1);
}
