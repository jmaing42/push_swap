/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_tot_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:25:31 by                   #+#    #+#             */
/*   Updated: 2022/07/10 09:26:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const size_t	g_ps_hardcoded_tot_3_distance = 6;
static const char	*g_ps_hardcoded_tot_3[] = {
	"\2\7\2\2\4\12",
	"\2\7\2\2\12",
	"\2\10\2\13\2",
	"\2\2\4\2",
	"\2\2\2\4",
	"\2\2\2",
};

void	ps_hardcoded_tot_3(
	const char *const **out_ptr,
	size_t *out_distance
)
{
	*out_ptr = g_ps_hardcoded_tot_3;
	*out_distance = g_ps_hardcoded_tot_3_distance;
}
