#include "./include/student.h"

int main(void)
{
    struct s_student    *student;
    bool                state;

    state = true;
    if (student_create(student) == true)
    {
        if (student_programm(student) == true)
        {
            printf("Student App dankt Ihnen!\n");
            state = false;
        }
        else
            printError("Programm Error !\n");
    }
    else
        printError("Internal Error !\n");
    student_destroy(student);
    return (state);
}