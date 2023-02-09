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

#ifndef C_INTERNAL_H
# define C_INTERNAL_H

# include "c.h"

# include <stddef.h>

# include "ft_types.h"

typedef struct s_c_memory_block
{
	size_t	capacity;
	size_t	size;
	t_byte	actual[];
}	t_c_memory_block;

#endif
