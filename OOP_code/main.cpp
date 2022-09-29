// Rodrigo Llaguno, A01198067
//Proyecto Integrador

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>

#include "Peliculas.h"
#include "Series.h"

bool checarNumCal(int x){
    if (x<0 || x>5){
        cout << "Calificacion debe ser del 1-5" << endl;
        return false;
    }else{
        return true;
    }
}

bool checarNumVid(int x){
    if (x<0 || x>10 || x == 10){
        cout << "No esta dentro del rango disponible" << endl;
        return false;
    }else{
        return true;
    }
}

void calificar(int opC, Peliculas *peliculasM, Series *seriesM, int cantP, int cantS){
    int opC2, calificacion;
    bool flag = false;

    if(opC == 1){
        cout << endl;
        for (int i = 0; i < cantP; i++){
            cout << peliculasM[i].getNombre() << " (" << i << ")"<< endl;
        }
        while(flag == false){
        cout << "Que pelicula quieres calificar: ";
        cin >> opC2;
        flag = checarNumVid(opC2);
        }

        flag = false;
        while (flag == false){
            cout << "Calificacion para " << peliculasM[opC2].getNombre() << " (1-5): ";
            cin >> calificacion;
            flag = checarNumCal(calificacion);
        }

        peliculasM[opC2].setCalificacion(calificacion);
        cout << "Cambio de calificacion exitosa" << endl;

    }else if(opC == 2){
        cout << endl;
        for (int i = 0; i < cantS; i++){
            cout << seriesM[i].getNombre() << " (" << i << ")"<< endl;
        }
        cout << "Que serie quieres calificar: ";
        cin >> opC2;

        while(flag == true){
            cout << "Calificacion para " << seriesM[opC2].getNombre() << " (1-5): ";
            cin >> calificacion;
            flag = checarNumCal(calificacion);
        }
    
        seriesM[opC2].setCalificacion(calificacion);
        cout << "Cambio de calificacion exitosa" << endl;
    } else{
        cout << "Opcion no disponible";
        return;
    }
}

void mostrarSoP(Series *seriesM, Peliculas *peliculasM, int cantP, int cantS, int det){
    int calificacion, contador = 0, opMV;
    string genero;
    if(det == 1){
        cout << "De que calificacion son las series que quieres ver (1-5): ";
        cin >> calificacion;

        cout << endl << "Calificacion    Serie                         Genero               ID                Duracion          Episodios" << endl;
        for(int i = 0; i < cantS; i++){
        if(seriesM[i].getCalificacion() == calificacion){
            seriesM[i].mostrar();
            contador = contador + 1;

        }else{
            continue;
        }
        } 
        if (contador == 0){
        cout << "No hay series con esta calificacion" << endl;
        }
    }
    
    else if(det == 2){
        cout << "De que calificacion son las peliculas que quieres ver (1-5): ";
        cin >> calificacion;

        cout << endl << "Calificacion    Peliculas               Genero                  ID                Duracion" << endl;
        for(int i = 0; i < cantP; i++){
        if(peliculasM[i].getCalificacion() == calificacion){
            peliculasM[i].mostrar();
            contador = contador + 1;
        }else{
            continue;
        }
        } 
        if (contador == 0){
        cout << "No hay peliculas con esta calificacion" << endl;
        }
    }

    else{
        cout << "Mostrar por genero (1) o calificacion (2): ";
        cin >> opMV;

        if(opMV == 1){
            cout << "Animacion, Sci-Fi, Drama"<< endl;
            cout << "De que genero son los videos que quieres ver: ";
            cin >> genero;
            //
            cout << endl << "Calificacion    Video               Genero                  ID                Duracion" << endl;
            for(int i = 0; i < cantP; i++){
                if(peliculasM[i].getGenero() == genero){
                peliculasM[i].mostrar();
                contador = contador + 1;
            }else{
                continue;
            }
            }

            for(int i = 0; i < cantS; i++){
                if(seriesM[i].getGenero() == genero){
                    seriesM[i].mostrar();
                    contador = contador + 1;

                }else{
                    continue;
                }
                }

            if (contador == 0){
            cout << "No hay videos con esta calificacion" << endl;
            }
        }

        else if(opMV == 2){
            cout << "De que calificacion son los videos que quieres ver (1-5): ";
            cin >> calificacion;

            cout << endl << "Calificacion    Video               Genero                  ID                Duracion            Episodios" << endl;
            for(int i = 0; i < cantP; i++){
                if(peliculasM[i].getCalificacion() == calificacion){
                peliculasM[i].mostrar();
                contador = contador + 1;
            }else{
                continue;
            }
            }

            for(int i = 0; i < cantS; i++){
                if(seriesM[i].getCalificacion() == calificacion){
                    seriesM[i].mostrar();
                    contador = contador + 1;
                }
                else{
                    continue;
                }
                }
                if (contador == 0){
                cout << "No hay videos con esta calificacion" << endl;
                }
            
        }
        else{
            cout << "Opcion no disponible";
            return;
        }
    }
}

