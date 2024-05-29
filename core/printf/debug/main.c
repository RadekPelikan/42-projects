#include <stdio.h>
#include <string.h>
#include "../include/ft_printf.h"
#include "../include/ft_printf_helpers.h"

// Size (first digit) determines the entire length of the resolved specifier

// Any flag and size is ignored
void test_printf_percent(void)
{
	printf("TEST: '%45.454%'\n");
}

// slices a string (takes n of chars of the start)
// shifts delimiter for integers, pointers and hex (puts zeros in front if larger than the count of digits)
// precision (float_size) for floats (output n float digit)
// if size is bigger than the float_size, then the rest of the result is filled with spaces or zeros (if is_zero)
// If after the dot isn't any specifier, 
// 0 will be put there, for what ever reason
void test_printf_dot(void)
{
	printf("TEST: '%.4s'\n", "ABCDEFGHIJKLMNO");
	printf("TEST: '%.03s'\n", "ABCDEFGHIJKLMNO");
	printf("TEST: '%.4d'\n", 123456);
	printf("TEST: '%.3d'\n", 456);
	printf("TEST: '%.5d'\n", 456);
	printf("TEST: '%.6u'\n", 456);
	printf("TEST: '%10.3f'\n", 123.123456789);

	char format[] = "TEST: '%10.20p'\n";
	int var = 30;
	printf("TEST: '%10p'\n", &var);
	printf(format, &var);

	char format1[] = "TEST: '%.3'\n";
	int var1 = 30;
	printf(format1, var1);

	char format2[] = "EMTY: '%. hi'\n";
	char var2[] = "Hello";
	printf(format2, var2);
	// '%.0.. hi'
	// Like WHAT?? Why is the zero there??? Whatever....
}

// Adds a single space in front of any number, test it in future
// Ignore for strings, decimal
void test_printf_space(void)
{
	printf("TEST: '%   d'\n", 30);

	char format[] = "TEST: '% p'\n";
	int var = 30;
	printf(format, &var);

	char format1[] = "TEST: '% u'\n";
	int var1 = 30;
	printf(format1, var1);

	char format2[] = "TEST: '% s'\n";
	char var2[] = "hello";
	printf(format2, var2);
}

// Appends 0x to the start of hex numbers
// Ignore for strings, decimal, pointers
void test_printf_hash(void)
{
	printf("TEST: '%#x'\n", 30);
	printf("TEST: '%#X'\n", 30);
	printf("TEST: '%#f'\n", 30.5);
	int ptr = 30;
	printf("TEST: '%p'\n", &ptr);

	char format[] = "TEST: '%#p'\n";
	printf(format, &ptr);

	char format1[] = "TEST: '%#s'\n";
	char var1[] = "hello";
	printf(format1, var1);

	char format2[] = "TEST: '%#c'\n";
	char var2 = 'c';
	printf(format2, var2);

	char format3[] = "TEST: '%#u'\n";
	int var3 = 30;
	printf(format3, var3);
}

// Puts a plus sign in front of the number
// if the number is negative, then the minus is kept
// Ignore for strings, decimal
void test_printf_plus(void)
{
	printf("TEST: '%++i'\n", -30);
	printf("TEST: '%+i'\n", 30);
	printf("TEST: '%+d'\n", -30);
	printf("TEST: '%+d'\n", 30);

	char format[] = "TEST: '%+p'\n";
	int var = 30;
	printf(format, &var);

	char format1[] = "TEST: '%+s'\n";
	char var1[] = "hello";
	printf(format1, var1);

	char format2[] = "TEST: '%+u'\n";
	int var2 = 30;
	printf(format2, var2);
}

// Puts zeros for numbers at the front, filling the size
// for float it fills the rest of float_size with zeros
// for strings it's ignored
void test_printf_zero(void)
{
	printf("TEST: '%00005d'\n", 30);
	printf("TEST: '%00005d'\n", -30);
	printf("TEST: '%0000+5d'\n", 30);
	printf("TEST: '%00005u'\n", 30);
	printf("TEST: '%05x'\n", 30);
	printf("TEST: '%05f'\n", 30.5);
	printf("TEST: '%05.1f'\n", 30.5);
	printf("TEST: '%05.5f'\n", 30.5);

	char format[] = "TEST: '%020p'\n";
	int var = 30;
	printf(format, &var);

	char format1[] = "TEST: '%010s'\n";
	char var1[] = "hello";
	printf(format1, var1);
}

// Padding from right
// if there are multiple '+' and '-' it does not matter
// zero flag is ignored
void test_printf_minus(void)
{
	printf("TEST: '%10s'\n", "hello");
	printf("TEST: '%-10s'\n", "hello");
	printf("TEST: '%10d'\n", 30);
	printf("TEST: '%-10d'\n", 30);
	printf("TEST: '%-++--10d'\n", 30);


	char format[] = "TEST: '%-010d'\n";
	int var = 30;

	printf(format, var);
}
#include <limits.h>

int	main(void)
{
	// test_printf_percent();
	// test_printf_dot();
	// test_printf_space();
	// test_printf_hash();
	// test_printf_plus();
	test_printf_zero();
	// test_printf_minus();

	// If there is any invalid character or sequence of characters after %, then it is ignored and printed as it is
	// char format[] = "'%4'";
	// output: '%4'
	// exept for '.', if there is an invalid character, then there will be zero added
	// char format[] = "'%.55v'";
	// output: '%.0v'
	// char format[] = "'%.'";
	// output: '%.0'
	// char format[] = "'%.";
	// output: '%.0
	// and if there will be an number, then it will be printed as it is
	// char format[] = "'%.5'";
	// output: '%.5'


	///////////////////////////////
	// char format[] = "%. v s '%10s'";
	// char var[] = "hello";

	// // char format[] = "'%u'";
	// // unsigned int var = UINT_MAX;

	// printf("format: '%s' | var: '%s'\n\n", format, var);
	// char *temp = ft_strjoin("PRINTF: \t", format);
	// char *format_preq = ft_strjoin(temp, "\n");
	// free(temp);

	// printf(format_preq, var);

	// printf("\n|||||||||||| DEBUG PART ||||||||||||\n");
	// free(format_preq);
	// temp = ft_strjoin("FT_PRINTF: \t", format);
	// format_preq = ft_strjoin(temp, "\n");
	// free(temp);
	// // ft_printf(format_preq, var);
	// free(format_preq);
	///////////////////////////////

	// ft_printf("%x\n", 48646448);

	int ptr = 4864886;
	ft_printf("'%010x'\n", ptr);
	printf("'%010x'\n", ptr);
}

