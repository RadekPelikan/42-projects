/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:33:06 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/14 17:38:53 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s1[i] || s2[i])
	{
		result = s1[i] - s2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}

/*
int	test(int expected, int returned)
{
	return (expected == returned);
}

void	check_values(int i, char *	str1, char *str2)
{
	int expected = strcmp(str1, str2);
	int returned = ft_strcmp(str1, str2);

	printf("Test%02d: ", i);
	if (test(expected, returned))
		printf("Passed\n");
	else
	{
		printf("Failed\t['%s' | '%s']\n", str1, str2);
		printf("\tExpected: %d\n", expected);
		printf("\tReturned: %d\n", returned);
	}
}

int	main()
{
	char *str1;
	char *str2;
	char tests[100][2][50] = {
		{"test1", "test1"},
		{"tes", "test1"},
		{"test1", "tes"},
		{"test2", "test1"},
		{"testA", "tbst~"},
		{"", "tbst~"},
		{"", "tbst~"},
	};
	int len = sizeof(tests) / sizeof(tests[0]);
	int els = sizeof(tests[0]) / sizeof(tests[0][0]);

	for (int i = 0; i < len; i++)
	{
		str1 = tests[i][0];
		str2 = tests[i][1];
		if (!*str1 && !*str2)
			break;
		check_values(i + 1, str1, str2);
	}
	return (0);
}
*/
