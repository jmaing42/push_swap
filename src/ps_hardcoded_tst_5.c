/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_tst_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:25:31 by                   #+#    #+#             */
/*   Updated: 2022/07/10 09:27:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const size_t	g_ps_hardcoded_tst_5_distance = 12;
static const char	*g_ps_hardcoded_tst_5[] = {
	"",
	"\6\6\6\3\11\11\11",
	"\6\6\3\11\11",
	"\6\6\6\3\11\3\11\11",
	"\6\6\3\6\3\11\11\11",
	"\6\6\3\6\3\11\3\11\11",
	"\6\3\11",
	"\6\2\6\3\1\11\11",
	"\6\6\3\11\3\11",
	"\6\2\2\3\6\1\1\11\11",
	"\6\2\3\6\3\1\11\11",
	"\6\2\2\3\6\1\3\1\11\11",
	"\6\3\6\3\11\11",
	"\6\2\6\3\1\3\11\11",
	"\6\3\6\3\11\3\11",
	"\6\2\2\5\6\1\1\11\11",
	"\6\2\3\6\3\1\3\11\11",
	"\6\2\3\2\5\6\1\1\11\11",
	"\6\3\6\3\6\3\11\11\11",
	"\6\2\6\3\6\1\3\11\11\11",
	"\6\3\2\3\6\3\1\11\11",
	"\6\2\2\5\6\1\3\1\11\11",
	"\6\3\2\3\6\3\1\3\11\11",
	"\6\2\2\5\6\6\1\1\11\11\11",
	"\3",
	"\2\6\10\3\13\1\11",
	"\2\6\3\1\11",
	"\2\6\10\3\13\3\1\11",
	"\2\6\3\10\3\13\1\11",
	"\2\6\3\10\3\13\3\1\11",
	"\6\3\11\3",
	"\2\2\6\3\1\1\11",
	"\2\2\3\6\1\1\11",
	"\2\2\2\3\6\1\1\1\11",
	"\2\2\5\6\5\1\1\11",
	"\2\2\2\3\6\1\3\1\1\11",
	"\2\3\6\3\1\11",
	"\2\2\6\3\1\3\1\11",
	"\2\2\3\6\1\3\1\11",
	"\2\2\2\5\6\1\1\1\11",
	"\2\2\5\6\5\1\3\1\11",
	"\2\2\3\2\5\6\1\1\1\11",
	"\2\3\6\3\10\3\13\1\11",
	"\2\2\6\5\10\1\3\13\1\11",
	"\2\3\2\5\6\5\1\1\11",
	"\2\2\2\5\6\1\3\1\1\11",
	"\2\3\2\5\6\5\1\3\1\11",
	"\2\2\2\5\6\6\1\1\11\1\11",
	"\3\6\3\11",
	"\2\6\6\3\1\11\11",
	"\2\6\3\1\3\11",
	"\2\6\2\3\6\1\1\11\11",
	"\2\6\3\6\3\1\11\11",
	"\2\6\2\3\6\1\3\1\11\11",
	"\3\6\3\11\3",
	"\2\2\6\5\1\1\11",
	"\2\2\5\6\1\1\11",
	"\2\6\10\3\2\13\1\11\1",
	"\2\2\3\6\5\1\1\11",
	"\2\2\2\3\6\1\5\1\1\11",
	"\2\3\6\3\1\3\11",
	"\2\2\6\3\6\1\1\11\11",
	"\2\3\2\5\6\1\1\11",
	"\2\2\2\5\6\1\1\1\3\11",
	"\2\2\5\6\5\6\1\1\11\11",
	"\2\2\2\3\6\6\1\1\1\11\11",
	"\2\3\6\3\6\3\1\11\11",
	"\2\2\6\3\6\1\3\1\11\11",
	"\2\3\2\3\6\5\1\1\11",
	"\2\2\2\5\6\1\5\1\1\11",
	"\2\2\5\6\5\6\1\3\1\11\11",
	"\2\2\2\5\6\6\1\1\1\11\11",
	"\3\6\3\6\3\11\11",
	"\2\6\6\3\1\3\11\11",
	"\2\6\3\6\1\3\11\11",
	"\2\6\2\5\6\1\1\11\11",
	"\2\6\3\6\3\1\3\11\11",
	"\2\6\3\2\5\6\1\1\11\11",
	"\3\2\3\6\3\1\11",
	"\2\2\6\5\1\3\1\11",
	"\2\2\5\6\1\3\1\11",
	"\6\2\2\5\11\5\6\1\1\11",
	"\2\2\3\6\5\1\3\1\11",
	"\2\2\5\2\5\6\1\1\1\11",
	"\3\2\3\6\3\1\3\11",
	"\2\2\6\5\6\1\1\11\11",
	"\2\2\5\6\6\1\1\11\11",
	"\6\2\2\3\11\5\6\1\1\11",
	"\2\2\3\6\5\6\1\1\11\11",
	"\2\2\5\2\5\6\1\1\1\3\11",
	"\2\2\6\6\6\1\1\11\11\11",
	"\2\2\6\3\6\6\1\1\11\11\11",
	"\2\2\2\6\10\1\1\13\1\11",
	"\2\2\2\3\6\10\1\1\13\1\11",
	"\2\2\2\6\10\1\1\12\1\11\11",
	"\2\2\2\5\6\6\1\1\1\3\11\11",
	"\2\6\6\6\1\3\11\11\11",
	"\2\6\6\3\6\1\3\11\11\11",
	"\6\2\2\2\11\5\1\1\1",
	"\2\6\2\5\6\1\3\1\11\11",
	"\6\2\2\2\11\5\1\3\1\1",
	"\2\6\2\5\6\6\1\1\11\11\11",
	"\2\2\6\10\1\3\13\1\11",
	"\2\2\6\3\10\1\3\13\1\11",
	"\2\2\3\6\10\1\3\13\1\11",
	"\6\2\2\3\11\5\6\5\1\1\11",
	"\6\2\2\2\11\5\1\5\1\1",
	"\2\2\5\2\5\6\1\3\1\1\11",
	"\2\2\6\6\10\1\13\1\11\11",
	"\2\2\6\5\6\1\3\1\11\11",
	"\2\2\5\6\6\1\3\1\11\11",
	"\6\2\2\5\11\5\6\5\1\1\11",
	"\2\2\3\6\5\6\1\3\1\11\11",
	"\2\2\5\2\5\6\1\5\1\1\11",
	"\2\2\6\6\6\1\1\3\11\11\11",
	"\2\2\6\5\6\6\1\1\11\11\11",
	"\2\2\5\6\6\6\1\1\11\11\11",
	"\2\2\6\5\2\10\1\1\11\13\1",
	"\2\2\3\6\5\6\6\1\1\11\11\11",
	"\2\2\5\2\3\6\10\1\1\13\1\11",
};

void	ps_hardcoded_tst_5(
	const char *const **out_ptr,
	size_t *out_distance
)
{
	*out_ptr = g_ps_hardcoded_tst_5;
	*out_distance = g_ps_hardcoded_tst_5_distance;
}
