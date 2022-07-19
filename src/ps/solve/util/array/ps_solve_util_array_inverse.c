#include "ps_solve_internal.h"

void	ps_solve_util_array_inverse(
	t_ps_solve_util_array *self
)
{
	size_t	i;

	i = -1;
	while (++i < self->length)
		self->array[i] = ~self->array[i];
}
