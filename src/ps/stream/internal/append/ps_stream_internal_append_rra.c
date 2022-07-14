#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rra(t_ps_stream *self, size_t count)
{
	if (
		ps_stream_internal_make_last_node_parallel(self)
		|| ps_stream_internal_make_last_parallel_node_reverse_rotate(
			&self->tail->value.parallel->a
		)
		|| ps_stream_internal_append_no_check_reverse_rotate(
			&self->tail->value.parallel->a,
			count
		)
	)
		return (true);
	ps_stream_internal_clear_last(self);
	return (false);
}
