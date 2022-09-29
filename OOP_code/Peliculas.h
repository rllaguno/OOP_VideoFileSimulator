// Situaccion Problema
// Rodrigo Llaguno Cardenas
// Peliculas.h


#ifndef Peliculas_h
#define Peliculas_h

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include "Video.h"

// Definición de la clase
class Peliculas: public Video
{
private:
    // Definición de atributos
    int calificacion;

public:
    // Definición de los métodos

    Peliculas();
    Peliculas(int calificacion, int iD, int duracion, string nombre, string genero);

    void setCalificacion(int calificacion);
    int getCalificacion();  

    void mostrar();
   
};

// Métodos de la clase

// Contructores y Destructor
Peliculas::Peliculas(): Video(){
    int calificacion = 0;
}

Peliculas::Peliculas(int calificacion, int iD, int duracion, string nombre, string genero): Video(iD, duracion, nombre, genero){
    this->calificacion = calificacion;
}

// Sets y Gets
void Peliculas::setCalificacion(int calificacion){
    this->calificacion = calificacion;
}

int Peliculas::getCalificacion(){
    return calificacion;
}


// Otros métodos
void Peliculas::mostrar(){
    cout << calificacion << "               " << nombre 
    << "               " << genero << "               " << iD
    << "               " << duracion << endl;
}


#endif /*Peliculas_h*/
