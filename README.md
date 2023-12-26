# Abschlussarbeit_Einf-hrung-in-C_DHBW
This repository contains the final exam of Einführung in C DHBW.


## Code-Struktur:
```
.
├── include
│   ├── student.h
│   └── student_list.h
├── main.c
├── Makefile
├── README.md
├── src
│   ├── actions.c
│   ├── student.c
│   ├── student_list.c
│   └── utils.c
└── students.csv

```

## Anwendung:

Um das Projekt zu erstellen und die ausführbare Datei zu erzeugen, führen Sie:
```
	make
```
Um alle erzeugten .o-Dateien zu löschen, führen Sie :
```
	make clean
```

Um alle erzeugten .o-Dateien und die ausführbare Datei zu löschen, führen Sie :
```
	make fclean
``` 

## &> src/student.c

### Funktion trim_string:
Diese Funktion entfernt führende und abschließende Leerzeichen (Whitespaces) aus einem gegebenen String str und gibt den modifizierten String zurück. Falls der ursprüngliche String str NULL ist oder bereits leer ('\0'), wird der ursprüngliche String unverändert zurückgegeben.

### Funktion student_create:
Diese Funktion erstellt ein neues Studentenobjekt durch dynamische Speicherzuweisung. Sie gibt einen Zeiger auf das erstellte Studentenobjekt über den Parameter student zurück. Falls die Speicherzuweisung fehlschlägt, wird false zurückgegeben, sonst true.

### Funktion import_students:
Diese Funktion liest Studentendaten aus einer CSV-Datei ("students.csv") und fügt jeden gelesenen Studenten in die übergebene Studentenliste list ein. Vor dem Einlesen wird die erste Zeile (Header) der CSV-Datei ignoriert. Nach dem Einlesen wird auf die Konsole eine Meldung über den importierten Studenten ausgegeben, und die Matrikelnummer des jeweiligen Studenten wird durch die Funktion trim_string bereinigt.

### Funktion export_students:
Diese Funktion exportiert die Daten aller Studenten in der übergebenen Studentenliste list in eine CSV-Datei ("students.csv"). Dabei wird die CSV-Datei neu erstellt, und der Header sowie die Daten der einzelnen Studenten werden in die Datei geschrieben.

### Funktion student_program:
Diese Funktion repräsentiert das Hauptprogramm für die Verwaltung von Studentendaten. Zunächst werden Studentendaten aus der CSV-Datei importiert. Dann wird ein Menü auf der Konsole angezeigt, und der Benutzer kann verschiedene Aktionen auswählen, wie das Hinzufügen, Anzeigen, Löschen, usw. von Studenten. Das Programm läuft in einer Endlosschleife, bis der Benutzer die Option zum Beenden auswählt. Vor dem Beenden wird die Funktion export_students aufgerufen, um die aktualisierten Daten in die CSV-Datei zu exportieren.

### Funktion student_destroy:
Diese Funktion deallokiert den Speicher für ein Studentenobjekt, einschließlich des Speichers für den Nachnamen und die Matrikelnummer.

### Funktion insert_student:
Diese Funktion fügt einen Studenten am Ende der Studentenliste list ein. Falls die Liste oder der übergebene Student NULL ist, wird nichts gemacht. Falls die Liste leer ist, wird der übergebene Student das erste Element der Liste. Andernfalls wird der Student am Ende der Liste hinzugefügt.


## src/student_list.c

### Funktion printAllStudents:
Diese Funktion gibt alle Studenteninformationen in der übergebenen Studentenliste list auf der Konsole aus. Sie verwendet die Funktion student_info_print_one, um die Informationen für jeden Studenten auszugeben. Nach dem Ausgeben der Informationen für alle Studenten wird wiederum der Benutzer aufgefordert, Enter zu drücken.

### Funktion student_list_create:
Diese Funktion erstellt eine neue leere Studentenliste durch dynamische Speicherzuweisung. Der erstellte Studentenlisten-Zeiger wird zurückgegeben.


## src/utils.c

### Funktion loadingScreen:
Diese Funktion simuliert einen Ladebildschirm auf der Konsole, der den Fortschritt in Prozent anzeigt.

### Funktion print_middle:
Diese Funktion gibt einen Text str in der Mitte der Konsole auf einer bestimmten Zeile line aus. Die Funktion verwendet ANSI Escape Codes, um die Position des Textes auf der Konsole zu steuern.

### Funktion printMenu:
Diese Funktion gibt ein Menü für die Studentenverwaltung auf der Konsole aus. Die Menüoptionen werden formatiert und auf verschiedenen Zeilen platziert. Die Funktion verwendet print_middle und ANSI Escape Codes für die Ausgabe.

### Funktion chomp:
Diese Funktion entfernt Zeilenumbrüche (\n oder \r) aus dem übergebenen String s. Es wird davon ausgegangen, dass der String durch ein Nullzeichen (\0) abgeschlossen ist.

### Funktion getString:
Diese Funktion fordert den Benutzer auf, eine Zeichenkette einzugeben, indem sie ein Prompt prompt anzeigt. Die eingegebene Zeichenkette wird in den Puffer buf geschrieben, und die Funktion entfernt Zeilenumbrüche mit chomp.

### Funktion printError:
Diese Funktion gibt eine Fehlermeldung auf dem Standardfehlerausgabekanal (stderr) aus. Die Funktion verwendet dprintf(2, "%s", str), um die Fehlermeldung auf dem Standardfehlerausgabekanal zu drucken.

### Funktion printHr:
Diese Funktion gibt eine horizontale Linie auf der Konsole aus. Die Länge der Linie beträgt 40 Zeichen, und sie besteht aus '='-Zeichen.

### Funktion string_only_space:
Diese Funktion überprüft, ob der übergebene String str ausschließlich aus Leerzeichen besteht. Wenn der String nur Leerzeichen enthält, gibt die Funktion true zurück; sonst gibt sie false zurück.
