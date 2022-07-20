/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 08:56:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINTER_H

# include <stdbool.h>

void	ft_pointer_swap(void **a, void **b);
void	*ft_pointer_if(
			bool condition,
			void *value_if_true,
			void *value_if_false);

#endif
