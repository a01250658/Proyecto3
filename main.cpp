#include <iostream>
#include <fstream>
#include "Reserva.h"
#include "Fecha.h"
#include "Material.h"
#include "Software.h"
#include "Disco.h"

using namespace std;
 
 int main() {
 material *materiales[30];
 reserva reservas[60];
 int iCont = 0;
  int iCont1 = 0;
  int iD1, iC = 1;
  bool bEx = false;
  int iRes = 0;
  int iMaterial;
  int iDuracion;
  int iNumP;
  int ver;
  int iCliente;
  int iMat;
  Fecha Fecha1;
  string sAut;
  string titulo;
  string Genero;
  char cTipo;
  bool valido = false;
  Fecha F1;
  bool bEx1 = false;
  string SO;
  ifstream MatTexto;
  MatTexto.open("Material.txt");
  ifstream ResTexto;
  ResTexto.open("Reserva.txt");
  
  while(!MatTexto.eof()){
    MatTexto>> iMaterial >> titulo >> cTipo;
    switch(cTipo){
      case'S':
      MatTexto>>SO;
      materiales[iCont] = new software(iMaterial,titulo,ver, SO);
      iCont++;
      break;
      case'D':
      MatTexto>>iDuracion;
      materiales[iCont] = new Disco(iMaterial,titulo,iDuracion,Genero);
      iCont++;
      break;
      case'B':
      MatTexto>>iNumP>>sAut;
      materiales[iCont] = new Libro(iMaterial,titulo,iNumP,sAut);
      iCont++;
      break;
    }
    }
    while (!ResTexto.eof())
{
  int D,M,A,iMat,cID;
  ResTexto>>D>>M>>A>>iMat>>cID;
  Fecha Fecha2(D,M,A);
  reserva r1(iMat,cID,Fecha2);
  reservas[iCont1]=r1;
  iCont1++;
}
char cMenu;
do{
  cout<<endl;
    cout<<"Menu"<<endl;
    cout<<"a.- Consultar la lista de Materiales:"<<endl;
    cout<<"b.- Consultar la lista de reservaciones:"<<endl;
    cout<<"c.- Consultar las reservaciones de un material dado:"<<endl;
    cout<<"d.- Consultar las reservaciones de una fecha dada:"<<endl;
    cout<<"e.- Hacer una reservación:"<<endl;
    cout<<"f.- Terminar:"<<endl;
    cin>>cMenu;
 switch(cMenu){
      case 'a':
      for(int iX = 0; iX < iCont; iX++) {
    materiales[iX]->MuestraDatos();
    cout << endl;
    }
    break;
    case 'b': 
    for(int iX = 0; iX < iCont1; iX++) {
    reservas[iX].MuestraDatos();
  int iD = reservas[iX].getMaterial();

    for (int iY=0;iY<iCont;iY++){
      if(materiales[iY] -> getMaterial() == iD ) {
      Fecha eReserva = reservas[iX].calculaFechaFinReserva(materiales[iY] -> cantidadDiasPrestamo());
    }}}
    break;
     case 'c':
    cout << endl <<" ID:  ";
    cin >> iD1;
    for(int iX = 0; iX < iCont1; iX++) {
    if(reservas[iX].getMaterial() == iD1) {
      cout << iC << " " << endl;
      reservas[iX].MuestraDatos();
      int iD2 = reservas[iX].getMaterial();
    for (int iY=0;iY<iCont;iY++){
      if(materiales[iY] -> getMaterial() == iD2 ) {
      Fecha eReserva = reservas[iX].calculaFechaFinReserva(materiales[iY] -> cantidadDiasPrestamo());
    }}
      iC++;
      bEx = true;
    }
    }
    break;
    case 'd':
  

    cout << endl;
    cin >> F1;
    for(int iX = 0; iX < iCont1; iX++) {
    if(reservas[iX].getReserva() == F1) {
      int X = reservas[iX].getMaterial();
      for(int iX = 0; iX < iCont; iX++) {
        if(materiales[iX] -> getMaterial() == X) {
          cout << "Reservado " << endl;
          materiales[iX] -> MuestraDatos();
          cout << endl;
          bEx1 = true;
        }
      }
    }  
  }
  if(bEx1 == false) {
    cout << "No hay reservacion" << endl <<endl;
  }
    break;
    case 'e':
  cout <<"Cliente ID= ";
  cin>>iCliente;
  cout << "Material ID= ";
  cin >> iMat;
  cout << "Fecha= "<< endl;
  cin>> Fecha1;
  for (int iX=0;iX<iCont;iX++){
    if(materiales[iX]->getMaterial() == iMat){
      for(int iY= 0;iY<iCont1;iY++){
        if (iMat == reservas[iY].getMaterial()){
          if (reservas[iY].getReserva() > Fecha1 || reservas[iY].calculaFechaFinReserva(materiales[iX]->cantidadDiasPrestamo()) < Fecha1){
            if(iCont1<60){
              reserva reser(iMat,iCliente,Fecha1);
              reservas[iCont1]= reser;
              cout << "Reservaste Correctamente" <<endl;
              iCont1++;
              valido = true;
              break;
            }
          }
          else { cout << "Ya esta reservado";}
        }
      }
    }
  }
  if(valido == false){
    cout << "No existe el Material"<< endl;
  }
  break;
case 'f':
break;
  default:
  cout << "Opcion invalida" << endl;
  break;
    }
 }
 while(cMenu!='f');

    return 0;
 }