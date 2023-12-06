#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
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


// actions.c
bool    addUser(struct s_student *student);
bool    removeUser(struct s_student *student);
void    printList(struct s_student *student);
int     number_of_students(struct s_student *student);

// student.c
bool    student_create(struct s_student *student);
bool    student_program(struct s_student *student);
void    student_destroy(struct s_student *student);


// utils.c
void    printError(char *str);
void    printMenu();
void    printHr();
void    getString(char *buf, char *prompt, int len);
void    loadingScreen();
void    print_middle(char *str, int line);