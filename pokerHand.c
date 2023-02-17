#include <stdio.h>


int main()
{
    int cartaNumero[5];
    char cartaNaipe[5];
    int i;

   for (i = 0; i<5; i++) {
    printf ("Digite sua carta %d: ", i+1);
    scanf("%d", &cartaNumero[i]);

    printf ("Digite o naipe da sua carta respectivamente: ");
    scanf("%s", &cartaNaipe[i]);
   }


   

  
   








    return 0;
}
