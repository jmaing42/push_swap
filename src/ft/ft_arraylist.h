/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:36:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/28 01:43:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAYLIST_H
# define FT_ARRAYLIST_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_ft_arraylist
{
	size_t	capacity;
	size_t	length;
	void	*data;
	size_t	size_of_item;
}	t_ft_arraylist;

t_err	ft_arraylist_init(
			t_ft_arraylist *self,
			size_t initial_capacity,
			size_t size_of_item);
t_err	ft_arraylist_push(
			t_ft_arraylist *self,
			void *in_item);
bool	ft_arraylist_pop(
			t_ft_arraylist *self,
			void *out_item);
t_err	ft_arraylist_fini(
			t_ft_arraylist *self,
			void (*free_item)(void *));

#endif
