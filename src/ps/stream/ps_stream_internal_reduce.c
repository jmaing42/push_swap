#include "ps_stream.h"
#include "ps_stream_internal.h"

#include "ft_size_t.h"

size_t	ps_stream_internal_reduce_push(
	t_ps_stream *self,
	size_t count,
	bool to_b
)
{
	size_t	min;
	if (!self->tail || self->tail->value.type != PS_STREAM_NODE_TYPE_SEPARATOR)
		return (0);

	min = self->tail->value.separator->push_to_right;
	if (to_b)
		min = self->tail->value.separator->push_to_left;
	min = ft_size_t_min(min, count);
	if (to_b)
		self->tail->value.separator->push_to_left -= min;
	else
		self->tail->value.separator->push_to_right -= min;
	ps_stream_internal_clear_last_separator_node(self);
	return (min);
}
