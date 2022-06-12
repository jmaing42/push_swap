/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:18:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/12 18:36:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TO_LINES_H
# define FT_TO_LINES_H

# include "ft_stringbuilder.h"

typedef struct s_ft_to_lines {
	t_stringbuilder	*current;
	const char		*pending;
	size_t			pending_offset;
	size_t			pending_length;
}	t_ft_to_lines;

t_err	ft_to_lines(
			t_ft_to_lines *context,
			const void *append,
			size_t append_length,
			char **out_line);

char	*ft_to_lines_end(t_ft_to_lines *context);
void	ft_to_lines_end_without_last_line(t_ft_to_lines *context);

#endif
