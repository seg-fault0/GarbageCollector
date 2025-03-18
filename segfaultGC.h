#ifndef SFGC_H
# define SFGC_H

# include <stdlib.h>

typedef struct s_gc
{
	void			*buffer;
	struct	s_gc	*next;
}t_gc;

void	*gc_malloc(size_t size);
void	gc_free(void *buffer);
void	gc_free_all(void);

#endif