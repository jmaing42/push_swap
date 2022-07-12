/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_find_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:01:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/13 01:11:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_hardcoded.h"

size_t	factorial(size_t n)
{
	if (n)
		return (n * factorial(n - 1));
	return (1);
}

size_t	ps_hardcoded_find_index(const int *arr, size_t len)
{
	size_t		result;
	size_t		i;

	if (!len)
		return (0);
	result = 0;
	i = -1;
	while (++i < len)
		if (arr[0] > arr[i])
			result++;
	return (
		(result * factorial(len - 1))
		+ ps_hardcoded_find_index(&arr[1], len - 1)
	);
}
