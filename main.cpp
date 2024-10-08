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
    int cod
);
bool buscarPais (struct Pais x[], int &cont, int cod);
bool buscarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont, 
    int cod,
    int tipo,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais
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
    int cod,
    int tipo
);
void excluirCliente(    
    struct Index idx[], 
    struct Cliente x[], 
    int &cont,
    struct Venda dbVenda[],
    int &numVenda
);
void reorganizarCliente (
    struct Index idx[], 
    struct Cliente x[], 
    int &cont
);
bool buscarVenda(
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
    int &numPacote,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int &numPais, 
    struct Index dbGuiaIndex[],
    struct Guia dbGuia[],
    int &numGuia
);
bool buscarPacote (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    int cod,
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[], 
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais,
    int tipo
);
void reorganizarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont
);
void incluirPacote (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    struct Index dbGuiaIndex[],
    struct Guia dbGuia[],
    int &numGuia,
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade
);
bool buscarPacoteGuia (
    struct Pacote x[], 
    int &cont, 
    int cod_guia
);
void incluirVenda (
    struct Index idx[], 
    struct Venda x[], 
    int &cont,
    struct Index dbClienteIndex[], 
    struct Cliente dbCliente[],
    int &numCliente, 
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote,
    struct Index dbGuiaIndex[],
    struct Guia dbGuia[],
    int &numGuia
);
bool buscarCodVenda(
    struct Index idx[], 
    struct Venda x[], 
    int &cont, 
    int cod
);
void reorganizarVenda (
    struct Index idx[], 
    struct Venda x[],
    int &cont
);
void reorganizarPacote (
    struct Index idx[], 
    struct Pacote x[],
    int &cont
);
void consultarPacote (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[], 
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais
);
void consultarPacotesEsgostados (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[], 
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais
);
void consultarVendas (
    struct Index idx[], 
    struct Venda x[], 
    int &cont, 
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[],
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais,
    struct Index dbClienteIndex[],
    struct Cliente dbCliente[],
    int &numCliente,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote
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
    int qtde_max_participantes, qtde_total_participantes;
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

    int numPacote = 1;
    Pacote dbPacote[40] = {
        {1, 1, 1000.00, "Tour pelo Brasil", 10, 4}
    };

    int numVenda = 1;
    Venda dbVenda[40] = {
        {1, 2, 1, 4, 4000.00}
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
    };

    Index dbVendaIndex[40] = {
        {1, 0},
        {2, 1}
    };


    do {
        reorganizarCliente(dbClienteIndex, dbCliente, numCliente);
        reorganizarGuia(dbGuiaIndex, dbGuia, numGuia);
        reorganizarVenda(dbVendaIndex, dbVenda, numVenda);
        reorganizarPacote(dbPacoteIndex, dbPacote, numPacote);

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
        cout << "(7) - Incluir Pacote" << endl << endl;
        cout << "(8) - Incluir Venda" << endl << endl;
        cout << "(9) - Consultar Pacote" << endl << endl;
        cout << "(10) - Consultar Pacotes Esgostados" << endl << endl;
        cout << "(11) - Consultar Vendas" << endl << endl;

        cout << "\033[31m" << "(0) - Sair" << "\033[0m" << endl << endl;

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
                excluirCliente(dbClienteIndex, dbCliente, numCliente, dbVenda, numVenda);
                break;

            case 6:
                excluirGuia(dbGuiaIndex, dbGuia, numGuia, dbPacoteIndex, dbPacote, numPacote, dbCidade, numCidade, dbPais, numPais, dbGuiaIndex, dbGuia, numGuia);
                break;

            case 7:
                incluirPacote(dbPacoteIndex, dbPacote, numPacote, dbGuiaIndex, dbGuia, numGuia, dbPais, numPais, dbCidade, numCidade);
                break;

            case 8:
                incluirVenda(dbVendaIndex, dbVenda, numVenda, dbClienteIndex, dbCliente, numCliente, dbPais, numPais, dbCidade, numCidade, dbPacoteIndex, dbPacote, numPacote, dbGuiaIndex, dbGuia, numGuia);
                break;

            case 9:
                consultarPacote(dbPacoteIndex, dbPacote, numPacote, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais);
                break;

            case 10:
                consultarPacotesEsgostados(dbPacoteIndex, dbPacote, numPacote, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais);
                break;

            case 11:
                consultarVendas(dbVendaIndex, dbVenda, numVenda, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais, dbClienteIndex, dbCliente, numCliente, dbPacoteIndex, dbPacote, numPacote);
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
            if (!buscarGuia(idx, x, cont, cod, 1, dbCidade, numCidade, dbPais, numPais)) {
                x[cont].cod_guia = cod;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, x[cont].nome);

                cout << "Endereco: ";
                cin.ignore();
                getline(cin, x[cont].endereco);


                cout << "Telefone: ";
                cin.ignore();
                getline(cin, x[cont].telefone);
                
                while (!cod_cidade_valid) {
                    cout << "Codigo da Cidade: ";
                    cin >> cod_cidade;
                    if (buscarCidade(dbCidade, numCidade, cod_cidade)) {
                        buscarPais(dbPais, numPais, cod_cidade);

                        getch();

                        cout << endl << endl;
                        
                        x[cont].cod_cidade = cod_cidade;
                        cod_cidade_valid = true;
                    }
                }
                cod_cidade_valid = false;

                x[cont].status = 0;

                int i;
                
                for (i = cont - 1; idx[i].cod > cod; i--) {
                    idx[i+1].cod = idx[i].cod;
                    idx[i+1].idx = idx[i].idx;
                }
                idx[i+1].cod = cod;
                idx[i+1].idx = cont;
                
                system("cls");
            } else {
                cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl << endl;
            }
        }
    }

    return;
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
        cout << "Informe o CODIGO do CLIENTE a ser INCLUIDO (0 para Encerrar): ";
        cin >> cod;
        
        if (cod != 0) {
            if (!buscarCliente(idx, x, cont, cod, 1)) {
                x[cont].cod_cliente = cod;

                cout << "Nome: ";
                cin.ignore();
                getline(cin, x[cont].nome);

                cout << "Endereco: ";
                cin.ignore();
                getline(cin, x[cont].endereco);

                while (!cod_cidade_valid) {
                    cout << "Codigo da Cidade: ";
                    cin >> cod_cidade;
                    
                    if (buscarCidade(dbCidade, numCidade, cod_cidade)) {
                        buscarPais(dbPais, numPais, cod_cidade);

                        getch();

                        cout << endl << endl;
                        
                        x[cont].cod_cidade = cod_cidade;
                        cod_cidade_valid = true;
                    }
                }
                cod_cidade_valid = false;

                x[cont].status = 0;

                int i;
                
                for (i = cont - 1; idx[i].cod > cod; i--) {
                    idx[i+1].cod = idx[i].cod;
                    idx[i+1].idx = idx[i].idx;
                }
                idx[i+1].cod = cod;
                idx[i+1].idx = cont;
                
                system("cls");
            } else {
                cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl << endl;
            }
        }
    }

    return;
}

