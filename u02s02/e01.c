#include  <sys/types.h>
#include  <sys/stat.h>
#include  <dirent.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

#include  <limits.h>
#include  <errno.h>
#include  <stdarg.h>

#define N 100

int main (
        int argc,
        char *argv[]
)
{
    char name[N];

    if (getcwd (name, N) == NULL)
        fprintf (stderr, "getcwd failed.\n");
    else
        fprintf (stdout, "getcwd: %s\n", name);

    if (chdir(argv[1]) < 0)
        fprintf (stderr, "chdir failed.\n");
    else
        fprintf (stdout, "chdir: changed to %s\n", argv[1]);

    if (getcwd (name, N) == NULL)
        fprintf (stderr, "getcwd failed.\n");
    else
        fprintf (stdout, "getcwd: %s\n", name);

    return (0);
}