#include "rush01.h"

static t_args	*init_args();
static int		count_words(char *str);
static int		*get_values(char *str, int start, size_t res_size);

t_args	*get_args(char *str)
{
	t_args	*args;
	size_t	size;
	int		arg_count;

	args = init_args();
	if (!args)
		return (NULL);
	arg_count = count_words(str);
	if (arg_count % 4 != 0)
	{
		free_args(&args);
		return (NULL);
	}
	size = (size_t) arg_count / 4;
	args->map_size = size;
	args->colup = get_values(str, 0, size);
	args->coldown = get_values(str, (int) size * 2, size);
	args->rowleft = get_values(str, (int) size * 4, size);
	args->rowright = get_values(str, (int) size * 6, size);
	if (!args->colup || !args->coldown || !args->rowleft || !args->rowright)
	{
		free_args(&args);
		return (NULL);
	}
	return (args);
}

static t_args	*init_args()
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->colup = NULL;
	args->coldown = NULL;
	args->rowleft = NULL;
	args->rowright = NULL;
	args->map_size = 0;
	return (args);
}

static int	count_words(char *str)
{
	int	i;
	int	count;
	t_bool in_word;

	i = 0;
	count = 0;
	in_word = FALSE;
	while (str[i])
	{
		if (!in_word && str[i] != ' ')
		{
			count++;
			in_word = TRUE;
		}
		else if (in_word && str[i] == ' ')
			in_word = FALSE;
		i++;
	}
	return (count);
}

static int	*get_values(char *str, int start, size_t res_size)
{
	int		*res;
	size_t	i;
	size_t	j;

	res = malloc(res_size * sizeof(int));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (j < res_size)
	{
		if (str[i] != ' ' && (str[i] < '0' || str[i] > ((int) res_size) + '0'))
		{
			free (res);
			return (NULL);
		}
		if (str[i] != ' ')
			res[j++] = str[i] - '0';
		i++;
	}
	return (res);
}

void	free_args(t_args **args)
{
	if (!args || !*args)
		return ;
	if ((*args)->colup)
		free((*args)->colup);
	if ((*args)->coldown)
		free((*args)->coldown);
	if ((*args)->rowleft)
		free((*args)->rowleft);
	if ((*args)->rowright)
		free((*args)->rowright);
	free(*args);
	*args = NULL;
}
