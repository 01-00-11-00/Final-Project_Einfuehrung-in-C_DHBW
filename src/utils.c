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
        printf("\033[%d;30H%s", g_line++, str);
}

void    printMenu()
{
    print_middle("Herzlich Willkom bei Student Appp!\n", 8);
    print_middle("Wie kann ich Ihnen Helfen ?\n", 9);
    print_middle("\t1- Neue User Hinzufuegen.\n", 10);    
    print_middle("\t2- Ein User Loeschen.\n", 11);    
    print_middle("\t3- Print User's Information.\n", 11);
    print_middle("\t4- Number of users\n", 12);
    print_middle("\t5- Quit\n", 13);
    print_middle("> ", 14);
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
