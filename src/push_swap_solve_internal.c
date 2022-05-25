/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:48:38 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/25 21:52:27 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <unistd.h>
#include <stdlib.h>

#include "ft_io.h"
#include "ft_exit.h"
#include "ft_size_t.h"

void	rx(size_t a, size_t b)
{
	const size_t	c = ft_size_t_min(a, b);
	size_t			i;

	i = -1;
	while (++i < c)
		if (ft_write(STDOUT_FILENO, "rr\n", 3))
			ft_exit(EXIT_FAILURE);
	i = c - 1;
	while (++i < a)
		if (ft_write(STDOUT_FILENO, "ra\n", 3))
			ft_exit(EXIT_FAILURE);
	i = c - 1;
	while (++i < b)
		if (ft_write(STDOUT_FILENO, "rb\n", 3))
			ft_exit(EXIT_FAILURE);
}

void	rrx(size_t a, size_t b)
{
	const size_t	c = ft_size_t_min(a, b);
	size_t			i;

	i = -1;
	while (++i < c)
		if (ft_write(STDOUT_FILENO, "rrr\n", 4))
			ft_exit(EXIT_FAILURE);
	i = c - 1;
	while (++i < a)
		if (ft_write(STDOUT_FILENO, "rra\n", 4))
			ft_exit(EXIT_FAILURE);
	i = c - 1;
	while (++i < b)
		if (ft_write(STDOUT_FILENO, "rrb\n", 4))
			ft_exit(EXIT_FAILURE);
}

void	sa(void)
{
	if (ft_write(STDOUT_FILENO, "sa\n", 3))
		ft_exit(EXIT_FAILURE);
}

void	sb(void)
{
	if (ft_write(STDOUT_FILENO, "sb\n", 3))
		ft_exit(EXIT_FAILURE);
}

void	px(size_t a, size_t b)
{
	const size_t	c = ft_size_t_min(a, b);
	size_t			i;

	i = c - 1;
	while (++i < a)
		if (ft_write(STDOUT_FILENO, "pa\n", 3))
			ft_exit(EXIT_FAILURE);
	i = c - 1;
	while (++i < b)
		if (ft_write(STDOUT_FILENO, "pb\n", 3))
			ft_exit(EXIT_FAILURE);
}
