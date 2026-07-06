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
void guardarCSV(RegistroProduccion *arreglo, int total) {
    FILE *archivo = fopen("produccion_turnos.csv", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar datos.\n");
        return;
    }
    fprintf (archivo, "codigo_registro;fecha;centro_costo;turno;materia_prima_kg;tiempo_min;unidades_producidas\n");
    for (int i = 0; i < total; i++) {
        fprintf(archivo, "%s;%s;%s;%d;%.2f;%.2f;%d;%d\n",
                arreglo[i].codigo_registro,
                arreglo[i].fecha,
                arreglo[i].centro_costo,
                arreglo[i].turno,
                arreglo[i].materia_prima_kg,
                arreglo[i].desperdicio_kg,
                arreglo[i].tiempo_min,
                arreglo[i].unidades_producidas);
    }
    fclose(archivo);
    printf("Datos guardados exitosamente en produccion_turnos.csv\n");
}
void listarRegistros(RegistroProduccion *arreglo, int total) {
    printf("\n--- LISTADO DE REGISTROS ---\n");
    for (int i = 0; i < total; i++) {
        float rend = calcularRendimiento(arreglo[i].materia_prima_kg, arreglo[i].desperdicio_kg);
        printf("Cod: %s | Fecha: %s | CC: %s | Turno: %d | MP: %.1f kg | Desp: %.1f kg | Rend: %.2f%%\n",
               arreglo[i].codigo_registro, arreglo[i].fecha, arreglo[i].centro_costo,
               arreglo[i].turno, arreglo[i].materia_prima_kg, arreglo[i].desperdicio_kg, rend);
            }
}

void registrarTurno(RegistroProduccion *arreglo, int *total) {
    if (*total >= 100) {
        printf("Error: Capacidad maxima de registros alcanzada.\n");
        return;
    }
    printf("Ingrese Codigo de Registro: ");
    scanf("%15s", arreglo[*total].codigo_registro); 
    printf("Ingrese Fecha (DD/MM/AAAA): ");
    scanf("%10s", arreglo[*total].fecha);
    printf("Ingrese Centro de Costo: ");
    scanf("%19s", arreglo[*total].centro_costo);
    printf("Ingrese Turno (1, 2, 3): ");
    scanf("%d", &arreglo[*total].turno);
    printf("Ingrese Materia Prima (kg): ");
    scanf("%f", &arreglo[*total].materia_prima_kg);
    printf("Ingrese Desperdicio (kg): ");
    scanf("%f", &arreglo[*total].desperdicio_kg);
    printf("Ingrese Tiempo (min): ");
    scanf("%d", &arreglo[*total].tiempo_min);
    printf("Ingrese Unidades: ");
    scanf("%d", &arreglo[*total].unidades_producidas);
    
    (*total)++;
    printf("Registro exitoso!\n");
}