/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer detectors
*/

#include <stdio.h>
#include "../include/prime.h"
#include "../include/my.h"

static void help2(void)
{
    printf(".\n\n\t\033[1m-E\033[0m \033[4mLAST\033[0m, \033[1m--end\033[0m="
    "\033[4mLAST\033[0m\n\t\tCompute prime numbers while they're inferior to "
    "\033[4mLAST\033[0m.\n\n\t\033[1m-F\033[0m \033[4mNUM\033[0m, \033[1m--fin"
    "d\033[0m=\033[4mNUM\033[0m\n\t\tPrint the \033[4mNUM\033[0mth prime numbe"
    "r.\n\n\t\033[1m-S\033[0m \033[4mNUM\033[0m, \033[1m--start\033[0m=\033[4m"
    "NUM\033[0m\n\t\tStart computing at \033[4mNUM\033[0m.\n\n\tAn invalid opt"
    "ion will set it to default.  You can quit the program\n\tby hitting CTRL+"
    "C. The program's calculations are stored in a file,\n\t\033[3mcalculation"
    "s_prime.txt\033[0m,   allowing the program to continue where it\n\tended "
    "when it was last quit (except \033[4m--find\033[0m).\n\n   \033[1mExit st"
    "atus:\033[0m\n\t0\tif the program has reached the  32-bit  integer limit "
    "or\n\t\tthe last requested prime number,\n\t1\tif the  \033[4mNUM\033[0mt"
    "h  prime number couldn't be found within the\n\t\t32-bit integer limit (w"
    "ith \033[1m--find\033[0m),\n\t84\tif an invalid argument was passed to th"
    "e program.\n\n \033[1mPRINTING "
    "FORMAT\033[0m\n\t$>  P-\033[4mn\033[0m:\t  \033[4mvalue\033[0m\n\n "
    "\033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo.\n\n \033[1mREPORTING B"
    "UGS\033[0m\n\tReport any bug or functioning error to <quentin.di-meo@epit"
    "ech.eu>\n\n");
}

int help(void)
{
    printf("\n\tWelcome to prime_computer.\n\n \033[1mUSAGE\033[0m\n\t./prime_"
    "computer [\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\tA prime "
    "number is a number that can only be divided by 1 or itself.\n\tThis progr"
    "am is a prime numbers computer.   This program is limited\n\tto the size "
    "of a 32-bit integer; it will thus stop calculating when\n\tit reaches a p"
    "rime number higher than \033[1m2,147,483,647\033[0m (which will not\n\tbe"
    " printed).\n\n\t\033[1m-d\033[0m \033[4mDIG\033[0m, \033[1m--digits"
    "\033[0m=\033[4mDIG\033[0m\n\t\tCompute the prime numbers until they're "
    "\033[4mDIG\033[0m-digits long.\n\n\t\033[1m-h\033[0m, \033[1m--help"
    "\033[0m\n\t\tDisplay this help.\n\n\t\033[1m--slow\033[0m=\033[4mMS"
    "\033[0m\n\t\tSlow down the program by waiting  \033[4mMS\033[0m  millisec"
    "onds after\n\t\tevery iteration. I'm suggesting 50, the limit is 60,000");
    help2();
    return (SUCCESS);
}

uint adjust(char *optarg, uint val)
{
    for (int i = 0; optarg[i]; i++)
        if (optarg[i] != '0' && val == 0)
            return (MAX);
    return (val);
}

char *is_find_alone(int a)
{
    if (a) {
        my_putstr("-F and --find must be used alone.\n");
        my_putstr("Try './tictactoe --help' for other information.\n");
        return (NULL);
    }
    return ("-");
}

int digits_ok(uint *settings, uint nb)
{
    if (my_strlen(my_itoa(nb)) >= settings[DIGITS])
        return (FALSE);
    return (TRUE);
}
