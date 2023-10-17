#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct futbo {
    int numeroEquipo;
    char nombreEquipo[50];
};

//funcion de presentacion.
void caratula(){
    printf("------PROYECTO FINAL PROGRAMACION II------\n");
    printf("------MANEJO DE UNA LIGA DE FÚTBOL------\n\n");
    printf("Este programa sirve como el manejo de una liga de fútbol. Dados 8 equipos iniciales, pasarán por las fases de un torneo, donde habrá un ganador final. Se hace uso de apuntadores, struct y archivos para almacenar toda la información del torneo.\n\n");
    printf("Integrantes:\n\n");
    printf("Bolaños De la O Fernanda\n");
    printf("Carrillo Aldana Jorge\n");
    printf("Rodarte Rosales Jesús Eduardo\n");
    system("pause");
    system("cls");
}

//esta funcion almacena los nombres de los equipos en el archivo torneo.txt
void NombreEquipos() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct futbo equipos[8];
    int i;

    fprintf(archivo, "Nombre Equipos\n");

    printf("Ingrese el nombre de los equipos:\n");
    for (i = 0; i < 8; i++) {
        printf("Equipo %d: ", i + 1);
        scanf(" %[^\n]", equipos[i].nombreEquipo); // Leer la línea completa incluyendo espacios

        equipos[i].numeroEquipo = i + 1;
        fprintf(archivo, "Equipo %d %s\n", equipos[i].numeroEquipo, equipos[i].nombreEquipo);
    }

    fclose(archivo);

    printf("\nNombres de equipos guardados exitosamente en torneo.txt.\n");
}

//esta funcion asigna las fechas en el primer enfrentamiento
void Calendario() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct futbo equipos[8];
    int i;

    // Leer los nombres de los equipos desde el archivo
    fscanf(archivo, "Nombre Equipos\n");
    for (i = 0; i < 8; i++) {
        fscanf(archivo, "Equipo %d %s\n", &equipos[i].numeroEquipo, equipos[i].nombreEquipo);
    }

    // Escribir los enfrentamientos con los nombres de los equipos
    fprintf(archivo, "\nFechas de enfrentamiento\n");
    fprintf(archivo, "Fecha 1: Enfrentamiento %s vs %s\n", equipos[0].nombreEquipo, equipos[1].nombreEquipo);
    fprintf(archivo, "Fecha 2: Enfrentamiento %s vs %s\n", equipos[2].nombreEquipo, equipos[3].nombreEquipo);
    fprintf(archivo, "Fecha 3: Enfrentamiento %s vs %s\n", equipos[4].nombreEquipo, equipos[5].nombreEquipo);
    fprintf(archivo, "Fecha 4: Enfrentamiento %s vs %s\n", equipos[6].nombreEquipo, equipos[7].nombreEquipo);

    fclose(archivo);

    printf("\nFechas de enfrentamiento guardadas exitosamente en torneo.txt.\n");
}

