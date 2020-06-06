#include <iostream>
#include "Material.h"
#include <string>

#ifndef software_h
#define software_h

class software:public material{
  private:
  int Version;
  string SO;
  public:
  software();
  software(int, string, int, string);
  void MuestraDatos();
  int cantidadDiasPrestamo();
};

software::software():material(){
  Version = 0;
  SO = "N/A";
}

software::software(int iNum, string sT, int iVer, string sOS):material(iNum, sT){
  Version = iVer;
  SO = sOS;
}

void software::MuestraDatos(){
  cout << "ID: " << IdMaterial << endl;
  cout << "Titulo: " << titulo << endl;
  cout << "Version: " << Version << endl;
  cout << "Sitema Operativo: " << SO << endl;
}

int software::cantidadDiasPrestamo(){
  return 1;
}

#endif