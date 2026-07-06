#include <stdio.h>
#include "producción.h"
#include <string.h>
#include <stdlib.h>

float calcularRendimiento(float materia_prima, float desperdicio) {
    if (materia_prima > 0) {
        return ((materia_prima - desperdicio) / materia_prima) * 100.0f;
    }
    return 0.0f;
}
void cargarCSV(RegistroProduccion *arreglo, int *total) {
    FILE *archivo = fopen("produccion_turnos.csv", "r");
    if (archivo == NULL) {
        printf("No se encontro archivo previo. Se creara uno nuevo al guardar.\n");
        return;
    }
    char linea[256];
    fgets(linea, sizeof(linea), archivo);
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%15[^;];%10[^;];%19[^;];%d;%f;%f;%d;%d",
               arreglo[*total].codigo_registro,
               arreglo[*total].fecha,
               arreglo[*total].centro_costo,
               &arreglo[*total].turno,
               &arreglo[*total].materia_prima_kg,
               &arreglo[*total].desperdicio_kg,
               &arreglo[*total].tiempo_min,
               &arreglo[*total].unidades_producidas);
        (*total)++;
    }
    fclose(archivo);
}