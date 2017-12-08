//
// Created by Davide on 08-Dec-17.
//

#ifndef OPERATING_SYSTEM_U02S02_H
#define OPERATING_SYSTEM_U02S02_H



struct stat {
    mode_t st_mode; /* file type & mode */
    ino_t st_ino; /* i-node number */
    dev_t st_dev; /* device number */
    dev_t st_rdev; /* device number */
    //...
};

#endif //OPERATING_SYSTEM_U02S02_H