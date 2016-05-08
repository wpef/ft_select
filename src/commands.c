#include "ft_select.h"

int	read_commands(t_term *term, t_infos *infos)
{
	char buf[15];

	read(0, buf, 15);
	ft_putendl(buf);
	return (run_select(term, infos));
}