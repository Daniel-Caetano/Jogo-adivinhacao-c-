#include <iostream>

using namespace std;

int main() {
  system("cls ");
  int numeroSecreto = 42;
  int chute;

  cout << "*********************************************" << endl;
  cout << "******BEM VINDOS AO JOGO DA ADIVINHAÇÃO******" << endl;
  cout << "*********************************************" << endl;
  do {

    cout << "Qual seu chute?" << endl;
    cin >> chute;

    if (chute == numeroSecreto) {
      cout << "Parabéns, você acertou" << endl;
    } else if (chute >= numeroSecreto) {
      cout << "Seu chute é maior que o numero secreto!" << endl;
    } else {
      cout << "Seu chute é menor que o numero secreto!" << endl;
    }

  } while (1);
}