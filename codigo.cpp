#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){
  int Nx = 101;
  int NT = 300;
  
  double rho = 40;
  double ten = 10.;
  double c = sqrt(ten/rho);
  double cl = c;
  double ratio = c*c/(cl*cl);

  int m = 1;

  double T[Nx][3];
  double Tpl[Nx][NT];

  for(int i=0;i<Nx;i++){
    for(int j=0;j<3;j++){
      T[i][j]=sin(2*M_PI*i*0.005);
    }
    for(int j=0;j<NT;j++){
      Tpl[i][j]=0.0;
    }
    Tpl[i][0]=T[i][0];
  }
  /*
  for(int i=1;i<Nx-1;i++){
    if(i*Dx < 1.2 && i*Dx > 0.8){
      T[i][0]=500.0;
    }
  }
  */
  for(int t=1;t<NT;t++){
    if(t==1){
      for(int ix=1; ix<Nx-1;ix++){
        T[ix][1] = T[ix][0] + 0.5*ratio*(T[ix+1][0] + T[ix-1][0]-2.*T[ix][0]);
      }
    }else{
      for(int ix=1; ix<Nx-1;ix++){
        T[ix][2] = 2.*T[ix][1] - T[ix][0] + ratio*(T[ix+1][1]+T[ix-1][1]-2.*T[ix][1]);
      }
    }
    if(t%1 == 0 || t == 1){
      for(int i=1;i<Nx;i++){
        Tpl[i][m]=T[i][2];
      }
      cout << m << endl;
      m = m + 1;
    }
    for(int ix=1;ix<Nx-1;ix++){
      T[ix][0]=T[ix][1];
      T[ix][1]=T[ix][2];
    }
  }

  ofstream MiData("Data.dat");
  for(int ix = 0; ix < Nx; ix++){
    for(int t = 0; t < m; t++){
      //MiData << ix << "\t" << t << "\t" << Tpl[ix][t] << endl;
      MiData << Tpl[ix][t] << endl;
    }
  }


  return 0;
}

