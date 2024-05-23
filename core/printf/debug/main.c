#include <stdio.h>
#include <string.h>
#include "../include/ft_printf.h"
#include "../include/ft_printf_helpers.h"

int	main(void)
{
	char format[] = "%30...s Test";
	char var[] = "hello";


	printf("format: '%s' | var: '%s'\n", format, var);
	char *temp = ft_strjoin("PRINTF: \t", format);
	char *format_preq = ft_strjoin(temp, "\n");
	free(temp);

	printf(format_preq, var);

	free(format_preq);
	temp = ft_strjoin("FT_PRINTF: \t", format);
	format_preq = ft_strjoin(temp, "\n");
	free(temp);
	ft_printf(format_preq, var);
	free(format_preq);
}

int	test_printf_dot(void)
{
	int result = printf("%.3d\n", 3);

	printf("RESULT: %d", result);
	return result;
}