void nuevo(Peliculas *peliculasM, Series *seriesM, int countP, int countS){
    int det, iD, duracion, calificacion;
    string nombre, genero;

    cout << "Cargar pelicula(1) o serie(2) nueva: ";
    cin >> det;

    if(det == 1){
        cout << "Nombre de pelicula: ";
        cin >> nombre;
        cout << "Genero de pelicula: ";
        cin >> genero;
        cout << "Calificacion de pelicula: ";
        cin >> calificacion;
        cout << "ID de pelicula: ";
        cin >> iD;
        cout << "Duracion de pelicula: ";
        cin >> duracion;

        Peliculas peliculaN(calificacion, iD, duracion, nombre, genero);
        peliculasM[countP] = peliculaN;
        cout << endl << "Pelicula se cargo con exito" << endl;
    }

    else if(det == 2){
        cout << "Nombre de serie: ";
        cin >> nombre;
        cout << "Genero de serie: ";
        cin >> genero;
        cout << "Calificacion de serie: ";
        cin >> calificacion;
        cout << "ID de serie: ";
        cin >> iD;
        cout << "Duracion de serie: ";
        cin >> duracion;

        Series serieN(calificacion, iD, duracion, nombre, genero);
        seriesM[countS] = serieN;
        cout << endl;
    }
    
    else{
        cout << "Opcion no disponible" << endl;
    }   
}


int main(){

    //Largo de nombre = 9
    //Largo de Genero = 9
    int cantP = 10, cantS = 10, countP = 5, countS = 5, det;
    Peliculas peliculasM[cantP];
    Peliculas pelicula1(0, 101, 117, "Cars     ", "Animacion");
    Peliculas pelicula2(0, 102, 81, "Toy Story", "Animacion");
    Peliculas pelicula3(0, 103, 121, "Star Wars", "Sci-Fi");
    Peliculas pelicula4(0, 104, 133, "Rogue One", "Sci-Fi");
    Peliculas pelicula5(0, 105, 96, "Up       ", "Animacion");

    //Largo de nombre = 15
    //Largo de Genero = 6
    Series seriesM[cantS];
    Series series1(0, 201, 150, "Stranger Things", "Drama");
    Series series2(0, 202, 200, "Peaky Blinders ", "Drama");
    Series series3(0, 203, 180, "Mandalorian    ", "Sci-Fi");
    Series series4(0, 204, 120, "Obi-Wan Kenobi ", "Sci-Fi");
    Series series5(0, 205, 300, "Flash          ", "Drama");

    peliculasM[0] = pelicula1;
    peliculasM[1] = pelicula2;
    peliculasM[2] = pelicula3;
    peliculasM[3] = pelicula4;
    peliculasM[4] = pelicula5;  

    seriesM[0] = series1;
    seriesM[1] = series2;
    seriesM[2] = series3;
    seriesM[3] = series4;
    seriesM[4] = series5;

    bool flag = true;
    int opcionMenu = 0;

    while (flag == true){
        cout << "\n";
        cout << "Opcion 1: Cargar Archivo de Video" << endl;
        cout << "Opcion 2: Mostrar Videos en General" << endl;
        cout << "Opcion 3: Mostrar Series" << endl;
        cout << "Opcion 4: Mostrar Peliculas" << endl;
        cout << "Opcion 5: Calificar un Video" << endl;
        cout << "Opcion 6: Salir" << endl << endl;
        cin >> opcionMenu;

        switch (opcionMenu){

            case 1:
                nuevo(peliculasM, seriesM, countP, countS);
                countP = countP + 1;
                countS = countS + 1;
                break;
                
            case 2:
                det = 3;
                mostrarSoP(seriesM, peliculasM, cantP, cantS, det);               
                break;

            case 3:
                det = 1;
                mostrarSoP(seriesM, peliculasM, cantP, cantS, det);               
                break;

            case 4:
                det = 2;
                mostrarSoP(seriesM, peliculasM, cantP, cantS, det);               
                break;

            case 5:
                int opC;
                cout << "Calificar pelicula (1) o serie (2): ";
                cin >> opC;
                calificar(opC, peliculasM, seriesM, cantP, cantS);
                break;

            case 6:
                flag = false;
                break;
            
            default:
                cout << "Opcion no disponible" << endl;
        }
    }

    return 0;
}