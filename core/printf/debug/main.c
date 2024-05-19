#include <stdio.h>
#include <string.h>
#include "../include/ft_printf.h"
#include "../include/ft_printf_helpers.h"

int	main(void)
{

	ft_printf("%.....s", "hello");
}

int	test_printf_dot(void)
{
	int result = printf("%.3d\n", 3);

	printf("RESULT: %d", result);
	return result;
}
