// Situaccion Problema
// Rodrigo Llaguno Cardenas
// Peliculas.h


#ifndef Episodio_h
#define Episodio_h

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>

// Definición de la clase
class Episodio
{
private:
    // Definición de atributos
    string tituloEpisodio;

public:
    // Definición de los métodos

    Episodio();
    Episodio(string tituloEpisodio);

    void setTituloEpisodio(string tituloEpisodio);
    string getTituloEpisodio();  

    void mostrarEpisodioSerie();
   
};

// Métodos de la clase

// Contructores y Destructor
Episodio::Episodio(){
    string tituloEpisodio = " ";
}

Episodio::Episodio(string tituloEpisodio){
    this->tituloEpisodio = tituloEpisodio;
}

// Sets y Gets
void Episodio::setTituloEpisodio(string tituloEpisodio){
    this->tituloEpisodio = tituloEpisodio;
}

string Episodio::getTituloEpisodio(){
    return tituloEpisodio;
}



// Otros métodos



#endif /*Episodio_h*/
