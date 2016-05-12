#include "ft_select.h"

int		get_files(int ac, char **av, t_infos *infos)
{
	infos->nbfiles = ac - 1;
	if ((infos->files = make_filelist(av)) != NULL)
	{
		infos->width = get_maxlen(infos);
		return (1);
	}
	return (-1);
}

t_files	*make_filelist(char **av)
{
	t_files *filelist;
	t_files	*ptr;
	t_files *ptr2;
	int		i;

	i = 1;
	if ((filelist = init_list(av[i])) == NULL)
		return (NULL);
	ptr = filelist;
	i++;
	while (av[i])
	{
		ptr2 = malloc(sizeof(t_files));
		ptr2->prev = ptr;
		ptr2->file = av[i];
		ptr2->len = ft_strlen(av[i]);
		ptr2->next = NULL;
		ptr->next = ptr2;
		ptr = ptr->next;
		ptr2 = ptr2->next;
		i++;
	}
	return (filelist);
}

int	make_loop(t_files *list)
{
	t_files *start;
	t_files *end;

	start = list;
	end = list;
	while (end->next)
		end = end->next;
	end->next = start;
	start->prev = end;
	return (1);
}

t_files	*init_list(char *av)
{
	t_files	*filelist;

	if (av == NULL)
		return (NULL);
	filelist = malloc(sizeof(t_files)); //leaks ici apparemment
	filelist->prev = NULL;
	filelist->file = av;
	filelist->len = ft_strlen(av);
	filelist->next = NULL;
	return (filelist);
}

int	get_maxlen(t_infos *infos)
{
	t_files	*ptr;
	int	maxlen;

	maxlen = 0;
	ptr = infos->files;
	while (ptr)
	{
		if (ptr->len + 1 > maxlen)
			maxlen = ptr->len + 1;
		ptr = ptr->next;
	}
	return (maxlen);
}

int		get_filepos(t_infos *infos)
{
	t_files *ptr;
	int		col;
	int		row;

	col = 0;
	row = 0;
	ptr = infos->files;
	while (ptr != NULL)
	{
		ptr->y_pos = row;
		ptr->x_pos = col * infos->width;
		row++;
		if (row >= infos->nb_row)
		{
			col++;
			row = 0;
		}
		ptr = ptr->next;
	}
	return (1);
}
