#include "ps_stream_internal.h"

#include "ft_size_t.h"

void	ps_stream_internal_append_no_check_push_to_a(
	t_ps_stream *self,
	size_t count
)
{
	count = ft_size_t_min(count, self->b);
	self->tail->value.separator->pa += count;
	self->b -= count;
	self->a += count;
}
