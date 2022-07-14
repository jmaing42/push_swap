#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rrr(t_ps_stream *self, size_t count)
{
	return (
		ps_stream_internal_append_rra(self, count)
		|| ps_stream_internal_append_rrb(self, count)
	);
}
