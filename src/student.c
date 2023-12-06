#include "../include/student.h"

// create the student array
bool student_create(struct s_student *student)
{
    memset(student, 0, sizeof(student));
    student->nachName = strdup("mouad");
    student->next = NULL;
    if (!student)
        return (false);
    return (true);
}


bool    student_program(struct s_student *student)
{
    int wahl, read, ret_code;

    loadingScreen();
    while (true)
    {
        system("clear");
        printMenu();
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
                ret_code = number_of_students(student);
                break;
            case 5: // end program 
                return (true);
            default:
                printError("Eingabe nicht korrekt. :(\n");
        }
        if (ret_code == false)
            return (false);
    }
    return (true);
}

// delete the student
void    student_destroy(struct s_student *student)
{
    // struct s_student *tmp;

    // while (!student)
    // {
    //     tmp = student;
    //     student = student->next;
    //     free(tmp);
    // }
}
