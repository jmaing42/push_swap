/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_sxs_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:54:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 16:54:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const size_t	g_ps_hardcoded_sxs_2_distance = 1;
static const char	*g_ps_hardcoded_sxs_2[] = {
	"",
	"\6",
};

void	ps_hardcoded_sxs_2(
	const char *const **out_ptr,
	size_t *out_distance
)
{
	*out_ptr = g_ps_hardcoded_sxs_2;
	*out_distance = g_ps_hardcoded_sxs_2_distance;
}
