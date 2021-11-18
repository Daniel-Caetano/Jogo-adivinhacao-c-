#include <Windows.h>
#include <iostream>

using namespace std;

void abertura() {
  system("cls ");
  cout << "*********************************************" << endl;
  cout << "******BEM VINDOS AO JOGO DA ADIVINHAÇÃO******" << endl;
  cout << "*********************************************" << endl;
}

int dificuldade() {
  int nivel;
  int nTentativas;
  cout << "\nEscolha o nivel do desafio:" << endl;
  cout << "__________________" << endl;
  cout << "|[1] = Facil     |" << endl;
  cout << "|[2] = Medio     |" << endl;
  cout << "|[3] = Dificil   |" << endl;
  cout << "------------------" << endl;
  cin >> nivel;

  switch (nivel) {
  case 1:
    nTentativas = 20;
    break;
  case 2:
    nTentativas = 13;
    break;
  case 3:
    nTentativas = 5;
    break;
  default:
    system("cls || clear");
    cout << "COMANDO INVALIDO" << endl;
    Sleep(1500);
    dificuldade();
  }

  return nTentativas;
}

int main() {
  const int NUMERO_SECRETO = 42;

  bool naoAcertou = true;
  bool igual;
  bool maior;

  int chute;
  int tentativas = 1;

  double pontuacao = 1000.00;

  abertura();
  const int _NIVEL = dificuldade();

  do {

    cout << "Qual seu chute?" << endl;
    cin >> chute;
    igual = chute == NUMERO_SECRETO;
    maior = chute >= NUMERO_SECRETO;

    if (igual) {
      system("cls");
      cout << "\nParabéns, você acertou em " << tentativas << " tentativas"
           << endl;
      cout.precision(2);
      cout << fixed;
      cout << "Sua pontuação foi de :|" << pontuacao << "|" << endl;
      naoAcertou = false;
      break;
    } else if (maior) {
      cout << "Seu chute é maior que o numero secreto!" << endl;
      double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
      pontuacao = pontuacao - pontosPerdidos;
    } else {
      cout << "Seu chute é menor que o numero secreto!" << endl;
      double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
      pontuacao = pontuacao - pontosPerdidos;
    }

    if (tentativas == _NIVEL) {
      system("cls || clear");
      naoAcertou = false;
      cout << "Você perdeu!!" << endl;
      cout << "Numero de tentativas: " << tentativas << endl;
      Sleep(1000);
      break;
    }
    tentativas++;
  } while (naoAcertou);
}