/* There're some numbers in the text file. Using a binary tree that program will display the numbers
from the text file sorted from the smallest to the largest.

task_02.06.2010 */
#include <stdio.h>
#include <stdlib.h>
#include "libs/Cursos.h"

// Structure for a tree node
typedef struct item {
    int clave;
    int posicion;
    struct item *left;
    struct item *right;
} Item;
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


void AddNode(int data, Item **node, int posicion);
int Cliente_Agregar();
void LeftOrder(Item *node);

int main() {

    char buffer[128];
    int i;
    Item *root = NULL; // root of tree
    FILE *fp = fopen("ex52.txt", "r");
    if (!fp) exit(1); // exit if the file opening is failed
    // reading values from the file
    int contador = 0;
    while (fgets(buffer, 128, fp) != NULL) {
        AddNode(atoi(buffer), &root, contador); // adding nodes to the tree
        contador++;
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
void AddNode(int clave, Item **node, int posicion) {
    if (*node == NULL) {
        *node = (Item *) calloc(1, sizeof(Item));
        (*node)->clave = clave;
        (*node)->posicion = posicion;
        (*node)->left = (*node)->right = NULL;
    } else {
        if (clave != -1) {
            if (clave < (*node)->clave) {
                AddNode(clave, &(*node)->left, posicion);
            } else if (clave > (*node)->clave) {
                AddNode(clave, &(*node)->right, posicion);
            } else {
                AddNode(clave+1,&(*node)->right,posicion);
            }
        }
    }
}

// Bypassing the tree on the left (in ascending order)
void LeftOrder(Item *node) {
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