/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:52:12 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 01:37:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/push_swap_solve_internal.h"

#define MAX_LENGTH 1024

int	main(int argc, char **argv)
{
	int		arr[MAX_LENGTH];
	size_t	i;
	size_t	j;

	if (argc < 1)
		return (EXIT_FAILURE);
	if (argc == 2)
		freopen(argv[2], "r", stdin);
	i = 0;
	while (scanf("%d", &arr[i]) == 1)
		i++;
	push_swap_solve_internal_inverse(arr, i);
	j = 0;
	while (j < i)
	{
		printf("%d\n", arr[j]);
		j++;
	}
}