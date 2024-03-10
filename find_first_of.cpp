/*
Die C-Funktion strcspn (string complement span, also "Spanne des Komplementärstrings") wird verwendet, 
um die Länge des Anfangssegments eines Strings zu bestimmen, das ausschließlich Zeichen enthält, die nicht 
in einem angegebenen Satz von Zeichen vorkommen.

Ihre Deklaration lautet:
size_t strcspn(const char *str1, const char *str2);

Sie gibt sozusagen zurück, an welcher Stelle eines der ins str2 angegebenen Zeichen in str1 das erste Mal auftaucht.

Wenn keines der in str2 geschriebenen Zeichen auftaucht, wird die Länge des Strings str1 zurückgegeben.

Wir wollen für unseren Fall die Funktion leicht verändern:

int first_of_in_string(const char* chars, const char* string)

Diese Funktion soll die Stelle des ersten Auftauchens eines der Zeichen aus chars in string zurückgeben. 
Ist keines der Zeichen in string vorhanden, dann soll eine -1 zurückgegeben werden. 
*/

/*Version 1
#include <stdio.h>

bool isOneOfGivenChars(char c, const char* chars)
{
    int i = 0;
    while(chars[i] != '\0')
    {
        if(chars[i] == c)
        {
            return true;
        }
    }
    return false;
}

int first_of_in_string(const char* chars, const char* string)
{
    int index = 0;
    int counter = 0;
    while(string[index] != '\0')
    {
        if(isOneOfGivenChars(string[index], chars))
        {
            return counter;
        }
        counter++;
    }
        return (counter == 0 ? -1 : counter);
}
*/




/* Version 2
#include <iostream>


int first_of_in_string(const char* chars, const char* string)
{
    int counter = 0;
    int index = 0;
    int i;
    while(string[index] != '\0')
    {   
        i = 0;
        while(chars[i] != '\0')
        {
            if(string[index] == chars[i])
            {
                return counter;
            }
            i++;
        }
        index++;
        counter++;
    }
    if(counter == index)
    {
        return -1;
    }
    return counter;
}

int main()
{
    const char* text = "Max Mustermann";
    const char* signs = "z";

    printf("Gefunden an Stelle: %d", first_of_in_string(signs, text));

/*
    char vorname[30];
    char nachname[30];
    printf("Vorname: ");
    fgets(vorname, 30, stdin);
    vorname[strcspn(vorname, "\n")] = '\0';

    printf("Nachname: ");
    fgets(nachname, 30, stdin);
    nachname[strcspn(nachname, "\n")] = '\0';

    printf("Eingegebener Name: %s %s\n", vorname, nachname);
*/
//  return 0;
//}

