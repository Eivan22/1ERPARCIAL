#ifndef _PROGRAMADOR
#define _PROGRAMADOR
//CREAMOS ESTRUCTURAS DE LAS ENTIDADES
struct Programador{
    int Id;
    char Nombre[30];
    char Apellido[50];
    int IdCategoria;
};
struct Proyecto{
    int Id;
    char Nombre[30];
};
struct Categoria{
    int Id;
    char Descripcion[50];
    float PagoXHora;
};
struct Trabajo{
    int Id;
    int IdProgramador;
    int IdProyecto;
    int Horas;
};

//LIMPIAR LISTAS
void LimpioListaProgramadores(struct Programador* ListProgramadores,int CantProgramadores);
void LimpioListaProyectos(struct Proyecto* ListProyectos,int CantProyectos);
void LimpioListaTrabajos(struct Trabajo* ListTrabajos,int CantTrabajos,int CantProgramadores,int CantProyectos);

void LimpioListaProgramadoresConsulta(struct Programador* ListProgramadoresConsulta,int CantProgramadores);
void LimpioListaProyectosConsulta(struct Proyecto* ListProyectosConsulta, int CantProyectos);

//INICIALIZO ESTRUCTURAS PARA ELIMINAR BASURA DE MEMORIA
void InicializoEstructura(struct Programador* ListProgramadores,int CantProgramadores,struct Proyecto* ListProyectos,int CantProyectos,struct Trabajo* ListTrabajos,int CantTrabajos);
#endif
