#include "../include/student.h"

// create the student array
bool student_create(struct s_student **student)
{
    struct s_student *tmp = malloc(sizeof(struct s_student)); // allocate storage space
    tmp->nachname = malloc(sizeof(char) * 100);
    
    if (tmp == NULL || tmp->nachname == NULL) 
        return (false);
    
    *student = tmp;

    return (true);
}

bool    student_program(struct s_student *student)
{
    int wahl, read, ret_code;

    while (true)
    {
        printMenu();
        
        char buf[100]; // use 1/100KB just to be sure

        do
        {
            printf("> ");
            if (!fgets(buf, 100, stdin))
            {
                // reading input failed, give up:
                return 1;
            }
            // have some input, convert it to integer:
            wahl = atoi(buf);
        } while (wahl == 0); // repeat until we got a valid number
        
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
                printf("%d\n", number_of_students(student));
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
void    student_destroy(struct s_student *student)
{
    struct s_student *tmp;

    while (!student)
    {
        tmp = student;
        student = student->next;
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