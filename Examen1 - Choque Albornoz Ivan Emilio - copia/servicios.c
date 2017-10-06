#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "servicios.h"

//LIMPIAR LISTAS
void LimpioListaProgramadores(struct Programador* ListProgramadores,int CantProgramadores)
{
    int x;
     for (x=0;x<CantProgramadores;x++)
        {
            //LISTA DE PROGRAMADORES
            //DEFINO VALOR VACIO COMO X, POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS(NO APLICADOS EN ESTE PARCIAL)
            ListProgramadores[x].Id=CantProgramadores+1;
            strcpy(ListProgramadores[x].Nombre,"X");
            strcpy(ListProgramadores[x].Apellido,"X");
            ListProgramadores[x].IdCategoria=CantProgramadores+1;
        }
}
void LimpioListaProyectos(struct Proyecto* ListProyectos,int CantProyectos)
{
    int x;
    for (x=0;x<CantProyectos;x++)
        {
            //LISTA DE PROYECTOS
            //DEFINO VALOR VACIO COMO X, POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS(NO APLICADOS EN ESTE PARCIAL)
            ListProyectos[x].Id=CantProyectos+1;
            strcpy(ListProyectos[x].Nombre,"X");
        }
}
void LimpioListaTrabajos(struct Trabajo* ListTrabajos,int CantTrabajos,int CantProgramadores,int CantProyectos)
{
    int x;
    for (x=0;x<CantTrabajos;x++)
        {
            //LISTA DE PROYECTOS
            //DEFINO VALOR VACIO COMO X, POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS(NO APLICADOS EN ESTE PARCIAL)
            ListTrabajos[x].Id=CantTrabajos+1;
            ListTrabajos[x].IdProgramador=CantProgramadores+1;
            ListTrabajos[x].IdProyecto=CantProyectos+1;
            ListTrabajos[x].Horas=0;
        }
}


void LimpioListaProgramadoresConsulta(struct Programador* ListProgramadoresConsulta,int CantProgramadores)
{
    int x;
    for (x=0;x<CantProgramadores;x++)
    {
        //LISTA DE PROGRAMADORES
        //DEFINO VALOR VACIO COMO X, POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS(NO APLICADOS EN ESTE PARCIAL)
        ListProgramadoresConsulta[x].Id=CantProgramadores+1;
        strcpy(ListProgramadoresConsulta[x].Nombre,"X");
        strcpy(ListProgramadoresConsulta[x].Apellido,"X");
        ListProgramadoresConsulta[x].IdCategoria=CantProgramadores+1;
    }
}
void LimpioListaProyectosConsulta(struct Proyecto* ListProyectosConsulta, int CantProyectos)
{
    int x;
    for (x=0;x<CantProyectos;x++)
    {
        //LISTA DE PROYECTOS
        //DEFINO VALOR VACIO COMO X, POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS(NO APLICADOS EN ESTE PARCIAL)
        ListProyectosConsulta[x].Id=CantProyectos+1;
        strcpy(ListProyectosConsulta[x].Nombre,"X");
    }
}

//INICIALIZO ESTRUCTURAS PARA ELIMINAR BASURA DE MEMORIA
void InicializoEstructura(struct Programador* ListProgramadores,int CantProgramadores,struct Proyecto* ListProyectos,int CantProyectos,struct Trabajo* ListTrabajos,int CantTrabajos)
{
    //FUNCIONES LIMPIAR LISTAS
    LimpioListaProgramadores(ListProgramadores,CantProgramadores);
    LimpioListaProyectos(ListProyectos,CantProyectos);
    LimpioListaTrabajos(ListTrabajos,CantTrabajos,CantProgramadores,CantProyectos);

    //CARGA LISTA DE PROYECTOS
    ListProyectos[0].Id=0;
    strcpy(ListProyectos[0].Nombre,"ProyectoCero");
    ListProyectos[1].Id=1;
    strcpy(ListProyectos[1].Nombre,"ProyectoOne");
    ListProyectos[2].Id=2;
    strcpy(ListProyectos[2].Nombre,"ProyectoTwo");
    ListProyectos[3].Id=3;
    strcpy(ListProyectos[3].Nombre,"ProyectoThree");
    ListProyectos[4].Id=4;
    strcpy(ListProyectos[4].Nombre,"ProyectoFour");

    //CARGA LISTA DE CATEGORIA
    ListCategoria[0].Id=0;
    strcpy(ListCategoria[0].Descripcion,"JUNIOR");
    ListCategoria[0].PagoXHora=10;
    ListCategoria[1].Id=1;
    strcpy(ListCategoria[1].Descripcion,"SEMISENIOR");
    ListCategoria[1].PagoXHora=20;
    ListCategoria[2].Id=2;
    strcpy(ListCategoria[2].Descripcion,"SENIOR");
    ListCategoria[2].PagoXHora=30;
}
