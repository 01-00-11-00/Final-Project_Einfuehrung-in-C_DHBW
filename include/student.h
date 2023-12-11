#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

static int     g_line = 24;

struct s_datum {
    int tag;
    int monat;
    int jahr;
};

struct s_student {
    char *nachname;
    char *matrikelnummer;
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

void    student_insert(struct s_student *head, struct s_student *student);
void    student_input(struct s_student *s);

int     student_info_print_one(struct s_student *student);
int     student_info_print_all(struct s_student *student);
int     student_info_write(struct s_student *student);
int     student_info_read(struct s_student *student);

// student.c
bool    student_create(struct s_student **student);
bool    student_program(struct s_student *student);
void    student_destroy(struct s_student **student);


// utils.c

void    student_insert(struct s_student *head, struct s_student *student);
void    printError(char *str);
void    printMenu();
void    printHr();
void    getString(char *buf, char *prompt, int len);
void    loadingScreen();
void    print_middle(char *str, int line);
