#include "header.h"

char	*alocpy(char *str)
{
	char	*toret;
	int		i;

	if (!str)
		return (NULL);
	toret = malloc(strlen(str) * sizeof(char) + 1);
	if (!toret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		toret[i] = str[i];
		i++;
	}
	toret[i] = '\0';
	return (toret);
}

void	swap_nodes(t_files *node1, t_files *node2)
{
	t_files *temp;

	if (node1 != NULL && node2 != NULL)
		return ;
	temp = node1;
	node1 = node2;
	node2 = temp;
}

void	print_ls(t_files *folders)
{
	t_files	*temp;

	temp = folders;
	while (temp)
	{
		if (temp->to_print == 1)
			printf("%s", temp->folder);	
		if (temp->next && temp->to_print == 1)
			printf("  ");
		temp = temp->next;
	}
}

void	sort_list(t_files *folders)
{
	t_files *temp;
	t_files *start;

	start = folders;
	while (folders)
	{
		if (folders->next)
		{
			if (strcmp(folders->folder, folders->next->folder) < 0)
			{
				swap_nodes(folders, folders->next);
				folders = start;
			}
			else
				folders = folders->next;
		}
		else
			break ;
	}
}



t_files	*add_node(char *file_name)
{
	t_files *new_node;

	new_node = malloc(sizeof(t_files));
	new_node->folder = alocpy(file_name); 
	new_node->next = NULL;
	if (new_node->folder[0] == '.')
		new_node->to_print = 0;
	else
		new_node->to_print = 1;
	return (new_node);
}

void	simple_ls()
{
	struct dirent *de;
	DIR *dir;
	t_files *folders;
	t_files *temp;

	dir = opendir(".");
	de = readdir(dir);
	if (de)
		folders = add_node(de->d_name);
	temp = folders;
	while (de)
	{	
		de = readdir(dir);
		if (de)
		{
			folders->next = add_node(de->d_name);
			folders = folders->next;
		}
	}
	folders = temp;
	sort_list(folders);
	print_ls(temp);
	closedir(dir);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		return (0);
	}
	else
		simple_ls();
	return (0);
}
