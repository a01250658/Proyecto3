#include <iostream>
#include "Material.h"
#ifndef Disco_h
#define Disco_h
using namespace std;

class Disco:public material{
  private:
  int Duracion;
  string Genero;
  public:
  Disco();
  Disco(int, string, int, string);
  void MuestraDatos();
  int cantidadDiasPrestamo();
};

Disco::Disco():material(){
  Duracion = 0;
  Genero = "N/A";
}
Disco::Disco(int iNum, string sT, int iDur, string sGen):material(iNum, sT){
  Duracion = iDur;
  Genero = sGen;
}

void Disco::MuestraDatos(){
  cout <<"ID: " << IdMaterial << endl;
  cout << "Titulo: " << titulo << endl;
  cout << "Duracion: " << Duracion << endl;
  cout << "Genero: " << Genero << endl;
}
int Disco:: cantidadDiasPrestamo(){
  return 2;
}
#endif