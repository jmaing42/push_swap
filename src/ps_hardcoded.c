/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:40:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 16:46:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_hardcoded.h"

const char *const	*ps_hardcoded_tst(size_t count)
{
	const char *const	*result;
	size_t				dummy;

	result = 0;
	if (count == 1)
		ps_hardcoded_tst_1(&result, &dummy);
	if (count == 2)
		ps_hardcoded_tst_2(&result, &dummy);
	if (count == 3)
		ps_hardcoded_tst_3(&result, &dummy);
	if (count == 4)
		ps_hardcoded_tst_4(&result, &dummy);
	if (count == 5)
		ps_hardcoded_tst_5(&result, &dummy);
	if (count == 6)
		ps_hardcoded_tst_6(&result, &dummy);
	if (count == 7)
		ps_hardcoded_tst_7(&result, &dummy);
	if (count == 8)
		ps_hardcoded_tst_8(&result, &dummy);
	return (result);
}

const char *const	*ps_hardcoded_tot(size_t count)
{
	const char *const	*result;
	size_t				dummy;

	result = 0;
	if (count == 1)
		ps_hardcoded_tot_1(&result, &dummy);
	if (count == 2)
		ps_hardcoded_tot_2(&result, &dummy);
	if (count == 3)
		ps_hardcoded_tot_3(&result, &dummy);
	if (count == 4)
		ps_hardcoded_tot_4(&result, &dummy);
	if (count == 5)
		ps_hardcoded_tot_5(&result, &dummy);
	if (count == 6)
		ps_hardcoded_tot_6(&result, &dummy);
	if (count == 7)
		ps_hardcoded_tot_7(&result, &dummy);
	if (count == 8)
		ps_hardcoded_tot_8(&result, &dummy);
	return (result);
}
