#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_pb(t_ps_stream *self, size_t count)
{
	if (
		ps_stream_internal_make_last_separator_node(self)
		|| ps_stream_internal_append_no_check_push_to_b(self, count)
	)
		return (true);
	ps_stream_internal_clear_last(self);
	return (false);
}
