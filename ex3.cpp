// Scrieti un program in care, folosind subprograme, cititi de la tastatura numarul de varfuri (n) si de arce(m) precum si arcelele(folosind vectorul arcelor)
// unui graf orientat G=(X,U) si verificati daca o secventa de varfuri(citita din fisierul ‚drum.txt’) reprezinta un drum elementar sau ne-elementar in graf.
// Secventa de varfuri este scrisa pe un singur rand,varfurile fiind delimitate prin spatiu. In urma verificarii se va afisa un mesaj corespunzator.
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int n,m,vi = 0,ve = 0;
int i,j,k;
int f[20][20];
int v[20];
ifstream in("drum.txt");
struct arc{
  int x;
  int y;
  int c;
} a[200];
struct pers{
  int x;
  int y;
} b[200];
void citire2(){
  cin>>n;
  cin>>m;
  for(i = 1; i <= m; i++){
    cin>>b[i].x;
    cin>>b[i].y;
  }
}
void matrice(){
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      f[i][j] = 0;
    }
  }
  for(i = 1; i <= n; i++) f[b[i].x][b[i].y] = 1;
}
void drum(){
  for(k = 1; k <= n; k++){
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++) if((f[i][j] == 0)&&(i != k) && j != k) f[i][j] = f[i][k] * f[k][j];
    }
  }
}
int main(){
  citire2();
  matrice();
  i = 1;
  while(in>>v[i]){
    i++;
  }
  int ok;
  ok = i - 1;
  for(i = 1; i <= ok; i++){
    in>>v[i];
  }
  drum();
  int n, o = 0;
  for(i = 1; i < ok; i++){
    if(f[v[i]][v[i + 1]] == 1)
      o++;
  }
  if (o == ok - 1){
    cout<<"Este drum";
  }
  else {cout<<"Nu este drum";
    n = 0;
  }
  if(v[1] == v[ok] && n != 0){
    cout<<" neelementar.";
  }
  if(v[1] != v[ok] && n!=0){
    cout<<" elementar.";
  }
  return 0;
}
