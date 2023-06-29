


char *strip_spaces(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (!(i % 2))
			*(str + i / 2) = *(str + i);
		++i;
	}
	++i;
	*(str + i / 2) = *(str + i);
	// ++i;
	*(str + i / 2) = 0;
	return (str);
}

char *char_to_values(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		*(str + i++) -= '0';
	return (str);
}


int str_len(char *str)
{
	int len;

	len = 0;
	while (*(str + len++))
		;
	return (len - 1);
}
