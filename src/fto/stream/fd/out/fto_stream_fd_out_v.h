/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_out_v.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:40:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 08:59:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_FD_OUT_V_H
# define FTO_STREAM_FD_OUT_V_H

# include "fto_stream_fd_out.h"

t_err	fto_stream_fd_out_v_write(
			t_fto_stream_fd_out *self,
			const char *buffer,
			size_t length,
			size_t *wrote_bytes);
void	fto_stream_fd_out_v_unsafe_free(
			t_fto_stream_fd_out *self);

#endif