void incluirPacote (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    struct Index dbGuiaIndex[],
    struct Guia dbGuia[],
    int &numGuia,
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade
) {
    system("cls");
    
    int cod_guia, qtde_max;
    bool cod_guia_valido = false, qtde_max_valida=false;

    for (int cod = 1; cod != 0;) {
        cout << "Informe o CODIGO do PACOTE a ser INCLUIDO (0 para Encerrar): ";
        cin >> cod;

        if (cod != 0) {
            if (!buscarPacote(idx, x, cont, cod, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais, 1)) {
                x[cont].cod_pacote = cod;

                cout << "Descricao: ";
                cin.ignore();
                getline(cin, x[cont].descricao);

                cout << "Valor por pessoa: ";
                cin >> x[cont].vlr_pessoa;

                while (!cod_guia_valido) {
                    cout << "Codigo do Guia: ";
                    cin >> cod_guia;
                    
                    if (buscarGuia(dbGuiaIndex, dbGuia, numGuia, cod_guia, 2, dbCidade, numCidade, dbPais, numPais)) {
                        x[cont].cod_guia = cod_guia;
                        cod_guia_valido = true;
                    } else {
                        cout << "\033[31m" << endl << "GUIA NAO ENCONTRADO" << "\033[0m" << endl << endl;
                    }
                }
                cod_guia_valido = false;

                while (!qtde_max_valida) {
                    cout << "QUANTIDADE MAXIMA de PARTICIPANTES: ";
                    cin >> qtde_max;

                    if (qtde_max > 0) {
                        x[cont].qtde_max_participantes = qtde_max;
                        qtde_max_valida = true;
                    } else {
                        cout << "\033[31m" << endl << "QUANTIDADE MAXIMA INVALIDA" << "\033[0m" << endl << endl;
                    }
                }
                qtde_max_valida = false;

                getch();

                int i;
                for (i = cont - 1; idx[i].cod > cod; i--) {
                    idx[i+1].cod = idx[i].cod;
                    idx[i+1].idx = idx[i].idx;
                }
                idx[i+1].cod = cod;
                idx[i+1].idx = cont;

                cont++;

                system("cls");
            } else {
                cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl << endl;
            }
        }
    }

    return;
}

