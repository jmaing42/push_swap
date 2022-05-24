/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/25 03:02:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include <stdlib.h>

#include "ft_exit.h"

void	*ft_malloc(size_t size)
{
	void *const	result = malloc(size);

	if (!result)
		ft_exit(EXIT_FAILURE);
	return (result);
}
