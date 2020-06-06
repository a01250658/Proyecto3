#include <iostream>
#include <string>
using namespace std;
#ifndef material_h
#define material_h
class material{
  protected:
  int IdMaterial;
  string titulo;
  public:
  material();
  material(int,string);
  int getMaterial();
  string getTitulo();
  void setMaterial(int);
  void setTitulo(string);
  virtual void MuestraDatos() =0;
  virtual int cantidadDiasPrestamo() = 0;
};

material::material(){
  IdMaterial = 0;
  titulo = "N/A";
}

material::material(int iMat, string sTit){
  IdMaterial=iMat;
  titulo=sTit;
}
int material::getMaterial(){
  return IdMaterial;
}
string material::getTitulo(){
  return titulo;
}
void material::setMaterial(int iMat){
  IdMaterial=iMat;
}
void material::setTitulo(string sTit){
  titulo=sTit;
}
#endif
