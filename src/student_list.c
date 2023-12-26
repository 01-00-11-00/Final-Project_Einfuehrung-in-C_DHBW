#include "student_list.h"
#include "student.h"


bool printAllStudents(StudentList *list)
{
    system("clear");
    

    if (list == NULL || list->head == NULL) {
        printError("Liste ist leer.\n");
        printError("Enter drücken, um fortzufahren\n");
        getchar();    
        return (true);
    }
    
    struct s_student *tmp = list->head;    

    while (tmp->next != NULL)
    {
        student_info_print_one(tmp);
        tmp = tmp->next;
    }
    student_info_print_one(tmp);

    printError("Enter drücken, um fortzufahren\n");
    getchar();    
    return (true);

}

StudentList *student_list_create()
{
    StudentList *list = malloc(sizeof(StudentList));
    list->size = 0;
    list->head = NULL;
    return (list);
}
