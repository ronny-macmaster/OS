// cpu.c
// Original source: OSTEP
// Modified and annotated by Ramesh Yerraballi
// CPU virtualization example showing how multiple processes seem to run apparently at the same time
//
// Build as: gcc -o io io.c
// run with ./io
// look at the file /tmp/file 

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

void
dowork()
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd >= 0);
    char buffer[20];
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, strlen(buffer)+1);
    assert(rc == (strlen(buffer) + 1));
    printf("wrote %d bytes\n", rc);
    fsync(fd);
    close(fd);
}

int
main(int argc, char *argv[])
{
    dowork();
    return 0;
}

