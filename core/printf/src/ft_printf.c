

#include "../include/ft_printf_helpers.h"

// Returns how many charaters has it printed, excluding null byte
// If function encounters an error a negative value is returned
int	ft_printf(const char *format, ...)
{
	// ft_string_format(format);
	ft_putstr(format);
	return (0);
}

// Returns a formatted string
char	*ft_string_format(const char *format, ...)
{
	char *result;
	va_list args;
	size_t i = 0;

	printf("%s\n", format);
	va_start(args, format);
	result = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			// ft_print_specifier(format + i, &args);
			printf("HEllo");
		}
		else
		{
			printf("HEllo");
		}
		++i;
	}

	va_end(args);
	return (result);
}