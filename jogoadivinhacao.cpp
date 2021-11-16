#include <iostream>

using namespace std;

void abertura() {
  system("cls ");
  cout << "*********************************************" << endl;
  cout << "******BEM VINDOS AO JOGO DA ADIVINHAÇÃO******" << endl;
  cout << "*********************************************" << endl;
}

int main() {
  const int NUMERO_SECRETO = 42;
  int chute;
  bool igual;
  bool maior;

  abertura();

  do {

    cout << "Qual seu chute?" << endl;
    cin >> chute;
    igual = chute == NUMERO_SECRETO;
    maior = chute >= NUMERO_SECRETO;

    if (igual) {
      cout << "Parabéns, você acertou" << endl;
    } else if (maior) {
      cout << "Seu chute é maior que o numero secreto!" << endl;
    } else {
      cout << "Seu chute é menor que o numero secreto!" << endl;
    }
  } while (1);
}