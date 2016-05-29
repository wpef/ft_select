#include "ft_select.h"

int	has_no_next(t_files *ptr, char *pos, t_infos *infos)
{
	if (ft_strcmp("ri", pos) == 0)
	{
		if ((ptr->col == (infos->nb_col - 1)) && (ptr->y_pos > infos->files->prev->y_pos))
			return (1);
		if (ptr->x_pos + ptr->len >= infos->ws_col - infos->width)
			return (2);
	}
	else if (ft_strcmp("do", pos) == 0)
	{
		if (ptr->y_pos == infos->nb_row)
			return (1);
		else if (ft_strcmp(ptr->file, infos->files->file) == 0)
			return (1);
	}
	else if (ft_strcmp("le", pos) == 0)
	{
		if (ptr->x_pos == 0)
		{
			if (ptr->y_pos > infos->files->prev->y_pos)
				return (2);
			return (1);
		}
	}
	else if (ft_strcmp("up", pos) == 0)
	{
		if (ptr->y_pos == 0)
			return (1);
	}
	return (0);
}

/*
** NOTE FOR FREE NODE
** **************************
** !!!!! TO BE USED AFTER LOOP !!!!!!
** **************************
** file must be a pointer to 
** a node of infos->files
** **************************
*/
int	free_node(t_files *file, t_infos *infos)
{
	t_files	*ptr;

	ptr = infos->files;
	while (ft_strcmp(file->file, ptr->file) != 0)
		ptr = ptr->next;
	if (ft_strcmp(infos->files->file, file->file) == 0)
		infos->files = infos->files->next;
	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	free(ptr);
	return(1);
}
