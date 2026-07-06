#ifndef PRODUCCION_H
#define PRODUCCION_H
typedef struct {
    char codigo_registro[16];
    char fecha[11]; 
    char centro_costo[20];
    int turno;
    float materia_prima_kg;
    float desperdicio_kg;
    int tiempo_min;
    int unidades_producidas;
} RegistroProduccion;
void cargarCSV(RegistroProduccion *arreglo, int *total);
void guardarCSV(RegistroProduccion *arreglo, int total);
void registrarTurno(RegistroProduccion *arreglo, int *total);
void listarRegistros(RegistroProduccion *arreglo, int total);
float calcularRendimiento(float materia_prima, float desperdicio);
#endif