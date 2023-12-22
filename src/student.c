#include "../include/student.h"
#include<unistd.h>
// create the student array
bool student_create(struct s_student **student)
{
    struct s_student *tmp = malloc(sizeof(struct s_student)); // allocate storage space
    tmp->nachname = malloc(sizeof(char) * 100);
    if (tmp == NULL || tmp->nachname == NULL) 
        return (false);
  
    tmp->nachname = (char*) malloc(sizeof(char));
    tmp->matrikelnummer = (char*) malloc(sizeof(char));
    *student = tmp;

    return (true);
}


bool    student_program(struct s_student *student)
{
    //student_input(student); //nur zum testen

    int wahl, read, ret_code;

    // loadingScreen();
    while (true)
    {
        system("clear");
        printMenu();
        
        char buf[100]; // use 1/100KB just to be sure
        memset(buf, 0, 100); // clear the buffer before reading

        do
        {
            printf("> ");
            if (!fgets(buf, 100, stdin))
            {
                // reading input failed, give up:
                return 1;
            }

            for(int i = 0; i < 100; i++) {
                printf("%d", buf[i]);
            }

            // have some input, convert it to integer:
            wahl = atoi(buf);
            printf("wahl: %d\n", wahl);
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
                ret_code = number_of_students(student);
                break;
            case 5:
                ret_code = student_info_print_one(student);
            case 6:
                ret_code = student_info_print_all(student);
            case 7:
                ret_code = student_info_write(student);
            case 8:
                ret_code = student_info_read(student);
            case 9: // end program 
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

void    insert_student(struct s_student *head, struct s_student *student)
{   
    /*
    Funktion funktioniert noch nicht. Wenn das Interface steht, kann weitergemacht werden. Insbesondere Studenten einlessen muss vorher implementiert werden.
    
    */
    struct s_student *tmp;

    tmp = head;



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
