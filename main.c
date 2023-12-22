#include "./include/student.h"

int main(void)
{
    struct s_student    *head;
    bool                state;

    state = true;

    student_create(&head); // create the student array


    if (student_program(head) == true) // checks if the program is running
    {
        state = false;
    }
    else
        printError("Program Error !\n");
    return (state);
}