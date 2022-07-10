/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_sxs_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:54:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 16:54:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const size_t	g_ps_hardcoded_sxs_3_distance = 2;
static const char	*g_ps_hardcoded_sxs_3[] = {
	"",
	"\3\6",
	"\3",
	"\11",
	"\6",
	"\3\11",
};

void	ps_hardcoded_sxs_3(
	const char *const **out_ptr,
	size_t *out_distance
)
{
	*out_ptr = g_ps_hardcoded_sxs_3;
	*out_distance = g_ps_hardcoded_sxs_3_distance;
}
