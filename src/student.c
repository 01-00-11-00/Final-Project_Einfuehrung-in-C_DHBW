#include "../include/student.h"

bool student_create(struct s_student *student)
{
    student = malloc(sizeof(struct s_student));
    if (!student)
        return (false);
    return (true);
}

bool    student_programm(struct s_student *student)
{
    int wahl, read, ret_code;

    while (true)
    {
        printMenu();
        printf("> ");
        read = scanf("%d", &wahl);
        if (!read)
            return (false);
        switch(wahl)
        {
            case 1:
                ret_code = addUser(student);
                break;
            case 2:
                ret_code = removeUser(student);
                break;
            case 3:
                printList(student);
                break;
            case 4:
                return (true);
            default:
                printError("Falsch eingabe :(\n");
        }
        if (ret_code == false)
            return (false);
    }
    return (true);
}

void    student_destroy(struct s_student *student)
{
    struct s_student *tmp;

    while (!student)
    {
        tmp = student;
        student = student->next;
        free(tmp);
    }
}
