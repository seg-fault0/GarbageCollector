#include "segfaultGC.h"

t_gc	*add_to_list(void *new)
{
	static t_gc	*start;
	static t_gc	*old;
	static int		first_call;
	t_gc			*new_node;

	if(!new)
		return (start);
	new_node = malloc(sizeof(t_gc));
	new_node->buffer = new;
	if(first_call == 0)
	{
		start = new_node;
		old = new_node;
		first_call = 1;
	}
	else
	{
		old->next = new_node;
		old = old->next;
	}
	return (NULL);
}

void	*gc_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (NULL);
	add_to_list(new);
	return (new);
}

void	gc_free(void *buffer)
{
	t_gc	*start;
	t_gc	*prev;
	t_gc	*current;

	start = add_to_list(NULL);
	prev = NULL;
	current = start;
	while (current)
	{
		if (current->buffer == buffer)
		{
			if (prev)
				prev->next = current->next;
			else
				start = current->next;
			free(current->buffer);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	gc_free_all(void)
{
	t_gc	*start = add_to_list(NULL);
	t_gc	*tmp;
	while(start ->next != NULL)
	{
		tmp = start;
		free(start->buffer);
		start = start->next;
		free(tmp);
	}
	free(start->buffer);
	free(start);
}