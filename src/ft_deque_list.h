/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:06:30 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 20:38:51 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_LIST_H
# define FT_DEQUE_LIST_H

# include "ft_deque.h"

t_deque	*new_deque_list(void (*cleaner)(void *));

#endif