void incluirVenda (
    struct Index idx[], 
    struct Venda x[], 
    int &cont,
    struct Index dbClienteIndex[], 
    struct Cliente dbCliente[],
    int &numCliente, 
    struct Pais dbPais[], 
    int &numPais,
    struct Cidade dbCidade[], 
    int &numCidade,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote,
    struct Index dbGuiaIndex[],
    struct Guia dbGuia[],
    int &numGuia
) {
    system("cls");
    
    int cod_cliente, cod_pacote, qtde_pessoas;
    double vlr_venda;
    bool cod_cliente_valido = false, cod_pacote_valido = false, qtde_pessoas_valido = false;
    int cod = 1;

    while (cod != 0) {
        cod_cliente_valido = false, cod_pacote_valido = false, qtde_pessoas_valido = false;

        cout << "Informe o CODIGO da VENDA a ser INCLUIDA (0 para Encerrar): ";
        cin >> cod;

        if (cod == 0) {
            break;
        }

        if (!buscarCodVenda(idx, x, cont, cod)) {
            x[cont].cod_venda = cod;

            while (!cod_cliente_valido) {
                cout << "CODIGO do CLIENTE: ";
                cin >> cod_cliente;

                if (buscarCliente(dbClienteIndex, dbCliente, numCliente, cod_cliente, 1)) {
                    cod_cliente_valido = true;
                    x[cont].cod_cli = cod_cliente;

                    while (!cod_pacote_valido) {
                        cout << "CODIGO do PACOTE: ";
                        cin >> cod_pacote;
                        cout << endl;

                        if (buscarPacote(dbPacoteIndex, dbPacote, numPacote, cod_pacote, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais, 1)) {
                            cod_pacote_valido = true;
                            x[cont].cod_pacote = cod_pacote;

                            while (!qtde_pessoas_valido) {
                                cout << "QUANTIDADE de PESSOAS: ";
                                cin >> qtde_pessoas;

                                int i = 0, f = numPacote - 1, m;

                                while (i <= f) {
                                    m = (i + f) / 2;

                                    if (cod_pacote == dbPacoteIndex[m].cod) {
                                        i = dbPacoteIndex[m].idx;

                                        if (qtde_pessoas > 0 && qtde_pessoas + dbPacote[i].qtde_total_participantes <= dbPacote[i].qtde_max_participantes) {
                                            qtde_pessoas_valido = true;
                                            dbPacote[i].qtde_total_participantes += qtde_pessoas;
                                            x[cont].qtde_pessoas = qtde_pessoas;

                                            vlr_venda = qtde_pessoas * dbPacote[i].vlr_pessoa;
                                            cout << "VALOR da VENDA: " << vlr_venda << endl;
                                            x[cont].vlr_total = vlr_venda;

                                            getch();

                                            break;
                                        } else {
                                            cout << "\033[31m" << endl << "A QUANTIDADE DE PESSOAS ULTRAPASSA A CAPACIDADE DO PACOTE!" << "\033[0m" << endl << endl;
                                            break;
                                        }
                                    } else if (cod > dbPacoteIndex[m].cod) {
                                        i = m + 1;
                                    } else {
                                        f = m - 1;
                                    }
                                }
                            }

                            if (qtde_pessoas_valido) {
                                int j;
                                for (j = cont - 1; idx[j].cod > cod; j--) {
                                    idx[j + 1].cod = idx[j].cod;
                                    idx[j + 1].idx = idx[j].idx;
                                }
                                idx[j + 1].cod = cod;
                                idx[j + 1].idx = cont;

                                cont++;

                                system("cls");
                            }

                        } else {
                            cout << "\033[31m" << "PACOTE NAO ENCONTRADO!" << "\033[0m" << endl;
                        }
                    }
                } else {
                    cout << "\033[31m" << "CLIENTE NAO ENCONTRADO!" << "\033[0m" << endl;
                }
            }
        } else {
            cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl << endl;
        }
    }

    return;
}


