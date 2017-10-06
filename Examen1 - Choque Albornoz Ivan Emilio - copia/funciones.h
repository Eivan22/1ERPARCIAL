#ifndef _FUNCIONES
#define _FUNCIONES
//CREAMOS ESTRUCTURAS DE LAS ENTIDADES
struct Pantalla{
    int Id;
    char Nombre[30];
    char Direccion[50];
    float PrecioPorDia;
    int idCategoria;
    int FlagOcupado; //0:vacio 1:ocupdo
    int Estado; //0:vacio 1:ocupdo
};
struct Publididad{
    int Id;
    char CuitCliente[12];
    int CantDiasPublisidad;
    char NombreVideo[30];
    int idPantalla;
    int FlagOcupado; //0:vacio 1:ocupdo
    int Estado; //0:vacio 1:ocupdo
};
struct Categoria{
    int Id;
    char Codigo[10];
    char Descripcion[50];
    int FlagOcupado; //0:vacio 1:ocupdo
    int Estado; //0:vacio 1:ocupdo
};

/*CREAMOS PROTOTIPOS DE LAS FUNCIONES DE NUESTRA BIBLIOTECA*/
/*CONVERSION*/
long convertir_cadena_a_entero(const char *cad);
char * convertir_entero_a_cadena(int num);
int LengtCadena(char *Cadena);
/*VALIDACION*/
int ValidarInt(char Cadena[]);
int ValidarFloat(char Cadena[]);
int ValidarYESNO(char Cadena[]);
/*MESSENGEBOX*/
int MensajeYESNO(char Mensaje[]);
int PreguntarSalirYESNO(char* Seguir);
/*OPERACIONES MATEMATICAS*/
float Suma(float ValorOne, float ValorTwo);
float Resta(float ValorOne, float ValorTwo);
float Dividir(float ValorOne, float ValorTwo);
float Multiplicar(float ValorOne, float ValorTwo);
int Factorial(float Valor);
int ValidarOpciones(char* Opcion,int ValIniOpciones, int ValEndOpciones,char MensajeError[]);
/*GRAFICAR*/
int GraficarX3Colum(int Colum1, int Colum2, int Colum3);
//LIMPIAR LISTAS
void LimpioListaPantallas(struct Pantalla* List,int Cant);
void LimpioListaPublicidad(struct Publididad* List,int Cant);
void LimpioListaCategorias(struct Categoria* List,int Cant);

//INICIALIZO ESTRUCTURAS PARA ELIMINAR BASURA DE MEMORIA
void InicializoEstructura(struct Pantalla* ListPantalla,int CantPantalla,struct Publididad* ListPublididad,int CantPublididad,struct Categoria* ListCategoria,int CantCategorias);
int SeleccionamosPantalla(struct Pantalla* ListPantalla, int CantRegEncontrados);
int BuscarPantalla(struct Pantalla* ListPantalla,int CantPantalla,struct Pantalla objPantallaBuscado,struct Categoria* ListCategoria , struct Pantalla* ListPantallaConsulta);
void AltaPantalla(struct Pantalla* ListPantalla,int CantPantallas,int *UltimoId_, struct Pantalla objPantalla);
void ModificarPantalla(struct Pantalla* ListPantalla,int CantPantalla,struct Pantalla objPantalla, struct Pantalla objPantallaBuscado,struct Categoria* ListCategoria , struct Pantalla* ListPantallaConsulta);
void EliminarPantalla(struct Pantalla* ListPantalla, struct Pantalla* ListPantallaConsulta,int CantPantalla,struct Categoria* ListCategoria, struct Pantalla objPantalla, struct Pantalla objPantallaBuscado, struct Publididad* ListPublicidad, int CantPiblicidad);

#endif
