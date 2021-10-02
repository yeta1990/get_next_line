
//https://stackoverflow.com/a/1643801

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.c"
//#include "get_next_line_rec.c"
#include "get_next_line_utils.c"

int	main()
{
	int fd;
	int	i;

	i = 0;
	fd = open("pepe", O_RDONLY);


// segfault when buffer size = size of lines

/*	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	system("leaks a.out");
return 1;*/
	//	printf("%i", fd);

	printf("%s", get_next_line(fd));

	printf("%s", get_next_line(fd));
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	printf("%s", get_next_line(fd));
	//	printf("%i", fd);
//	get_next_line(fd);	
	printf("%s", get_next_line(fd));


	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
