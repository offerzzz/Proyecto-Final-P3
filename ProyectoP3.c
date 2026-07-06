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
