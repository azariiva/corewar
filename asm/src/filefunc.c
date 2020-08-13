#include "asm.h"

int		isrighttype(char *name)
{
	if (!ft_strcmp(name + (ft_strlen(name) - 2), ".s"))
		return (1);
	return (0);
}

char	*new_filename(char *file, char *type)
{
	char	*filenew;

	filenew = (char *)malloc(sizeof(char) * ((ft_strlen(file) - 2) +
	ft_strlen(type)));
	ft_strncpy(filenew, file, ft_strlen(file) - 2);
	ft_strcat(filenew, type);
	return (filenew);
}
