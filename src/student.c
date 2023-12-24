#include "../include/student.h"

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

void import_students(StudentList *list) {
    const char filename[] = "students.csv";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Skip first line
    fscanf(file, "%*[^\n]\n");

    while (!feof(file)) {
        printf("Importiere Studenten...\n");
        struct s_student *student = malloc(sizeof(struct s_student));
        student->nachname = malloc(sizeof(char) * 100);
        student->matrikelnummer = malloc(sizeof(char) * 10);
        fscanf(file, "%[^,],%[^,],%d.%d.%d,%d.%d.%d,%d.%d.%d\n", student->nachname, student->matrikelnummer, &student->geburtsDatum.tag, &student->geburtsDatum.monat, &student->geburtsDatum.jahr, &student->startDatum.tag, &student->startDatum.monat, &student->startDatum.jahr, &student->endDatum.tag, &student->endDatum.monat, &student->endDatum.jahr);
        insert_student(list, student);
        printf("Imported student %s\n", student->nachname);
        student_info_print_one(student);
    }
    fclose(file);
    getchar();
}


bool    student_program( StudentList *list)
{
    int wahl, ret_code;
    struct s_student *student;

    import_students(list);

    while (true)
    {
        system("clear");
        printMenu();
        
        char buf[10]; // use 1/100KB just to be sure
        memset(buf, 0, 10); // clear the buffer before reading

        do
        {     
            if(fgets(buf, 10, stdin) == NULL) // read from stdin 
            { 
                exit(1);
            }
            wahl = atoi(buf);
        } 
        while (wahl == 0); // repeat until we got a valid number
        
        
        switch(wahl)
        {
            case 1:
                ret_code = addUser(list);
                break;
            case 2:
                ret_code = removeUser(list);
                break;
            case 3:
                //ret_code = printList(student);

                break;
            case 4:
                ret_code = number_of_students(list);
                break;
            case 5:
                ret_code = input_student(student);
            case 6:
                ret_code = student_list_print(list);
                printf("Retrun code: %d\n", ret_code);
                break;
            case 7:
                ret_code = student_info_write(student);
                break;
            case 8:
                ret_code = student_info_read(student);
                break;
            case 9: // end program 
                return (true);
            default:
                printError("Eingabe nicht korrekt. :(\n");
        }
        if (ret_code == false) {
            printf("Error\n");
            return (false);
        }
    }
    return (true);
}

// delete the student
void    student_destroy(struct s_student *student)
{
    if (student->nachname)
        free(student->nachname);
    if (student->matrikelnummer)
        free(student->matrikelnummer);       
    
    free(student);
}

void    insert_student(StudentList *list, struct s_student *student)
{   
    // Überprüfen ob die Liste oder der Student leer ist
    if (list == NULL || student == NULL)
        return;
    
    // Überprüfen ob die Liste leer ist
    if (list->head == NULL)
    {
        list->head = student;
        list->size++;
        return;
    }
    
    struct s_student* tmp = list->head;
    
    // Keine Elemente in der Liste
    if (tmp->next == NULL)
    {
        tmp->next = student;
        list->size++;
        return;
    }

    // Letzes Element finden
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    // Hinzufügen
    tmp->next = student;
    list->size++;
    return;
}
