/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:08:29 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 22:35:08 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stddef.h>

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *mem, size_t len);
void	*ft_memset(void *mem, int value, size_t len);
void	ft_memcpy(void *dest, const void *source, size_t size);

#endif
