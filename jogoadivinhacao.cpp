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

  bool naoAcertou = true;
  bool igual;
  bool maior;

  int chute;
  int tentativas = 0;

  double pontuacao = 1000.00;

  abertura();

  do {

    cout << "Qual seu chute?" << endl;
    cin >> chute;
    igual = chute == NUMERO_SECRETO;
    maior = chute >= NUMERO_SECRETO;

    if (igual) {
      system("cls");
      cout << "\nParabéns, você acertou em " << cout.precision(2) << tentativas
           << " tentativas" << endl;
      cout.precision(2);
      cout << fixed;
      cout << "Sua pontuação foi de :|" << pontuacao << "|" << endl;

      naoAcertou = false;
    } else if (maior) {
      cout << "Seu chute é maior que o numero secreto!" << endl;
      double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
      pontuacao = pontuacao - pontosPerdidos;
      tentativas++;
    } else {
      cout << "Seu chute é menor que o numero secreto!" << endl;
      double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
      pontuacao = pontuacao - pontosPerdidos;
      tentativas++;
    }

    // if (tentativas - 1 == 5) {
    // system("cls");
    // cout << "Você perdeu!!" << endl;
    // naoAcertou = false;
    // }
  } while (naoAcertou);
}