// Se da un grup format din n persoane, care se cunosc sau nu intre ele. De la tastatura se introduc m perechi de numere intregi (x,y) cu semnificatia
// „persoana x o cunoaste pe persoana y”. Relatia de cunostinta nu este neaparatreciproca. Numim celebritate, o persoana care este cunoscuta de catre toate 
// celelalte persoane din grup, dar ea nu cunoaste pe nici un alt membru algrupului. Sa se determine daca in grup exista sau nu o astfel de celebritate. 
// (problema celebritatii)
#include <iostream>
#include <fstream>
using namespace std;
ofstream out ("date.out");
ifstream in ("date.in");
int a[20][20], m, n, ok;
void citire(){
  int x,y,i,j;
  in>>n;
  in>>m;
  for(i = 1; i <= m; i++){
    in>>x;
    in>>y;
    a[x][y]=1;
  }
  in.close();
}
int main(){
  int i,j;
  citire();
  for(i = 1; i <= n; i++){
    ok=1;
    for(j = 1; j <= n; j++) if(a[i][j] == 1 && i !=j ) ok = 0;
    for(j = 1; j <= n; j++) if(a[j][i] == 0 && i != j) ok = 0;
    if(ok==1){
      out<<"In grup exista cel putin o celebritate.";
      return 0;
    }
  }
  out<<"Nu exista nicio celebritate in grup.";
  out.close();
  return 0;
}
