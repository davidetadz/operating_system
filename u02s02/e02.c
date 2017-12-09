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
    struct stat statbuf;
    DIR *dp;
    char fullName[N];
    struct dirent *dirp;
    int i;

    if (argc != 2) {
        fprintf (stderr, "Usage: pgrm <pathname>");
        exit (1);
    }

    if (lstat(argv[1], &statbuf) < 0 ) {
        fprintf (stderr, "Error.\n");
        exit (1);
    }

    if (S_ISDIR(statbuf.st_mode) == 0) {
        fprintf (stderr, "Error.\n");
        exit (1);
    }

    /* Directory */

    if ( (dp = opendir(argv[1])) == NULL) {
        fprintf (stderr, "Error.\n");
        exit (1);
    }

    i = 0;
    while ( (dirp = readdir(dp)) != NULL) {
        sprintf (fullName, "%s/%s", argv[1], dirp->d_name);

        if (lstat(fullName, &statbuf) < 0 ) {
            fprintf (stderr, "Error.\n");
            exit (1);
        }

        if (S_ISDIR(statbuf.st_mode) == 0) {
            fprintf (stdout, "File %d: %s\n", i, fullName);
        } else {
            fprintf (stdout, "Dir  %d: %s\n", i, fullName);
        }
        i++;
    }

    if (closedir(dp) < 0) {
        fprintf (stderr, "Error.\n");
        exit (1);
    }

    return(0);
}