void excluirCliente(    
    struct Index idx[], 
    struct Cliente x[], 
    int &cont,
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
        cout << "\033[31m" << "CLIENTE NAO CADASTRADO" << "\033[0m" << endl;
        getch();
        return;
    }

    if (!buscarVenda(dbVenda, numVenda, cod_cliente)) {
        if (x[i].status == 0) {
            buscarCliente(idx, x, cont, cod_cliente, 1);
            cout << "Deseja EXCLUIR esse CLIENTE? (S/N): ";
            cin >> conf;
            conf = toupper(conf);
        
            if (conf == 'S') {
                x[i].status = 1;
                cout << endl << "\033[32m" << "Cliente excluido com sucesso!" << "\033[0m" << endl;
                getch();
                return;
            }
        } else {
            cout << "\033[31m" << "CLIENTE JA EXCLUIDO" << "\033[0m" << endl;
            getch();
        }
    } else {
        buscarCliente(idx, x, cont, cod_cliente, 1);
        cout << "\033[31m" << "CLIENTE NAO PODE SER EXCLUIDO, TEM VENDAS ASSOCIADAS" << "\033[0m" << endl;
        getch();
    }
}

void excluirGuia(    
    struct Index idx[], 
    struct Guia x[], 
    int &cont,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int &numPais,
    struct Index dbGuiaIndex[],
    struct Guia dbGuia[],
    int &numGuia
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

    if (!buscarPacoteGuia(dbPacote, numPacote, cod_guia)) {
        if (x[i].status == 0) {
            buscarGuia(idx, x, cont, cod_guia, 1, dbCidade, numCidade, dbPais, numPais);
            cout << "Deseja EXCLUIR esse GUIA? (S/N): ";
            cin >> conf;
            conf = toupper(conf);
            
            if (conf == 'S') {
                x[i].status = 1;
                cout << endl << "\033[32m" << "Guia excluido com sucesso!" << "\033[0m" << endl;
                getch();
                return;
            }
        } else {
            cout << "\033[31m" << "CLIENTE JA EXCLUIDO" << "\033[0m" << endl;
            getch();
        }
    } else {
        buscarGuia(idx, x, cont, cod_guia, 1, dbCidade, numCidade, dbPais, numPais);
        cout << "\033[31m" << "GUIA NAO PODE SER EXCLUIDO, TEM PACOTES ASSOCIADOS" << "\033[0m" << endl;
        getch();
    }
}


void consultarPacote (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[], 
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais
) {
    system("cls");
    int cod_pacote = 1;

    while (cod_pacote != 0) {
        cout << "Informe o CODIGO da PACOTE a ser CONSUTADO (0 para Encerrar): ";
        cin >> cod_pacote;
        cout << endl;

        if (cod_pacote == 0) {
            return;
        }

        if (!buscarPacote(idx, x, cont, cod_pacote, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais, 1)) {
            cout << "\033[31m" << "PACOTE NAO ENCONTRADO" << "\033[0m" << endl;
        }

        getch();

        system("cls");
    }
}

