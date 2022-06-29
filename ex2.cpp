// Se defineste un arc al unui graf orientat ca o inregistrare cu treicampuri: varful din care iese arcul, varful in care intra arcul si un cost
// asociat arcului (un numar intreg). Definim un graf orientat ca un vector dearce. Fiind dat vectorul de arce al unui graf orientat G=(X,U) cu m arce si n varfuri,
// sa se construiasca si sa se afiseze matricea de adiacenta, apoi sa se determine costul mediu al grafului (media aritmetica a costurilor arcelor).
#include <iostream>
#include <fstream>
using namespace std;
ofstream out ("date.out");
ifstream in ("date.in");
int a[20][20], m, n, ok, s;
struct arce{
  int x,y,cs;
}v[20];

void citire (){
  int a,b,c,i;
  in>>n;
  in>>m;
  for(i = 1; i <= m; i++){
    in>>a;
    in>>b;
    in>>c;
    v[i].x = a;
    v[i].y = b;
    v[i].cs = c;
  }
  in.close();
}
int main(){
  int i,j;
  citire();
  for(i = 1; i <= m; i++){
    a[v[i].x][v[i].y] = 1;
    s = s + v[i].cs;
  }
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++)
      out<<a[i][j]<<" ";
    out<<endl;
  }
  out<<"Costul mediu este "<<s/m;
  out.close();
  return 0;
}
