/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:37:31 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/16 15:38:19 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_sresult(t_sresult *sresult)
{
	free(sresult->result);
	free(sresult);
}

void	free_seqresult(t_seqresult *seqresult)
{
	free_sresult(seqresult->sresult);
	free(seqresult);
}

void	free_seqresult_keep_str(t_seqresult *seqresult)
{
	free(seqresult->sresult);
	free(seqresult);
}

void	free_fresult(t_fresult *fresult)
{
	free(fresult->result);
	free(fresult);
}
