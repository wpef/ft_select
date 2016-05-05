#include "ft_select.h"

int get_infos(int ac, char **av, t_infos *files)
{
	files->nbfiles = ac - 1;
	files->args = make_filelist(av);
	//get window_size;
	return (1);
}

t_files	*make_filelist(char **av)
{
	t_files *filelist;
	t_files	*ptr;
	t_files *ptr2;
	int i;

	i = 1;
	filelist = init_list(av[i]);
	ptr = filelist;
	while (av[i])
	{
		i++;
		ptr2 = malloc(sizeof(t_files));
		ptr2->prev = ptr;
		ptr2->file = av[i];
		ptr2->next = NULL;
		ptr->next = ptr2;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	return (filelist);
}

t_files	*init_list(char *av)
{
	t_files	*filelist;
	
	filelist = malloc(sizeof(t_files));
	filelist->prev = NULL;
	filelist->file = av;
	filelist->next = NULL;
	return(filelist);
}
