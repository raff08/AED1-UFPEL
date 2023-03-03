#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


bool canWinNim(int n) {

    if (n % 4 != 0) {
        return true; // 1 = venceu
    } else {
        return false; // 0 = perdeu
    }

}


int main()
{
    int n;

    printf ("Digite a quantidade de pedras: \n");
    scanf ("%d",&n);


    printf ("%d", canWinNim(n));

    


    return 0;
}
