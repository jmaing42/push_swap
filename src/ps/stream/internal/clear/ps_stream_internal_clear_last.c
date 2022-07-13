#include "ps_stream_internal.h"
#include <stdbool.h>

bool	ps_stream_internal_clear_last(t_ps_stream *self)
{
	if (self->tail && ps_stream_internal_clear_last_node(self->tail))
	{
		if (self->tail->prev)
			self->tail->prev->next = NULL;
		else
			self->head = NULL;
		self->tail = self->tail->prev;
		return (true);
	}
	return (false);
}
