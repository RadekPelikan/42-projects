/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:38:26 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/16 15:38:19 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FREE_H
# define FT_PRINTF_FREE_H

# include "ft_printf_types.h"

void	free_sresult(t_sresult *sresult);
void	free_seqresult(t_seqresult *seqresult);
void	free_seqresult_keep_str(t_seqresult *seqresult);
void	free_fresult(t_fresult *fresult);

#endif