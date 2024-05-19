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

char *ft_strnjoin(size_t count, ...) {
	va_list args;
	size_t i = 0;
	char *result;
	char *temp;

	va_start(args, count);
	result = ft_strjoin(va_arg(args, char*), va_arg(args, char*));
	i = 2;
	while (i < count)
	{
		temp = ft_strjoin(result, va_arg(args, char*));
		free(result);
		result = temp;
		++i;
	}

	va_end(args);
	return result;
}