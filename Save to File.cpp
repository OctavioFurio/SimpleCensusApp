#include "../Censo.hpp"

void salveTudoAqui(std::string nome, casa *forms, int lim) {

  std::ofstream arquivo(nome);

  casa *lista = new casa[lim + 1];

  int i, j;

  for (i = 0; i < lim; i++)
    lista[i + 1] = forms[i];

  casa sentinela;

  for (i = 2; i <= lim; i++) {
    sentinela = lista[i];
    lista[0] = sentinela;
    j = i;
    while ((sentinela.endereco[0] < lista[j - 1].endereco[0]) ||
           ((sentinela.endereco[0] == lista[j - 1].endereco[0]) &&
            (sentinela.endereco[1] < lista[j - 1].endereco[1]))) {
      lista[j] = lista[j - 1];
      j--;
    }
    lista[j] = sentinela;
  }

  for (int x = 1; x <= lim; x++) {
    arquivo << lista[x].endereco << "\n";
    arquivo << lista[x].ocupantes << "\n";
    arquivo << lista[x].estudantes << "\n";
    arquivo << lista[x].rendaMedia << "\n";
  }

  arquivo.close();
}
