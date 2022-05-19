/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:43:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 15:52:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strict_atoi.h"

#include <limits.h>

t_err	ft_strict_atoi(const char *str, int *out)
{
	int	sgn;
	int	result;

	result = 0;
	sgn = 1;
	if (*str == '-')
	{
		str++;
		sgn = -1;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9')
			|| result > INT_MAX / 10 || result < INT_MIN / 10
			|| (result == INT_MAX / 10
				&& (*str++ - '0') > (INT_MAX % 10))
			|| (result == INT_MIN / 10
				&& (*str++ - '0') < (INT_MAX % 10)))
			return (true);
		result = result * 10 + (*str++ - '0') * sgn;
	}
	*out = result;
	return (false);
}
