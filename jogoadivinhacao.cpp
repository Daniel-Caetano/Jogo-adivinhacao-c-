#include <iostream>

using namespace std;

int main() {
  system("cls ");
  const int numeroSecreto = 42;
  int chute;
  bool igual = numeroSecreto == chute;
  bool maior = numeroSecreto >= chute;

  cout << "*********************************************" << endl;
  cout << "******BEM VINDOS AO JOGO DA ADIVINHAÇÃO******" << endl;
  cout << "*********************************************" << endl;
  do {

    cout << "Qual seu chute?" << endl;
    cin >> chute;

    if (igual) {
      cout << "Parabéns, você acertou" << endl;
    } else if (maior) {
      cout << "Seu chute é maior que o numero secreto!" << endl;
    } else {
      cout << "Seu chute é menor que o numero secreto!" << endl;
    }

  } while (1);
}