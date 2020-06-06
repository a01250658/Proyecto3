#include <iostream>
#include "Material.h"
#ifndef Libro_h
#define Libro_h
using namespace std;

class Libro:public material{
  private:
  int numPag;
  string Autor;
  public:
  Libro();
  Libro(int, string, int, string);
  void MuestraDatos();
  int cantidadDiasPrestamo();
};

Libro::Libro():material(){
  numPag = 0;
  Autor = "N/A";
}

Libro::Libro(int iNum, string sT, int PNum, string sAut):material(iNum, sT){
  numPag = PNum;
  Autor = sAut;
}

void Libro::MuestraDatos(){
  cout << "ID: " << IdMaterial << endl;
  cout << "Titulo: " << titulo << endl;
  cout << "Numero de Pag: " << numPag << endl;
  cout << "Autor: " << Autor << endl;
}
int Libro::cantidadDiasPrestamo(){
  return 7;
}
#endif