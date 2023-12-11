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
bool addUser(struct s_student *student)
{
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

    if (s->nachname[0] == '\0')
    {

        return false;
    }
    return true;
}
bool matrikelnummer_is_Set(struct s_student *s)
{
    //printf("%p\n",s->matrikelnummer); //test
    if (s->matrikelnummer[0] == '\0')
    {
        return false;
    }
    return true;
}

bool s_datum_is_Set(struct s_datum d)
{
    return d.jahr && d.monat && d.tag;
}

bool startDatum_is_Set(struct s_student *s)
{
    if (s_datum_is_Set(s->startDatum))
    {
        return 1;
    }
    return false;
}
bool endDatum_is_Set(struct s_student *s)
{
    if (s_datum_is_Set(s->endDatum))
    {
        return 1;
    }
    return false;
}
bool geburtsDatum_is_Set(struct s_student *s)
{
    if (s_datum_is_Set(s->geburtsDatum))
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

// Check ob alle Werte des Studenten gesetzt sind
bool All_values_Set(struct s_student *s)
{
    return nachName_is_Set(s) && matrikelnummer_is_Set(s)

           // TODO: Reihenfolge Datum überprüfen (geburt < start < end)
           && startDatum_is_Set(s) && endDatum_is_Set(s) && geburtsDatum_is_Set(s)
        //& next_is_Set(s)
        ;
}

struct s_datum setdatum(char *info)
{ // Info beinhaltet Grund des Datums
    printHr();
    printf("%s%s", info, " eingeben:\n\n");
    struct s_datum d;

    char input[10]; // Max 10 Zeichen für input -> Max mögliche Jahreszahl = 9999999999

    // Einlesen der Daten für den Tag
    printf("Bitte geben Sie den Tag ein (1 - 31):\n>");
    fgets(input, sizeof(input), stdin);
    d.tag = atoi(input) > 0 && atoi(input) <= 31 ? atoi(input) : 0;

    // Einlesen der Daten für den Monat
    printf("Bitte geben Sie den Monat ein (1 - 12):\n>");
    fgets(input, sizeof(input), stdin);
    d.monat = atoi(input) > 0 && atoi(input) <= 12 ? atoi(input) : 0;

    // Einlesen der Daten für das Jahr
    printf("Bitte geben Sie das Jahr ein (>0):\n>");
    fgets(input, sizeof(input), stdin);
    d.jahr = atoi(input) > 0 ? atoi(input) : 0;

    printHr();
    return d;
}



// Eingabe der Daten eines Studenten
// Leerer Student wird übergeben, befüllt und dann returned
void student_input(struct s_student *s)
{
    printf("itworks");
    do
    {
        if (!nachName_is_Set(s)) // nur leere Werte erneut einlesen
        {
            printf("\nNachname: ");
            getString_local(s->nachname, 100);
        }
        if (!matrikelnummer_is_Set(s))
        {
            printf("\nMatrikelnummer: ");
            getString_local(s->matrikelnummer, 100);
        }
        if (!startDatum_is_Set(s))
        {
            s->startDatum = setdatum("Start Datum");
        }
        if (!endDatum_is_Set(s))
        {
            s->endDatum = setdatum("End Datum");
        }
        if (!geburtsDatum_is_Set(s))
        {
            s->geburtsDatum = setdatum("Geburtsdatum");
        }
    } while (!All_values_Set(s)); // Redu bis alle Werte gesetzt sind



    /*printf("Last Name: %s\n", s->nachname);
    printf("Matriculation Number: %s\n", s->matrikelnummer);
    printf("Start Date: %d/%d/%d\n", s->startDatum.tag, s->startDatum.monat, s->startDatum.jahr);
    printf("End Date: %d/%d/%d\n", s->endDatum.tag, s->endDatum.monat, s->endDatum.jahr);
    printf("Birth Date: %d/%d/%d\n", s->geburtsDatum.tag, s->geburtsDatum.monat, s->geburtsDatum.jahr);*/


    return true;
}
