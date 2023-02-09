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

#include "ps_parse_args.h"

#include <stdlib.h>
#include <stdbool.h>

static const int	g_test_y_0[] = {0, 1, 2, 3, 4, 5};
static const int	g_test_y_1[] = {5, 4, 3, 2, 1, 0};
static const int	g_test_y_2[] = {-2, -1, 0, 1, 2};
static const int	g_test_y_3[] = {2, 1, 0, -1, -2};
static const int	g_test_y_4[] = {2147483647, 2147483646, 2147483645};
static const int	g_test_y_5[] = {-2147483648, -2147483647, -2147483646};
static const int	g_test_y_6[] = {-2147483648, 2147483647};
static const int	g_test_y_7[] = {999, -2100000000, 42, -42, 0};
static const int	g_test_y_8[] = {0};
static const int	g_test_y_9[] = {-42};

static const int	g_test_n_0[] = {0, 1, 2, 3, 4, 5, 0};
static const int	g_test_n_1[] = {5, 4, 3, 2, 1, 0, 5};
static const int	g_test_n_2[] = {-2, -1, 0, 1, 2, 0};
static const int	g_test_n_3[] = {2, 1, 0, -1, -2, 0};
static const int	g_test_n_4[] = {2147483647, 2147483646, 2147483647};
static const int	g_test_n_5[] = {-2147483648, -2147483647, -2147483648};
static const int	g_test_n_6[] = {-2147483648, -2147483648};
static const int	g_test_n_7[] = {999, -2100000000, 42, -42, 0, 999};
static const int	g_test_n_8[] = {0, 0};
static const int	g_test_n_9[] = {-42, -42};

static void	test(const int *ints, size_t count, bool expect)
{
	if (ps_parse_args_is_uniq(ints, count) != expect)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	test(g_test_y_0, sizeof(g_test_y_0) / sizeof(g_test_y_0[0]), true);
	test(g_test_y_1, sizeof(g_test_y_1) / sizeof(g_test_y_1[0]), true);
	test(g_test_y_2, sizeof(g_test_y_2) / sizeof(g_test_y_2[0]), true);
	test(g_test_y_3, sizeof(g_test_y_3) / sizeof(g_test_y_3[0]), true);
	test(g_test_y_4, sizeof(g_test_y_4) / sizeof(g_test_y_4[0]), true);
	test(g_test_y_5, sizeof(g_test_y_5) / sizeof(g_test_y_5[0]), true);
	test(g_test_y_6, sizeof(g_test_y_6) / sizeof(g_test_y_6[0]), true);
	test(g_test_y_7, sizeof(g_test_y_7) / sizeof(g_test_y_7[0]), true);
	test(g_test_y_8, sizeof(g_test_y_8) / sizeof(g_test_y_8[0]), true);
	test(g_test_y_9, sizeof(g_test_y_9) / sizeof(g_test_y_9[0]), true);
	test(g_test_n_0, sizeof(g_test_n_0) / sizeof(g_test_n_0[0]), false);
	test(g_test_n_1, sizeof(g_test_n_1) / sizeof(g_test_n_1[0]), false);
	test(g_test_n_2, sizeof(g_test_n_2) / sizeof(g_test_n_2[0]), false);
	test(g_test_n_3, sizeof(g_test_n_3) / sizeof(g_test_n_3[0]), false);
	test(g_test_n_4, sizeof(g_test_n_4) / sizeof(g_test_n_4[0]), false);
	test(g_test_n_5, sizeof(g_test_n_5) / sizeof(g_test_n_5[0]), false);
	test(g_test_n_6, sizeof(g_test_n_6) / sizeof(g_test_n_6[0]), false);
	test(g_test_n_7, sizeof(g_test_n_7) / sizeof(g_test_n_7[0]), false);
	test(g_test_n_8, sizeof(g_test_n_8) / sizeof(g_test_n_8[0]), false);
	test(g_test_n_9, sizeof(g_test_n_9) / sizeof(g_test_n_9[0]), false);
	test(NULL, 0, true);
}
