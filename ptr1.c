/********************************************************************************
* ptr1.c: Demonstration av enkel-, dubbel- och trippelpekare i C.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* main: Deklarerar en intvariabel döpt x och tilldelar startvärdet 0. Sedan
*       deklareras en intpekare döpt ptr1, som pekar på adressen till x.
*       För att genomföra detta används den så kallade adressoperatorn &, där
*       &x betyder "adressen till x". För att komma åt innehållet på adressen
*       som ptr1 pekar på så kan vi använda den så kallade derefensoperatorn *,
*       där *ptr1 betyder "innehållet på adressen som ptr1 pekar på", i detta
*       fall innehållet som variabel x lagrar.
* 
*       För att genomföra utskrift av adressen kan formatspecificeraren %p
*       användas. Via ptr1 ändras värdet på x till 3 via dereferensen *ptr1.
*        
*       Sedan deklareras en dubbelpekare ptr2, som pekar på adressen till ptr1.
*       Via ptr2 ändras värdet på x till 5 via dereferensen **ptr2.
* 
*       Sedan deklareras en trippelpekare ptr3, som pekar på adressen till ptr2.
*       Via ptr3 ändras värdet på x till 7 via derefenresen ***ptr3.
********************************************************************************/
int main(void)
{
   int x = 0;
   int* ptr1 = &x;
   int** ptr2 = &ptr1;
   int*** ptr3 = &ptr2;

   printf("The variable x is stored at address %p\n", &x);
   printf("The pointer ptr1 is pointing at the address of x: %p\n", ptr1);
   printf("The value at this address is %d\n", *ptr1);
   printf("This is the value of x: %d\n\n", x);

   *ptr1 = 3;

   printf("The value of x is now changed to %d\n", x);
   printf("The pointer ptr1 is stored at address %p\n", &ptr1);
   printf("The pointer ptr2 is pointing at the address of ptr1: %p\n", ptr2);
   printf("The value of x is still %d\n\n", **ptr2);

   **ptr2 = 5;

   printf("The value of x is now changed to %d\n", x);
   printf("The pointer ptr2 is stored at address %p\n", &ptr2);
   printf("The pointer ptr3 is pointing at the address of ptr2: %p\n", ptr3);
   printf("The value of x is still %d\n\n", ***ptr3);

   ***ptr3 = 7;

   printf("The value of x is now changed to %d\n", x);
   printf("The pointer ptr3 is stored at address %p\n", &ptr3);

   return 0;
}