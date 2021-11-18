// Daniel Caetano de Souza Ferreira
// 18/11/2021
// Jogo desenvolvido para acompanhar site do Alura no curso de C++

#include <Windows.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const string _PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutesErrados;

void abertura() {
  system("cls || clear");
  cout << "\n*********************" << endl;
  cout << "*** Jogo da Forca ***" << endl;
  cout << "*********************" << endl;
  cout << endl;
}
bool procura_letra(char chute) {
  for (char letra : _PALAVRA_SECRETA) {
    if (letra == chute) {
      return true;
    }
  }
  return false;
}

bool nao_acertou() {
  for (char letra : _PALAVRA_SECRETA) {
    if (!chutou[letra]) {
      return true;
    }
  }
  return false;
}

void tabela() {
  for (char letra : _PALAVRA_SECRETA) {
    if (chutou[letra]) {
      cout << letra << " ";
    } else {
      cout << "_ ";
    }
  }
}

bool nao_enforcou() { return chutesErrados.size() < 5; }
int main() {
  char chute;

  abertura();

  do {

    cout << "\nSeu chute: ";
    cin >> chute;
    chutou[chute] = true;

    tabela();

    if (procura_letra(chute)) {
      cout << "\nVoce acertou!" << endl;
    } else {
      cout << "\nVoce errou!!" << endl;
      chutesErrados.push_back(chute);
    }

    cout << "Chutes errados: |";
    for (char letra : chutesErrados) {
      cout << letra << "|";
    }

    cout << endl;
  } while (nao_enforcou() && nao_acertou());
}
