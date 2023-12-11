#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct s_datum
{
    int tag;
    int monat;
    int jahr;
};

struct s_student
{
    char *nachname;
    char *matrikelnummer;
    struct s_datum startDatum;
    struct s_datum endDatum;
    struct s_datum geburtsDatum;

    struct s_student *next;
};

bool addUser(struct s_student *student);
bool removeUser(struct s_student *student);
void printList(struct s_student *student);
int number_of_students(struct s_student *student);

bool student_create(struct s_student **student);

bool student_programm(struct s_student *student);
void student_destroy(struct s_student *student);

void student_insert(struct s_student *head, struct s_student *student);
void student_input(struct s_student *s);

void printError(char *str);
void printMenu();