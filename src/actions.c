#include "../include/student.h"

/* Muss ein User zu unsere Linked List hinzufuegen */
bool    addUser(struct s_student *student)
{
    return (true);
}

/* User suchen und Loeschen */
bool    removeUser(struct s_student *student)
{
    return (true);
}

/* Muss Die Informationen Ueber jedes User schreiben */
void    printList(struct s_student *student)
{

}

// return number of students 
int     number_of_students(struct s_student *head) {

    int num_students = 0;
    struct s_student *current_student = head;

    // check if the current student is the last student
    while (current_student != NULL) {
        num_students++;
        current_student = current_student->next;
    }
    
    return num_students;

}