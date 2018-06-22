#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int validar_cadena(char cadena[30]);
int validar_num(char numero[30]);
struct nodo{
     string palab;
     string sinonim;
     struct nodo *izq, *der;
};
typedef struct nodo *ABB;/* es un puntero de tipo nodo que hemos llamado ABB*/
int bb =1, bandera; //son banderas que sirven para que no se cicle el bloque: consulta, modificar
int sw1;            //bandera que verifica si una cadena introducida es valida en el bloque; consulta, modificar
char aa[30] ;       //recibe la palabra a modificar o consultar en el bloque; consulta, modificar
string AA;          //recibe la palabra la cual se va a modificar o a consultar
ABB crearNodo(string x,string p ){  //bloque que crea nodo, asigna valores e inicializa punteros en NULL
     ABB nuevoNodo;
     nuevoNodo = new(struct nodo);
     nuevoNodo->palab = x;
     nuevoNodo->sinonim = p;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
return nuevoNodo;
}
void insertar(ABB &arbol, string x, string p){    //bloque que hace un recorrido verificando
     if(arbol==NULL){//su pisicion y cuando encuentra posicion inserta el nodo
           arbol = crearNodo(x, p);
     }
     else{
          if(x < arbol->palab){
               insertar(arbol->izq, x, p);
          }
          else{
               if(x > arbol->palab){
                    insertar(arbol->der, x, p);
               }
          }
     }
}
void menu(){

     cout<<"\n\n                DICCIONARIO DE SINONIMOS "<<endl<<endl;     //men? principal de opciones
     cout<<"  MENU DE OPCIONES:                          "<<endl<<endl;
     cout<<"  1. Consultar sinonimos                     "<<endl;
     cout<<"  2. Consultar el diccionario completo       "<<endl;
     cout<<"  3. Agregar palabras al diccionario         "<<endl;
     cout<<"  4. Imprimir.                               "<<endl;
     cout<<"  5. Eliminar terminos                       "<<endl;
     cout<<"  6. Modificar sinonimos                     "<<endl;
     cout<<"  7. Salir                                   "<<endl;
     cout<<"\n INGRESE EL NUMERO DE LA OPCION DESEADA: ";
}
void enOrden(ABB &arbol){  //bloque que imprime valores en pantalla de forma alfabetica
         fflush(stdin);
         if(arbol!=NULL){
              fflush(stdin);
              enOrden(arbol->izq);
              cout <<"\n  "<< setiosflags(ios::left)<<setw(15) << arbol->palab<<setw(15)<<setiosflags(ios::left) <<arbol->sinonim<<endl;
              enOrden(arbol->der);
         }
}
void modificar(ABB &arbol){                                          //bloque que modifica el sinonimo de 1 palabra ya existente
      fflush(stdin);
      if(bb == 1){   //este if verifica que solo la primera vez que entre pida la palabra a modificar
              cout<<"  MODIFICAR SINONIMOS"<<endl<<endl;
              cout<<"  Ingrese Palabra a Modificar : ";
              cin>>aa;
              sw1 = validar_cadena(aa);
              if(sw1 == 0){ //verifica si la cadena ingresada es valida
                AA= aa;
              }
              else
              {
                cout <<"\n  Cadena invalida\n";
              }
        bb=bb+1;
     }
     if(arbol!=NULL){  //verifica si el diccionario no esta vacio
              modificar(arbol->izq);
              if(arbol->palab == AA){ //verifica cuando ya se posiciono correctamente deacuerdo a la palabra buscada
                   int op,sf;
                   char oP[5];

                   cout<<"\n\n  Palabra     :  "<<arbol->palab <<endl;
                   cout<<"  Sinonimo    :  "<<arbol->sinonim <<endl<<endl;
                   cout<<"  Esta Seguro de Modificar el Sinonimo de: "<<arbol->palab<<endl;
                   cout<<"  1. SI"<<endl;
                   cout<<"  2. NO"<<endl<<endl;
                   cout<<"  Ingrese Opcion: ";
                   cin>>oP;
                   sf = validar_num(oP);
                   if(sf == 0){
                    op = atoi(oP);
                   }else{
                    cout << "\n  OPCION INVLIDA\n";
                   }
                   if(op==1){
                       cout<<"\n\n  Ingrese el Nuevo Sinonimo de "<<arbol->palab<<":  ";
                       cin>>aa;
                       sw1 = validar_cadena(aa);
                       if(sw1 == 0){
                              AA= aa;
                              arbol->sinonim=AA;
                              bandera=1;
                              cout<<"\n\n  MODIFICADO EXITOSAMENTE";
                       }
                       else{
                            bandera=1;
                       }
                   }
                   else{
                        cout<<"\n\n  NO SE MODIFICARA NADA";
                        bandera=1;
                   }
              }
              modificar(arbol->der);
     }
}
void consultar(ABB &arbol){
     if(bb == 1){
              cout<<"  CONSULTAR PALABRAS EN EL DICCIONARIO"<<endl<<endl;
              cout<<"  Ingrese Palabra a Consultar: ";
              cin>>aa;
              sw1 = validar_cadena(aa);
              if(sw1 == 0){
                AA= aa;
              }
              else
              {
                cout <<"\n  Cadena invalida\n\n";
              }
        bb=bb+1;
     }
     if(arbol!=NULL){
              consultar(arbol->izq);
              if(arbol->palab == AA){
                   cout<<"\n\n  Palabra :  "<<arbol->palab <<endl;
                   cout<<"  Sinonimo:  "<<arbol->sinonim<<endl;
                   bandera=1;
              }
              consultar(arbol->der);
              }
}
void diccionario_preconstruido(ABB &arbol){//inserta el diccionario preconstruio
     insertar(arbol, "perro", "can");
     insertar(arbol, "ave", "pajaro");
     insertar(arbol, "colegio" , "escuela");
     insertar(arbol, "casa", "hogar");
     insertar(arbol, "avion", "aeronave");
     insertar(arbol, "lanzar", "aventar");
     insertar(arbol, "festejar", "celebrar");
     insertar(arbol, "reino", "monarquia");
     insertar(arbol, "quemar", "incinerar");
     insertar(arbol, "ilogico", "absurdo");
     insertar(arbol, "computadora", "ordenador");
     insertar(arbol, "hombre", "individuo");
     insertar(arbol, "investigar", "indagar");
     insertar(arbol, "dinero", "efectivo");
     insertar(arbol, "zumo", "jugo");
     insertar(arbol, "bala", "municion");
     insertar(arbol, "empresa", "corporacion");
     insertar(arbol, "ganancia", "beneficio");
     insertar(arbol, "joven", "adoloscente");
     insertar(arbol, "televicion", "televisor");
}
int validar_cadena(char cadena[30])//valida las entradas de texto para que no
{                                  // haya errores durante la ejecucion
	int i=0,sw=0,j;
	j=strlen(cadena);
	while(i<j && sw == 0)
	{
		if(isalpha(cadena[i])!=0)
		{
 			i++;
		}
		else
		{
 			sw=1;
		}
   }
	return sw;
}

