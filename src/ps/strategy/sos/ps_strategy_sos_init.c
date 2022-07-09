/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sos_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:26:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 16:27:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sos.h"

#include <stdint.h>

// TODO: implement

void	ps_strategy_sss_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].sot.item.moves = SIZE_MAX;
	table[index].sot.func = NULL;
	table[index].sot.name = "sos_never_used";
}
