
//https://stackoverflow.com/a/1643801

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	main()
{
//	printf("%i", BUFFER_SIZE);
	int fd;
	int	i;

	i = 0;
	fd = open("pepe", O_RDONLY);
//	printf("%lu\n", sizeof(fd));
//	printf("%lu\n", sizeof("sq100"));
//	while (fd)
//	{
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
//		i++;
//	}		
	
}
