#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

#define true 1
#define false 0

/*ESTA FUNCION CONVIERTE DE UNA VARIABLE TIPO TEXTO(CHAR) A UNA NUEMRICA(LONG)
-VALORES DE ENTREDA: REQUIERE UNA VARIABLE TIPO CHAR PASADA POR VALOR
-VALORES DE SALIDA: DEVUELVE UNA VARIABLE NUMERICA TIPO LONG CON LA CADENA CONVERTIDA, EN CASO DE NO HABERCE PODIDO HABER LLEGADO A REALIZAR LA CONVERCION DEVUELVE CERO*/
long convertir_cadena_a_entero(const char *cad)
{
    long num = 0;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    int digito;
    int i;

    for (i = tam ; i > 0; --i) {
        digito = (int) (cad[i - 1] - 48);
        num += digito * pow(10.0, tam - i);
    }
    return num;
}
/*ESTA FUNCION CONVIERTE ENTEROS EN TEXTO
-VALORES DE ENTRADA: REQUIERE UNA VARIBLE NUMERICA DE TIPO INTERO
-VALORES DE SALIDA: DEVUELVE UNA VARIBLE DE TIPO CHAR CON EL LA CADENA CONVERTIDA*/
char * convertir_entero_a_cadena(int num)
{
#define MAX_TAM 80

    char *cad;
    int digito;
    int i = 0;

    cad = (char*) malloc(MAX_TAM * sizeof(char));  /* No olvidar liberar la memoria asignada */
    memcpy(cad, "\0", MAX_TAM);  /* Bruto, pero efectivo :) */

    while (num >= 1) {
        digito = num % 10;

        if (i < MAX_TAM - 1) {
            cad[i] = (char) (digito + 48);
            num -= digito;
            num /= 10;
        }

        ++i;
    }

    /* Pero los dígitos de la cadena han quedado en orden inverso,  */
    /* así que los ordenamos correctamente */

    int  tam = strlen(cad);
    char temp;

    for (i = 0; i < tam / 2; ++i) {
        temp = cad[i];
        cad[i] = cad[tam - i - 1];
        cad[tam - i - 1] = temp;
    }

    return cad;
}
/*ESTA FUNCION VALIDA SI ES QUE EL VALOR PASADO EN LA ENTRADA ES NUMERICO
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO*/
int ValidarInt(char Cadena[])
{
    int valido=1;
    int a;
    int control = 0;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if(isdigit(Cadena[a]) == 0)
        {
            control = control + 1;
        }
    }
    if(control > 0)
    {
        valido=0;
    }
    return valido;
}
/*ESTA FUNCION VALIDA QUE EL VALOR INGREADO SEA UN NUMERICO DE TIPO FLOTANTE
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO FLOTANTE*/
int ValidarFloat(char Cadena[])
{
    int valido=1;
    int a;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if((Cadena[a] !='-') && (Cadena[a] !='.') && (isdigit(Cadena[a]) == 0))
        {
            valido = 0;
            return valido;
        }
    }
    return valido;
}

