#include "../include/student.h"

char *trim_string(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while( isspace((unsigned char) *frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
    }

    if( frontp != str && endp == frontp )
            *str = '\0';
    else if( str + len - 1 != endp )
            *(endp + 1) = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }

    return str;
}


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

void import_students(StudentList *list)
{
    const char      *filename = "students.csv";
    FILE            *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }
    printf("Importiere Studenten...\n");
    fscanf(file, "%*[^\n]\n");
    while (!feof(file)) {
        struct s_student *student = malloc(sizeof(struct s_student));
        student->nachname = malloc(sizeof(char) * 100);
        student->matrikelnummer = malloc(sizeof(char) * 10);
        fscanf(file, "%[^,],%[^,],%d.%d.%d,%d.%d.%d,%d.%d.%d\n", student->nachname, student->matrikelnummer, &student->geburtsDatum.tag, &student->geburtsDatum.monat, &student->geburtsDatum.jahr, &student->startDatum.tag, &student->startDatum.monat, &student->startDatum.jahr, &student->endDatum.tag, &student->endDatum.monat, &student->endDatum.jahr);
        insert_student(list, student);
        
        printf("Imported student %s\n", student->nachname);
        student->matrikelnummer =  trim_string(student->matrikelnummer);
        // student_info_print_one(student);
    }
    fclose(file);
    getchar();
}

int export_students(StudentList *list)
{
    const char          *filename = "students_export.csv";
    FILE                *file = fopen(filename, "w");
    struct s_student    *tmp = list->head;

    system("clear");
    if (file == NULL) {
        printf("Datei konnte nicht geöffnet werden %s\n", filename);
        return false;
    }
    fprintf(file, "Nachname,Matrikelnummer,Geburtsdatum,Startdatum,Enddatum\n");
    while (tmp != NULL) {
        fprintf(file, "%s,%s,%d.%d.%d,%d.%d.%d,%d.%d.%d\n", tmp->nachname, tmp->matrikelnummer, tmp->geburtsDatum.tag, tmp->geburtsDatum.monat, tmp->geburtsDatum.jahr, tmp->startDatum.tag, tmp->startDatum.monat, tmp->startDatum.jahr, tmp->endDatum.tag, tmp->endDatum.monat, tmp->endDatum.jahr);
        tmp = tmp->next;
    }
    fclose(file);
    return true;
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
                ret_code = addStudent(list);
                break;
            case 2:
                ret_code = printStudent(list);
                break;
            case 3:
                ret_code = deleteStudent(list);
                break;
            case 4:
                ret_code = number_of_students(list);
                break;
            case 5:
                ret_code = printAllStudents(list);
                break;
            case 6: // end program
                ret_code = export_students(list);
                system("clear");
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
