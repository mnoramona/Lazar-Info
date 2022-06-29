#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf.in.txt");
void gext(int n,int a[100][100]){
  int d = 0;
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      d = d + a[i][j];
    }
    cout<<"Gradul exterior al varfului "<<i<<" este "<<d<<endl;
    d = 0;
  }
}
void gint(int n, int a[100][100]){
  int d = 0;
  int i, j;
  for(j = 1; j <= n; j++){
    for(i = 1; i <= n; i++){
      d = d + a[i][j];
    }
    cout<<"Gradul interior al varfului "<<j<<" este "<<d<<endl;
    d = 0;
  }
}
void msuc(int n, int a[100][100]){
  int i, j;
  for(i = 1; i <= n; i++){
    cout<<"Multimea succesorilor varfului "<<i<<" este { ";
    for(j = 1; j <= n; j++){
      if(a[i][j] != 0)
      cout<<j<<" ";
    }
    cout<<"}"<<endl;
  }
}
void mpre(int n, int a[100][100]){
  int i, j;
  for(j = 1; j <= n; j++){
    cout<<"Multimea predecesorilor varfului "<<j<<" este { ";
    for(i = 1; i <= n; i++){
      if(a[i][j] != 0)
        cout<<i<<" ";
    }
    cout<<"}"<<endl;
  }
}
int main(){
  int n;
  f>>n;
  int a[100][100];
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      f>>a[i][j];
    }
  }
  gext(n,a);
  cout<<endl<<endl;
  gint(n,a);
  cout<<endl<<endl;
  msuc(n,a);
  cout<<endl<<endl;
  mpre(n,a);
  cout<<endl<<endl;
  return 0;
}