int ValidarYESNO(char Cadena[])
{
    int valido=1;
    int a;
    int control = 0;
    if(LengtCadena(Cadena)>1)
    {
        valido=0;
    }
    else
    {
        if(Cadena[0]=='s' || Cadena[0]=='S' || Cadena[0]=='n' || Cadena[0]=='N')
        {
            valido=1;
        }
        else
        {
            valido=0;
        }
    }
    return valido;
}
/*ESTA FUNCION CUENTA LA LONGITUD DE LA CADENA PASADA COMO ENTRADA
-VALORES DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALORES DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO CON LA CANTIDAD DE CARACTERES QUE TIENE LA CADENA DE ENTRADA*/
int LengtCadena(char *Cadena)
{
    int a=0;
    while(Cadena[a]!='\0')
    {
        a++;
    }
    return a;
}
/*ESTA FUNCION EJECUTA UN MENSAJE CON RESPUESTA YES/NO QUE EL USUARIO DESEEE
-VALORES DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR, LA QUE SE MOSTRARA EN EL CUERPO DEL MENSAJE
-VALORES DE SALIDA: DEVUEVE UNA VARIABLE DE TIPO ENTERO HACIENDO REFERENCIA A LA RESPUESTA DEL USUARIO ANTE EL MENSAJE,
DONDE 0 ES RESPUESTA NEGATIVA Y 1 ES RESPUESTA POSITIVA*/
int MensajeYESNO(char Mensaje[])
{
    char Respuesta[25];
    int IsOK;
    do{
        printf("\n\n%s S/N",Mensaje);
        scanf(" %s",&Respuesta);
        IsOK = ValidarYESNO(Respuesta);
        if(IsOK==1)
        {
            if((Respuesta[0]=='S') || (Respuesta[0]=='s'))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("\nEL VALOR INGRESADO NO CORRESPONDE A UNA OPCION VALIDA!\n");
        }
    }while(IsOK==0);
}
/*ESTA FUNCION ESCRIBE UN MENSAJE CON RESPUESTA YES/NO PARA CONSITUAR O NO OPERANDO
-VALORES DE ENTRADA: REQUIERE UN PUNTERO A CHAR PARA UNA RESPUESTA RESPUESTA
-VALORES DE SALIDA: DEVUEVE UN ENTERO CON EL RESULTADO DE LA PREGUNTA,DONDE 0 ES RESPUESTA NEGATIVA Y 1 ES RESPUESTA POSITIVA*/
int PreguntarSalirYESNO(char* Seguir)
{
    Seguir='N';
    int Sigue=0;
     /*PREGUNTAMOS SI DESEA SALIR O NO DE LA PANTALLA*/
    printf("_________________________________________________________________________\n");
    int Resp = MensajeYESNO("Desea continuar operando?");
    if(Resp==1) //SI LA RESPUESTA ES NEGATIVA
    {
        Seguir='S';
        Sigue=1;
    }
    system("cls");
    return Sigue;
}
/*ESTA FUNCION SUMA DOS VALORES INGRESADOS POR EL USUARIO
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, LAS CUALES SE SUMARAN
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA SUMA*/
float Suma(float ValorOne, float ValorTwo)
{
    return ValorOne+ValorTwo;
}
/*ESTA FUNCION RESTA DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, DE LAS CUALES LA SEGUNDA SE RESTARA DE LA PRIMERA
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA RESTA*/
float Resta(float ValorOne, float ValorTwo)
{
    return ValorOne-ValorTwo;
}
/*ESTA FUNCION DIVIDE DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, DE LAS CUALES LA SEGUNDA DIVIDE A LA PRIMERA
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA DIVICION*/
float Dividir(float ValorOne, float ValorTwo)
{
    return ValorOne/ValorTwo;
}
/*ESTA FUNCION MULTIPLICA DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, LAS CUALES SE MULTIPLICARAN
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA MULTIPLICACION*/
float Multiplicar(float ValorOne, float ValorTwo)
{
    return ValorOne*ValorTwo;
}
/*ESTA FUNCION FACTORIZA UN VALOR INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: UNA VARIABLE NUMERICAS DE TIPO FLOTANTE, LA CUAL SE CALCULARA EL FACTORIAL
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DEL FACTORIAL*/
int Factorial(float Valor)
{
    int aux,factor= 1;
    for (aux = Valor; aux > 1; aux--)
    {
        factor = factor * aux;
    }
    return factor;
}
/*ESTA FUNCION VALIDA SI LO INGRESADO CORRESPONDE A LOS PARAMETROS DE LAS OPCIONES SETEADAS
-VALORES DE ENTRADA: UN CHAR PARA LA OPCION TIPEADA, UN INT CON EL VALOR INICIAL DE OPCIONES, UN INT CON EL VALOR MAXIMO DE OPCIONES, UN STRING CON EL TEXTO EN CASO DE ERROR
-VALORES DE SALIDA: DEVULVE UN 0 EN CASO POSITIVO Y UN 1 EN CASO CONTRARIO*/
int ValidarOpciones(char* Opcion,int ValIniOpciones, int ValEndOpciones,char MensajeError[])
{
    int Verificado=false;
    long Aux=0;
    if(LengtCadena(Opcion)<2)
    {
        if(!(Opcion[0]=='0'))
        {
            if(ValidarInt(Opcion)==1)
            {
                Aux = convertir_cadena_a_entero(Opcion);
                if(!(Aux>ValEndOpciones || Aux<ValIniOpciones))
                {
                    Verificado=true;
                }
            }
        }
    }
    if(Verificado==false)
    {
        printf("*_%s\n",toupper(MensajeError));
    }
    return Verificado;
}
/*GRAFICAR*/
int GraficarX3Colum(int Colum1, int Colum2, int Colum3)
{
    int i, hasta18=Colum1, de19a35=Colum2, mayorDe35=Colum3, mayor;
    //ESTABLECEMOS CUAL ES LA COLUMNA CON MAYOR VALOR PARA GRAFICAR MEJOR
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }
    //ROTULO DE EJE Y
    printf("(Cant)\n");
    //GRAFICAMOS VALORES CON FORMATO
    for(i=mayor; i>0; i--){
        //ROTULO DE CAMPOS EJE Y
        if(i<10){
            printf("    %d| ",i);
        }
        else
        {
            printf("   %d| ",i);
        }
        //GRAFICAMOS COLUMNAS
        if(i<= hasta18){
            printf("\t###");
        }
        else
        {
            printf("\t   ");
        }
        if(i<= de19a35){
            printf("\t###");
        }
        else{printf("\t   ");}
        if(i<= mayorDe35){
                printf("\t###");
        }
        printf("\n");
    }
    printf("   --+-------------------------");
    //ROTULO DE EJE X
    printf("\n     |\t<18\t19-35\t>35    (Edad)");
    //VALORES DE LAS COLUMNAS
    printf("\n      \t(%d)\t(%d)\t(%d)\n", hasta18, de19a35, mayorDe35);
    return 0;
}
//LIMPIAR LISTAS
void LimpioListaPantallas(struct Pantalla* List,int Cant)
{
    int isReady=false;
    int x;
    for (x=0;x<Cant;x++)
    {
        //DEFINO VALOR VACIO COMO X o false (-1), POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS
        List[Cant].Id= false;
        strcpy(List[Cant].Nombre,"X");
        strcpy(List[Cant].Direccion,"X");
        List[Cant].idCategoria = false;
        List[Cant].PrecioPorDia = false;
        List[Cant].Estado = false;
        List[Cant].FlagOcupado = false;
    }
    isReady=true;
    return isReady;
}
void LimpioListaPublicidad(struct Publididad* List,int Cant)
{
    int isReady=false;
    int x;
    for (x=0;x<Cant;x++)
    {
        //DEFINO VALOR VACIO COMO X o false (-1), POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS
        List[Cant].Id = false;
        strcpy(List[Cant].CuitCliente,"X");
        List[Cant].CantDiasPublisidad=0;
        List[Cant].idPantalla = false;
        strcpy(List[Cant].NombreVideo,"X");
        List[Cant].Estado = false;
        List[Cant].FlagOcupado = false;
    }
    isReady=true;
    return isReady;
}
void LimpioListaCategorias(struct Categoria* List,int Cant)
{
    int isReady=false;
    int x;
    for (x=0;x<Cant;x++)
    {
        //DEFINO VALOR VACIO COMO X o false (-1), POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS
        List[Cant].Id = false;
        strcpy(List[Cant].Codigo,"X");
        strcpy(List[Cant].Descripcion,"X");
        List[Cant].Estado = false;
        List[Cant].FlagOcupado = false;
    }
    isReady=true;
    return isReady;
}

