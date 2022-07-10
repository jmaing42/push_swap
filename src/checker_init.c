/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:59:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 17:44:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "ft_malloc.h"

#include "ft_strict_atoi.h"

t_checker_state	*checker_init(size_t count, char **arr_as_string)
{
	t_checker_state *const	result
		= (t_checker_state *)ft_malloc(sizeof(t_checker_state));
	int *const				a = (int *)ft_malloc(sizeof(int) * (count + 1));
	int *const				b = (int *)ft_malloc(sizeof(int) * (count + 1));
	size_t					i;
	size_t					j;

	result->a = (t_checker_state_part){a, count + 1, 0, count};
	result->b = (t_checker_state_part){b, count + 1, 0, 0};
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
