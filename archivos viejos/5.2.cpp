/* There're some numbers in the text file. Using a binary tree that program will display the numbers
from the text file sorted from the smallest to the largest.

task_02.06.2010 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


// Structure for a tree node
typedef struct item {
    int clave;
    int posicion;
    struct item *left;
    struct item *right;
} *Item;
struct
{
    int codigo;
    char nombre[20];
    char descripcion[100];
    char idioma[20];
    char ultima_fecha[15];
    int duracion;
    int no_asistentes; /// debe estar vacio pero se llena cada que se agrega un asistente
    int costo;

}Curso;


bool AddNode(int , Item &, int );
int Cliente_Agregar();
void LeftOrder(Item &node);
Item root = NULL;//crea la raiz del arbol y le asuga null
int main() {

    char buffer[128];
    int i;

    FILE *fp = fopen("ex52.txt", "r");
    if (!fp) {
        std::cout << "no hay datos\n";
        exit(1);
    }//exit(1); // exit if the file opening is failed



    // reading values from the file
    int posiciondentro_del_dato_en_archivo = 0;
    int numeros_negativo = 0;

    while (fgets(buffer, 128, fp) != NULL) {
        if(AddNode(atoi(buffer), root, posiciondentro_del_dato_en_archivo)){
            printf("Nodo [%d] agregado con valor [%d]\n",posiciondentro_del_dato_en_archivo,atoi(buffer));
            posiciondentro_del_dato_en_archivo++;
        }else{
            printf("-1 encontrado en la posicion [%d]\n", numeros_negativo);
        }
        numeros_negativo++;
    }

    fclose(fp);
    if (root == NULL) {
        printf("arbol vacio\n");
    } else {

        LeftOrder(root);

    }

    char c; // exit from the program
    puts("\n\nEnter \"Y\" and press \"Enter\" for exit");
    do
        c = getchar();
    while (c != 'Y' && c != 'y');
    return 0;
}

//funcion inserta los nuevos nodos con la informacion
//buscar dar la posicion tambien la posicion esta desfasada debio a que no acepta el menos 1
bool AddNode(int clave, Item &node, int posicion) {
     bool agregdo = true;
    if (node == NULL) {
        node = new (struct item);
        node->clave = clave;
        node->posicion = posicion;
        node->left = node->right = NULL;

    } else {
        if (clave != -1) {
            if (clave < node->clave) {
                AddNode(clave, node->left, posicion);
            } else if (clave > node->clave) {
                AddNode(clave, node->right, posicion);
            } else {
                AddNode(clave+1,node->right,posicion);
            }
        }else {
            agregdo = false;
        }
    }
    return agregdo;
}

// Bypassing the tree on the left (in ascending order)
void LeftOrder(Item &node) {
    if (node->left) {
        LeftOrder(node->left);

    }
    printf("%d ", node->clave);
    if (node->right) {
        LeftOrder(node->right);
    }
}
int Cliente_Agregar(){


    return 0;
}