void consultarPacotesEsgostados (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[], 
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais
) {
    system("cls");

    int numPacotesEsgotados = 0, opcao = -1;

    for (int k=0; k < cont; k++) {
        int i = idx[k].idx;

        if (x[i].qtde_max_participantes == x[i].qtde_total_participantes) {
            numPacotesEsgotados++;

            cout << "\033[31m";

            cout << "Codigo do Pacote: " << x[i].cod_pacote
                << endl << "Descricao: " << x[i].descricao << endl;

            buscarGuia(dbGuiaIndex, dbGuia, numGuia, x[i].cod_guia, 3, dbCidade, numCidade, dbPais, numPais);

            cout << "Total arrecadado: R$ " << x[i].qtde_total_participantes * x[i].vlr_pessoa
                << endl << endl;

            cout << "\033[0m";
        }
    }

    if (numPacotesEsgotados == 0) {
        cout << "\033[31m" << "NAO HA PACOTES ESGOTADOS" << "\033[0m" << endl;
    }

    cout << endl << "============================================" <<
        endl << endl << "Digite 0 para SAIR: ";
    while (opcao != 0) {
        cin >> opcao;
    }

    return;
}

void consultarVendas (
    struct Index idx[], 
    struct Venda x[], 
    int &cont, 
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[],
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais,
    struct Index dbClienteIndex[],
    struct Cliente dbCliente[],
    int &numCliente,
    struct Index dbPacoteIndex[],
    struct Pacote dbPacote[],
    int &numPacote
) {
    system("cls");

    int opcao = -1;
    double vlr_total_vendas = 0;

    for (int k=0; k < cont; k++) {
        int i = idx[k].idx;

        vlr_total_vendas = vlr_total_vendas + x[i].vlr_total;
    }
    
    cout << "\033[32m" << "Valor Total das Vendas: R$ " << vlr_total_vendas << "\033[0m" << endl << endl;

    for (int k=0; k < cont; k++) {
        int i = idx[k].idx;

        cout << "Codigo da Venda: " << x[i].cod_venda;

        buscarCliente(dbClienteIndex, dbCliente, numCliente, x[i].cod_cli, 2);
        cout << endl;
        buscarPacote(dbPacoteIndex, dbPacote, numPacote, x[i].cod_pacote, dbGuiaIndex, dbGuia, numGuia, dbCidade, numCidade, dbPais, numPais, 2);
        cout << endl;

        cout << "Quantidade de Pessoas " << x[i].qtde_pessoas << endl
            << "Valor total: R$ " << x[i].vlr_total
            << endl << endl;
    }

    cout << endl << "============================================" <<
        endl << endl << "Digite 0 para SAIR: ";
    while (opcao != 0) {
        cin >> opcao;
    }

    return;
}


void reorganizarVenda (
    struct Index idx[], 
    struct Venda x[],
    int &cont
) {
    struct Venda novoDbX[40];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].idx;
        j++;
        novoDbX[j] = x[i];
        idx[j].cod = novoDbX[j].cod_venda;
        idx[j].idx = j;
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].idx;
    	x[k] = novoDbX [i];
	}
}

void reorganizarPacote (
    struct Index idx[], 
    struct Pacote x[],
    int &cont
) {
    struct Pacote novoDbX[40];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].idx;
        j++;
        novoDbX[j] = x[i];
        idx[j].cod = novoDbX[j].cod_pacote;
        idx[j].idx = j;
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].idx;
    	x[k] = novoDbX [i];
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


