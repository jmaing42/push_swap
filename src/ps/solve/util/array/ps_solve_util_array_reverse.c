#include "ps_solve_internal.h"

void	ps_solve_util_array_reverse(
	t_ps_solve_util_array *self
)
{
	const size_t	to = self->length / 2;
	size_t			i;
	int				tmp;

	i = -1;
	while (++i < to)
	{
		tmp = self->array[self->length - i - 1];
		self->array[self->length - i - 1] = self->array[i];
		self->array[i] = tmp;
	}
}
