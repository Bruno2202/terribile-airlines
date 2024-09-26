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
void incluirCliente (
    struct Index idx[], 
    struct Cliente x[], 
    int &cont, 
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade
);
bool buscarCliente (
    struct Index idx[], 
    struct Cliente x[], 
    int &cont, 
    int cod
);
void excluirCliente(    
    struct Index idx[], 
    struct Cliente x[], 
    int &cont,
    struct Index dbVendaIndex[],
    struct Venda dbVenda[],
    int &numVenda
);
void reorganizarCliente (
    struct Index idx[], 
    struct Cliente x[], 
    int &cont
);
bool buscarVenda(
    struct Index idx[], 
    struct Venda x[], 
    int &cont, 
    int cod_cli
);
void excluirGuia(    
    struct Index idx[], 
    struct Guia x[], 
    int &cont,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote
);
bool buscarPacote(
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    int cod_guia
);
void reorganizarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont
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
    int status;
};

struct Cliente {
    int cod_cliente, cod_cidade;
    string nome, endereco;
    int status;
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
        {1, 1, "Bruno", "Rua Jose de Alencar, 590", "+55 (18)99805-12345", 0},
        {2, 2, "Brian", "Coe Ave, 910", "+1 202-633-1000", 0}
    };

    int numCliente = 2;
    Cliente dbCliente[40] = {
        {1, 1, "Breno", "Rua Dom Pedro I, 458", 0},
        {2, 2, "Julian", "Ave John Peterson, 282", 0}
    };

    int numPacote = 2;
    Pacote dbPacote[40] = {
        {1, 1, 1000.00, "Tour pelo Brasil"},
    };

    int numVenda = 1;
    Venda dbVenda[40] = {
        {1, 2, 1, 4, 4000.00},
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
        reorganizarCliente(dbClienteIndex, dbCliente, numCliente);
        reorganizarGuia(dbGuiaIndex, dbGuia, numGuia);

        system("cls");

        cout << "============================================================" << endl
            << "=============        " << "\033[46m" << "TERRIBILE AIRLINES" << "\033[0m" << "        =============" << endl
            << "============================================================" << endl << endl;

        cout << "MENU: " << endl << endl;
        cout << "(1) - Cadastrar Paises" << endl << endl;
        cout << "(2) - Cadastrar Cidades" << endl << endl;
        cout << "(3) - Incluir Guia" << endl << endl;
        cout << "(4) - Incluir Cliente" << endl << endl;
        cout << "(5) - Excluir Cliente" << endl << endl;
        cout << "(6) - Excluir Guia" << endl << endl;

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

            case 4:
                incluirCliente(dbClienteIndex, dbCliente, numCliente, dbPais, numPais, dbCidade, numCidade);
                break;

            case 5:
                excluirCliente(dbClienteIndex, dbCliente, numCliente, dbVendaIndex, dbVenda, numVenda);
                break;

            case 6:
                excluirGuia(dbGuiaIndex, dbGuia, numGuia, dbPacoteIndex, dbPacote, numPacote);
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
                    cout << "Codigo da Cidade: ";
                    cin >> cod_cidade;
                    if (buscarCidade(dbCidade, numCidade, cod_cidade, dbPais, numPais)) {
                        buscarPais(dbPais, numPais, cod_cidade);

                        getch();

                        cout << endl << endl;
                        
                        x[cont].cod_cidade = cod_cidade;
                        cod_cidade_valid = true;
                    }
                }
                cod_cidade_valid = false;

                int i;
                
                for (i = cont - 1; idx[i].cod > cod; i--) {
                    idx[i+1].cod = idx[i].cod;
                    idx[i+1].idx = idx[i].idx;
                }
                idx[i+1].cod = cod;
                idx[i+1].idx = cont;
                
                system("cls");
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

void incluirCliente (
    struct Index idx[], 
    struct Cliente x[], 
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
        cout << "Informe o Codigo do CLIENTE a ser incluido (0 para Encerrar): ";
        cin >> cod;
        if (cod != 0) {
            if (buscarCliente(idx, x, cont, cod)) {
                x[cont].cod_cliente = cod;
                cout << "Nome: ";
                cin >> x[cont].nome;

                cout << "Endereco: ";
                cin >> x[cont].endereco;

                while (!cod_cidade_valid) {
                    cout << "Codigo da Cidade: ";
                    cin >> cod_cidade;
                    if (buscarCidade(dbCidade, numCidade, cod_cidade, dbPais, numPais)) {
                        buscarPais(dbPais, numPais, cod_cidade);

                        getch();

                        cout << endl << endl;
                        
                        x[cont].cod_cidade = cod_cidade;
                        cod_cidade_valid = true;
                    }
                }
                cod_cidade_valid = false;

                int i;
                
                for (i = cont - 1; idx[i].cod > cod; i--) {
                    idx[i+1].cod = idx[i].cod;
                    idx[i+1].idx = idx[i].idx;
                }
                idx[i+1].cod = cod;
                idx[i+1].idx = cont;
                
                system("cls");
            }
        }
    }

    return;
}