bool buscarPacoteGuia (
    struct Pacote x[], 
    int &cont, 
    int cod_guia
) {
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

bool buscarPacote (
    struct Index idx[], 
    struct Pacote x[], 
    int &cont, 
    int cod,
    struct Index dbGuiaIndex[], 
    struct Guia dbGuia[], 
    int &numGuia,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais,
    int tipo
) {
    int i = 0, f = cont - 1;
    int m;

    while (i <= f) {
        m = (i + f) / 2;

        if (cod == idx[m].cod) {
            i = idx[m].idx;

            switch (tipo) {
                case 1:
                    buscarGuia(dbGuiaIndex, dbGuia, numGuia, x[i].cod_guia, 2, dbCidade, numCidade, dbPais, numPais);
                    cout << "Valor por pessoa: R$" << x[i].vlr_pessoa
                        << endl << "Descricao: " << x[i].descricao
                        << endl << "Quantidade de Participantes: " << x[i].qtde_total_participantes
                        << endl << "Quantidade Max. de Participantes: " << x[i].qtde_max_participantes
                        << endl << "Total arrecadado: R$ " << x[i].qtde_total_participantes * x[i].vlr_pessoa
                        << endl << endl;
                    return true;

                case 2: 
                    cout << "Descricao do Pacote: " << x[i].descricao;
                    return true;

                default:
                    buscarGuia(dbGuiaIndex, dbGuia, numGuia, x[i].cod_guia, 2, dbCidade, numCidade, dbPais, numPais);
                    cout << "Valor por pessoa: R$" << x[i].vlr_pessoa
                        << endl << "Descricao: " << x[i].descricao
                        << endl << "Quantidade de Participantes: " << x[i].qtde_total_participantes
                        << endl << "Quantidade Max. de Participantes: " << x[i].qtde_max_participantes
                        << endl << "Total arrecadado: R$ " << x[i].qtde_total_participantes * x[i].vlr_pessoa
                        << endl << endl;
                    return true;
            }
        } 
        else if (cod > idx[m].cod) {
            i = m + 1;
        } 
        else {
            f = m - 1;
        }
    }

    return false;
}

bool buscarCidade(
    struct Cidade x[], 
    int &cont, 
    int cod
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

bool buscarCodVenda(
    struct Index idx[], 
    struct Venda x[], 
    int &cont, 
    int cod
) {
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2) {
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == idx[m].cod) {
        i = idx[m].idx;
        cout << endl << "Codigo da Venda: " << x[i].cod_venda
            << endl << "Codigo do Cliente " << x[i].cod_cli
            << endl << "Codigo do Pacote: " << x[i].cod_pacote 
            << endl << "Quantidade de Pessoas: " << x[i].qtde_pessoas
            << endl << "valor Total: " << x[i].vlr_total
            << endl << endl;

        return true;
    } else {
        return false;
    }

    getch();
}

bool buscarVenda(struct Venda x[], int &cont, int cod_cli) {
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
    int cod,
    int tipo
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

        switch (tipo) {
        case 1:
            cout << endl << "Codigo do Cliente: " << x[i].cod_cliente
                << endl << "Nome: " << x[i].nome
                << endl << "Endereco: " << x[i].endereco
                << endl << "Codigo da Cidade: " << x[i].cod_cidade
                << endl << endl;
            return true;
        
        case 2: 
            cout << endl << "Nome do Cliente: " << x[i].nome;
            return true;

        default:
            cout << endl << "Codigo do Cliente: " << x[i].cod_cliente
                << endl << "Nome: " << x[i].nome
                << endl << "Endereco: " << x[i].endereco
                << endl << "Codigo da Cidade: " << x[i].cod_cidade
                << endl << endl;
            return true;
        }
    } else {
        return false;
    }

    getch();
}

bool buscarGuia (
    struct Index idx[], 
    struct Guia x[], 
    int &cont, 
    int cod,
    int tipo,
    struct Cidade dbCidade[],
    int &numCidade,
    struct Pais dbPais[],
    int numPais
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
        switch (tipo) {
            case 1: 
                i = idx[m].idx;
                cout << endl << "Codigo do Guia: " << x[i].cod_guia
                    << endl << "Nome: " << x[i].nome
                    << endl << "Endereco: " << x[i].endereco
                    << endl << "Telefone: " << x[i].telefone
                    << endl << "Codigo da Cidade: " << x[i].cod_cidade
                    << endl << endl;
                return true;
                    
            case 2:
                i = idx[m].idx;
                cout << "\033[32m" << "Nome: " << x[i].nome << "\033[0m" << endl;
                buscarCidade(dbCidade, numCidade, x[i].cod_cidade);
                buscarPais(dbPais, numPais, x[i].cod_cidade);
                return true;

            case 3:
                i = idx[m].idx;
                cout << "Nome do guia: " << x[i].nome << endl;
                return true;
            
            default:
                i = idx[m].idx;
                cout << endl << "Codigo do Guia: " << x[i].cod_guia
                    << endl << "Nome: " << x[i].nome
                    << endl << "Endereco: " << x[i].endereco
                    << endl << "Telefone: " << x[i].telefone
                    << endl << "Codigo da Cidade: " << x[i].cod_cidade
                    << endl << endl;
                return true;
        }
    } else {
        return false;
    }

    getch();
}