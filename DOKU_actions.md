### Funktion chomp_local:
Diese Funktion ist eine eigene Implementierung der chomp-Funktion und entfernt das Zeilenumbruchzeichen '\n' aus einem gegebenen String str. Falls der ursprüngliche String str NULL ist oder bereits leer ('\0'), wird der ursprüngliche String unverändert zurückgegeben.

### Funktion getString_local:
Diese Funktion liest eine Zeichenkette von der Konsole ein und gibt sie als String zurück. Die Funktion liest die Zeichenkette bis zum ersten Zeilenumbruchzeichen '\n' ein und entfernt dieses aus dem String. Falls die Eingabe leer ist, wird NULL zurückgegeben.

### Funktion student_info_print_one:
Diese Funktion gibt die Informationen eines Studenten auf der Konsole aus. Falls der übergebene Student NULL ist, wird nichts ausgegeben.

### Funktion addStudent:
Diese Funktion allokiert dynamisch Speicher für einen neuen Studenten und fügt ihn am Ende der Studentenliste list ein. Dafür wird dei Funktion insert_student verwendet. Falls die Speicherzuweisung fehlschlägt, wird false zurückgegeben, sonst true.

### Funktion printStudent:
Diese Funktion fragt nach einer Matrikelnummer mit der Funktion getString_local und gibt die Informationen des Studenten mit dieser Matrikelnummer auf der Konsole aus. Falls die Matrikelnummer nicht gefunden wird, wird eine entsprechende Meldung ausgegeben. Auch wird eine Meldung ausgegeben, falls die Liste leer ist.
Damit der Output der Funktion nicht sofort überschrieben wird, wird der Benutzer aufgefordert, Enter zu drücken.

### Funktion deleteStudent:
Diese Funktion fragt nach einer Matrikelnummer mit der Funktion getString_local und löscht den Studenten mit dieser Matrikelnummer aus der Studentenliste. Falls die Matrikelnummer nicht gefunden wird, wird eine entsprechende Meldung ausgegeben. Auch wird eine Meldung ausgegeben, falls die Liste leer ist. Der Speicher für den gelöschten Studenten wird deallokiert.

### Funktion number_of_students:
Diese Funktion gibt die Anzahl der Studenten in der übergebenen Studentenliste aus. 

### Funktion nachName_is_Set:
Diese Funktion prüft, ob der Nachname eines Studenten gesetzt ist. 

### Funktion matrikelnummer_is_Set:
Diese Funktion prüft, ob die Matrikelnummer eines Studenten gesetzt ist.


### Funktion s_datum_is_Set:
Diese Funktion prüft, ob ein Beliebiges Datum eines Studenten gesetzt ist.

### Funktion verify_no_time_travel:
Diese Funktion prüft, ob die Daten in der Richtigen Reihenfolge eingegeben wurden. Das heißt, dass das Geburtsdatum vor dem Eintrittsdatum liegen muss. Die Funktion nimmt zwei Datums-structs entgegen und rechnet diese in Tage um. Sie werden anschließend verglichen und das Ergebnis wird zurückgegeben.

### Funktion startDatum_is_Set:
Diese Funktion prüft, ob das Eintrittsdatum eines Studenten gesetzt ist.

### Funktion geburtsDatum_is_Set:
Diese Funktion prüft, ob das Geburtsdatum eines Studenten gesetzt ist.

### Funktion All_values_Set:
Diese Funktion prüft, ob alle Werte eines Studenten gesetzt sind.

### Funktion endDatum_is_Set:
Diese Funktion prüft, ob das Austrittsdatum eines Studenten gesetzt ist.

### Funktion setdatum:
Diese Funktion ist eine utility Funktion, die ein Datum-struct mit den erstellt und zurückgibt. Die Funktion nimmt einen String entgegen, der dem Nutzer ausgibt, welches Datum er eingeben soll. Die Funktion nimmt dann die Eingabe des Nutzers entgegen und prüft, ob das Datum im richtigen Format eingegeben wurde. 

### Funktion input_student:

Diese Funktion nimmt einen Studenten-struct entgegen und füllt diesen mit den Eingaben des Nutzers. Die Funktion prüft, ob die Eingaben im richtigen Format eingegeben wurden. Falls nicht, wird der Nutzer aufgefordert, die Eingabe zu wiederholen. Die Funktion gibt einen Status zurück.