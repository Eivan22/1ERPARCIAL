/*
EXAMEN NRO 1 DE PROGRAMACION
UTN-2017
CARRERA: TECNICO EN PROGRAMACION
MATERIA: LABORATORIO I
ALUMNO: CHOQUE ALBORNOZ IVAN EMILIO
CURSO:1E - TN
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

#define CANTPANTALLAS 5
#define CANTPUBLICIDADES 25
#define CANTCATEGORIAS 3


//VARIABLES GLOBALES
int UltimoId = 0;
int UltimoIdTrabajo = 0;
char Verif;
int Verificado=0;
int isOK=0;
int x=0;
long Aux=0;

//CREO ESTRUCTURA DEL SISTEMA
struct Pantalla objPantalla, ListPantalla[CANTPANTALLAS],ListPantallaConsulta[CANTPANTALLAS];
struct Publididad objPublicidad, ListPublididad[CANTPUBLICIDADES],ListPublididadConsulta[CANTPUBLICIDADES];
struct Categoria objCategoria, ListCategoria[CANTCATEGORIAS];

int main()
{
    InicializoEstructura(ListPantalla,CANTPANTALLAS,ListPublididad,CANTPUBLICIDADES,ListCategoria,CANTCATEGORIAS);
    //MENU INICIAR
    //MIENTRAS LA VARIABLE 'Seguir' DE TIPO CHAR SEA 'S', SE REFRESCARA EL MENU INICIAR
    //-COMO VALOR DE ENTRADA LA PANTALLA REQUIERE SELECCIONAR UNA OPCION DEL MENU
    //-COMO VALOR DE SALIDA ESTA SELECCION DE DERIVARA A UN SELECTOR PARA EJECUTAR LA OPERACION SOLICITADA
    char Seguir='S';
    while(Seguir=='S')
    {
        printf("\n********************ADMINISTRACION DE PUBLICIDADES**********************\n");
        printf("*                                                                       *\n");
        printf("*       OPERACIONES:                                                    *\n");
        printf("*                   1- Agregar de pantalla                              *\n");
        printf("*                   2- Modificar pantalla                               *\n");
        printf("*                   3- Eliminar de pantalla                             *\n");
        printf("*                   4- Contratar una publicidad                         *\n");
        printf("*                   5- Modificar condiciones de publicacion             *\n");
        printf("*                   6- Cancelar contratacion                            *\n");
        printf("*                   7- Cancelar facturacion                             *\n");
        printf("*                   8- Lista de contrataciones                          *\n");
        printf("*                   9- Lista de Pantallas                               *\n");
        printf("*                  10- Salir                                            *\n");
        printf("*                                                                       *\n");
        printf("*************************************************************************\n");
        //VALIDAMOS QUE SE INGRESE UN VALOR DE ENTRE LAS OPCIONES DADAS
        //-LA VARIABLE DE TIPO 'Aux' CONTRENDRA EN VALOR FORMATEADO A ENTERO COMO VALIDACION DEL VALOR INGRESADO POR EL USUARIO
        Aux=0;
        do
        {
            printf("\nSELECCIONE UNA OPERACION: ");
            char Opcion[]="0";
            scanf("%s",&Opcion);
            Verificado=ValidarOpciones(Opcion,1,11,"EL VALOR INGRESADO NO ES VALIDO");
            if(Verificado==1)
            {
                Aux=convertir_cadena_a_entero(Opcion);
            }
        }while(Verificado!=1);
        //LIMPIAMOS PANTALLA
        system("cls");
        //SEGUN EL VALOR INGRESADO SELECCIONAREMOS LA OPERACION A REALIZAR
        switch(Aux)
        {
            case 1: //ALTA
                {
                    AltaPantalla();
                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 2: //MODIFICACION
                {
                    ModificarPantalla());
                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 3: //BAJA
                {
                    EliminarPantalla();
                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 4: //ASIGNAR PROGRAMADOR A PROYECTO
                {
                    AsignarProgramadorAProyecto();
                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 5:
                {

                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 6:
                {

                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 7:
                {

                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 8:
                {

                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 9: //SALIMOS DE LA PANTALLA
                {
                    PreguntarSalirYESNO(Seguir);
                    break;
                }
            case 10: //SALIMOS DE LA PANTALLA
            {
                Seguir = 'N';
                break;
            }
        }
    }
    return 0;
}
