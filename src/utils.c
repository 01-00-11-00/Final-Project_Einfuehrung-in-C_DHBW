#include "../include/student.h"

void    printError(char *str)
{
    dprintf(2, "%s", str);
}

void    printMenu()
{
    printf("Herzlich Willkommen in der bei Student App!\n");
    printf("Wie kann ich Ihnen Helfen ?\n");
    printf("\t1- Neue Studenten Hinzufuegen.\n");
    printf("\t2- Ein Studenten Loeschen.\n");
    printf("\t3- Studenten Informationen ausgeben.\n");
    printf("\t4- Anzahl der Studenten ausgeben.\n");
    printf("\t5- Quit\n");
}

void    printHr()
{
    int i;
    int length;
    i = 0;
    length = 40;
    printf("<");
    while(i < length)
    {
        printf("=");
        i++;
    }
    printf(">\n");
}