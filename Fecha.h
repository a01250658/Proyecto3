#include <iostream>
using namespace std;
#ifndef Fecha_h
#define Fecha_h

class Fecha{
  private:
  int dd;
  int mm;
  int aa;
  public:
  Fecha();
  Fecha(int,int,int);
  int getD();
  int getM();
  int getY();
  void setD(int);
  void setM(int);
  void setY(int);
  Fecha operator+(int);
  bool operator>=(Fecha);
  bool operator<=(Fecha);
  bool operator>(Fecha);
  bool operator<(Fecha);
  bool operator==(Fecha);
  friend istream& operator>>(istream&, Fecha&);
  friend ostream& operator<<(ostream&, Fecha);
  string nombreMes();
};
Fecha::Fecha(int iD, int iM, int iA){
  dd=iD;
  mm=iM;
  aa=iA;
}
int Fecha::getD(){
  return dd;
}
int Fecha::getM(){
  return mm;
}
int Fecha::getY(){
  return aa;
}
istream& operator>>(istream &ins, Fecha &Fecha1){
  int iD,iM,iA;
  cout << "Dia: " << endl;
  ins >> Fecha1.dd;
  cout << "Mes: " << endl;
  ins >> Fecha1.mm;
  cout << "Año: " << endl;
  ins >> Fecha1.aa;
  return ins;
}

ostream& operator << (ostream &out, Fecha Fecha1){
  out << "Dia: " << Fecha1.dd << endl;
  out << "Mes: " << Fecha1.mm << endl;
  out << "Año: " << Fecha1.aa << endl;
  return out;
}

Fecha Fecha::operator+(int dd){
  int iD, iM, iA;
  iD = dd + iD;
  iM = mm;
  iA = aa;
  if(iM == 1 || iM == 3 || iM == 5 || iM == 7 || iM == 8 || iM ==10 || iM == 12){
    if(iD > 31){
      iD = 1;
      iM++;
    }
    if(iM > 12){
      iA++;
      iM = 1;
    } 
  }
  if (iM == 4 || iM == 6 || iM == 9 || iM == 11){
    if(iD > 30){
      iD = 1;
      iM++;
    }
    if(iM > 12){
      iA++;
      iM = 1;
    }
  } if (iM ==2){
    if (iD > 28){
      iD =1;
      iM++;
    }
    if(iM > 12){
      iA++;
      iM = 1;
    }
  }
  Fecha nFecha(dd,mm,aa);
  return nFecha;
}
bool Fecha::operator>=(Fecha Fecha1){
  if(aa>Fecha1.getY()){
    return true;
  }else if(aa == Fecha1.getY()){
    if(mm>Fecha1.getM()){
      return true;
    } 
    else if ( mm == Fecha1.getM()){
      if(dd >= Fecha1.getD()){
        return true;
      }
    }
  }
  return false;
}
bool Fecha::operator>(Fecha Fecha1){
  if (dd>Fecha1.getD()){
    if (mm>Fecha1.getM()){
      if(aa>Fecha1.getY()){
        return true;
      }
    }
  }
  if (mm>Fecha1.getM()){
      if (aa>Fecha1.getY()){
       return true;}
  }
  if (aa>Fecha1.getY()){
    return true;}
  return false;
}
bool Fecha::operator<=(Fecha Fecha1){
  if (aa<Fecha1.getY()){
    return true;}
    else if(aa==Fecha1.getY()){
      if (mm<Fecha1.getM()){
        return true;
      }
      else if (mm==Fecha1.getM()){
        if(dd<=Fecha1.getD()){
          return true;
        }
      }
    }
    return false;
}
bool Fecha::operator<(Fecha Fecha1){
  if (aa<Fecha1.getY()){
    return true;
  }
  if (mm<Fecha1.getM()){
    if (aa<Fecha1.getY()){
      return true;
    }
  }
  if (dd<Fecha1.getD()){
    if (mm<Fecha1.getM()){
      if (aa<Fecha1.getY()){
        return true;
      }
    }
  }
  return false;
}
bool Fecha::operator==(Fecha Fecha1){
  if (dd==Fecha1.getD()){
    if (mm==Fecha1.getM()){
      if (aa==Fecha1.getY()){
        return true;
        }
      }
    }
  return false;
}
string Fecha::nombreMes(){
  switch(mm){
    case 1:
      return "Ene";
      break;
      case 2:
      return "Feb";
      break;
      case 3:
      return "Mar";
      break;
      case 4:
      return "Abr";
      break;
      case 5:
      return "May";
      break;
      case 6:
      return "Jun";
      break;
      case 7:
      return "Jul";
      break;
      case 8:
      return "Ago";
      break;
      case 9:
      return "Sep";
      break;
      case 10:
      return "Oct";
      break;
      case 11:
      return "Nov";
      break;
      case 12:
      return "Dic";
      break;
      default:
      return "N/A";
      break;
  }
}
#endif