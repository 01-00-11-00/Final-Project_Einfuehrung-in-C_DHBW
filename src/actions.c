#include "../include/student.h"

/* Muss ein User zu unsere Linked List hinzufuegen */
bool    addUser(struct s_student *head)
{  
    struct s_student *new_student = malloc(sizeof(struct s_student)); // allocate storage space

    new_student->nachname = malloc(sizeof(char) * 100);

    new_student->matrikelnummer = malloc(sizeof(char) * 10);

    if (new_student == NULL || new_student->nachname == NULL || new_student->matrikelnummer == NULL) 
        return (false);

    input_student(new_student);

    printf("Student wurde angelegt: %s\n", new_student->nachname);  
    
    // printError("User wurde hinzugefuegt.\n");

    head->next = new_student;
    
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

bool    nachname_is_set         (struct s_student *s)
{
    /*
    if(s->nachname)
    {
        return 1;
    }
    */
    return false;
}
bool    matrikelnummer_is_set   (struct s_student *s)
{
    if(s->matrikelnummer)
    {
        return 1;
    }
    return false;
}

bool s_datum_is_Set             (struct s_datum d)
{
    return d.jahr
    && d.monat
    && d.tag
    ;
}

bool    start_datum_is_set       (struct s_student* s)
{
    if(s_datum_is_Set(s->startDatum))
    {
        return 1;
    }
    return false;
}
bool    end_datum_is_set         (struct s_student* s)
{
    if(s_datum_is_Set(s->endDatum))
    {
        return 1;
    }
    return false;
}
bool    geburtsdatum_is_set     (struct s_student* s)
{
    if(s_datum_is_Set(s->geburtsDatum))
    {
        return 1;
    }
    return false;
}

/*bool next_is_Set(struct s_student s)
{
    if(**s.next)
    {
        return 1;
    }
    return false;
}*/

//Check ob alle Werte des Studenten gesetzt sind
bool    all_values_set          (struct s_student *s)
{
    return nachname_is_set(s)
        && matrikelnummer_is_set(s)

        //TODO: Reihenfolge Datum überprüfen (geburt < start < end)
        && start_datum_is_set(s)
        && end_datum_is_set(s)
        && geburtsdatum_is_set(s)
        //& next_is_Set(s)
    ;
}

struct s_datum setdatum (char *info){ //Info beinhaltet Grund des Datums
    printf("%s%s",info, " eingeben: ");
    struct s_datum d;

    char input[10];

    // Einlesen der Daten für den Tag
    printf("Tag (1 - 31): ");
    fgets(input, sizeof(input), stdin);
    d.tag = atoi(input) > 0 && atoi(input) <= 31 ? atoi(input) : 0;

    // Einlesen der Daten für den Monat
    printf("Monat (1-12): ");
    fgets(input, sizeof(input), stdin);
    d.monat = atoi(input) > 0 && atoi(input) <= 12 ? atoi(input) : 0;

    // Einlesen der Daten für das Jahr
    printf("Jahr (> 0): ");
    fgets(input, sizeof(input), stdin);
    d.jahr = atoi(input) > 0 ? atoi(input) : 0;

    return d;
}

// Eingabe der Daten eines Studenten
// Leerer Student wird übergeben, befüllt und dann returned
void input_student  (struct s_student* s)
{   
        printf("Neuen Studenten anlegen \n");
        
        if(!nachname_is_set(s)) // nur leere Werte erneut einlesen
        {
            printf("Nachname: ");
            fgets(s->nachname, 100, stdin);
        }
        
        if(!matrikelnummer_is_set(s))
        {
            printf("Matrikelnummer: ");
            fgets(s->matrikelnummer, 10, stdin);

        }
        if(!start_datum_is_set(s))
        {
            s->startDatum = setdatum("Start Datum");
        }
        if(!end_datum_is_set(s))
        {
            s->endDatum = setdatum("End Datum");
        }
        if(!geburtsdatum_is_set(s))
        {
            s->geburtsDatum = setdatum("Geburtsdatum");
        }
        
}