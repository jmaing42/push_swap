/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_sxs_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:54:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 16:54:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const size_t	g_ps_hardcoded_sxs_4_distance = 5;
static const char	*g_ps_hardcoded_sxs_4[] = {
	"",
	"\2\3\6\1",
	"\6\3\11",
	"\11\3",
	"\3\6",
	"\2\3\11\1",
	"\3",
	"\2\3\11\1\11",
	"\6\6\3\6",
	"\11",
	"\11\3\11",
	"\6\3\6\6",
	"\11\3\6\6",
	"\6\3\6",
	"\3\6\6\3\6",
	"\3\11",
	"\6\6",
	"\6\6\3",
	"\6",
	"\6\6\3\11",
	"\6\3",
	"\11\3\6",
	"\3\6\6",
	"\3\6\6\3",
};

void	ps_hardcoded_sxs_4(
	const char *const **out_ptr,
	size_t *out_distance
)
{
	*out_ptr = g_ps_hardcoded_sxs_4;
	*out_distance = g_ps_hardcoded_sxs_4_distance;
}
