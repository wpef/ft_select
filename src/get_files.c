/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:02:19 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/20 15:12:29 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			get_files(int ac, char **av, t_infos *infos)
{
	infos->nbfiles = ac - 1;
	if ((infos->files = make_filelist(av)) != NULL)
	{
		infos->width = get_maxlen(infos);
		return (1);
	}
	return (-1);
}

t_files		*make_filelist(char **av)
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
		ptr2->slect = 0;
		ptr2->next = NULL;
		ptr2->type = get_ftype(av[i]);
		ptr->next = ptr2;
		ptr = ptr->next;
		ptr2 = ptr2->next;
		i++;
	}
	return (filelist);
}

int		get_ftype(char *file)
{
	struct stat	*buf;
	int			ftype;

	ftype = 0;
	buf = malloc(sizeof(struct stat));
	if (lstat(file, buf) != -1)
	{
		if (S_ISDIR(buf->st_mode))
			ftype = 1;
		else if (S_ISLNK(buf->st_mode))
			ftype = 2;
	}
	free(buf);
	return (ftype);
}

t_files		*init_list(char *av)
{
	t_files	*filelist;

	if (av == NULL)
		return (NULL);
	filelist = malloc(sizeof(t_files));
	filelist->prev = NULL;
	filelist->file = av;
	filelist->len = ft_strlen(av);
	filelist->type = get_ftype(av);
	filelist->slect = 0;
	filelist->next = NULL;
	filelist->loop = 0;
	return (filelist);
}

int			get_filepos(t_infos *infos)
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
		ptr->col = col + 1;
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
