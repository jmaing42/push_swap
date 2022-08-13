/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoded_find_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/ft/test/strict_atoi/main.c
/*   Created: 2022/07/11 21:16:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/16 17:41:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_strict_atoi.h"
=======
/*   Created: 2022/07/10 09:01:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 17:04:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_hardcoded.h"

#include "ft_memory.h"
#include "ft_malloc.h"

size_t	factorial(size_t n)
{
	if (n)
		return (n * factorial(n - 1));
	return (1);
}
>>>>>>> origin/push_swap_test:src/ps_hardcoded_find_index.c

size_t	ps_hardcoded_find_index(const int *arr, size_t len)
{
<<<<<<< HEAD:src/ft/test/strict_atoi/main.c
	char	buffer[1024];
	int		i;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\n]", buffer) != 1)
			break ;
		if (ft_strict_atoi(buffer, &i))
			puts("invalid");
		else
			printf("%d\n", i);
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
=======
	size_t		result;
	size_t		i;

	if (!len)
		return (0);
	result = 0;
	i = -1;
	while (++i < len)
		if (arr[0] > arr[i])
			result++;
	return (
		(result * factorial(len - 1))
		+ ps_hardcoded_find_index(&arr[1], len - 1)
	);
>>>>>>> origin/push_swap_test:src/ps_hardcoded_find_index.c
}
