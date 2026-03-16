#include <iostream>
#include <math.h>
using namespace std;

int division_entera(int dividendo, int divisor, int &resto);
int facto(int n);
int factoR(int n);
double hipot(float co, float ca);
void intercambio(char &a, char &b);

int main() {
  int resto = 10;
  int dividendo = 15;
  int divisor = 5;
  int div = division_entera(dividendo, divisor, resto);
  cout << div << " " << resto << endl;
  return 0; /*
  resto = 0;
      int coci = division_entera(10, 5,resto);
      cout << coci << " " << resto << endl;
      coci = division_entera(10, 3,resto);
      cout << coci << " " << resto << endl;

      cout <<" ****************** " <<endl;
      cout << " " << facto(5) << endl;
      cout <<" ****************** " <<endl;
      cout << " " << factoR(5) << endl;

      cout <<" **Hipotenusa************** " <<endl;
      cout << " " << hipot(2,5) << endl;
  */
  return 0;
}

int division_entera(int dividendo, int divisor, int &resto) {
  int cociente = dividendo / divisor;
  resto = dividendo % divisor;
  return cociente;
}

int facto(int n) {
  int factorial = 1;
  for (int i = 2; i <= n; i++) {
    factorial *= i;
  }
  return factorial;
}

int factoR(int n) {
  if (n == 1 || n == 0)
    return 1;

  else {
    return n * factoR(n - 1);
  }
}

double hipot(float co, float ca) {
  double hipo = sqrt(pow(co, 2) + pow(ca, 2));
  return hipo;
}
