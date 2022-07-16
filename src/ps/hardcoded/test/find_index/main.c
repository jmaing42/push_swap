/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 01:15:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/17 01:21:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_hardcoded.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	const size_t	length = argc - 1;
	int *const		arr = calloc(length, sizeof(int));
	size_t			i;

	if (!arr)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < length)
		arr[i] = atoi(argv[i + 1]);
	printf("%zu\n", ps_hardcoded_find_index(arr, length));
	free(arr);
	return (EXIT_SUCCESS);
}
