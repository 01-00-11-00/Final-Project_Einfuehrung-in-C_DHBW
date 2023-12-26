#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include "student_list.h"

extern int     g_line;

struct s_datum {
    int tag;
    int monat;
    int jahr;
};

struct s_student {
    char                *nachname;
    char                *matrikelnummer;
    struct s_datum      startDatum;
    struct s_datum      endDatum;
    struct s_datum      geburtsDatum;
    
    struct s_student    *next;
};


// actions.c
bool    addStudent(StudentList *list);
bool    printStudent(StudentList *list);
bool    deleteStudent(StudentList *list);
int     number_of_students(StudentList *list);
void    insert_student(StudentList *list, struct s_student *student);
int     input_student(struct s_student *s);
int     student_info_print_one(struct s_student *student);
int     student_info_print_all(struct s_student *student);

// student.c
bool    student_create(struct s_student **student);
bool    student_program(StudentList *list);
void    student_destroy(struct s_student *student);


// utils.c
void    printError(char *str);
void    printMenu();
void    printHr();
void    getString(char *buf, char *prompt, int len);
void    loadingScreen();
void    print_middle(char *str, int line);
bool    string_only_space(char *str);