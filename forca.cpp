// Daniel Caetano de Souza Ferreira
// 18/11/2021
// Jogo desenvolvido para acompanhar site do Alura no curso de C++

#include <Windows.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const string _PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;

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

int main() {
  string palavra_secreta = "MELANCIA";
  bool naoAcertou = true;
  bool naoEnforcou = true;

  char chute;

  abertura();

  cout << "\nDigite uma letra" << endl;
  do {

    cin >> chute;
    chutou[chute] = true;
    cout << "Seu chute foi:" << chute << endl;

    for (char letra : _PALAVRA_SECRETA) {
      if (chutou[letra]) {
        cout << letra << " ";
      } else {
        cout << "_ ";
      }
    }

    if (procura_letra(chute)) {
      cout << "\nLetra existe!" << endl;
    } else {
      cout << "\nLetra nao existe!!" << endl;
    }

  } while (naoAcertou && naoEnforcou);
}
