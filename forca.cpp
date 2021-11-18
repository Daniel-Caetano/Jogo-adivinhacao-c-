// Daniel Caetano de Souza Ferreira
// 18/11/2021
// Jogo desenvolvido para acompanhar site do Alura no curso de C++

#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string palavraSecreta;
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
  for (char letra : palavraSecreta) {
    if (letra == chute) {
      return true;
    }
  }
  return false;
}

bool nao_acertou() {
  for (char letra : palavraSecreta) {
    if (!chutou[letra]) {
      return true;
    }
  }
  return false;
}
bool nao_enforcou() { return chutesErrados.size() < 5; }

void tabela() {
  for (char letra : palavraSecreta) {
    if (chutou[letra]) {
      cout << letra << " ";
    } else {
      cout << "_ ";
    }
  }
}

void encerramento() {
  system("cls || clear");
  cout << "\nFim de jogo" << endl;
  if (nao_enforcou()) {
    cout << "Parabens, voce ganhou o jogo!" << endl;
    cout << "Palavra secreta:|" << palavraSecreta << "|" << endl;
    cout << "Chutes errados:|";
    for (char letra : chutesErrados) {
      cout << letra << "|";
    }
  } else {
    cout << "Voce perdeu, tente outra vez!!!" << endl;
    cout << "Palavra secreta:|" << palavraSecreta << "|" << endl;
    cout << "Chutes errados:|";
    for (char letra : chutesErrados) {
      cout << letra << "|";
    }
  }
}
void chutes_errados() {
  cout << "Chutes errados: |";
  for (char letra : chutesErrados) {
    cout << letra << "|";
  }
}

vector<string> le_arquivo() {
  int qtdPalavra;
  ifstream arquivo;
  arquivo.open("palavra.txt");
  if (arquivo.is_open()) {

    arquivo >> qtdPalavra;
    vector<string> palavras;

    for (int i = 0; i < qtdPalavra; i++) {
      string palavraLida;
      arquivo >> palavraLida;
      // cout << "Linha: " << i + 1 << "| Palavra: " << palavraLida << endl;
      palavras.push_back(palavraLida);
    }
    arquivo.close();
    return palavras;
  } else {
    cout << "Não foi possivel abrir o arquivo" << endl;
    exit(0);
  }
}

void sorteia_palavra() {
  vector<string> palavras = le_arquivo();
  srand(time(NULL));
  palavraSecreta = palavras[rand() % palavras.size()];
}
int main() {
  char chute;

  sorteia_palavra();
  le_arquivo();
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

    chutes_errados();

    cout << endl;
  } while (nao_enforcou() && nao_acertou());
  encerramento();
}
