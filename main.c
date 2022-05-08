#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BITS 16
#define BITS_MULT (BITS * 2) - 2

int descolacamento(int num[], int x);
void mult(int M[], int Q[], int A[], int MN[]);
int converteBinario(int num, int vet[BITS]);
int somaBit(int b1, int b2, int b3, int *cout);
void soma(int num1[BITS], int num2[BITS], int result[BITS]);
void zerarVetor(int v[], int n);
void imprimeBin(int num[], int n);

int main()
{
    int vetNum1[BITS], vetNum2[BITS], vetNum1Negado[BITS], result_mult[BITS_MULT], resto[BITS], restoMod, num1, num2, i, resultDec, lenNum1, lenNum2;
    zerarVetor(vetNum1, BITS);
    zerarVetor(vetNum2, BITS);
    zerarVetor(result_mult, BITS_MULT);
    lenNum1 = converteBinario(7, vetNum1);
    lenNum2 = converteBinario(3, vetNum2);
    converteBinario(3 * -1, vetNum1Negado);
    mult(vetNum1, vetNum2, result_mult, vetNum1Negado);
}

int descolacamento(int num[], int x)
{
    int i, aux = num[BITS - 1];
    for (i = 1; i < BITS; i++)
        num[i] = num[i - 1];
    num[0] = x;
    return aux;
}

void mult(int M[], int Q[], int A[], int MN[])
{
    int cont = BITS, aux = 0;
    while (cont)
    {
        if (Q[BITS - 1] == 1 && aux == 0)
        {
            soma(A, MN, A);
            aux = descolacamento(A, 1);
        }
        else if (Q[BITS - 1] == 0 && aux == 1)
        {
            soma(A, M, A);
        }

        cont--;
    }
}

int converteBinario(int num, int vet[BITS])
{
    int i = BITS - 1, aux = 0, cont = 0, j;
    int one[BITS];
    zerarVetor(one, BITS);
    one[BITS - 1] = 1;

    if (num < 0)
        aux = 1, num = num * -1;

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
    if (aux)
    {
        for (i = 0; i < BITS; i++)
        {
            if (vet[i] == 0)
                vet[i] = 1;
            else
                vet[i] = 0;
        }
        soma(vet, one, vet);
    }
    return cont;
}

int somaBit(int b1, int b2, int b3, int *cout)
{
    *cout = (b1 + b2 + b3) / 2;
    return ((b1 + b2 + b3) % 2);
}

void soma(int num1[BITS], int num2[BITS], int result[BITS])
{
    int i, aux = 0;
    for (i = BITS - 1; i > 0; i--)
        result[i] = somaBit(num1[i], num2[i], aux, &aux);
    if (aux == 1)
        result[i] = aux;
}

void zerarVetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = 0;
}

void imprimeBin(int num[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", num[i]);
    printf("\n");
}