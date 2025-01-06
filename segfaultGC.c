#include "segfaultGC.h"

s_sfgc	*add_to_list(void *new)
{
	static s_sfgc	*start;
	static s_sfgc	*old;
	static int		first_call;
	s_sfgc			*new_node;

	if(!new)
		return (start);
	new_node = malloc(sizeof(s_sfgc));
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

void	*malloc_GC(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (NULL);
	add_to_list(new);
	return (new);
}

void	free_all_GC(void)
{
	s_sfgc	*start = add_to_list(NULL);
	s_sfgc	*tmp;
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