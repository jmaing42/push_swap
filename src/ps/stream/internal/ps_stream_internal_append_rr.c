#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rr(t_ps_stream *self, size_t count)
{
	if (
		ps_stream_internal_make_last_parallel_node(self)
		|| ps_stream_internal_append_no_check_rotate(
			&self->tail->value.parallel->a,
			count
		)
		|| ps_stream_internal_append_no_check_rotate(
			&self->tail->value.parallel->b,
			count
		)
	)
		return (true);
	ps_stream_internal_clear_last(self);
	return (false);
}