//INICIALIZO ESTRUCTURAS PARA ELIMINAR BASURA DE MEMORIA
void InicializoEstructura(struct Pantalla* ListPantalla,int CantPantalla,struct Publididad* ListPublididad,int CantPublididad,struct Categoria* ListCategoria, int CantCategorias)
{
    //LIMPIAR LISTAS
    LimpioListaPantallas(ListPantalla, CantPantalla);
    LimpioListaPublicidad(ListPublididad, CantPublididad);
    LimpioListaCategorias(ListCategoria, CantCategorias);

    int x;
    for (x=0;x<CantCategorias;x++)
    {
        //DEFINO VALOR VACIO COMO X o false (-1), POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS
        ListCategoria[CantCategorias].Id = x;
        strcpy(ListCategoria[CantCategorias].Codigo,x+1);
        strcpy(ListCategoria[CantCategorias].Descripcion,"Categoria nro"+ x);
        ListCategoria[CantCategorias].Estado = true;
        ListCategoria[CantCategorias].FlagOcupado = true;
    }
}

int SeleccionamosPantalla(struct Pantalla* ListPantalla, int CantRegEncontrados)
{

    //INICIALIZAMOS INDICE DE SELECCION DE REGISTRO
    int RegSeleccionado = -1;
    if(CantRegEncontrados > 1)
    {
        do{
            //SI HAY VARIOS REGISTROS COINCIDENTES PREGUNTAMOS CUAL QUIERE ELIMINAR
            char ReadVal[]="";
            printf("\nSeleccione ID de Registro para operar: ");
            scanf("%s",&ReadVal);
            //RECORREMOS LISTA DE RESULTADOS PARA VALIDAR COINCIDENCIA
            int x;
            for(x=0;x<CantRegEncontrados;x++)
            {
                /*if(ListarPantallas[x].Id==convertir_cadena_a_entero(ReadVal))
                {
                    RegSeleccionado=x;
                }*/
            }
            //SI NO HAY RELACION ENTRE EL VALOR INGRESADO Y LOS RESULTADOS MOSTRAMOS UN MENSAJE
            if(RegSeleccionado==-1)
            {
                printf("\nEL VALOR INGRESADO NO COINCIDE CON EL RESULTADO DE LA BUSQUEDA REALIZADA..\n");
            }
        }while(RegSeleccionado==-1);
    }
    else
    {
        //SI ENCONTRAMOS UN SOLO REGISTRO, LO SELECCIONAMOS POR DEFAULT
        RegSeleccionado = 0;
    }
    printf("\n\n>>REGISTRO SELECIONADO\n");
    //MUESTRO EN PANTALLA REGISTRO/S RESULTANTE
    /*printf("\nId: %d\n",ListPantalla[x].Id);
    printf("Nombre: %s\n",ListPantalla[x].Nombre);
    printf("Direccion: %s\n",ListPantalla[x].Direccion);
    printf("Precio de Alquiler xDia: %.0f\n",ListPantalla[x].PrecioPorDia);
    printf("Categoria: %s\n",ListCategoria[ListPantalla[x].idCategoria].Descripcion);*/
    return RegSeleccionado;
}

