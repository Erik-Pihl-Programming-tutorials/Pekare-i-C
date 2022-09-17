/********************************************************************************
* ptr2.c: Demonstration av pekare som funktionsparametrar för skrivning till 
*         variablers adresser i C.
*         
*         Kom ihåg: Som en tumregel bör pekare användas för funktionsparametrar
*         vid användning av större objekt, såsom objekt av struktar (måste
*         passeras manuellt) samt strängar och arrayer (passeras automatiskt), 
*         då pekare till dessa är mycket effektivare att passera än att kopiera
*         objektet och sedan passera den stora kopian på stacken.
*
*         För datamedlemmar av primitiva datatyper, såsom int och double, bör
*         pekare enbart användas ifalkl skrivning till datamedlemmens adress
*         skall genomföras. Detta beror på att för så små objekt så upptar
*         pekaren lika mycket eller mer utrymme än en kopia, samtidigt som
*         det blir mer att hålla reda på (adressoperatorer & och dereferenser). 
*         Pekare är dock okej även i detta fall.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* assign: Tilldelar heltal 3, 5 och 7 till tre variabler på angivna adresser.
* 
*         - a: Pekare till den första variabeln.
*         - b: Pekare till den andra variabeln.
*         - c: Pekare till den tredje variabeln.
********************************************************************************/
void assign(int* a, 
            int* b,
            int* c)
{
   *a = 3;
   *b = 5;
   *c = 7;
   return;
}

/********************************************************************************
* print: Skriver ut heltal lagrat av tre variabler i terminalen.
* 
*        - a: Det första heltalet.
*        - b: Det andra heltalet.
*        - c: Det tredje heltalet.
********************************************************************************/
void print(const int a,
           const int b,
           const int c)
{
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("c = %d\n\n", c);
   return;
}

/********************************************************************************
* main: Deklarerar tre intvariabler x, y och z och tilldelar heltal 3, 5 och 7
*       via anrop av funktionen assign, där variablernas adresser passeras. 
*       Detta kallas pass-by-reference (vi skickar referenser till variablerna).
*       Variablernas innehåll skrivs sedan ut i terminalen via anrop av 
*       funktionen print, där kopior av variablernas passeras. Detta kallas
*       pass-by-value (vi skickar variablernas värden).
********************************************************************************/
int main(void)
{
   int x, y, z;
   assign(&x, &y, &z); 
   print(x, y, z);
   return 0;
}