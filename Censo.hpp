#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <utility>

// Tipo de dado
struct casa {
  char endereco[25];
  int ocupantes = 0;
  int estudantes = 0;
  int caracteres[25];
  float rendaMedia = 0.0;
};

// Funções importantes
void salveTudoAqui(std::string nome, casa *forms, int lim);
int menu(std::pair<int, std::string> p[], int lim);
