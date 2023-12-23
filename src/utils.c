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
	int i;

	i = 5;
    print_middle(".---------------------------------------------.\n", i++);
    print_middle("|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n", i++);
    print_middle("|xx.---------------------------------------.xx|\n", i++);
    print_middle("|xx|  Herzlich Willkomen bei Student Appp! |xx|\n", i++);
    print_middle("|xx|  Wie kann ich Ihnen Helfen ?          |xx|\n", i++);
    print_middle("|xx|\t1- Neuen User Hinzufuegen.      |xx|\n", i++);    
    print_middle("|xx|\t2- Ein User Loeschen.           |xx|\n", i++);    
    print_middle("|xx|\t3- Print User's Information.    |xx|\n", i++);
    print_middle("|xx|\t4- Number of users.             |xx|\n", i++);
    print_middle("|xx|\t5- Print Student Info.          |xx|\n", i++);
    print_middle("|xx|\t6- Print All Students Info.     |xx|\n", i++);
    print_middle("|xx|\t7- Studend Info Upload.         |xx|\n", i++);
    print_middle("|xx|\t8- Student Info Download.       |xx|\n", i++);
    print_middle("|xx|\t9- Quit.                        |xx|\n", i++);
    print_middle("|xx|  >                                    |xx|\n", i++);
    print_middle("|xx*---------------------------------------*xx|\n", i++);
    print_middle("|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n", i++);
    print_middle(".---------------------------------------------.\n", i++);
    print_middle("                |xxxxxxxxxxxxx|\n", i++);
    print_middle("               /xxxxxxxxxxxxxxx\\\n", i++);
    print_middle("              |xxxxxxxxxxxxxxxxx|\n", i++);
    printf("\033[19;38H");
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
}

bool string_only_space(char *str)
{
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] != ' ')
            return false;
        i++;
    }
    return true;
}

// TODO !
// void go_back()
// {
//     printf("\033[35;45HClick on b if you want to go back to the menu !\n");
//     printf("\33[2K\r");
//     usleep(500000);
// }
