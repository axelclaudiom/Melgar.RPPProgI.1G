#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct {
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;
/*
1. Crear una función llamada calcularIVA que reciba como primer parámetro el precio bruto de un producto y como segundo
parámetro la dirección de memoria de una variable donde debe escribir el valor del impuesto(el IVA es 21%). La función
retorna 1 si salió todo bien o 0 si hubo algún error. Realizar la llamada desde main. **/

/* 2. Crear una función que se llame subibaja que reciba una cadena de caracteres y que los caracteres en minúscula los pase
 a mayúscula y los que están en mayúscula los pase a minúscula retorna 1 si esta todo bien o 0 si hubo algún error. **/

 /*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha
 estructura por marca ascendente Ante igualdad de marca deberá ordenarse por precio descendente. Hardcodear datos y mostrarlos
 desde el main. * */

int calcularIVA(float pBruto, float* valorImpuesto);
int ordenarNotebooks(eNotebook lista[], int tam);
//int subibaja(char cadena[]);

int main()
{
    eNotebook lista[TAM] = {
    {1, "intel", "acer", 500.40,},
    {2, "intel", "hp", 200.30},
    {3, "amd", "asus", 360.80},
    {4, "intel", "lg",900.90},
    {5, "amd", "lenovo",908.9}
    };

    float valorImpuesto;
    //calcularIVA(5000, &valorImpuesto);
    if(calcularIVA(5000, &valorImpuesto)){
        printf("Iva %f\n" , valorImpuesto);
    }


    for(int i = 0; i< TAM; i++)
    {
        printf("  %d  %10s       %10s      %2f\n", lista[i].id , lista[i].procesador, lista[i].marca, lista[i].precio);
    }

    ordenarNotebooks(lista, TAM);

    printf("\n\n");

    for(int i = 0; i< TAM; i++)
    {
        printf("  %d  %10s       %10s      %2f\n", lista[i].id , lista[i].procesador, lista[i].marca, lista[i].precio);
    }

    return 0;
}

int calcularIVA(float pBruto, float* valorImpuesto){
    int todoOk = 0;
    if(valorImpuesto != NULL){
        *valorImpuesto = pBruto * 21 /100;
        todoOk = 1;
    }
    return todoOk;
}
/*
int subibaja(char cadena[]){
int

return todoOk;
}*/


int ordenarNotebooks(eNotebook lista[], int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i+1; j< tam; j++)
            {
                if((strcmp(lista[i].marca, lista[j].marca) > 0 ) || ((strcmp(lista[i].marca, lista[j].marca) == 0) && lista[i].precio < lista[j].precio))
                {
                    auxNotebook = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNotebook;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
