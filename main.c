#include "student.h"
#include "student_list.h"


int main(void)
{
    StudentList         *list;
    bool                state;

    list = student_list_create();
    state = true;
    if (student_program(list) == true)
        state = false;
    else
        printError("Program Error !\n");
    return (state);
}
