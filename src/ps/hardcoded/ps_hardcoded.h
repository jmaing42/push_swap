
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 01:07:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/13 01:09:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HARDCODED_H
# define PS_HARDCODED_H

# include "ps_stream.h"

size_t				ps_hardcoded_find_index(const int *arr, size_t len);
t_err				ps_hardcoded_execute(
						t_ps_stream *stream,
						size_t index,
						bool from_right,
						const char *const *table);

# define PS_HARDCODED_COUNT_TST 8
# define PS_HARDCODED_COUNT_TSB 8
# define PS_HARDCODED_COUNT_TXT 8
# define PS_HARDCODED_COUNT_TXB 8
# define PS_HARDCODED_COUNT_TOT 8
# define PS_HARDCODED_COUNT_TOS 8
# define PS_HARDCODED_COUNT_TOB 8
# define PS_HARDCODED_COUNT_SSS 8
# define PS_HARDCODED_COUNT_SXS 9
# define PS_HARDCODED_COUNT_SOT 8
# define PS_HARDCODED_COUNT_SOB 8
# define PS_HARDCODED_COUNT_BST 8
# define PS_HARDCODED_COUNT_BSB 8
# define PS_HARDCODED_COUNT_BXT 8
# define PS_HARDCODED_COUNT_BXB 8
# define PS_HARDCODED_COUNT_BOT 8
# define PS_HARDCODED_COUNT_BOS 8
# define PS_HARDCODED_COUNT_BOB 8

const char *const	*ps_hardcoded_tst_table(size_t count);
const char *const	*ps_hardcoded_tsb_table(size_t count);
const char *const	*ps_hardcoded_txt_table(size_t count);
const char *const	*ps_hardcoded_txb_table(size_t count);
const char *const	*ps_hardcoded_tot_table(size_t count);
const char *const	*ps_hardcoded_tos_table(size_t count);
const char *const	*ps_hardcoded_tob_table(size_t count);
const char *const	*ps_hardcoded_sss_table(size_t count);
const char *const	*ps_hardcoded_sxs_table(size_t count);
const char *const	*ps_hardcoded_sot_table(size_t count);
const char *const	*ps_hardcoded_sob_table(size_t count);
const char *const	*ps_hardcoded_bst_table(size_t count);
const char *const	*ps_hardcoded_bsb_table(size_t count);
const char *const	*ps_hardcoded_bxt_table(size_t count);
const char *const	*ps_hardcoded_bxb_table(size_t count);
const char *const	*ps_hardcoded_bot_table(size_t count);
const char *const	*ps_hardcoded_bos_table(size_t count);
const char *const	*ps_hardcoded_bob_table(size_t count);

#endif
