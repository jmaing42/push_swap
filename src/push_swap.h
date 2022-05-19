/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:57:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 15:56:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# include "ft_types.h"

# define OPTION_BAKE_LEVEL "PUSH_SWAP_BAKE_LEVEL="

typedef struct s_push_swap
{
	int		bake_level;
	size_t	args_length;
	int		*args;
}	t_push_swap;

t_err	push_swap_init(t_push_swap *self, int argc, char **argv, char **envp);

#endif
