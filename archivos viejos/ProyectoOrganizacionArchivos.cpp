//ProyectoOrganizacionArchivos.cpp
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libs/Bitacora.cpp"
#include "libs/Menus.cpp"

struct nodo {
    int hashCode;
    struct nodo *izq, *der;
};
typedef struct nodo *Arbol;

//nombre de la variable



//funcion que crea un nuevo nodo para el arbol de indices
Arbol crearNodo(int claveHash) {
    Arbol nuevoNodo;
    nuevoNodo = new (struct nodo);
    nuevoNodo->hashCode = claveHash;
    return nuevoNodo;
}
//funcion inserta nodo en arbol
bool insertarNodo(Arbol &nodo, int claveHash) {
    bool error = false;
    if (nodo == NULL) {
        nodo = crearNodo(claveHash);
    } else if (claveHash < nodo->hashCode) {
        insertarNodo(nodo->izq, claveHash);
    } else if (claveHash > nodo->hashCode) {
        insertarNodo(nodo->der, claveHash);

    } else {
        error = true;
        printf("Ocurrio un error\n");
    }

    return error;
}

int main() {
    char local_date[25];
    double time_lapse_seconds;
    /*bool (*write_bitacora)(double,char [25]);
    write_bitacora = &escribir_bitacora;*/
/////Obtener hora local/////
    time_t rawtime, segundostranscurridos;
    struct tm *horalocal;
    time(&rawtime);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    horalocal = localtime(&rawtime);//obtiene la fecha y hiora de ejecucion debe ir en el archivo
    Arbol nodo;
//	bool nOO = insertarNodo(nodo,123);
////bloque de tiempo de ejecucion
    menuPrincipal();
    getchar();

////////////////////////////////final de la ejecucion guarda los datos en la bitacora//////////////////////////////
    time(&segundostranscurridos);
    time_lapse_seconds = difftime(segundostranscurridos, rawtime);
    strcpy(local_date, asctime(horalocal));
    escribir_bitacora(time_lapse_seconds, local_date);//funcion llamada de la libreria
    printf("segundos transcurridos: %.3f\n", time_lapse_seconds);
    printf("char time : %s\n", local_date);
    return 0;
}

