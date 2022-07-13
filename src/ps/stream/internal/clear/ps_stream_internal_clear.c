#include "ps_stream_internal.h"

void	ps_stream_internal_clear(t_ps_stream *self)
{
	while (ps_stream_internal_clear_last(self))
		;
}
