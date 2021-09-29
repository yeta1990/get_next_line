
//https://stackoverflow.com/a/1643801

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	main()
{
	int fd;
	int	i;

	i = 0;
	fd = open("pepe", O_RDONLY);
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	
}
