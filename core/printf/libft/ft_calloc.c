/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:31:10 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 19:02:06 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

// int	main(void)
// {
//     size_t nmemb = 5;
//     size_t size = sizeof(int);

//     // Using standard calloc
//     int *standard_calloc_result = (int *)calloc(nmemb, size);
//     if (standard_calloc_result == NULL) {
//         fprintf(stderr, "Standard calloc failed\n");
//         return (1);
//     }

//     printf("Standard calloc result:\n");
//     for (size_t i = 0; i < nmemb; ++i) {
//         printf("%d ", standard_calloc_result[i]);
//     }
//     printf("\n");

//     free(standard_calloc_result);

//     // Using ft_calloc
//     int *ft_calloc_result = (int *)ft_calloc(nmemb, size);
//     if (ft_calloc_result == NULL) {
//         fprintf(stderr, "ft_calloc failed\n");
//         return (1);
//     }

//     printf("ft_calloc result:\n");
//     for (size_t i = 0; i < nmemb; ++i) {
//         printf("%d ", ft_calloc_result[i]);
//     }
//     printf("\n");

//     free(ft_calloc_result);

//     return (0);
// }
