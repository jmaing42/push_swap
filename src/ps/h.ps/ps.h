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

#ifndef PS_H
# define PS_H

# include <stddef.h>

typedef struct s_ps_ints
{
	size_t	count;
	int		*ints;
}	t_ps_ints;

typedef enum e_ps_command
{
	PS_NOP,
	PS_PA,
	PS_PB,
	PS_SA,
	PS_SB,
	PS_SS,
	PS_RA,
	PS_RB,
	PS_RR,
	PS_RRA,
	PS_RRB,
	PS_RRR,
}	t_ps_command;

#endif
