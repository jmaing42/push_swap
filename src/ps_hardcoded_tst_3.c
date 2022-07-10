/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_tst_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:25:31 by                   #+#    #+#             */
/*   Updated: 2022/07/10 09:26:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const size_t	g_ps_hardcoded_tst_3_distance = 5;
static const char	*g_ps_hardcoded_tst_3[] = {
	"",
	"\6\3\11",
	"\3",
	"\6\3\11\3",
	"\3\6\3\11",
	"\3\6\3\11\3",
};

void	ps_hardcoded_tst_3(
	const char *const **out_ptr,
	size_t *out_distance
)
{
	*out_ptr = g_ps_hardcoded_tst_3;
	*out_distance = g_ps_hardcoded_tst_3_distance;
}
