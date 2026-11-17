#include "header.h"

t_files	*folders

void	store_directory(struct dirent *de, t_files *folders)
{
	
}

void	simple_ls()
{
	struct dirent *de;
	DIR *dir;
	t_files *folders;

	dir = opendir(".");
	de = readdir(dir);
	while (de)
	{
		store_directory(de, folders);
		de = readdir(dir);
	}
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
