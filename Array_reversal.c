#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi, *dizi, i;
    scanf("%d", &sayi);
    dizi = (int*) malloc(sayi * sizeof(int));
    for(i = 0; i < sayi; i++) {
        scanf("%d", dizi + i);
    }

    int *klon_dizi;
    klon_dizi = (int*) malloc(sayi * sizeof(int));
    
    for(i = 0; i < sayi; i++)
        klon_dizi[i] = dizi[i];
    
    for(i = 0; i < sayi; i++)
        dizi[i] = klon_dizi[sayi -i -1];
    
    for(i = 0; i < sayi; i++)
        printf("%d ", *(dizi + i));

    free(klon_dizi);
    free(dizi);
    return 0;
}

