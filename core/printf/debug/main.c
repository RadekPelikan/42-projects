#include "../include/ft_printf.h"
#include "../include/ft_printf_helpers.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
    char *strs[] = {"Hello", "World", "C!", 0};
	char *result = ft_strnjoin(strs);

	printf("%s", result);
	free(result);

}

int	test_printf_dot(void)
{
	int result = printf("%.3d\n", 3);

	printf("RESULT: %d", result);
	return result;
}