int BuscarPantalla(struct Pantalla* ListPantalla,int CantPantalla,struct Pantalla objPantallaBuscado,struct Categoria* ListCategoria , struct Pantalla* ListPantallaConsulta)
{
    //DEFINIMOS PARAMETRO DE BUSQUEDA, EN ESTE CASO CAMPO NOMBRE
    printf("\n      BUSCAR ID PANTALLA: ");
    scanf("%s",&objPantallaBuscado.Id);
    ValidarInt(objPantallaBuscado.Id);
    //INICIALIZAMOS CONTADOR DE REGISTROS ENCONTRADOS POR BUSQUEDA
    int CantRegEncontrados = 0;
    //LIMPIO LISTA CONSULTA
    LimpioListaPantallas(ListPantallaConsulta,CantPantalla);
    //RECORREMOS LA LISTA,MOSTRAMOS Y GUARDAMOS LOS RESULTADOS DE LA MISMA
    printf("\n>RESULTADO:\n");
    int x;
    for(x = 0; x < CantPantalla; x++)
    {
         if(ListPantalla[x].Id==objPantallaBuscado.Id)
         {
                //MUESTRO EN PANTALLA REGISTRO/S RESULTANTE
                printf("\nId: %d\n",ListPantalla[x].Id);
                printf("Nombre: %s\n",ListPantalla[x].Nombre);
                printf("Direccion: %s\n",ListPantalla[x].Direccion);
                printf("Precio de Alquiler xDia: %.0f\n",ListPantalla[x].PrecioPorDia);
                printf("Categoria: %s\n",ListCategoria[ListPantalla[x].idCategoria].Descripcion);
                //GUARDO REGISTRO/S RESULTANTE
                ListPantallaConsulta[x].Id= ListPantalla[x].Id;
                strcpy(ListPantallaConsulta[x].Nombre,ListPantalla[x].Nombre);
                strcpy(ListPantallaConsulta[x].Direccion,ListPantalla[x].Direccion);
                ListPantallaConsulta[x].idCategoria = ListPantalla[x].idCategoria;
                ListPantallaConsulta[x].PrecioPorDia = ListPantalla[x].PrecioPorDia;
                ListPantallaConsulta[x].Estado = ListPantalla[x].Estado;
                ListPantallaConsulta[x].FlagOcupado = ListPantalla[x].FlagOcupado;
                //CUENTO CANTIDAD DE REGISTROS ENCONTRADOS
                CantRegEncontrados = CantRegEncontrados+1;
         }
    }
    return CantRegEncontrados;
}

