#include "ps_solve_internal.h"

void	ps_solve_util_array_sort_as(
	t_ps_solve_util_array *self,
	const int *order_array,
	size_t order_length
)
{
	size_t	i;
	size_t	j;
	size_t	k;
	bool	escape;
	size_t	index;

	index = 0;
	i = -1;
	while (++i < self->length)
	{
		j = -1;
		while (++j < order_length)
		{
			escape = false;
			k = -1;
			while (++k < index && !escape)
				if (self->array[k] == order_array[j])
					escape = true;
			if (escape)
				break ;
			self->array[index++] = order_array[j];
		}
	}
}
