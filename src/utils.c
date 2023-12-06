#include "../include/student.h"

void loadingScreen()
{
    int progress = 0;
    const char progressBarChars[] = {'-', '='};

    for (int i = 0; i < 20; i++)
        printf("\n");
    while (progress < 101)
    {
        system("clear");
        printf("Loading: %3d%% [", progress);

        for (int i = 0; i < progress / 2; i++)
            printf("%c", progressBarChars[1]);

        for (int i = progress / 2; i < 50; i++)
            printf("%c", progressBarChars[0]);
        
        printf("]\r");
        fflush(stdout);
        usleep(50000);
        progress++;
    }
    system("clear");
    sleep(1);
}

void    print_middle(char *str, int line)
{
    if (line != 0)
        printf("\033[%d;30H%s", line, str);
    else
        printf("\033[%d;42H%s", g_line++, str);
}

void    printMenu()
{
    print_middle(".---------------------------------------------.\n", 5);
    print_middle("|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n", 6);
    print_middle("|xx.---------------------------------------.xx|\n", 7);
    print_middle("|xx|  Herzlich Willkom bei Student Appp!   |xx|\n", 8);
    print_middle("|xx|  Wie kann ich Ihnen Helfen ?          |xx|\n", 9);
    print_middle("|xx|\t1- Neue User Hinzufuegen.       |xx|\n", 10);    
    print_middle("|xx|\t2- Ein User Loeschen.           |xx|\n", 11);    
    print_middle("|xx|\t3- Print User's Information.    |xx|\n", 12);
    print_middle("|xx|\t4- Number of users.             |xx|\n", 13);
    print_middle("|xx|\t5- Quit.                        |xx|\n", 14);
    print_middle("|xx|  >                                    |xx|\n", 15);
    print_middle("|xx*---------------------------------------*xx|\n", 16);
    print_middle("|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n", 17);
    print_middle(".---------------------------------------------.\n", 18);
    print_middle("                |xxxxxxxxxxxxx|\n", 19);
    print_middle("               /xxxxxxxxxxxxxxx\\\n", 20);
    print_middle("              |xxxxxxxxxxxxxxxxx|\n", 21);
    printf("\033[15;38H");
}

void    chomp(char *s)
{
    while (*s && *s != '\n' && *s != '\r')
        s++;
    *s = '\0';
}

void    getString(char *buf, char *prompt, int len)
{
    printf("%s", prompt);
    fgets(buf, len, stdin);
    chomp(buf);
}

void    printError(char *str)
{
    dprintf(2, "%s", str);
}
 
// void    printHr()
// {
//     int i;
//     int length;
//     i = 0;
//     length = 40;
//     printf("<");
//     while(i < length)
//     {
//         printf("=");
//         i++;
//     }
//     printf(">\n");
// }
