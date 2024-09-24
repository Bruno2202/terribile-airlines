#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>


using namespace std;

void lerPais(struct Pais x[], int &numPais);
void lerCidade(struct Cidade x[], int &numCidade);
bool buscarCidade (
    struct Cidade x[], 
    int &cont, 
    int cod, 
    struct Pais dbPais[], 
    int &numPais
);
bool buscarPais (struct Pais x[], int &cont, int cod);
bool buscarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont, 
    int cod
);
void incluirGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont, 
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade
);


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

struct Cliente {
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

struct Index {
    int cod, idx;
};


int main() {
    int opcao = 0;

    int numPais = 2;
    Pais dbPais[40] = {
        {1, "Brasil"},
        {2, "EUA"}
    };

    int numCidade = 2;
    Cidade dbCidade[40] = {
        {1, 1, "Rio de Janeiro", "RJ"},
        {2, 2, "Orlando", "Florida"}
    };

    int numGuia = 2;
    Guia dbGuia[40] = {
        {1, 1, "Bruno", "Rua Jose de Alencar, 590", "+55 (18)99805-12345"},
        {2, 2, "Brian", "Coe Ave, 910", "+1 202-633-1000"},
    };

    int numCliente = 2;
    Cliente dbCliente[40] = {
        {1, 1, "Breno", "Rua Dom Pedro I, 458"},
        {2, 2, "Julian", "Ave John Peterson, 282"}
    };

    int numPacote = 2;
    Pacote dbPacote[40] = {
        {1, 1, 1000.00, "Tour pelo Brasil"},
        {2, 2, 1000.00, "US Tour"}
    };

    int numVenda = 2;
    Venda dbVenda[40] = {
        {1, 2, 1, 4, 4000.00},
        {2, 1, 2, 4, 4000.00}
    };

    Index dbGuiaIndex[40] = {
        {1, 0},
        {2, 1}
    };

    Index dbClienteIndex[40] = {
        {1, 0},
        {2, 1}
    };

    Index dbPacoteIndex[40] = {
        {1, 0},
        {2, 1}
    };

    Index dbVendaIndex[40] = {
        {1, 0},
        {2, 1}
    };


    do {
        system("cls");

        cout << "============================================================" << endl
            << "=============        " << "\033[46m" << "TERRIBILE AIRLINES" << "\033[0m" << "        =============" << endl
            << "============================================================" << endl << endl;

        cout << "MENU: " << endl << endl;
        cout << "(1) - Cadastrar Paises" << endl << endl;
        cout << "(2) - Cadastrar Cidades" << endl << endl;
        cout << "(3) - Incluir Guia" << endl << endl;

        cout << "(0) - Sair" << endl << endl;

        cout << "Selecione uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                lerPais(dbPais, numPais);
                break;

            case 2:
                lerCidade(dbCidade, numPais);
                break;

            case 3:
                incluirGuia(dbGuiaIndex, dbGuia, numGuia, dbPais, numPais, dbCidade, numCidade);
                break;

            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}

void lerPais(struct Pais x[], int &numPais) {
    int cod_pais;
    char conf = ' ';
    bool codValido;

    for (int i=numPais ; i<40 ; i++) {
        system("cls");

        codValido = false;

        cout << endl << "================= \033[46mCADASTRO DE PAISES\033[0m =================" << endl;

        while (!codValido) {
            cout << endl << "Informe o CODIGO do PAIS: ";
            cin >> cod_pais;
            if (numPais != 0) {
                for (int j = 0 ; j < numPais ; j++) {
                    if (cod_pais == x[j].cod_pais) {
                        j = numPais;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        x[i].cod_pais = cod_pais; 
                        codValido = true;
                    }
                }
            }
        }
        
        cout << endl << "Informe o NOME do pais: ";
        cin.ignore();
        getline(cin, x[i].nome);

        numPais++;

        cout << endl << "Deseja cadastrar mais um pais? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            return;
        }
    }
}

void lerCidade(struct Cidade x[], int &numCidade) {
    int cod_cidade;
    char conf = ' ';
    bool codValido;

    for (int i=numCidade ; i<40 ; i++) {
        system("cls");

        codValido = false;

        cout << endl << "================= \033[46mCADASTRO DE CIDADES\033[0m =================" << endl;

        while (!codValido) {
            cout << endl << "Informe o CODIGO da cidade: ";
            cin >> cod_cidade;
            if (numCidade != 0) {
                for (int j = 0 ; j < numCidade ; j++) {
                    if (cod_cidade == x[j].cod_cidade) {
                        j = numCidade;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        x[i].cod_cidade = cod_cidade; 
                        codValido = true;
                    }
                }
            }
        }
        
        cout << endl << "Informe o NOME da cidade: ";
        cin.ignore();
        getline(cin, x[i].nome);

        cout << endl << "Informe o UF da cidade: ";
        cin.ignore();
        getline(cin, x[i].UF);

        cout << endl << "Informe o CODIGO do PAIS: ";
        cin >> x[i].cod_pais;

        numCidade++;

        cout << endl << "Deseja cadastrar mais uma cidade? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            return;
        }
    }
}

void incluirGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont, 
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade
) {
    system("cls");
    
    cont++;
    int cod_cidade;
    bool cod_cidade_valid = false;

    for (int cod = 1; cod != 0;){
        cout << "Informe o Codigo do GUIA a ser incluido (0 para Encerrar): ";
        cin >> cod;
        if (cod != 0) {
            if (buscarGuia(idx, x, cont, cod)) {
                x[cont].cod_guia = cod;
                cout << "Nome: ";
                cin >> x[cont].nome;

                cout << "Endereco: ";
                cin >> x[cont].endereco;

                cout << "Telefone: ";
                cin >> x[cont].telefone;
                
                while (!cod_cidade_valid) {
                    cout << "Cidade: ";
                    cin >> cod_cidade;
                    if (buscarCidade(dbCidade, numCidade, cod_cidade, dbPais, numPais)) {
                        x[cont].cod_cidade = cod_cidade;
                        cod_cidade_valid = false;
                    }
                }

                int i;
                
                for (i = cont - 1; idx[i].cod > cod; i--) {
                    idx[i+1].cod = idx[i].cod;
                    idx[i+1].idx = idx[i].idx;
                }
                idx[i+1].cod = cod;
                idx[i+1].idx = cont;
            }
        }
    }

    return;
}

bool buscarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont, 
    int cod
) {
    int i = 0, f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2) {
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == idx[m].cod) {
        cout << endl << "\033[31m" << "GUIA JA CADASTRADO" << "\033[0m";
        i = idx[m].idx;
        cout << endl << "Codigo do Guia: " << x[i].cod_guia
            << endl << "Nome: " << x[i].nome
            << endl << "Endereco: " << x[i].endereco
            << endl << "Telefone: " << x[i].telefone
            << endl << "Codigo da Cidade: " << x[i].cod_cidade
            << endl << endl;

        return false;
    } else {
        return true;
    }

    getch();
}

bool buscarCidade (
    struct Cidade x[], 
    int &cont, 
    int cod, 
    struct Pais dbPais[], 
    int &numPais
) {
    int i = 0, f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != x[m].cod_cidade; m = (i + f) / 2) {
        if (cod > x[m].cod_cidade)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == x[m].cod_cidade) {
        i = x[m].cod_cidade;
        cout << "\033[32m" << "Cidade: " << x[i].nome << " - " << x[i].UF << "\033[0m" << endl << endl;
        buscarPais(dbPais, numPais, x[i].cod_pais);
        return true;
    } else {
        cout << "\033[31m" << "CIDADE NAO ENCONTRADA!" << "\033[0m" << endl;
        return false;
    }

    getch();
}

bool buscarPais (struct Pais x[], int &cont, int cod) {
    int i = 0, f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != x[m].cod_pais; m = (i + f) / 2) {
        if (cod > x[m].cod_pais)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == x[m].cod_pais) {
        i = x[m].cod_pais;
        cout << "Pais: " << x[i].nome;
        return true;
    } else {
        cout << "\033[31m" << "PAIS NAO ENCONTRADO!" << "\033[0m" << endl;
        return false;
    }

    getch();
}