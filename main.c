#include "./include/student.h"
#include "./include/student_list.h"


int main(void)
{
    struct s_student    *head;
    StudentList         *list;
    bool                state;

    list = student_list_create();

    state = true;

    //student_create(&head); // create the student array


    if (student_program(list) == true) // checks if the program is running
    {
        state = false;
    }
    else
        printError("Program Error !\n");
    return (state);
}
