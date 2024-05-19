#include "../include/ft_printf.h"
#include "../include/ft_printf_helpers.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// ft_printf("%d", 5, 5);
	char *result = ft_strnjoin(5,"Hello", "My", "Name", "is", "Govaci");

	printf("%s", result);
	free(result);

}

int	test_printf_dot(void)
{
	int result = printf("%.3d\n", 3);

	printf("RESULT: %d", result);
	return result;
}
