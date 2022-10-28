#include "./Censo.hpp"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

void listAll(std::pair<int, std::string> p[], int lim) {
  int info, casa = 0;
  std::cout << "\n\t>>==================[ DADOS ]==================<<\n"
            << "\n\tListagem completa do conteudo do arquivo:\n\n";

  for (int i = 0; i < lim; i++) {
    info = i % 4;
    switch (info) {
    case 0:
      casa++;
      std::cout << "\n\t\t[ Casa numero " << casa << " ]\n";
      std::cout << "\n\t\tRua: " << p[i].second;
      break;
    case 1:
      std::cout << "\t\tOcupantes: " << p[i].second;
      break;
    case 2:
      std::cout << "\t\tEstudantes: " << p[i].second;
      break;
    case 3:
      std::cout << "\t\tRenda Media: " << p[i].second;
      break;
    }
    std::cout << std::endl;
  }
  std::cout << "\n\n\t>>==================[  FIM  ]==================<<";
  menu(p, lim);
}

int lookFor(std::pair<int, std::string> p[], std::string busca, int lim) {

  int ID = 0, S = 0, L = lim / 4;

  // Separando apenas os enderecos.
  std::string enderecos[L];
  for (int i = 0; i < L; i++)
    enderecos[i] = p[i * 4].second;

  // Busca binaria.
  while (S != L) {
    ID = (S + L) / 2;

    // std::cout << S << " " << ID << " " << L << std::endl;

    if (busca.compare(enderecos[ID]) == 0)
      return ID * 4;

    if (busca.compare(enderecos[ID]) > 0)
      S = ID + 1;

    else
      L = ID;
  }

  return -1;
}

int searchMenu(std::pair<int, std::string> casas[], int lim) {

  int ID;

  std::cout << "\n\n\t[PESQUISA]\n\n\t";
  std::cout << "Cite o endereco da casa a ser pesquisada.\n\t"
            << "Digite \"Sair\" para sair.\n\n\t>> ";

  // Input permitindo whitespace.

  char whiteSpaceInput[25];
  std::cin.ignore();
  std::cin.getline(whiteSpaceInput, 25);
  std::string input(whiteSpaceInput);

  if (input != "Sair" && input != "SAIR" && input != "sair") {
    ID = lookFor(casas, input, lim);

    if (ID == -1) {
      std::cout
          << "\n\n\tERRO: Endereco ausente na lista. Tente novamente.\n\t";
      menu(casas, lim);
      return 0;
    }

    std::cout << "\n\t>>==================[ DADOS ]==================<<";
    std::cout << "\n\n\tCasa encontrada! Seguem seus dados:\n\t"
              << "\n\t\t[ Casa numero " << (ID / 4) + 1 << " ]\n"
              << "\n\t\tRua: " << casas[ID].second
              << "\n\t\tOcupantes: " << casas[ID + 1].second
              << "\n\t\tEstudantes: " << casas[ID + 2].second
              << "\n\t\tRenda Media: " << casas[ID + 3].second;
    std::cout << "\n\n\t>>==================[  FIM  ]==================<<";
  }

  menu(casas, lim);
  return 0;
}

int menu(std::pair<int, std::string> p[], int lim) {

  std::cout << "\n\n\t[MENU]\n\n\t";

  std::cout << "(1)\tListar todos as casas visitadas e seus dados.\n\t"
            << "(2)\tBuscar os dados de uma casa.\n\n\t"
            << "(3)\tSair\n\n\t>> ";

  int input;
  std::cin >> input;

  switch (input) {
  case 1:
    listAll(p, lim);
    break;
  case 2:
    searchMenu(p, lim);
    break;
  case 3:
    break;
  default:
    std::cout << "\n\t ERRO: Input indevido. Tente novamente.";
    menu(p, lim);
    break;
  }
  return 0;
}

int main() {

  std::cout << "\n\n\tBem-vindo.\n\tProcurando por: \"./Leitura dos "
               "dados/Dados da pesquisa.txt\"...\n";

  std::ifstream arquivo("./Leitura dos dados/Dados da pesquisa.txt");
  std::pair<int, std::string> inputs[100];
  std::string local;

  // Leitura dos conteudos do arquivo.
  int n = 0;
  if (arquivo.is_open()) {
    for (; std::getline(arquivo, inputs[n].second); n++) {
      inputs[n].first = n;
    }
    std::cout << "\n\tLeitura concluida com exito.";
  }

  else {
    std::cout << "\n\tErro na leitura do arquivo!\n\n";
    return 0;
  }

  menu(inputs, n);
  return 0;
}
