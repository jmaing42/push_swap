#include "ps_stream_internal.h"

#include "ft_size_t.h"

void	ps_stream_internal_append_no_check_push_to_a(
	t_ps_stream *self,
	size_t count
)
{
	count = ft_size_t_min(count, self->a);
	self->tail->value.separator->pb += count;
	self->a -= count;
	self->b += count;
}
