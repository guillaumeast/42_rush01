#include "rush01.h"

static void	ft_putnbr_rec(int nbr)
{
	int		mod;
	char	c;

	if (nbr <= -10 || nbr >= 10)
		ft_putnbr_rec(nbr / 10);
	mod = nbr % 10;
	if (mod < 0)
		mod *= -1;
	c = mod + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
		write (1, "-", 1);
	ft_putnbr_rec(nbr);
}
