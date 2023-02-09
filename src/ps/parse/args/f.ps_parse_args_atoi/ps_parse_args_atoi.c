/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_args_atoi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/09 22:41:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_parse_args.h"

#include <limits.h>

#include "ft_types.h"

t_err	ps_parse_args_atoi(const char *str, int *out)
{
	int	sgn;
	int	result;

	if (!str[0]
		|| (str[0] == '-' && !str[1])
		|| (str[0] == '-' && str[1] == '0')
		|| (str[0] == '0' && str[1]))
		return (true);
	result = 0;
	sgn = 1;
	if (*str == '-' && *str++)
		sgn = -1;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9')
			|| result > INT_MAX / 10 || result < INT_MIN / 10
			|| (result == INT_MAX / 10
				&& (*str - '0') > (INT_MAX % 10))
			|| (result == INT_MIN / 10
				&& (*str - '0') > -(INT_MIN % 10)))
			return (true);
		result = result * 10 + (*str++ - '0') * sgn;
	}
	*out = result;
	return (false);
}
