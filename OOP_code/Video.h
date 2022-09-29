// Situaccion Problema
// Rodrigo Llaguno Cardenas
// Video.h


#ifndef Video_h
#define Video_h

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>

// Definición de la clase
class Video
{
protected:
    // Definición de atributos
    int iD;
    int duracion;
    string nombre;
    string genero;


public:
    // Definición de los métodos

    Video();
    Video(int iD, int duracion, string nombre, string genero);

    void setID(int iD);
    void setDuracion(int duracion);
    void setNombre(string nombre);
    void setGenero(string genero);
    int getID();
    int getDuracion();
    string getNombre();
    string getGenero();   
   
};

// Métodos de la clase

// Contructores y Destructor
Video::Video(){
    int iD = 0;
    int duracion = 0;
    string nombre = " ";
    string genero = " ";
}

Video::Video(int iD, int duracion, string nombre, string genero){
    this->iD = iD;
    this->duracion = duracion;
    this->nombre = nombre;
    this->genero = genero;
}

// Sets y Gets
void Video::setID(int iD){
    this->iD = iD;
}
void Video::setDuracion(int duracion){
    this->duracion = duracion;
}
void Video::setNombre(string nombre){
    this->nombre = nombre;
}
void Video::setGenero(string genero){
    this->genero = genero;
}

int Video::getID(){
    return iD;
}
int Video::getDuracion(){
    return duracion;
}
string Video::getNombre(){
    return nombre;
}
string Video::getGenero(){
    return genero;
}

// Otros métodos



#endif /*Video_h*/