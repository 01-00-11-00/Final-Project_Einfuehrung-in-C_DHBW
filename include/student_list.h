#pragma once
#include <stdbool.h>

struct s_student_list
{
    int size;
    struct s_student *head;
};

typedef struct s_student_list StudentList;


StudentList *student_list_create();
void student_list_destroy(StudentList *list);
bool student_list_print(StudentList *list);