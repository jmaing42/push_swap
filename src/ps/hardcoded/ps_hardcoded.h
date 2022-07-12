/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 01:07:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/13 01:09:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HARDCODED_H
# define PS_HARDCODED_H

# include "ps_stream.h"

size_t	ps_hardcoded_find_index(const int *arr, size_t len);
void	ps_hardcoded_execute(
			t_ps_stream *stream,
			size_t index,
			bool from_right,
			const char *const *table);

#endif
