#include "../include/student.h"


static void    chomp_local(char *s)
{
    while (*s && *s != '\n' && *s != '\r')
        s++;
    *s = '\0';
}

static void    getString_local(char *buf, int len)
{
    fgets(buf, len, stdin);
    chomp_local(buf);
}

int     student_info_print_one(struct s_student *student)
{
    return (true);
}

int     student_info_print_all(struct s_student *student)
{
    return (true);
}

int     student_info_write(struct s_student *student)
{
    return (true);
}

int     student_info_read(struct s_student *student)
{
    return (true);
}


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
bool removeUser(struct s_student *student)
{
    return (true);
}

/* Muss Die Informationen Ueber jedes User schreiben */
void printList(struct s_student *student)
{

}

// return number of students
int number_of_students(struct s_student *head)
{

    int num_students = 0;
    struct s_student *current_student = head;

    // check if the current student is the last student
    while (current_student != NULL)
    {
        num_students++;
        current_student = current_student->next;
    }

    return num_students;
}

bool nachName_is_Set(struct s_student *s)
{

    if (s->nachname[0] == '\0'
    || string_only_space(s->nachname))


bool matrikelnummer_is_Set(struct s_student *s)
{
    //printf("%p\n",s->matrikelnummer); //test
    if (s->matrikelnummer[0] == '\0'
    || string_only_space(s->matrikelnummer))
=======
    */
    return false;
}


bool s_datum_is_Set(struct s_datum d)
{
    return d.jahr && d.monat && d.tag;
}

bool date_is_same_or_later(struct s_datum d1, struct s_datum d2)
        // d1 muss größer sein als d2, da die Daten in folgender Reihenfolge sein müssen:
        // Geburtstag, Startdatum, Enddatum (können natürlich auch alle an einem Tag sein, wenn jemand nen 1000er iq hat)
{
    if(d1.jahr >  d2.jahr
    || d1.jahr == d2.jahr && d1.monat >  d2.monat
    || d1.jahr == d2.jahr && d1.monat == d2.monat && d1.tag > d2.tag)

    {
        return 0;
    }
    return 1;

bool startDatum_is_Set(struct s_student *s)
{
    if (s_datum_is_Set(s->startDatum)
    && date_is_same_or_later(s->geburtsDatum, s-> startDatum)) //gebdate vor startdate

    {
        return 1;
    }
    return 0;
}


bool endDatum_is_Set(struct s_student *s)
{
    if (s_datum_is_Set(s->endDatum)
    && date_is_same_or_later(s->startDatum, s->endDatum)) //startdate vor enddate

    {
        return 1;
    }
    return 0;
}
  
bool geburtsDatum_is_Set(struct s_student *s)
{
    if (s_datum_is_Set(s->geburtsDatum))
    {
        return 1;
    }
    return false;
}

// Check, ob alle Werte des Studenten gesetzt sind
bool All_values_Set(struct s_student *s)
{
    return nachName_is_Set(s)
    && matrikelnummer_is_Set(s)

    && startDatum_is_Set(s)
    && endDatum_is_Set(s)
    && geburtsDatum_is_Set(s);
}

struct s_datum setdatum(char *info) { //Info beinhaltet Grund des Datums
    printf("%s%s", info, " eingeben:\n\n");

    struct s_datum d;

    char input[10]; // Max 10 Zeichen für input -> Max mögliche Jahreszahl = 9999999999

    // Einlesen der Daten für den Tag
    printf("Tag (1 - 31): ");
    fgets(input, sizeof(input), stdin);
    d.tag = atoi(input) > 0 && atoi(input) <= 31 ? atoi(input) : 0;
    if(!d.tag)
        return d;

    // Einlesen der Daten für den Monat
    printf("Monat (1-12): ");
    fgets(input, sizeof(input), stdin);
    d.monat = atoi(input) > 0 && atoi(input) <= 12 ? atoi(input) : 0;
    if(!d.monat)
        return d;

    // Einlesen der Daten für das Jahr
    printf("Jahr (> 0): ");
    fgets(input, sizeof(input), stdin);
    d.jahr = atoi(input);// > 0 ? atoi(input) : 0;
    if(!d.jahr)
        return d;

    return d;
}


// Eingabe der Daten eines Studenten
// Leerer Student wird übergeben, befüllt und dann returned
void student_input(struct s_student *s)
{
    printf("\033[2J\033[H");
    char heading[] = "----------     Neuen Student Anlegen     ----------\n\n";
    do
    {
        if (!nachName_is_Set(s)) // nur leere Werte erneut einlesen
        {
            printf("\033[2J\033[H");
            printf("%s",heading);
            printf("\nNachname: ");
            getString_local(s->nachname, 100);
            if(!nachName_is_Set(s))
            {
                printf("Nachname ungültig! Bitte versuchen Sie es erneut.");
                getchar();
                continue;
            } //Redo bis gültige Werte gesetzt sind
        }
        if (!matrikelnummer_is_Set(s))
        {
            printf("\033[2J\033[H");
            printf("%s",heading);
            printf("\nMatrikelnummer: ");
            getString_local(s->matrikelnummer, 100);
            if(!matrikelnummer_is_Set(s))
            {
                printf("Matrikelnummer ungültig! Bitte versuchen Sie es erneut.");
                getchar();
                continue;
            }
        }

        if (!geburtsDatum_is_Set(s))
        {
            printf("\033[2J\033[H");
            printf("%s",heading);
            s->geburtsDatum = setdatum("Geburtsdatum");
            if(!geburtsDatum_is_Set(s))
            {
                printf("Geburtsdatum ungültig! Bitte versuchen Sie es erneut und beachten Sie die richtige Reihenfolge der Datums.");
                getchar();
                continue;
            }
        }
        if (!startDatum_is_Set(s))
        {
            printf("\033[2J\033[H");;
            printf("%s",heading);
            s->startDatum = setdatum("Start Datum");
            if(!startDatum_is_Set(s))
            {
                printf("Start-Datum ungültig! Bitte versuchen Sie es erneut und beachten Sie die richtige Reihenfolge der Datums.");
                getchar();
                continue;
            }
        }
        if (!endDatum_is_Set(s))
        {
            printf("\033[2J\033[H");
            printf("%s",heading);
            s->endDatum = setdatum("End Datum");
            if(!endDatum_is_Set(s))
            {
                printf("End-Datum ungültig! Bitte versuchen Sie es erneut und beachten Sie die richtige Reihenfolge der Datums.");
                getchar();
                continue;
            }
        }

        /*if(!All_values_Set(s)) //Info an Benutzer: Ungültige Werte erneut eingeben
        {
            printf("%s",heading);
            printf("Nicht alle Werte wurden gesetzt. Bitte versuchen Sie es erneut!\n");
            getchar();
            printf("\033[2J\033[H");
        }*/

    } while (!All_values_Set(s)); // Redo bis alle Werte gesetzt sind

    printf("%s", s->nachname);
}

