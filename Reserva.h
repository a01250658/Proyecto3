#include <iostream>
#include "Libro.h"
#include "Disco.h"
#include "Fecha.h"
#include "Software.h"
using namespace std;

#ifndef reserva_h
#define reserva_h
class reserva{
  private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
  public:
  reserva();
  reserva(int,int,Fecha);
  int getMaterial();
  int getCliente();
  Fecha getReserva();
  void setMaterial(int);
  void setCliente(int);
  void setReserva(Fecha);
  Fecha calculaFechaFinReserva(int);
  void MuestraDatos();
};
reserva::reserva(){
  idMaterial=-1;
  idCliente=-1;
}
reserva::reserva(int iMat, int iCli, Fecha Res){
  idMaterial=iMat;
  idCliente=iCli;
  fechaReservacion=Res;
}
int reserva::getMaterial(){
  return idMaterial;
}
int reserva::getCliente(){
  return idCliente;
}
Fecha reserva::getReserva(){
  return fechaReservacion;
}
void reserva::setMaterial(int iMat){
  idMaterial=iMat;
}
void reserva::setCliente(int iCli){
  idCliente=iCli;
}
void reserva::setReserva(Fecha Res){
  fechaReservacion=Res;
}
Fecha reserva::calculaFechaFinReserva(int dd1){
  Fecha Result;
  Result=fechaReservacion+dd1;
  return Result;
}
void reserva::MuestraDatos(){
  cout<<"Material= "<<idMaterial<<endl;
  cout<<"Cliente= "<<idCliente<<endl;
  cout<<"Fecha de Reserva:"<<endl;
  cout<<fechaReservacion<<endl;
}
#endif