//cuartos de final
void Enfrentamientos() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct futbo equipos[8];
    int i;

    // Leer los nombres de los equipos desde el archivo
    fscanf(archivo, "Nombre Equipos\n");
    for (i = 0; i < 8; i++) {
        fscanf(archivo, "Equipo %d %s\n", &equipos[i].numeroEquipo, equipos[i].nombreEquipo);
    }

    fprintf(archivo, "\nGanadores de primera fase\n");

    printf("Ingrese los resultados de los enfrentamientos:\n");

    int golesE1, golesE2;
    do {
        printf("\nEnfrentamiento %s vs %s\n", equipos[0].nombreEquipo, equipos[1].nombreEquipo);
        printf("Goles %s: ", equipos[0].nombreEquipo);
        scanf("%d", &golesE1);
        printf("Goles %s: ", equipos[1].nombreEquipo);
        scanf("%d", &golesE2);

        if (golesE1 == golesE2) {
            printf("Error: Ingresa dos cantidades diferentes de goles.\n");
        }
    } while (golesE1 == golesE2);

    char ganador1[50];
    if (golesE1 > golesE2) {
        sprintf(ganador1, "%s", equipos[0].nombreEquipo);
    } else if (golesE1 < golesE2) {
        sprintf(ganador1, "%s", equipos[1].nombreEquipo);
    } else {
        sprintf(ganador1, "Empate"); // al final no se hace uso de esta línea porque implementamos do while para asegurar que no hayan empates
    }

    fprintf(archivo, "Enfrentamiento %s vs %s\n", equipos[0].nombreEquipo, equipos[1].nombreEquipo);
    fprintf(archivo, "Goles %s: %d\n", equipos[0].nombreEquipo, golesE1);
    fprintf(archivo, "Goles %s: %d\n", equipos[1].nombreEquipo, golesE2);
    fprintf(archivo, "Ganador: %s\n", ganador1);

    int golesE3, golesE4;
    do {
        printf("\nEnfrentamiento %s vs %s\n", equipos[2].nombreEquipo, equipos[3].nombreEquipo);
        printf("Goles %s: ", equipos[2].nombreEquipo);
        scanf("%d", &golesE3);
        printf("Goles %s: ", equipos[3].nombreEquipo);
        scanf("%d", &golesE4);

        if (golesE3 == golesE4) {
            printf("Error: Ingresa dos cantidades diferentes de goles.\n");
        }
    } while (golesE3 == golesE4);


    char ganador2[50];
    if (golesE3 > golesE4) {
        sprintf(ganador2, "%s", equipos[2].nombreEquipo);
    } else if (golesE3 < golesE4) {
        sprintf(ganador2, "%s", equipos[3].nombreEquipo);
    } else {
        sprintf(ganador2, "Empate"); // al final no se hace uso de esta línea porque implementamos do while para asegurar que no hayan empates
    }
    fprintf(archivo, "Enfrentamiento %s vs %s\n", equipos[2].nombreEquipo, equipos[3].nombreEquipo);
    fprintf(archivo, "Goles %s: %d\n", equipos[2].nombreEquipo, golesE3);
    fprintf(archivo, "Goles %s: %d\n", equipos[3].nombreEquipo, golesE4);
    fprintf(archivo, "Ganador: %s\n", ganador2);

    int golesE5, golesE6;
    do {
        printf("\nEnfrentamiento %s vs %s\n", equipos[4].nombreEquipo, equipos[5].nombreEquipo);
        printf("Goles %s: ", equipos[4].nombreEquipo);
        scanf("%d", &golesE5);
        printf("Goles %s: ", equipos[5].nombreEquipo);
        scanf("%d", &golesE6);

        if (golesE5 == golesE6) {
            printf("Error: Ingresa dos cantidades diferentes de goles.\n");
        }
    } while (golesE5 == golesE6);


    char ganador3[50];
    if (golesE5 > golesE6) {
        sprintf(ganador3, "%s", equipos[4].nombreEquipo);
         } else if (golesE5 < golesE6) {
        sprintf(ganador3, "%s", equipos[5].nombreEquipo);
    } else {
        sprintf(ganador3, "Empate"); // al final no se hace uso de esta línea porque implementamos do while para asegurar que no hayan empates
    }
    fprintf(archivo, "Enfrentamiento %s vs %s\n", equipos[4].nombreEquipo, equipos[5].nombreEquipo);
    fprintf(archivo, "Goles %s: %d\n", equipos[4].nombreEquipo, golesE5);
    fprintf(archivo, "Goles %s: %d\n", equipos[5].nombreEquipo, golesE6);
    fprintf(archivo, "Ganador: %s\n", ganador3);

    int golesE7, golesE8;
    do {
        printf("\nEnfrentamiento %s vs %s\n", equipos[6].nombreEquipo, equipos[7].nombreEquipo);
        printf("Goles %s: ", equipos[6].nombreEquipo);
        scanf("%d", &golesE7);
        printf("Goles %s: ", equipos[7].nombreEquipo);
        scanf("%d", &golesE8);

        if (golesE7 == golesE8) {
            printf("Error: Ingresa dos cantidades diferentes de goles.\n");
        }
    } while (golesE7 == golesE8);


    char ganador4[50];
    if (golesE7 > golesE8) {
        sprintf(ganador4, "%s", equipos[6].nombreEquipo);
    } else if (golesE7 < golesE8) {
        sprintf(ganador4, "%s", equipos[7].nombreEquipo);
    } else {
        sprintf(ganador4, "Empate"); // al final no se hace uso de esta línea porque implementamos do while para asegurar que no hayan empates
    }
    fprintf(archivo, "Enfrentamiento %s vs %s\n", equipos[6].nombreEquipo, equipos[7].nombreEquipo);
    fprintf(archivo, "Goles %s: %d\n", equipos[6].nombreEquipo, golesE7);
    fprintf(archivo, "Goles %s: %d\n", equipos[7].nombreEquipo, golesE8);
    fprintf(archivo, "Ganador: %s\n", ganador4);

    fprintf(archivo, "\n");

    fclose(archivo);

    printf("\nResultados de los enfrentamientos guardados exitosamente en torneo.txt.\n");
}


