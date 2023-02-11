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

#ifndef C_H
# define C_H

# include <stddef.h>

void	*c_malloc(size_t size);
void	*c_calloc(size_t count, size_t size);
void	*c_realloc(void *ptr, size_t size);
void	c_free(void *ptr);

void	*c_memdup(const void *ptr, size_t size);
void	*c_memcpy(void *dest, const void *source, size_t length);
void	*c_memset(void *buffer, int c, size_t length);
void	c_bzero(void *buffer, size_t length);

#endif
