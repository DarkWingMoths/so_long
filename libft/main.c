#include "libft.h"

int	main(void)
{
	char *s;

	s = get_next_line(0);
	free(s);
	return (0);
}
