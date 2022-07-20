/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 08:56:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pointer.h"

void	ft_pointer_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	*ft_pointer_if(
	bool condition,
	void *value_if_true,
	void *value_if_false
)
{
	if (condition)
		return (value_if_true);
	return (value_if_false);
}
