#ifndef SFGC_H
# define SFGC_H

# include <stdlib.h>

typedef struct s_sfgc
{
	void			*buffer;
	struct	s_sfgc	*next;
}s_sfgc;

void	*malloc_GC(size_t size);
void	free_all_GC(void);

#endif