void excluirCliente(    
    struct Index idx[], 
    struct Cliente x[], 
    int &cont,
    struct Index dbVendaIndex[],
    struct Venda dbVenda[],
    int &numVenda
) {
    system("cls");

    int cod_cliente, i=0, f=cont - 1, m;
    char conf = ' ';

    cout << endl << "Informe o CODIGO do CLIENTE a ser EXCLUIDO (0 para Encerrar): ";
    cin >> cod_cliente;

    if (cod_cliente == 0) {
        return;
    }

    while (f >= i) {
        m = (i + f) / 2;

        if (cod_cliente == idx[m].cod) {
            i = idx[m].idx;
            break;
        } else if (cod_cliente > idx[m].cod) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    if (cod_cliente != idx[m].cod) {
        cout << "\033[31m" << "CLIENTE NÃO CADASTRADO" << "\033[0m" << endl;
        getch();
        return;
    }

    if (!buscarVenda(dbVendaIndex, dbVenda, numVenda, cod_cliente)) {
        if (x[i].status == 0) {
            buscarCliente(idx, x, cont, cod_cliente);
            cout << "Deseja EXCLUIR esse CLIENTE? (S/N): ";
            cin >> conf;
            conf = toupper(conf);
        
            if (conf == 'S') {
                x[i].status = 1;
                cout << "Cliente excluido com sucesso!" << endl;
                getch();
                return;
            }
        } else {
            cout << "\033[31m" << "CLIENTE JA EXCLUIDO" << "\033[0m" << endl;
            getch();
        }
    } else {
        buscarCliente(idx, x, cont, cod_cliente);
        cout << "\033[31m" << "CLIENTE NAO PODE SER EXCLUIDO, TEM VENDAS ASSOCIADAS" << "\033[0m" << endl;
        getch();
    }
}

void reorganizarCliente (
    struct Index idx[], 
    struct Cliente x[], 
    int &cont
) {
    struct Cliente novoDbX[40];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].idx;
        if (x[i].status == 0){
            j++;
            novoDbX[j] = x[i];
            idx[j].cod = novoDbX[j].cod_cliente;
            idx[j].idx = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].idx;
    	x[k] = novoDbX [i];
	}
}

bool buscarVenda(struct Index idx[], struct Venda x[], int &cont, int cod_cli) {
    int i = 0;
    int f = cont - 1;
    
    while (i <= f) {
        int m = (i + f) / 2;
        
        if (x[m].cod_cli == cod_cli) {
            return true;
        }
        if (x[m].cod_cli < cod_cli) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    return false;
}

bool buscarCliente (
    struct Index idx[], 
    struct Cliente x[], 
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
        i = idx[m].idx;
        cout << endl << "Codigo do Cliente: " << x[i].cod_cliente
            << endl << "Nome: " << x[i].nome
            << endl << "Endereco: " << x[i].endereco
            << endl << "Codigo da Cidade: " << x[i].cod_cidade
            << endl << endl;

        return false;
    } else {
        return true;
    }

    getch();
}

void excluirGuia(    
    struct Index idx[], 
    struct Guia x[], 
    int &cont,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote
) {
    system("cls");

    int cod_guia, i=0, f=cont - 1, m;
    char conf = ' ';

    cout << endl << "Informe o CODIGO do GUIA a ser EXCLUIDO (0 para Encerrar): ";
    cin >> cod_guia;

    if (cod_guia == 0) {
        return;
    }

    while (f >= i) {
        m = (i + f) / 2;

        if (cod_guia == idx[m].cod) {
            i = idx[m].idx;
            break;
        } else if (cod_guia > idx[m].cod) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    if (cod_guia != idx[m].cod) {
        cout << "\033[31m" << "GUIA NAO CADASTRADO" << "\033[0m" << endl;
        getch();
        return;
    }

    if (!buscarPacote(dbPacoteIndex, dbPacote, numPacote, cod_guia)) {
        if (x[i].status == 0) {
            buscarGuia(idx, x, cont, cod_guia);
            cout << "Deseja EXCLUIR esse GUIA? (S/N): ";
            cin >> conf;
            conf = toupper(conf);
            
            if (conf == 'S') {
                x[i].status = 1;
                cout << "Guia excluido com sucesso!" << endl;
                getch();
                return;
            }
        } else {
            cout << "\033[31m" << "CLIENTE JA EXCLUIDO" << "\033[0m" << endl;
            getch();
        }
    } else {
        buscarGuia(idx, x, cont, cod_guia);
        cout << "\033[31m" << "GUIA NAO PODE SER EXCLUIDO, TEM PACOTES ASSOCIADAS" << "\033[0m" << endl;
        getch();
    }
}

void reorganizarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont
) {
    struct Guia novoDbX[40];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].idx;
        if (x[i].status == 0){
            j++;
            novoDbX[j] = x[i];
            idx[j].cod = novoDbX[j].cod_guia;
            idx[j].idx = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].idx;
    	x[k] = novoDbX [i];
	}
}

bool buscarPacote(struct Index idx[], struct Pacote x[], int &cont, int cod_guia) {
    int i = 0;
    int f = cont - 1;
    
    while (i <= f) {
        int m = (i + f) / 2;
        
        if (x[m].cod_guia == cod_guia) {
            return true;
        }
        if (x[m].cod_guia < cod_guia) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    
    return false;
}

bool buscarCidade(
    struct Cidade x[], 
    int &cont, 
    int cod, 
    struct Pais dbPais[], 
    int &numPais
) {
    int i = 0, f = cont - 1;
    int m;

    while (i <= f) {
        m = (i + f) / 2;

        if (cod == x[m].cod_cidade) {
            cout << "\033[32m" << "Cidade: " << x[m].nome << " - " << x[m].UF << "\033[0m" << endl;
            return true;
        }

        if (cod > x[m].cod_cidade) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    cout << "\033[31m" << "CIDADE NAO ENCONTRADA!" << "\033[0m" << endl;
    return false;
}

bool buscarPais (struct Pais x[], int &cont, int cod) {
    int i = 0, f = cont - 1;
    int m;

    while (i <= f) {
        m = (i + f) / 2;

        if (cod == x[m].cod_pais) {
            cout << "\033[32m" << "Pais: " << x[m].nome << "\033[0m" << endl;
            return true;
        }

        if (cod > x[m].cod_pais) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    cout << "\033[31m" << "PAIS NAO ENCONTRADO!" << "\033[0m" << endl;
    return false;
}