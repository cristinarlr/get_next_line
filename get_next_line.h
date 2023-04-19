#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>

#include <sys/stat.h>

//#define BUFFER_SIZE

char    *get_next_line(int fd);

#endif
