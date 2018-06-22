#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>
#include <string>
#include <unistd.h>

typedef struct Curso {
    int codigo;
    char nombre[20];
    char descripcion[100];
    char idioma[20];
    char ultima_fecha[15];
    int duracion;
    int no_asistentes;
    int costo;

} curso;

typedef struct Instructor {
    char nombre[20];
    char nacionalidad[30];
    char domicilio[50];
    int codigo_postal;
    int rfc;
    char curp[20];
    char correo[30];
    int telefono;

} instructor;

void menuPrincipal();

void menucursos();

void menuInstructor();

void menuParticipantes();

curso Curso_Altas();

bool EsUnNumero(const char *);

bool validar_Duracion(int);

bool validarFecha(char [15]);

void mostrarCurso();

bool escribir_bitacora(double, char [25]);

bool guardarCurso(curso);

bool verificar_clave_Unica(int );

curso curso1;
FILE *Escritura_archivo_Cursos, *Lectura_archivo_Cursos;
char nombre_archivo_cursos[] = "Cursos.dat";

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
    //menu principal


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
                curso1 = Curso_Altas();
                if(!guardarCurso(curso1)){
                    printf("Error al escribir el archivo!!!\n");

                }
                fflush(stdin);
                std::cin.ignore(254,'\n');
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
            case 5:
                menuPrincipal();//llamado al menu principal
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
            case 5:
                menuPrincipal();//llamado al menu principal
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
curso Curso_Altas() {
    curso Curso_impartido;
    char temp_fecha[15], temp_duracion[15], temporal_codigo[15], temporal_costo[15];
    int temp_int_duracion;
    bool temp_validar_Clave;
    std::cin.ignore(256, '\n');
    do{
        do {
            printf("Codigo del Curso: ");
            std::cin.getline(temporal_codigo, 15, '\n');
            if (!EsUnNumero(temporal_codigo)) {
                printf("%s", "Codigo incorrecto\n");
            }
        } while (!EsUnNumero(temporal_codigo));
        Curso_impartido.codigo = atoi(temporal_codigo);
        temp_validar_Clave = verificar_clave_Unica(Curso_impartido.codigo);
    }while(temp_validar_Clave == true);//validar si el codigo ya se encuentra regitrado

    //buscar el codigo para aceparlo
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
            std::cout << "\nDuracion en dias [1-5]: ";
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
    curso cursos_disponibles;
    Lectura_archivo_Cursos = fopen(nombre_archivo_cursos,"rb");
    if (Lectura_archivo_Cursos){
        fread(&cursos_disponibles, sizeof(curso),1,Lectura_archivo_Cursos);
        while (!feof(Lectura_archivo_Cursos)){
            //printf(bitacoraEjecucion, "%7.2f\t%45s", tiempo_segundos, fecha);
            printf("Codigo : %d\n",cursos_disponibles.codigo);
            printf("Nombre: %s\n",cursos_disponibles.nombre);
            printf("Descripcion: %s\n",cursos_disponibles.descripcion);
            printf("Idioma: %s\n",cursos_disponibles.idioma);
            printf("Ultima Fecha: %s\n",cursos_disponibles.ultima_fecha);
            printf("Duracion(dias): %d\n",cursos_disponibles.duracion);
            printf("Numero Asistentes: %d\n",cursos_disponibles.no_asistentes);
            printf("Costo : $ %d \n",cursos_disponibles.costo);
            fread(&cursos_disponibles, sizeof(curso),1,Lectura_archivo_Cursos);
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
        //fecha aceptada
        resultado = true;

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

bool guardarCurso(curso cursoActual) {
    Escritura_archivo_Cursos = fopen(nombre_archivo_cursos, "ab+");
    bool guardado= false;
    if (Escritura_archivo_Cursos) {
        fwrite(&cursoActual, sizeof(curso), 1, Escritura_archivo_Cursos);
        guardado = true;
    } else {
        printf("Error al guardar registro!!!\n");
    }
    fclose(Escritura_archivo_Cursos);
    return guardado;
}
//verificaClave(cursoActual.codigo)
bool verificar_clave_Unica(int clave){
    curso AuxiliarCursos;
    bool registro_repetido= false;
    Lectura_archivo_Cursos = fopen(nombre_archivo_cursos,"rb");
    if(Lectura_archivo_Cursos){
        fread(&AuxiliarCursos,sizeof(curso),1,Lectura_archivo_Cursos);
        while(!feof(Lectura_archivo_Cursos)){
            if(clave == AuxiliarCursos.codigo){
                registro_repetido = true;
                break;
            }
            fread(&AuxiliarCursos,sizeof(curso),1,Lectura_archivo_Cursos);
        }
        fclose(Lectura_archivo_Cursos);
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