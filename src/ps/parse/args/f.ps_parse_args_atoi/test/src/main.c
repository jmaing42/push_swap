/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:16:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/09 23:13:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_types.h"
#include "ps_parse_args.h"

static t_err	read_file_contents(const char *filename, char **out)
{
	FILE *const		fp = fopen(filename, "rb");
	unsigned long	length;
	bool			error;

	length = 0;
	error = !fp;
	*out = NULL;
	if (!error && fseek(fp, 0, SEEK_END))
		error = true;
	if (!error)
		length = ftell(fp);
	if (!error && fseek(fp, 0, SEEK_SET))
		error = true;
	if (!error)
		*out = malloc(length + 1);
	if (!*out)
		error = true;
	if (!error && fread(*out, 1, length, fp) != length)
		error = true;
	if (fp)
		fclose(fp);
	if (error)
		free(*out);
	(*out)[length] = '\0';
	return (error);
}

int	main(int argc, char **argv)
{
	char	*file;
	char	*line;
	char	*olds;
	int		i;

	if (argc < 2 || read_file_contents(argv[1], &file))
		return (EXIT_FAILURE);
	line = strtok_r(file, "\n", &olds);
	while (line)
	{
		if (ps_parse_args_atoi(line, &i))
		{
			if (puts("invalid") == EOF)
				return (EXIT_FAILURE);
		}
		else
		{
			if (printf("%d\n", i) < 0)
				return (EXIT_FAILURE);
		}
		line = strtok_r(NULL, "\n", &olds);
	}
	free(file);
	return (EXIT_SUCCESS);
}
