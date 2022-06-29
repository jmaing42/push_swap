/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:58:38 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/25 19:43:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIZE_T_H
# define FT_SIZE_T_H

# include <stddef.h>
# include <stdbool.h>

size_t	ft_size_t_min(size_t a, size_t b);
size_t	ft_size_t_max(size_t a, size_t b);
size_t	ft_size_t_if(
			bool condition,
			size_t value_if_true,
			size_t value_if_false);

#endif