void AltaPantalla(struct Pantalla* ListPantalla,int CantPantallas,int *UltimoId_, struct Pantalla objPantalla)
{
    int UltimoId=UltimoId_;
    printf("\n****************************ALTA DE PANTALLA*****************************\n");
    //CONTROLAMOS LA FACTIBILIDAD DE CARGAR UN REGISTRO NUEVO Y EN CASO DE SER VIABLE DEFINIMOS EL ID DEL REGISTRO
    int contador,cargaOK=0,Aux=0;
    //SI EL VALOR DE ID QUE SE PRETENDIA ASIGNAR ESTA LLENO VERIFICAMOS, SINO LO ASIGNAMOS AL NUEVO REGISTRO
    while(ListPantalla[UltimoId].FlagOcupado > -1)
    {
        //INCREMENTAMOS PARA COMPARAR CON EL SIGUIENTE REGISTRO DE LA LISTA
        UltimoId = UltimoId+1;
        //SI EXCEDEMOS LA CANTIDAD DE ID POR REGISTRO RESETEAMOS
        if(UltimoId>CantPantallas)
        {
            UltimoId=0;
        }
        //CONTADOR DE REGISTROS COMPARADOS
        contador = contador+1;
        if(contador>CantPantallas)
        {
            //SI RECORRIMOS TODA LA LISTA Y NO HAY REGISTRO DISPONIBLE MOSTRAMOS MENSAJE Y BLOQUEAMOS LA CARGA
            printf("\nHA EXEDIDO LA CANTIDAD DE REGISTROS PERMITIDOS!\nPara cargar un nuevo registro debe eliminar alguno de los cargados\n");
            cargaOK=1;
            break;
        }
    }
    //SI LA CARGA EN VIABLE PROCEDEMOS A LEER-VERIFICAR-CARGAR DATOS
    if(cargaOK==0)
    {
        //GRABAMOS ID DEL REGISTRO PROGRAMADOR
        objPantalla.Id = UltimoId;
        printf("\n      NOMBRE: ");
        scanf("%s",&objPantalla.Nombre);

        printf("\n      DIRECCION: ");
        scanf("%s",&objPantalla.Direccion);

        printf("\n      PRECIO PUBLICIDAD POR DIA: $");
        scanf("%s",&objPantalla.PrecioPorDia);
        do
        {
            printf("\n                          > 0: PANTALLA LCD\n");
            printf("\n                          > 1: PANTALLA GIGANTE LED\n");
            printf("\n      NUMERO DE CATEGORIA: ");
            char IdRead[]="0";
            scanf("%s",&IdRead);
            int Verificado=1;
            Verificado = ValidarInt(IdRead);
            if(Verificado==1)
            {
                Aux = convertir_cadena_a_entero(IdRead);
                if(Aux>1 || Aux<0)
                {
                    printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
                }
                else
                {
                    objPantalla.idCategoria = Aux;
                }
            }
            else
            {
                printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
            }
        }while(Aux>1 || Aux<0);

        //CARGO OBJRETO EN LISTA
        ListPantalla[UltimoId].Id= objPantalla.Id;
        strcpy(ListPantalla[UltimoId].Nombre,objPantalla.Nombre);
        strcpy(ListPantalla[UltimoId].Direccion,objPantalla.Direccion);
        ListPantalla[UltimoId].idCategoria = objPantalla.idCategoria;
        ListPantalla[UltimoId].PrecioPorDia = objPantalla.PrecioPorDia;
        ListPantalla[UltimoId].Estado = true;
        ListPantalla[UltimoId].FlagOcupado = true;
        //MENSAJE DE CONFIRMACION DE CARGA EXITOSA
        printf("\n      REGISTRO CARGADO CORRECTAMENTE!\n\n");
        //INCREMENTAMOS EL CONTADOR DE REGISTROS CARGADOS
        UltimoId = UltimoId+1;
        if(UltimoId>CantPantallas)
        {
            //SI EXEDEMOS LA CANTIDAD DE REGISTROS DE LA LISTA RESETEAMOS
            UltimoId=0;
        }
    }
    printf("\n\n");
}

