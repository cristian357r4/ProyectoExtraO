#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>
#include <string>
#include <unistd.h>

typedef struct item {
    int clave;
    int posicion;
    struct item *left;
    struct item *right;
} *Item;
typedef struct Curso {
    int codigo;
    char nombre[20];
    char descripcion[100];
    char idioma[20];
    char ultima_fecha[15];
    int duracion;
    int no_asistentes;
    int costo;
} cursos;

typedef struct Participantes {
    int claveParticipante;
    char nombre[20];
    char nacionalidad[30];
    char domicilio[50];
    int codigo_postal;
    char correo_elec[30];
    int telefono;

} participantes;


typedef struct Instructor {
    int claveInstructor;
    char nombre[20];
    char nacionalidad[30];
    char domicilio[50];
    int codigo_postal;
    int rfc;
    char curp[20];
    char correo[30];
    int telefono;
} instructores;

void menuPrincipal();
void menucursos();
void menuInstructor();
void menuParticipantes();
cursos Curso_Altas();
bool EsUnNumero(const char *);
bool validar_Duracion(int);
bool validarFecha(char [15]);
void mostrarCurso();
bool escribir_bitacora(double, char [25]);
bool guardarCurso(cursos);
bool verificar_clave_Unica(int);
void AddNode(int, Item &, int);
void cargar_Participantes_Arbol();
void cargar_Instuctores_Arbol();
void cargar_Cursos_Arbol();
void Arbol_mostrar(Item &);

cursos curso;
instructores instructor;
participantes participante;
FILE *Cursos_Escritura_archivo, *Cursos_Lectura_archivo,
        *Instructor_Escritura_archivo, *Instructor_Lectura_archivo,
        *Participante_Escritura_archivo, *Participante_Lectura_archivo;
char nombre_archivo_cursos[] = "Cursos.dat", nombre_archivo_instructor[] = "Instructor.dat",
        nombre_archivo_participante[] = "Participante.dat";

Item Arbol_Cursos = NULL, Arbol_Participantes = NULL, Arbol_Instructores = NULL;

