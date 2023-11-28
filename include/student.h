#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct s_datum {
    int tag;
    int monat;
    int jahr;
};

struct s_student {
    char *nachName;
    char *matrikelNummer;
    struct s_datum startDatum;
    struct s_datum endDatum;
    struct s_datum geburtsDatum;
    
    struct s_student *next;
};



bool    addUser(struct s_student *student);
bool    removeUser(struct s_student *student);
void    printList(struct s_student *student);

bool    student_create(struct s_student *student);
bool    student_programm(struct s_student *student);
void    student_destroy(struct s_student *student);

void    printError(char *str);
void    printMenu();