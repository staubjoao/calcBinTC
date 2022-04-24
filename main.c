#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BITS 16

void compDois(int vet[BITS], int len);
int converteBinario(int num, int vet[BITS]);
void zerarVetor(int *v);
void imprimeBin(int num[BITS]);

int main()
{
    int vetNum1[BITS], vetNum2[BITS], result[BITS], resto[BITS], restoMod, num1, num2, i, resultDec, lenNum1, lenNum2;
    zerarVetor(vetNum1);
    lenNum1 = converteBinario(3, vetNum1);
    imprimeBin(vetNum1);
    compDois(vetNum1, lenNum1);
    imprimeBin(vetNum1);
}

void compDois(int vet[BITS], int len)
{
    for (int i = BITS - len-1; i < BITS; i++)
    {
        if (vet[i] == 0)
            vet[i] = 1;
        else
            vet[i] = 0;
    }
}

int converteBinario(int num, int vet[BITS])
{
    int i = BITS - 1, aux = num, cont = 0;
    if (num < 0)
        num = num * -1;

    while (num > 0)
    {
        if (num % 2 == 0)
            vet[i] = 0;
        else
            vet[i] = 1;
        num /= 2;
        i--;
        cont++;
    }
    if (aux < 0)
        vet[0] = 1;
    return cont;
}

void zerarVetor(int *v)
{
    for (int i = 0; i < BITS; i++)
        v[i] = 0;
}

void imprimeBin(int num[BITS])
{
    for (int i = 0; i < BITS; i++)
        printf("%d", num[i]);
    printf("\n");
}