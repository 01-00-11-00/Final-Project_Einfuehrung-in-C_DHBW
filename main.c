#include "./include/student.h"

int main(void)
{
    struct s_student student;

    if (student_create(&student) == true)
    {
        if (student_programm(&student) == true)
            printf("Student App dankt Ihnen!\n");
    }
    else
        printError("Internal Error !\n");
    student_destroy(&student);
    return (0);
}