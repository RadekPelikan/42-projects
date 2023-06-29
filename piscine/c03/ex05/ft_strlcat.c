/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:52:28 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 13:42:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	while (dest[i])
		i++;
	len = 0;
	while (src[len])
		len++;
	if (size <= i)
		len += size;
	else
		len += i;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}

/*
int	test(char *expected, char *returned)
{
	for (int i = 0; expected[i]; i++)
		if (expected[i] != returned[i])
			return (0);
	return (1);
}

void	check_values(int i, char *str1, char *str2, unsigned int n)
{
	char expected[50];
	int a = strlcat(strcpy(expected, str1), str2, n);
	char returned[50];
	int b = ft_strlcat(strcpy(returned, str1), str2, n);

	printf("Test%02d: ", i);
	if (a == b && test(expected, returned))
		printf("Passed\n");
	else
	{
		printf("Failed\t['%s' | '%s' | %i]\n", str1, str2, n);
		printf("\tExpected: %i %s \n", a, expected);
		printf("\tReturned: %i %s \n", b, returned);
	}
}

int	main()
{
	// check_values(1, "aaa", "a", 5);
	// return 0 ;
	char *str1;
	char *str2;
	unsigned int counter = 1;
	char tests[100][2][50] = {
		{"aaa", "a"},
		{"aaa", "ab"},
		{"a", "aaa"},
		{"aaa", ""},
	};
	int len = sizeof(tests) / sizeof(tests[0]);
	// int els = sizeof(tests[0]) / sizeof(tests[0][0]);

	for (unsigned int n = 0; n <= 20; n++)
		for (int i = 0; i < len; i++)
		{
			str1 = tests[i][0];
			str2 = tests[i][1];
			if (!*str1 && !*str2)
				break;
			check_values(counter++, str1, str2, n);
		}
	return (0);
}
*/
