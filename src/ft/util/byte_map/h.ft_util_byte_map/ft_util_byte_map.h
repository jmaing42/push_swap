/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BYTE_MAP_H
# define FT_BYTE_MAP_H

# include "ft_types.h"

/**
 * @brief bake map for single set
 *
 * @param map out parameter to get result
 * @param include_null indicate whether include NULL
 * @param set input
 */
void	ft_byte_map(t_byte *map, bool include_null, const t_byte *set);

#endif
