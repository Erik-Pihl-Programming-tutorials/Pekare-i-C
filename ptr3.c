/********************************************************************************
* main.c: Demonstration av pekare f�r arrayer i C. Eftersom pekare skickas
*         automatiskt via passering av arrayer i C s� anv�nds ingen
*         adressoperator & vid funktionsanrop. Inte heller kr�vs n�gon
*         dereferensoperator * f�r att komma �t inneh�llet p� adressen f�r
*         pekare till arrayerna. Dock beh�vs antalet element lagrat i arrayerna
*         passeras, f�rutom f�r str�ngar, d�r ett nolltecken \0 anv�nds f�r
*         att indikera textstyckets slut.
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
* print_name: Skriver ut angivet namn.
* 
*             - s: Pekare till namnet som skall skrivas ut.
********************************************************************************/
void print_name(const char* s)
{
   printf("Name: %s\n", s);
   return;
}

/********************************************************************************
* print_numbers: Skriver ut heltal lagrade i en array / ett f�lt.
* 
*                - numbers: Pekare till f�ltet inneh�llande heltalet.
*                - size:    Arrayens storlek, dvs. antalet heltal i f�ltet.
********************************************************************************/
void print_numbers(const int* numbers,
                   const size_t size)
{
   printf("--------------------------------------------------------------------------------\n");

   for (const int* i = numbers; i < numbers + size; ++i)
   {
      printf("%d\n", *i);
   }

   printf("--------------------------------------------------------------------------------\n\n");
   return;
}

/********************************************************************************
* main: Fyller statisk array med tio heltal 0 - 9, som skrivs ut i terminalen
*       via anrop av funktionen print_numbers. En str�ng inneh�llande namnet
*       Kalle Anka passeras sedan (indirekt via pekare) till funktionen 
*       print_name f�r utskrift.
********************************************************************************/
int main(void)
{
   int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   const size_t size = sizeof(numbers) / sizeof(int);
   const char s[] = "Kalle Anka";

   print_numbers(numbers, size);
   print_name(s);

   return 0;
}