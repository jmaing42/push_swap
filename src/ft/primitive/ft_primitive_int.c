/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitive_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:58:54 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/20 20:32:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_int.h"

void	ft_primitive_int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_primitive_int_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_primitive_int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_primitive_int_if(
	bool condition,
	int value_if_true,
	int value_if_false
)
{
	if (condition)
		return (value_if_true);
	else
		return (value_if_false);
}
