int	ft_sqrt(int nb)
{
	int	base;
	int	temp;

	base = 1;
	while (++base)
	{
		temp = nb / base;
		if (temp == base && nb % base == 0)
			return (base);
		else if (temp < base)
			return (0);
	}
	return (0);
}

