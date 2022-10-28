#include "../Censo.hpp"
#include <string>

int main() {

  std::string nome = "Dados da pesquisa.txt";

  int limit;
  int ID = 0;

  std::cout << "\n\tQuantas residencias foram visitadas? \n\n\t>> ";
  std::cin >> limit;

  std::cout << "\n\t>>======================[ INPUT ]======================<<";

  casa formularios[limit];

  do {

    std::cout << "\n\n\tQual o endereço (apenas rua) da " << ID + 1
              << " casa visitada? \t|  ";
    std::cin.ignore();
    std::cin.getline(formularios[ID].endereco, 25);

    std::cout << "\n\tQual a quantia de ocupantes da " << ID + 1
              << " casa? \t\t\t|  ";
    std::cin >> formularios[ID].ocupantes;

    std::cout << "\n\tDesses ocupantes, quantos tem idade escolar? \t\t|  ";
    std::cin >> formularios[ID].estudantes;

    std::cout << "\n\tQual a renda media da " << ID + 1
              << " casa visitada? \t\t\t|  ";
    std::cin >> formularios[ID].rendaMedia;

    std::cout << "\n\tCasa no." << ID + 1 << " registrada com sucesso.\n";

    ID++;

  } while (ID < limit);

  std::cout << "\n\t>>======================[  FIM  ]======================<<"
            << "\n\n\tOrdenando & Salvando em arquivo...";

  salveTudoAqui(nome, formularios, limit);

  std::cout << "\n\n\tLog salvo com sucesso em: ./" << nome << "\n\n";
}
