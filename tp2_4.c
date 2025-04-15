#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define N 5

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
   };
   
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);



int main () {

    int num;
    srand(time(NULL));

    struct compu pc[N]; // almacena las características de las 5 PCs generadas

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    for (int i = 0; i < N; i++)
    {
        pc[i].velocidad = 1 + rand() % 3; // valor entero aleatorio entre 1 y 3 
        pc[i].anio = 2015 + rand() % 10;  // valor entero aleatorio entre 2015 y 2024
        pc[i].cantidad_nucleos = 1 + rand() % 8; // valor entero aleatorio entre 1 y 8 
        num = rand() % 6;
        pc[i].tipo_cpu = tipos[num]; //PC generada aleatoriamente
    }
    
    listarPCs(pc, N);
    mostrarMasVieja(pc, N);

    return 0;


}


void listarPCs(struct compu pcs[], int cantidad) { 
    
    int i;

    for (i = 0; i < cantidad; i++){
        printf("\n- PC -  %d -", i + 1);
        printf("\nAnio : %d", pcs[i].anio);
        printf("\nVelocidad : %d", pcs[i].velocidad);
        printf("\nCantidad de nucleos : %d", pcs[i].cantidad_nucleos);
        printf("\nTipo de CPU : %s\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){

    struct compu aux;
    aux.anio = 2025;
    int i;

    for (i = 0; i < cantidad; i++) {

        if (pcs[i].anio < aux.anio){

            aux = pcs[i];
        }
    }
         printf("\n- - - PC mas Vieja - - -");
         printf("\nAnio : %d", aux.anio);
         printf("\nVelocidad : %d", aux.velocidad);
         printf("\nCantidad de nucleos : %d", aux.cantidad_nucleos);
         printf("\nTipo de CPU: %s\n", aux.tipo_cpu);

}