void ModificarPantalla(struct Pantalla* ListPantalla,int CantPantalla,struct Pantalla objPantalla, struct Pantalla objPantallaBuscado,struct Categoria* ListCategoria , struct Pantalla* ListPantallaConsulta)
{
    printf("\n************************MODIFICACION PANTALLA****************************\n");
    int CantRegEncontrados = BuscarPantalla(ListPantalla,CantPantalla,objPantallaBuscado,ListCategoria ,ListPantallaConsulta);
    //VERIFICAMOS QUE EXISTA AL MENOS UN RESULTADO PARA LA BUSQUEDA REALIZADA
    if(CantRegEncontrados == 0)
    {
        //SI NO HAY COINCIDENCIAS MOSTRAMOS UN MENSAJE
        printf("\nNO SE ENCONTRARON RESULTADOS!\n");
    }
    else
    {
        int RegSeleccionado=0;
        //int RegSeleccionado = SeleccionamosPantalla(CantRegEncontrados);
        //CONFIRMAMOS SI DESEA BORRAR EL REGISTRO
        int Respuesta = MensajeYESNO("Esta seguro que desea modificar este registro?");
        if(Respuesta==1) //SI LA RESPUESTA ES POSITIVA MODIFICAMOS EL REGISTRO
        {
            printf("\nMODIFICAR REGISTRO:\n");
            objPantalla.Id = ListPantalla[RegSeleccionado].Id;
            printf("\n      NOMBRE: ");
            scanf("%s",&objPantalla.Nombre);

            printf("\n      DIRECCION: ");
            scanf("%s",&objPantalla.Direccion);

            printf("\n      PRECIO PUBLICIDAD POR DIA: $");
            scanf("%s",&objPantalla.PrecioPorDia);
            long Aux=0;
            do
            {
                printf("\n                          > 0: PANTALLA LCD\n");
                printf("\n                          > 1: PANTALLA GIGANTE LED\n");
                printf("\n      NUMERO DE CATEGORIA: ");
                char IdRead[]="0";
                scanf("%s",&IdRead);
                int Verificado = 0;
                Verificado = ValidarInt(IdRead);
                if(Verificado==1)
                {
                    Aux = convertir_cadena_a_entero(IdRead);
                    if(Aux>1 || Aux<0)
                    {
                        printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
                    }
                    else
                    {
                        objPantalla.idCategoria = Aux;
                    }
                }
                else
                {
                    printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
                }
            }while(Aux>1 || Aux<0);

            //CARGO OBJRETO EN LISTA
            ListPantalla[RegSeleccionado].Id= objPantalla.Id;
            strcpy(ListPantalla[RegSeleccionado].Nombre,objPantalla.Nombre);
            strcpy(ListPantalla[RegSeleccionado].Direccion,objPantalla.Direccion);
            ListPantalla[RegSeleccionado].idCategoria = objPantalla.idCategoria;
            ListPantalla[RegSeleccionado].PrecioPorDia = objPantalla.PrecioPorDia;
            ListPantalla[RegSeleccionado].Estado = true;
            ListPantalla[RegSeleccionado].FlagOcupado = true;
            //MENSAJE DE CONFIRMACION DE CARGA EXITOSA
            printf("\n      REGISTRO FUE MODIFICADO CORRECTAMENTE!\n\n");
        }
    }
    printf("\n\n");
}

