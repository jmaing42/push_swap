#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rr(t_ps_stream *self, size_t count)
{
	return (
		ps_stream_internal_append_ra(self, count)
		|| ps_stream_internal_append_rb(self, count)
	);
}
