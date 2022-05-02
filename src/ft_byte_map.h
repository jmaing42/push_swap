/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:52:10 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 14:54:44 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BYTE_MAP_H
# define FT_BYTE_MAP_H

# include "ft_types.h"

void	ft_byte_map(const t_byte *set, t_byte *map, bool include_null);

#endif
