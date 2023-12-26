#include "student.h"

int     g_line = 24;

void loadingScreen()
{
    int progress = 0;
    const char progressBarChars[] = {'-', '='};

    for (int i = 0; i < 20; i++)
        printf("\n");
    while (progress < 101)
    {
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
    print_middle("|xx|          Studentenverwaltung          |xx|\n", i++);
    print_middle("|xx|                                       |xx|\n", i++);
    print_middle("|xx|\t1 - Studenten anlegen           |xx|\n", i++);    
    print_middle("|xx|\t2 - Studenten finden            |xx|\n", i++);
    print_middle("|xx|\t3 - Studenten löschen           |xx|\n", i++);    
    print_middle("|xx|\t4 - Anzahl Studenten            |xx|\n", i++);
    print_middle("|xx|\t5 - Alle Studenten ausgeben     |xx|\n", i++);
    print_middle("|xx|\t6 - Programm beenden            |xx|\n", i++);
    print_middle("|xx|  >                                    |xx|\n", i++);
    print_middle("|xx*---------------------------------------*xx|\n", i++);
    print_middle("|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n", i++);
    print_middle(".---------------------------------------------.\n", i++);
    print_middle("                |xxxxxxxxxxxxx|\n", i++);
    print_middle("               /xxxxxxxxxxxxxxx\\\n", i++);
    print_middle("              |xxxxxxxxxxxxxxxxx|\n", i++);
    printf("\033[16;38H");
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
