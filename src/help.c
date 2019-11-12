/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer help
*/

#include <stdio.h>
#include "../include/prime.h"
#include "../include/my.h"

static void help2(void)
{
    printf("d\033[0m=\033[4mNUM\033[0m\n\t\tFind and print the  \033[4mNUM"
    "\033[0mth  prime number. Using this will\n\t\tdeny all other parameter."
    "\n\n\t\033[1m-S\033[0m \033[4mNUM\033[0m, \033[1m--start\033[0m=\033[4m"
    "NUM\033[0m\n\t\tStart computing at \033[4mNUM\033[0m.\n\n\tAn invalid opt"
    "ion will set it to default.  You can quit the program\n\tby hitting CTRL+"
    "C.\n\n   \033[1mExit st"
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
    printf("\n\tWelcome to prime_computer.\n\n \033[1mUSAGE\033[0m\n\t"
    "./prime_computer [\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\t"
    "A prime number is a number that can only be divided by 1 or itself.\n\t"
    "This program is a prime numbers computer.   This program is limited\n\t"
    "to the size of a 32-bit integer; it will thus stop calculating when\n\t"
    "it reaches a prime number higher than \033[1m2,147,483,647\033[0m "
    "(which will not\n\tbe printed).\n\n\t\033[1m-d\033[0m \033[4mDIG\033[0m, "
    "\033[1m--digits\033[0m=\033[4mDIG\033[0m\n\t\tCompute the prime numbers "
    "until they're \033[4mDIG\033[0m-digits long.\n\n\t\033[1m-h\033[0m, "
    "\033[1m--help\033[0m\n\t\tDisplay this help.\n\n\t\033[1m--silent\033[0m\n\t\tMake it so the program doesn't display what it finds.\n\n\t\033[1m--slow\033[0m="
    "\033[4mMS\033[0m\n\t\tSlow down the program by waiting  \033[4mMS\033[0m "
    "milliseconds after\n\t\tevery iteration. I'm suggesting 50, "
    "the limit is 60,000.\n\n\t\033[1m--store\033[0m\n\t\tMake the program store the results it finds in  a  file,\n\t\t\033[3mcalculation"
    "s_prime.txt\033[0m, allowing the program to continue\n\t\twhere  it ended"
    " when it was last quit.  Be  careful,  it\n\t\tgrows exponentially fast in size (155KB for results from\n\t\t0 to 9,999).\n\n\t\033[1m-u\033[0m \033[4mNUM\033[0m, \033[1m"
    "--until\033[0m=\033[4mNUM\033[0m\n\t\tCompute prime numbers until the "
    "\033[4mNUM\033[0mth prime number.\n\n\t\033[1m-E\033[0m \033[4mNUM"
    "\033[0m, \033[1m--end\033[0m=\033[4mNUM\033[0m\n\t\tCompute prime "
    "numbers while they're inferior to \033[4mNUM\033[0m.\n\n\t\033[1m-F"
    "\033[0m \033[4mNUM\033[0m, \033[1m--fin");
    help2();
    return (SUCCESS);
}
