#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 10
#define MAX_CURSOS 10
#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 30
#define NOTA_APROBACION 70.0

typedef struct {
    char curso[MAX_DESCRIPCION];
    double calif1;
    double calif2;
    double calif3;
    double calif_final;
    char observacion[12];
} Curso;

typedef struct {
    char nombre[MAX_NOMBRE];
    Curso cursos[MAX_CURSOS];
    int num_cursos;
    double promedio_final_alumno;
} Alumno;

/* Función para calcular la calificación final y la observación */
void calcular_curso(Curso *c) {
    c->calif_final = (c->calif1 + c->calif2 + c->calif3) / 3.0;
    if (c->calif_final >= NOTA_APROBACION) {
        strcpy(c->observacion, "APROBADO");
    } else {
        strcpy(c->observacion, "DESAPROBADO");
    }
}

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    int cont_alumnos = 0;
    int cont_total_cursos = 0;
    double suma_promedios_alumnos = 0.0;
    
    char nombre_input[MAX_NOMBRE];

    printf("--- REGISTRO DE ALUMNOS Y CURSOS ---\n");
    printf("Ingrese nombre del alumno (o 'FIN' para terminar):\n");

    while (cont_alumnos < MAX_ALUMNOS) {
        printf("\nNombre del Alumno: ");
        if (scanf("%49s", nombre_input) != 1) break;

        if (strcmp(nombre_input, "FIN") == 0 || strcmp(nombre_input, "fin") == 0) break;

        Alumno nuevo_alumno;
        strcpy(nuevo_alumno.nombre, nombre_input);
        nuevo_alumno.num_cursos = 0;
        nuevo_alumno.promedio_final_alumno = 0.0;
        double suma_calif_finales = 0.0;
        
        printf("--- CURSOS PARA %s (Escriba 'FIN' en Curso para siguiente alumno) ---\n", nombre_input);
        
        while (nuevo_alumno.num_cursos < MAX_CURSOS) {
            char curso_input[MAX_DESCRIPCION];
            double c1, c2, c3;

            printf("Curso %d: ", nuevo_alumno.num_cursos + 1);
            if (scanf("%29s", curso_input) != 1) break;

            if (strcmp(curso_input, "FIN") == 0 || strcmp(curso_input, "fin") == 0) break;

            printf("  Calificacion 1: ");
            if (scanf("%lf", &c1) != 1) break;
            printf("  Calificacion 2: ");
            if (scanf("%lf", &c2) != 1) break;
            printf("  Calificacion 3: ");
            if (scanf("%lf", &c3) != 1) break;

            nuevo_alumno.cursos[nuevo_alumno.num_cursos].calif1 = c1;
            nuevo_alumno.cursos[nuevo_alumno.num_cursos].calif2 = c2;
            nuevo_alumno.cursos[nuevo_alumno.num_cursos].calif3 = c3;
            strcpy(nuevo_alumno.cursos[nuevo_alumno.num_cursos].curso, curso_input);
            
            calcular_curso(&nuevo_alumno.cursos[nuevo_alumno.num_cursos]);
            suma_calif_finales += nuevo_alumno.cursos[nuevo_alumno.num_cursos].calif_final;
            nuevo_alumno.num_cursos++;
        }
        
        if (nuevo_alumno.num_cursos > 0) {
            nuevo_alumno.promedio_final_alumno = suma_calif_finales / nuevo_alumno.num_cursos;
            suma_promedios_alumnos += nuevo_alumno.promedio_final_alumno;
            cont_total_cursos += nuevo_alumno.num_cursos;
        }

        alumnos[cont_alumnos] = nuevo_alumno;
        cont_alumnos++;
    }

    /* Impresión del Reporte */
    printf("\n=================================================================================\n");
    printf("                                REPORTE DE CURSOS\n");
    printf("=================================================================================\n");
    
    for (int i = 0; i < cont_alumnos; i++) {
        printf("NOMBRE: %s\n", alumnos[i].nombre);
        printf("%-30s %-20s %15s %15s\n", " ", "REPORTE DE CURSOS", "CALIF. FINAL", "OBSERVACIÓN");
        printf("---------------------------------------------------------------------------------\n");

        for (int j = 0; j < alumnos[i].num_cursos; j++) {
            printf("%-30s %-20s %15.2f %15s\n", 
                " ", 
                alumnos[i].cursos[j].curso, 
                alumnos[i].cursos[j].calif_final, 
                alumnos[i].cursos[j].observacion);
        }
        
        /* TOTAL ALUMNO */
        printf("TOTAL ALUMNO %d CURSOS %15.2f\n", 
            alumnos[i].num_cursos, 
            alumnos[i].promedio_final_alumno);
        printf("\n");
    }

    /* TOTAL GENERAL */
    double promedio_general = 0.0;
    if (cont_alumnos > 0) {
        promedio_general = suma_promedios_alumnos / cont_alumnos;
    }
    
    printf("---------------------------------------------------------------------------------\n");
    printf("TOTAL GENERAL %d ALUMNOS %15s %15.2f\n", 
        cont_alumnos, 
        "PROMEDIO GENERAL:", 
        promedio_general);
    printf("=================================================================================\n");

    return 0;
}