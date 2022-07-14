#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_ss(t_ps_stream *self)
{
	return (
		ps_stream_internal_append_sa(self)
		|| ps_stream_internal_append_sb(self)
	);
}
