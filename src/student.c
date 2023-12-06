#include "../include/student.h"

// create the student array
bool student_create(struct s_student **student)
{
    struct s_student *tmp = malloc(sizeof(struct s_student)); // allocate storage space
    
    if (tmp == NULL) 
        return (false);
    
    *student = tmp;
    
    return (true);
}


bool    student_program(struct s_student *student)
{
    int wahl, read, ret_code;

    // loadingScreen();
    while (true)
    {
        system("clear");
        printMenu();
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
                ret_code = number_of_students(student);
                break;
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
void    student_destroy(struct s_student **student)
{
    struct s_student *tmp;

    while (!student)
    {
        tmp = *student;
        *student = (*student)->next;
        free(tmp);
        // TODO Free strings 
    }

}

void    student_insert(struct s_student *head, struct s_student *student)
{   
    /*
    Funktion funktioniert noch nicht. Wenn das Interface steht, kann weitergemacht werden. Insbesondere Studenten einlessen muss vorher implementiert werden.
    
    */
    struct s_student *tmp;

    tmp = head;

    printf("HALLO\n");
    printf("%s %s\n", student->nachname, tmp->nachname);


    while (tmp->next != NULL) {
        if (tmp->next->nachname[0] > student->nachname[0]) {
            student->next = tmp->next;
            tmp->next = student;
            return;
        } else {
            tmp = tmp->next;
        }
    }

}