/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:57:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/27 01:58:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# include "push_swap_count.h"

# define OPTION_BAKE_LEVEL "PUSH_SWAP_BAKE_LEVEL="

typedef struct s_push_swap
{
	int						bake_level;
	t_push_swap_count_part	*map;
	t_push_swap_count_item	solution;
}	t_push_swap;

#endif
