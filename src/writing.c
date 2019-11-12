/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer writing functions
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../include/prime.h"
#include "../include/my.h"

static void writing_result(int fd, char *nth, char *nb)
{
    lseek(fd, 0, SEEK_END);
    write(fd, "  P-", 4);
    write(fd, nth, my_strlen(nth));
    write(fd, ":\t", 2);
    if (my_strlen(nth) < 3)
        write(fd, "\t", 1);
    write(fd, nb, my_strlen(nb));
    write(fd, "\n", 1);
}

uint write_result(uint nth, uint nb, int id, uint *settings)
{
    int fd = EOF;
    char *n_th = NULL;
    char *number = NULL;

    if (!settings[STORE] && settings[SILENT] && !settings[FIND])
        return (++nth);
    if (settings[STORE])
        fd = open("calculations_prime.txt", O_CREAT | O_WRONLY);
    n_th = my_utoa(++nth);
    number = my_utoa(nb);
    fchmod(fd, 0666);
    if (!id) {
        if (!settings[SILENT] || settings[FIND])
            printf("  P-%d:\t%c%d\n", nth, nth > 99 ? '\0' : '\t', nb);
        if (settings[STORE])
            writing_result(fd, n_th, number);
    }
    free(n_th);
    free(number);
    close(fd);
    return (nth);
}
