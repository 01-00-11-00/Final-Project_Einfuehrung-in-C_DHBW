#include "./include/student.h"

int main(void)
{
    struct s_student    *student;
    bool                state;

    state = true;
    if (student_create(&student) == true) // write the array. Double pointer muss hier verwendet werden!!!
    {
        if (student_program(student) == true) // checks if the program is running
        {
            print_middle("Student App dankt Ihnen!\n", 0);
            state = false;
        }
        else
            printError("Program Error !\n");
    }
    else
        printError("Internal Error !\n");
    student_destroy(&student); // deletes the array
    return (state);
}