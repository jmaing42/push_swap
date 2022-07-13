#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_sa(t_ps_stream *self)
{
	if (
		ps_stream_internal_make_last_parallel_node(self)
		|| ps_stream_internal_append_no_check_swap(
			&self->tail->value.parallel->a
		)
	)
		return (true);
	ps_stream_internal_clear_last(self);
	return (false);
}
