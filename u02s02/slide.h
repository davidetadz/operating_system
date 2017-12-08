//
// Created by Davide on 08-Dec-17.
//

#include <sys/types.h>
#include <sys/stat.h>

int stat (const char *path, struct stat *sb);
int lstat (const char *path, struct stat *sb);
int fstat (int fd, struct stat *sb);

struct stat {
    mode_t st_mode; /* file type & mode */
    ino_t st_ino; /* i-node number */
    dev_t st_dev; /* device number */
    dev_t st_rdev; /* device number */
    //...
};

#include <unistd.h>

char *getcwd (char *buf, int size);

int chdir (char *path);

#include <unistd.h>
#include <sys/stat.h>

int mkdir (const char *path, mode_t mode);

int rmdir (const char *path);

#include <dirent.h>


DIR *opendir(
        constchar *filename
);

struct dirent *readdir(
        DIR *dp
);

int closedir(
        DIR *dp
);


struct dirent {
    inot_t d_no;
    char d_name[NAM_MAX + 1];
    //...
};