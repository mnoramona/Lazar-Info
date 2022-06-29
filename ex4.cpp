#include <iostream>
using namespace std;
void testare(int n,int m,int &OK){
  int a[n][m];
  int bara1 = 0, bara2 = 0, bara3 = 0;
  OK = 0;
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= m; j++){
      cout<<" Introduceti elementul din pozitia "<<i<<" "<<j<<" a matricei"<<endl;
      cin>>a[i][j];
    }
  }
  OK = OK + 1;
  cout<<"Matricea este patratica"<<endl;
  for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++){
      if(a[i][j] == 0 || a[i][j] == 1){
        bara1 = bara1 + 1;
        if(i == j){
          if(a[i][j] == 0) bara2 = bara2 + 1;
        else
          cout<<"Pe diagonala principala nu se afla numai 0"<<endl;
        } 
      }
    }
  if(bara1 == n * n){
    OK = OK + 1;
    cout<<"Matricea este binara"<<endl;
    if(bara2 == n){
      OK = OK + 1;
      cout<<"Matricea are numai 0 pe diagonala principala"<<endl;
    }
  }
}
int main(){
  int n,m,OK=0;
  cout<<"Introduceti n numarul de linii a matricii"<<endl;
  cin>>n;
  cout<<"Introduceti m numarul de coloane a matricii"<<endl;
  cin>>m;
  if(n == m){
    testare(n,m,OK);
  }
  else
    cout<<"Matricea nu este patratica"<<endl;
  if(OK==3)
    cout<<"Matricea data poate fi matrice de adiacenta"<<endl;
  else
    cout<<"Matricea data nu poate fi matrice de adiacenta"<<endl;
  return 0;
}
