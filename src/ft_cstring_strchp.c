/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_strchp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:25:46 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 15:08:06 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#ifdef DEVELOPMENT

# include <stdlib.h>
# include <unistd.h>

# include "ft_io.h"
# include "ft_exit.h"

size_t	ft_strchp(const char *str, char ch)
{
	size_t	result;

	if (!str)
	{
		ft_puts(STDERR_FILENO, "ft_strchp(): wrong parameter given\n", NULL);
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	result = -1;
	while (str[++result])
		if (str[result] == ch)
			break ;
	return (result);
}

size_t	ft_strrchp(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	if (!str)
	{
		ft_puts(STDERR_FILENO, "ft_strrchp(): wrong parameter given\n", NULL);
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	i = -1;
	while (str[++i])
		if (str[i] == ch)
			result = i;
	return (result);
}

size_t	ft_strnchp(const char *str, size_t max_len, char ch)
{
	size_t	result;

	if (!str)
	{
		ft_puts(STDERR_FILENO, "ft_strnchp(): wrong parameter given\n", NULL);
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	result = -1;
	while (++result < max_len && str[result])
		if (str[result] == ch)
			break ;
	return (result);
}

size_t	ft_strnrchp(const char *str, size_t max_len, char ch)
{
	size_t	result;
	size_t	i;

	if (!str)
	{
		ft_puts(STDERR_FILENO, "ft_strnrchp(): wrong parameter given\n", NULL);
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	i = -1;
	while (++i < max_len && str[i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#else

size_t	ft_strchp(const char *str, char ch)
{
	size_t	result;

	result = -1;
	while (str[++result])
		if (str[result] == ch)
			break ;
	return (result);
}

size_t	ft_strrchp(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == ch)
			result = i;
	return (result);
}

size_t	ft_strnchp(const char *str, size_t max_len, char ch)
{
	size_t	result;

	result = -1;
	while (++result < max_len && str[result])
		if (str[result] == ch)
			break ;
	return (result);
}

size_t	ft_strnrchp(const char *str, size_t max_len, char ch)
{
	size_t	result;
	size_t	i;

	i = -1;
	while (++i < max_len && str[i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#endif
