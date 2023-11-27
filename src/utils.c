#include "../include/student.h"

void    printError(char *str)
{
    dprintf(2, "%s", str);
}

void    printMenu()
{
    printf("Herzlich Willkom bei Student Appp!\n");
    printf("Wie kann ich Ihnen Helfen ?\n");
    printf("\t1- Neue User Hinzufuegen.\n");
    printf("\t2- Ein User Loeschen.\n");
    printf("\t3- Print User's Information.\n");
    printf("\t4- Quit\n");
}
