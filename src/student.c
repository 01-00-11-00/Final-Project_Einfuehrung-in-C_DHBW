#include "../include/student.h"

// create the student array
bool student_create(struct s_student *student)
{
    student = malloc(sizeof(struct s_student)); // allocate storage space
    if (!student)
        return (false);
    return (true);
}


bool    student_program(struct s_student *student)
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
                printf("%d\n", number_of_students(student));
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
    struct s_student *tmp;

    while (!student)
    {
        tmp = student;
        student = student->next;
        free(tmp);
    }
}
