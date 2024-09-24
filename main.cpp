#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

struct Pais {
    int cod_pais;
    string nome;
};

struct Cidade {
    int cod_cidade, cod_pais;
    string nome, UF;
};

struct Guia {
    int cod_guia, cod_cidade;
    string nome, endereco, telefone;
};

struct Cliete {
    int cod_cliente, cod_cidade;
    string nome, endereco;
};

struct Pacote {
    int cod_pacote, cod_guia;
    double vlr_pessoa;
    string descricao; 
};

struct Venda {
    int cod_venda, cod_cli, cod_pacote, qtde_pessoas;
    double vlr_total;
};

struct GuiaIndex {
    int cod_guia, idx;
};

struct ClienteIndex {
    int cod_cliente, idx;
};

struct PacoteIndex {
    int cod_pacote, idx;
};

struct VendaIndex {
    int cod_venda, idx;
};

int main() {
    int opcao = 0;

    do {
        system("cls");

        cout << "============================================================" << endl
            << "=============        " << "\033[46m" << "TERRIBILE AIRLINES" << "\033[0m" << "        =============" << endl
            << "============================================================" << endl << endl;

        cout << "MENU: " << endl << endl;
        cout << "(1) - " << endl << endl;

        cout << "(0) - Sair" << endl << endl;

        cout << "Selecione uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                break;

            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}