void SF() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct futbo equipos[8];
    int i;

    // Leer los nombres de los equipos desde el archivo
    fscanf(archivo, "Nombre Equipos\n");
    for (i = 0; i < 8; i++) {
        fscanf(archivo, "Equipo %d %s\n", &equipos[i].numeroEquipo, equipos[i].nombreEquipo);
    }

    // Leer los ganadores de primera fase desde el archivo
    fscanf(archivo, "\nGanadores de primera fase\n");

    char ganador1[50], ganador2[50], ganador3[50], ganador4[50];

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador1);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador2);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador3);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador4);

    printf("\nEquipos ganadores de primera fase:\n");
    printf("1. %s\n", ganador1);
    printf("2. %s\n", ganador2);
    printf("3. %s\n", ganador3);
    printf("4. %s\n", ganador4);

    fclose(archivo);
}

void SF1() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct futbo equipos[8];
    int i;

    // Leer los nombres de los equipos desde el archivo
    fscanf(archivo, "Nombre Equipos\n");
    for (i = 0; i < 8; i++) {
        fscanf(archivo, "Equipo %d %s\n", &equipos[i].numeroEquipo, equipos[i].nombreEquipo);
    }

    // Leer los ganadores de primera fase desde el archivo
    fscanf(archivo, "\nGanadores de primera fase\n");

    char ganador1[50], ganador2[50], ganador3[50], ganador4[50];

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador1);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador2);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador3);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador4);

    fclose(archivo);

    printf("\nSemifinales 1:\n");

    int golesSF1_1, golesSF1_2;
    do {
        printf("Enfrentamiento: %s vs %s\n", ganador1, ganador2);
        printf("Ingrese los goles para cada equipo:\n");
        printf("Goles %s: ", ganador1);
        scanf("%d", &golesSF1_1);
        printf("Goles %s: ", ganador2);
        scanf("%d", &golesSF1_2);

        if (golesSF1_1 == golesSF1_2) {
            printf("Error: Ingresa dos cantidades diferentes de goles.\n");
        }
    } while (golesSF1_1 == golesSF1_2);


    char ganadorSF1_1[50], ganadorSF1_2[50];
    if (golesSF1_1 > golesSF1_2) {
        sprintf(ganadorSF1_1, "%s", ganador1);
        sprintf(ganadorSF1_2, "%s", ganador2);
    } else if (golesSF1_1 < golesSF1_2) {
        sprintf(ganadorSF1_1, "%s", ganador2);
        sprintf(ganadorSF1_2, "%s", ganador1);
    } else {
        printf("Hubo un empate en la semifinal 1. Se requiere una definición adicional.\n"); // al final no se hace uso de esta línea porque implementamos do while para asegurar que no hayan empates
        return;
    }

    archivo = fopen("torneo.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "\nSemifinales 1\n");
    fprintf(archivo, "Enfrentamiento: %s vs %s\n", ganador1, ganador2);
    fprintf(archivo, "Goles %s: %d\n", ganador1, golesSF1_1);
    fprintf(archivo, "Goles %s: %d\n", ganador2, golesSF1_2);
    fprintf(archivo, "Ganador: %s\n", ganadorSF1_1);

    fclose(archivo);

    printf("Resultados de la semifinal 1 guardados exitosamente en torneo.txt.\n");
}
void SF2() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct futbo equipos[8];
    int i;

    // Leer los nombres de los equipos desde el archivo
    fscanf(archivo, "Nombre Equipos\n");
    for (i = 0; i < 8; i++) {
        fscanf(archivo, "Equipo %d %s\n", &equipos[i].numeroEquipo, equipos[i].nombreEquipo);
    }

    // Leer los ganadores de primera fase desde el archivo
    fscanf(archivo, "\nGanadores de primera fase\n");

    char ganador1[50], ganador2[50], ganador3[50], ganador4[50];

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador3);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador4);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador3);

    fscanf(archivo, "Enfrentamiento %*s vs %*s\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Goles %*s: %*d\n");
    fscanf(archivo, "Ganador: %s\n", ganador4);

    fclose(archivo);

    printf("\nSemifinales 2:\n");

    int golesSF2_1, golesSF2_2;
    do {
        printf("Enfrentamiento: %s vs %s\n", ganador3, ganador4);
        printf("Ingrese los goles para cada equipo:\n");
        printf("Goles %s: ", ganador3);
        scanf("%d", &golesSF2_1);
        printf("Goles %s: ", ganador4);
        scanf("%d", &golesSF2_2);

        if (golesSF2_1 == golesSF2_2) {
            printf("Error: Ingresa dos cantidades diferentes de goles.\n");
        }
    } while (golesSF2_1 == golesSF2_2);


    char ganadorSF2_1[50], ganadorSF2_2[50];
    if (golesSF2_1 > golesSF2_2) {
        sprintf(ganadorSF2_1, "%s", ganador3);
        sprintf(ganadorSF2_2, "%s", ganador4);
    } else if (golesSF2_1 < golesSF2_2) {
        sprintf(ganadorSF2_1, "%s", ganador4);
        sprintf(ganadorSF2_2, "%s", ganador3);
    } else {
        printf("Hubo un empate en la semifinal 2. Se requiere una definición adicional.\n"); // al final no se hace uso de esta línea porque implementamos do while para asegurar que no hayan empates
        return;
    }

    archivo = fopen("torneo.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "\nSemifinales 2\n");
    fprintf(archivo, "Enfrentamiento: %s vs %s\n", ganador3, ganador4);
    fprintf(archivo, "Goles %s: %d\n", ganador3, golesSF2_1);
    fprintf(archivo, "Goles %s: %d\n", ganador4, golesSF2_2);
    fprintf(archivo, "Ganador: %s\n", ganadorSF2_1);

    fclose(archivo);

    printf("Resultados de la semifinal 2 guardados exitosamente en torneo.txt.\n");
}
void Finalistas() {
    FILE *archivo;
    archivo = fopen("torneo.txt", "r+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char ganadorSF1[50], ganadorSF2[50];
    int maxGolesSF1 = -1, maxGolesSF2 = -1;
    char linea[100];

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (strstr(linea, "Semifinales 1") != NULL) {
            fgets(linea, sizeof(linea), archivo);  // Saltar la línea de título
            fgets(linea, sizeof(linea), archivo);  // Obtener la línea del enfrentamiento
            fgets(linea, sizeof(linea), archivo);  // Obtener la línea de los goles
            int golesSF1;
            sscanf(linea, "Goles %[^:]: %d", ganadorSF1, &golesSF1);
            if (golesSF1 > maxGolesSF1) {
                maxGolesSF1 = golesSF1;
            }
        } else if (strstr(linea, "Semifinales 2") != NULL) {
            fgets(linea, sizeof(linea), archivo);  // Saltar la línea de título
            fgets(linea, sizeof(linea), archivo);  // Obtener la línea del enfrentamiento
            fgets(linea, sizeof(linea), archivo);  // Obtener la línea de los goles
            int golesSF2;
            sscanf(linea, "Goles %[^:]: %d", ganadorSF2, &golesSF2);
            if (golesSF2 > maxGolesSF2) {
                maxGolesSF2 = golesSF2;
            }
        }
    }

    printf("Los finalistas son:\n");
    printf("- %s (Ganador de la SF1)\n", ganadorSF1);
    printf("- %s (Ganador de la SF2)\n", ganadorSF2);

    printf("\nSimulación de la final:\n");
    printf("Enfrentamiento: %s vs %s\n", ganadorSF1, ganadorSF2);
    printf("Ingrese los goles para cada equipo:\n");
    int golesFinal1, golesFinal2;
    printf("Goles %s: ", ganadorSF1);
    scanf("%d", &golesFinal1);
    printf("Goles %s: ", ganadorSF2);
    scanf("%d", &golesFinal2);

    printf("\nResultado de la final:\n");
    char campeon[50];
   
   
    if (golesFinal1 > golesFinal2) {
        printf("%s gana la final con un resultado de %d-%d\n", ganadorSF1, golesFinal1, golesFinal2);
        strcpy(campeon, ganadorSF1);
    } else if (golesFinal1 < golesFinal2) {
        printf("%s gana la final con un resultado de %d-%d\n", ganadorSF2, golesFinal2, golesFinal1);
        strcpy(campeon, ganadorSF2);
       
    // al final no se usa porque no pueden haber empates
    } else {
        printf("Hubo un empate en la final. Se requiere una definición adicional.\n");
        return;
    }

    // Guardar el campeón en el archivo
    fseek(archivo, 0, SEEK_END);
    fprintf(archivo, "Campeon Del Torneo:\n");
    fprintf(archivo, "%s\n", campeon);

    fclose(archivo);
}

int main() {

    //llamada a las funciones en main, haciendo el programa lo más modular posible
    caratula();
    NombreEquipos();
    Calendario();
    Enfrentamientos();
    SF();
SF1();
SF2();
Finalistas();

system("pause");

    return 0;
}