int validar_num(char numero[30])// valida que la opcion digitada sea
{                               //un numero para que no se produscan errores
	int i=0,sw=0,j;
	j=strlen(numero);
	while(i<j && sw == 0)
	{
		if(isdigit(numero[i])!=0)
		{
 			i++;
		}
		else
		{
 			sw=1;
		}
   }
	return sw;
}
ABB obtenerNodoReemplazo(ABB &nodoReemp){//obtiene la direccion del
    ABB reemplazarPadre = nodoReemp;     //nodo que se pretende eliminar
    ABB reemplazo = nodoReemp;
    ABB auxiliar = nodoReemp->der;
    while(auxiliar != NULL){
        reemplazarPadre = reemplazo;
        reemplazo = auxiliar;
        auxiliar = auxiliar->izq;
    }
    if(reemplazo != nodoReemp -> der){
        reemplazarPadre->izq = reemplazo->der;
        reemplazo->der = nodoReemp->der;
    }
    cout <<"\n  El Elemento Eliminado se Reemplazara con : "<< reemplazo->palab;
    return reemplazo;
}
// metodo para eliminar un nodo del arbol
bool eliminar(ABB &arbol, string palabra){
    ABB auxiliar = arbol;
    ABB padre = arbol;
    bool esHijoIzq = true;
    while(auxiliar->palab != palabra){
        padre = auxiliar;
        if(palabra < auxiliar-> palab){
            esHijoIzq = true;
            auxiliar = auxiliar->izq;
        }else{
            esHijoIzq = false;
            auxiliar = auxiliar->der;
        }
        if(auxiliar == NULL){
            return false;
        }
     }//Fin del while
     if(auxiliar->izq == NULL && auxiliar->der == NULL){
        if(auxiliar == arbol){
            arbol = NULL;
        }else if(esHijoIzq){
            padre->izq = NULL;
        }else{
            padre->der = NULL;
        }
     }else if(auxiliar->der == NULL){
        if(auxiliar == arbol){
            arbol = auxiliar->izq;
        }else if(esHijoIzq){
            padre->izq = auxiliar->izq;
        }else{
            padre->der = auxiliar->izq;
        }
     }else if(auxiliar->izq == NULL){
        if(auxiliar == arbol){
            arbol = auxiliar->der;
        }else if(esHijoIzq){
            padre->izq = auxiliar->der;
        }else{
            padre->der = auxiliar->der;
        }
     }else{
        ABB reemplazo = obtenerNodoReemplazo(auxiliar);
        if(auxiliar == arbol){
            arbol = reemplazo;
        }else if(esHijoIzq){
            padre->izq = reemplazo;
        }else{
            padre->der = reemplazo;
        }
        reemplazo->izq = auxiliar->izq;
     }
     return true;
}// funcion encargada de devolver el nodo reemplazo
int main()
{
    system("color F0");
    ABB arbol = NULL;   // creado Arbol
    bool invalida = false;
    int opc,sw; //almacena la opcion del menu
    char x[30] ,y[30],Opc[5],z[30] ; // palabra a insertar en un nodo
    string X,Y,Z;
    diccionario_preconstruido(arbol);
    do{
         fflush(stdin);
         menu();
         cin >>Opc;
         sw = validar_num(Opc);
         if(sw == 0){
            opc = atoi(Opc);
         }else{
            cout << "\n  OPCION INVLIDA\n";
        invalida = true;
         }
         cout<<endl<<endl;
         switch(opc){
                    case 1:
                         fflush(stdin);
                         if(arbol!= NULL){
                             bb=1;
                             bandera=0;
                             consultar(arbol);
                             if(bandera==0){
                                            cout<<"\n  NO EXISTE LA PALABRA EN EL DICCIONARIO!!!!";
                             }
                         }
                         else{
                              cout<<"  Diccionario Vacio, Ingrese Algun Termino..!!!!!"<<endl;
                         }

                         break;
                    case 2:
                         fflush(stdin);
                         if(arbol!=NULL){
                             fflush(stdin);
                             cout<<"  CONSULTAR TODO EL DICCIONARIO.\n"<<endl;
                             cout<<"  "<<setiosflags(ios::left)<<setw(15) <<"palabra"<<setiosflags(ios::left)<<setw(15) << "sinonimo"<< endl<< endl;
                             cout<<"-------------------------------\n";
                             enOrden(arbol);
                         }
                         else{
                              cout<<" Diccionario vacio, Ingrese Algun Termino"<<endl;
                         }
                         break;
                    case 3:
                         fflush(stdin);
                         cout<<"\n  A?ADIR PALABRA AL DICCIONARIO"<<endl<<endl;
                         cout<<"  Palabra a Ingresar: ";
                         cin>>x;
                         sw = validar_cadena(x);
                         if(sw == 0){
                            X= x;
                         }
                         else
                         {
                            cout << "\n Cadena invalida";
                         }
                         cout<<"\n  Sinonimo: ";
                         cin>>y;
                         sw = validar_cadena(y);
                         if(sw == 0){
                            Y= y;
                         }
                         else
                         {
                            cout << "\n Cadena invalida";
                         }
                         insertar(arbol, X, Y);

                         break;
                    case 4:

                         cout << "\n  LA OPCION NO SE HA IMPLEMENTAO GRACIAS\n";
                         break;
                    case 5:
                         if(arbol != NULL){
                            cout<<"  "<<setiosflags(ios::left)<<setw(15) <<"palabra"<<setiosflags(ios::left)<<setw(15) << "sinonimo"<< endl<< endl;
                            cout<<"-------------------------------\n";
                            enOrden(arbol);
                            cout <<"\n\n  Ingresa el Elemneto a Eliminar: ";
                            cin >> z;
                            sw = validar_cadena(z);
                            if(sw == 0){
                                Z = z;
                                if(eliminar(arbol,Z) == false){
                                    cout << "\n  Elemento no Encontrado\n";
                                }else{
                                    cout << "\n\n  Elemento Eliminado";
                                }
                            }
                            else
                            {
                                cout << "  Cadena Invalida";
                            }
                         }else{
                            cout <<"\n  El Diccionario se Encuentra Vacio\n";
                         }
                         break;
                    case 6:
                         fflush(stdin);
                         if(arbol!= NULL){
                             bb=1;
                             bandera=0;
                             modificar(arbol);
                             if(bandera==0){
                                            cout<<"  NO EXISTE LA PALABRA EN EL DICCIONARIO";
                             }
                         }
                         else{
                              cout<<"  Diccionario Vacio, Ingrese Algun Termino"<<endl;
                         }
                         break;
                    case 7:
                         cout<<"  Cerrando Programa, hasta luego";
                         break;
                    default:
                            cout<<"  Opcion Incorrecta, vuelva a intentar "<<endl;

                }
                cout<<endl<<endl<<endl<<endl;
                fflush(stdin);
                system("pause");  system("cls");
       }while(opc!=7 || invalida == true);
    return 0;
}




