#include "../include/ft_printf_helpers.h"


void ft_free_str(char *str)
{
	size_t i;
	size_t len;

	len = ft_strlen(str);
	i = 0;
	while(i < len) {
		free(str + i);
		++i;
	}
}

char *ft_strnjoin(char **strs) {
	size_t i = 0;
	size_t len;
	char *result;
	char *temp;

	len = 0;
	while (strs[len])
		++len;
	result = ft_strjoin(strs[0], strs[1]);
	i = 2;
	while (i < len)
	{
		temp = ft_strjoin(result, strs[i]);
		free(result);
		result = temp;
		++i;
	}
	return result;
}
