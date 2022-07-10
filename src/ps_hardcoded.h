/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 08:58:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 17:05:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HARDCODED_H

# include <stddef.h>
# include <stdbool.h>

size_t				ps_hardcoded_find_index(const int *arr, size_t len);
void				ps_hardcoded_execute(
						size_t index,
						bool from_right,
						const char *const *table);

void				ps_hardcoded_sxs_1(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_2(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_3(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_4(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_5(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_6(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_7(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_sxs_8(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_1(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_2(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_3(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_4(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_5(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_6(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_7(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tst_8(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_1(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_2(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_3(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_4(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_5(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_6(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_7(
						const char *const **out_ptr,
						size_t *out_distance);
void				ps_hardcoded_tot_8(
						const char *const **out_ptr,
						size_t *out_distance);

const char *const	*ps_hardcoded_tst(size_t count);
const char *const	*ps_hardcoded_tot(size_t count);

#endif
