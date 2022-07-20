/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_const_pointer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 08:56:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONST_POINTER_H

# include <stdbool.h>

void		ft_const_pointer_swap(const void **a, const void **b);
const void	*ft_const_pointer_if(
				bool condition,
				const void *value_if_true,
				const void *value_if_false);

#endif