void EliminarPantalla(struct Pantalla* ListPantalla, struct Pantalla* ListPantallaConsulta,int CantPantalla,struct Categoria* ListCategoria, struct Pantalla objPantalla, struct Pantalla objPantallaBuscado, struct Publididad* ListPublicidad, int CantPublicidad)
{
    printf("\n****************************BORRAR PANTALLA******************************\n");
    int CantRegEncontrados = BuscarPantalla(ListPantalla,CantPantalla,objPantallaBuscado,ListCategoria ,ListPantallaConsulta);
    //VERIFICAMOS QUE EXISTA AL MENOS UN RESULTADO PARA LA BUSQUEDA REALIZADA
    if(CantRegEncontrados == 0)
    {
        //SI NO HAY COINCIDENCIAS MOSTRAMOS UN MENSAJE
        printf("\nNO SE ENCONTRARON RESULTADOS!\n");
    }
    else
    {
        int RegSeleccionado=0;
        //int RegSeleccionado = SeleccionamosPantalla(CantRegEncontrados);
        //CONFIRMAMOS SI DESEA BORRAR EL REGISTRO
        int Respuesta = MensajeYESNO("Esta seguro que desea eliminar este registro?\nNo solo lo eliminara de la lista de programadores sino de la lista de Proyectos en los que este trabajando ");
        if(Respuesta==1) //SI LA RESPUESTA ES POSITIVA "ELIMINAMOS" REGISTRO
        {
            ListPantalla[RegSeleccionado].Id= false;
            strcpy(ListPantalla[RegSeleccionado].Nombre,"X");
            strcpy(ListPantalla[RegSeleccionado].Direccion,"X");
            ListPantalla[RegSeleccionado].idCategoria = false;
            ListPantalla[RegSeleccionado].PrecioPorDia = false;
            ListPantalla[RegSeleccionado].Estado = false;
            ListPantalla[RegSeleccionado].FlagOcupado = false;
            //ELIMINO AL PANTALLA DE LA LISTA DE PUBLICIDADES
            int x=0;
            for(x=0;x<CantPublicidad;x++)
            {
                if(ListPublicidad[x].idPantalla==ListPantalla[RegSeleccionado].Id)
                {
                    ListPublicidad[CantPublicidad].Id = false;
                    strcpy(ListPublicidad[CantPublicidad].CuitCliente,"X");
                    ListPublicidad[CantPublicidad].CantDiasPublisidad=0;
                    ListPublicidad[CantPublicidad].idPantalla = false;
                    strcpy(ListPublicidad[CantPublicidad].NombreVideo,"X");
                    ListPublicidad[CantPublicidad].Estado = false;
                    ListPublicidad[CantPublicidad].FlagOcupado = false;
                }
            }
            printf("\nEL REGISTRO SE ELIMINO CORRECTAMENTE!");
        }
    }
    printf("\n\n");
}

void ListarPantallas(struct Pantalla* ListPantalla, struct Pantalla* ListPantallaConsulta,int CantPantalla,struct Categoria* ListCategoria, struct Pantalla objPantalla,struct Publididad* ListPublididad,int CantPublicidad,int UltimoId)
{
    printf("\n***********************LISTADO DE PANTALLAS******************************\n");
    //INICIALIZAMOS CONTADOR DE REGISTROS ENCONTRADOS POR BUSQUEDA
    int CantRegEncontrados = 0;
    //RECORREMOS LA LISTA,MOSTRAMOS Y GUARDAMOS LOS RESULTADOS DE LA MISMA
    printf("\n>RESULTADO:\n");
    //ORDENA POR NRO DE REGISTRO MENOR A MAYOR
    int x;
    for(x = 0; x < CantProgramadores;x++)
    {
        //FILTRO POR LOS REGISTROS QUE SE CARGARON UNICAMENTE
        if(ListProgramadores[x].Nombre[0] != 'X')
        {
            //CUENTO CANTIDAD DE REGISTROS ENCONTRADOS
            CantRegEncontrados = CantRegEncontrados+1;
            printf("\nId: %d\n",ListPantalla[x].Id);
            printf("Nombre: %s\n",ListPantalla[x].Nombre);
            printf("Direccion: %s\n",ListPantalla[x].Direccion);
            printf("Precio de Alquiler xDia: %.0f\n",ListPantalla[x].PrecioPorDia);
            printf("Categoria: %s\n",ListCategoria[ListPantalla[x].idCategoria].Descripcion);

        }
    }
    printf("\n>>REGISTROS ENCONTRADOS: %d\n",CantRegEncontrados);
    printf("\n\n");
}

