// Situaccion Problema
// Rodrigo Llaguno Cardenas
// Series.h


#ifndef Series_h
#define Series_h

#include "Episodio.h"
#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include "Video.h"

// Definición de la clase
class Series: public Video
{
private:
    // Definición de atributos
    int calificacion;
    int episodios[3];

public:
    // Definición de los métodos

    Series();
    Series(int calificacion, int iD, int duracion, string nombre, string genero);

    void setCalificacion(int calificacion);
    void setEpisodios(Episodio episodios);
    int getCalificacion();  
    int getEpisodios();

    void mostrar();
   
};

// Métodos de la clase

// Contructores y Destructor
Series::Series(): Video(){
    int calificacion = 0;
}

Series::Series(int calificacion, int iD, int duracion, string nombre, string genero): Video(iD, duracion, nombre, genero){
    this->calificacion = calificacion;
    episodios[0] = 1;
    episodios[1] = 2;
    episodios[2] = 3;
}

// Sets y Gets
void Series::setCalificacion(int calificacion){
    this->calificacion = calificacion;
}
int Series::getCalificacion(){
    return calificacion;
}
int Series::getEpisodios(){
    return *episodios;
} 

// Otros métodos

void Series::mostrar(){
    cout << calificacion << "               " << nombre
    << "               " << genero << "               " << iD
    << "               " << duracion << "               "
    << episodios[0]  << " " << episodios[1] << " "<< episodios[2]<< endl;
}


#endif /*Series_h*/