int main() {

    std::cout << "Datos guardados en el arbol\n";
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

/////////////////////MENUS /////////////////////////////
void menuPrincipal() {
    cargar_Cursos_Arbol();
    Arbol_mostrar(Arbol_Cursos);
    int op;
    do {
        fflush(stdin);
        system("cls");
        system("clear");
        //limpiar pantalla
        printf("PROYECTO \n");
        printf("1.   CURSOS.....\n");
        printf("2.   INSTRUCTORES ......\n");
        printf("3.   ESTUDIANTES....\n");
        printf("4.   INFORMES ....\n");
        printf("5.   ADMINISTRACION ....\n");
        printf("6.   AYUDA ....\n");
        printf("7.   SALIR ....\n");
        scanf("%d", &op);
        switch (op) {
            case 1:/*Cursos*/
                menucursos();
                break;
            case 2:/*Instructores*/
                menuInstructor();
                break;
            case 3://Estudiantes
                menuParticipantes();
                break;
            case 4://informes
                system("cls");//limpiar pantalla
                printf("\t\t ¡¡Gracias por usar esta aplicacion!! ^____^// ");
                break;
            case 5://administracion

                break;
            case 6://ayuda

                break;
            case 7:
                printf("Saliendo\n");
                for (int (i) = 0; (i) < 50; (i)++) {

                    printf("%s", ".");
                    fflush(stdout);
                    usleep(10000);
                }
                printf("\n");
                break;
            default:
                system("cls");
                printf("\n\n\n\t\t Opcion erronea\n\n");
                break;//Salir del caso
        }
    } while (op != 7);
}

void menucursos() {//menu de cursos

    system("cls");
    system("clear");
    int opcd;
    do {
        system("cls");
        system("clear");
        printf("\n\n");
        printf("\n\t\t\t CURSOS \n\n");
        printf("\n\t\t\t 1.Agregar cursos");
        printf("\n\t\t\t 2.Eliminar curso");
        printf("\n\t\t\t 3.Modificar datos");
        printf("\n\t\t\t 4.Concultar total de cursos");
        printf("\n\t\t\t 5.Consultar alumnos por curso");
        printf("\n\t\t\t 6.Regresar");
        printf("\n\n\n");
        printf(" \t\t\t\t ");
        scanf("%d", &opcd);
        switch (opcd) {
            case 1:
                curso = Curso_Altas();
                if (!guardarCurso(curso)) {
                    printf("Error al escribir el archivo!!!\n");

                }
                fflush(stdin);
                //std::cin.ignore(254, '\n');
                getchar();
                //alta_curso();//Hacer llamado al modulo de altas de cursos
                //getch();
                break;
            case 2:
                //eliminar_curso();//hacer llamado al modulo para eliminar un curso
                //getch();
                break;
            case 3:
                //modi_curso();//hacer llamado al mddulo para modificar un curso
                //getch();
                break;
            case 4:
                mostrarCurso();
                //consu_curso();//hacer llamado al modulo para consultar un curso
                break;
            case 5:
                //consu_GG();//hacer llamado al modulo para consultar alumnos por curso
                break;
            default:
                system("cls");
                printf("\n\n\n\t\t Opcion erronea\n\n");
                break;
        }
    } while (opcd != 6);
}

void menuInstructor() {//menu de los instructores
    system("cls");
    system("clear");
    int opc;
    do {
        system("cls");
        system("clear");
        printf("\n\n");
        printf("\n\t\t\t INSTRUCTORES \n\n");
        printf("\n\t\t\t 1.Agregar instructor");
        printf("\n\t\t\t 2.Eliminar instructor");
        printf("\n\t\t\t 3.Modificar datos");
        printf("\n\t\t\t 4.Asignar nuevo curso");
        printf("\n\t\t\t 7.Regresar");
        printf("\n\n\n");
        printf(" \t\t\t\t ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                //altas();//llamado al odulo para altas de instructores
                //getch();
                break;
            case 2:
                ///eliminar();//hacer el llamado al menu de eliminar instructores
                break;
            case 3:
                //ejemplar();//hacer el llamado al menu para modificar datos personales del instructor
                break;
            case 4:
                //ejemplar1();//Hacer el llamado al menu para asignar nuevos cursos
                break;

            default:
                system("cls");
                printf("\n\n\n\t\t Opcion erronea\n\n");
                break;
        }
    } while (opc != 5);
}

void menuParticipantes() {//menu de los instructores
    system("cls");
    system("clear");
    int opc;
    do {
        system("cls");
        system("clear");
        printf("\n\n");
        printf("\n\t\t\t PARTICIPANTES \n\n");
        printf("\n\t\t\t 1.Agregar participante");
        printf("\n\t\t\t 2.Eliminar participante");
        printf("\n\t\t\t 3.Modificar datos");
        printf("\n\t\t\t 4.Asignar nuevo curso");
        printf("\n\t\t\t 7.Regresar");
        printf("\n\n\n");
        printf(" \t\t\t\t ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                //altas();//llamado al odulo para altas de participantes
                //getch();
                break;
            case 2:
                //eliminar();//hacer el llamado al menu de eliminar participantes
                break;
            case 3:
                //ejemplar();//hacer el llamado al menu para modificar datos personales del participante
                break;
            case 4:
                //ejemplar1();//Hacer el llamado al menu para asignar nuevos cursos
                break;
            default:
                system("cls");
                printf("\n\n\n\t\t Opcion erronea\n\n");
                break;
        }
    } while (opc != 5);
}
////////////////FIN MENUS ////////////////////////////

////////////////////cursos///////////////////////////
cursos Curso_Altas() {
    cursos Curso_impartido;
    char temp_fecha[15], temp_duracion[15], temporal_codigo[15], temporal_costo[15];
    int temp_int_duracion;
    bool temp_validar_Clave;
    std::cin.ignore(256, '\n');
    do {
        do {
            printf("Codigo del Curso: ");
            std::cin.getline(temporal_codigo, 15, '\n');
            if (!EsUnNumero(temporal_codigo)) {
                printf("%s", "Codigo incorrecto\n");
            }
        } while (!EsUnNumero(temporal_codigo));
        Curso_impartido.codigo = atoi(temporal_codigo);
        temp_validar_Clave = verificar_clave_Unica(Curso_impartido.codigo);
    } while (temp_validar_Clave == true);//validar si el codigo ya se encuentra regitrado
    printf("Nombre del Curso: ");
    std::cin.getline(Curso_impartido.nombre, 20, '\n');
    printf("Descripcion: ");
    std::cin.getline(Curso_impartido.descripcion, 100, '\n');
    printf("Idioma: ");
    std::cin.getline(Curso_impartido.idioma, 20, '\n');
    do {
        printf("Ingresa la fecha con el formato M-D-YYYY o MM-DD-YYYY: ");
        std::cin.getline(temp_fecha, 15, '\n');
    } while (!validarFecha(temp_fecha));//si la fecha se introdujo en el formato especifico avanza y devuelve true
    strcpy(Curso_impartido.ultima_fecha, temp_fecha);
    do {
        do {
            std::cout << "Duracion en dias [1-5]: ";
            std::cin.getline(temp_duracion, 15, '\n');
            if (!EsUnNumero(temp_duracion)) {
                printf("Ingresa un numero!!\n");
            }
        } while (!EsUnNumero(temp_duracion));
        temp_int_duracion = atoi(temp_duracion);
    } while (!validar_Duracion(temp_int_duracion));
    Curso_impartido.duracion = temp_int_duracion;
    do {
        printf("Ingresa el costo : $");
        std::cin.getline(temporal_costo, 15, '\n');
        if (!EsUnNumero(temporal_costo)) {
            printf("Ingrese un numero!!\n");
        }
    } while (!EsUnNumero(temporal_costo));
    Curso_impartido.costo = atoi(temporal_costo);
    printf("Guardando registro\n");
    for (int (i) = 0; (i) < 50; (i)++) {
        printf("%s", ".");
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    return Curso_impartido;
}

void mostrarCurso() {
    cursos cursos_disponibles;
    Cursos_Lectura_archivo = fopen(nombre_archivo_cursos, "rb");
    if (Cursos_Lectura_archivo) {
        fread(&cursos_disponibles, sizeof(cursos), 1, Cursos_Lectura_archivo);
        while (!feof(Cursos_Lectura_archivo)) {
            //printf(bitacoraEjecucion, "%7.2f\t%45s", tiempo_segundos, fecha);
            printf("--------------------------------------------\n");
            printf("Codigo : %d\n", cursos_disponibles.codigo);
            printf("Nombre: %s\n", cursos_disponibles.nombre);
            printf("Descripcion: %s\n", cursos_disponibles.descripcion);
            printf("Idioma: %s\n", cursos_disponibles.idioma);
            printf("Ultima Fecha: %s\n", cursos_disponibles.ultima_fecha);
            printf("Duracion(dias): %d\n", cursos_disponibles.duracion);
            printf("Numero Asistentes: %d\n", cursos_disponibles.no_asistentes);
            printf("Costo : $ %d \n", cursos_disponibles.costo);
            printf("--------------------------------------------\n");
            fread(&cursos_disponibles, sizeof(cursos), 1, Cursos_Lectura_archivo);
        }
    }
    printf("Saliendo\n");
    for (int (i) = 0; (i) < 50; (i)++) {
        printf("%s", ".");
        fflush(stdout);
        usleep(100000);
    }
    fflush(stdin);
    getchar();
}

bool validarFecha(char temp_fecha[15]) {
    bool resultado = false;
    if (std::regex_match(temp_fecha,
                         std::regex("^(0?[1-9]|1[0-2])[\\-](0?[1-9]|[12]\\d|3[01])[\\-](19|20)\\d{2}$"))) {
        resultado = true;//fecha aceptada
    } else {
        std::cout << "\nfecha incorrecta\n";
        //mantiene el valor de bandera para pedir nuevamente la fecha
    }
    return resultado;
}

bool validar_Duracion(int duracion) {
    bool resultado = false;
    if (duracion <= 5 && duracion >= 1) {
        resultado = true;
    }
    return resultado;
}

bool EsUnNumero(const char *cadena) {
    bool respuesta = false;
    for (; *cadena; ++cadena) {
        // En cuanto un caracter no sea numérico
        if (std::isdigit(*cadena))
            respuesta = true;
    }
    return respuesta;
}

bool guardarCurso(cursos cursoActual) {
    Cursos_Escritura_archivo = fopen(nombre_archivo_cursos, "ab+");
    bool guardado = false;
    if (Cursos_Escritura_archivo) {
        fwrite(&cursoActual, sizeof(cursos), 1, Cursos_Escritura_archivo);
        guardado = true;
    } else {
        printf("Error al guardar registro!!!\n");
    }
    fclose(Cursos_Escritura_archivo);
    return guardado;
}

//verificaClave(cursoActual.codigo)
bool verificar_clave_Unica(int clave) {
    cursos AuxiliarCursos;
    bool registro_repetido = false;
    Cursos_Lectura_archivo = fopen(nombre_archivo_cursos, "rb");
    if (Cursos_Lectura_archivo) {
        fread(&AuxiliarCursos, sizeof(cursos), 1, Cursos_Lectura_archivo);
        while (!feof(Cursos_Lectura_archivo)) {
            if (clave == AuxiliarCursos.codigo) {
                registro_repetido = true;
                break;
            }
            fread(&AuxiliarCursos, sizeof(cursos), 1, Cursos_Lectura_archivo);
        }
        fclose(Cursos_Lectura_archivo);
    }
    return registro_repetido;
}
///////////////////fin cursos ///////////////////////

//////////////////////BITACORA//////////////////////
bool escribir_bitacora(double tiempo_segundos, char fecha[25]) {
    FILE *bitacoraEjecucion;
    bool estadoApertura = true;
    bitacoraEjecucion = fopen("bitacoraEjecucion.txt", "a+");
    if (bitacoraEjecucion != NULL) {
        fprintf(bitacoraEjecucion, "%7.2f\t%45s", tiempo_segundos, fecha);
        fclose(bitacoraEjecucion);
    } else {
        estadoApertura = false;
    }
    return estadoApertura;
}
////////////////////////////////////////////////////

/////////////////FUNCIONES DEL ARBOL/////////////////

/////////////////AGREGA NODO AL ARBOL O LO CREA///////
//se puede usar en la funcion guardar Curso, participante, tutor Item & cambia dependiendo del arbol
// node con el que se trabaja en el momento
//unicamente contando el numero de cursos
void AddNode(int clave, Item &node, int posicion) {
    //la posicion debe hacerse contanto todos los registros de el archivo
    //debes agregar el nodo al arbol no hay campos vacios
    //bool agredado = false;
    if (node == NULL) {
        node = new (struct item);
        node->clave = clave;
        node->posicion = posicion;
        node->left = node->right = NULL;
        //agredado = true;
    } else {
        //como no hay posiciones vacias se agrega normalmente la comprobacion se hizo
        //de manera externa
        if (clave < node->clave) {
            AddNode(clave, node->left, posicion);
        } else if (clave > node->clave) {
            AddNode(clave, node->right, posicion);
        }
        // no necesario ya que no hay calves iguales
        /*else {
            AddNode(clave + 1, node->right, posicion);
        }*/
    }
}

//debera agregar solo un elemento asi podemos llamar tambien en la funcion
//de agregacion individual del registro, y se usara varias veces con el archivo osea en un ciclo
void cargar_Cursos_Arbol() {
    cursos auxiliar_curso;
    Cursos_Lectura_archivo = fopen(nombre_archivo_cursos, "rb");
    int posicion_Registro = 0;
    if (Cursos_Lectura_archivo) {
        std::cout <<"abrio bien el archivo de Cursos \n";
        fread(&auxiliar_curso, sizeof(cursos), 1, Cursos_Lectura_archivo);
        while (!feof(Cursos_Lectura_archivo)) {
            std::cout <<"codigo: "<<auxiliar_curso.codigo <<"- posicion:"<<posicion_Registro<<std::endl;
            AddNode(auxiliar_curso.codigo, Arbol_Cursos, posicion_Registro);
            fread(&auxiliar_curso, sizeof(cursos), 1, Cursos_Lectura_archivo);
            posicion_Registro++;
        }
        std::cout << "funcion de cargar datos en arbol\n";
        std::cout << Arbol_Cursos << std::endl;
        getchar();
        fclose(Cursos_Lectura_archivo);
    }
}

void cargar_Instuctores_Arbol() {
    instructores auxiliar_instructor;
    Instructor_Lectura_archivo = fopen(nombre_archivo_instructor, "rb");
    int posicion_Registro = 0;
    if (Instructor_Lectura_archivo) {
        fread(&auxiliar_instructor, sizeof(instructores), 1, Instructor_Lectura_archivo);
        while (feof(Instructor_Lectura_archivo)) {
            AddNode(auxiliar_instructor.claveInstructor, Arbol_Instructores, posicion_Registro);
            fread(&auxiliar_instructor, sizeof(instructores), 1, Instructor_Lectura_archivo);
            posicion_Registro++;
        }
        fclose(Instructor_Lectura_archivo);
    }
}
void cargar_Participantes_Arbol() {
    participantes auxiliar_participantes;
    Participante_Lectura_archivo = fopen(nombre_archivo_participante, "rb");
    int posicion_Registro = 0;
    if (Participante_Lectura_archivo) {
        fread(&auxiliar_participantes, sizeof(participantes), 1, Participante_Lectura_archivo);
        while (feof(Instructor_Lectura_archivo)) {
            AddNode(auxiliar_participantes.claveParticipante, Arbol_Participantes, posicion_Registro);
            fread(&auxiliar_participantes, sizeof(participantes), 1, Participante_Lectura_archivo);
            posicion_Registro++;
        }
        fclose(Participante_Lectura_archivo);
    }
}
void Arbol_mostrar(Item &Arbol){
    if (Arbol->left) {
        Arbol_mostrar(Arbol->left);
    }
    printf("clave [%d] - posicion [%d]", Arbol->clave, Arbol->posicion);
    if (Arbol->right) {
        Arbol_mostrar(Arbol->right);
    }
}
////////////////////FINAL DE FUNCIONES DE ARBOL////////////////////