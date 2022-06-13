/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:59:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 00:16:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "ft_malloc.h"

#include "ft_strict_atoi.h"

t_checker_state	*checker_init(size_t count, char **arr_as_string)
{
	t_checker_state *const	result = ft_malloc(sizeof(t_checker_state));
	int *const				a = (int *)ft_malloc(sizeof(int) * count);
	int *const				b = (int *)ft_malloc(sizeof(int) * count);
	size_t					i;
	size_t					j;

	result->a = (t_checker_state_part){a, count, 0, count};
	result->b = (t_checker_state_part){b, count, 0, 0};
	i = -1;
	while (++i < count)
	{
		if (ft_strict_atoi(arr_as_string[i], &a[i]))
			checker_exit("Error: invalid int given.\n");
		j = 0;
		while (j < i)
			if (a[i] == a[j++])
				checker_exit("Error: duplicate number given.\n");
	}
	return (result);
}
