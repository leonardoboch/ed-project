#include"Sequencial.h"
#include"Encadeada.h"

using namespace std;

int main()
{
    int opc_lista = -1;
    cout << "1--- SEQUENCIAL" << endl;
    cout << "2 --- ENCADEADA " << endl;
    cout <<"0 --- SAIR " << endl;
    cin >> opc_lista;
    if(opc_lista == 1)
    {
        int tamanhoLista = 0;
        string nomeArquivo;
        cout << "\t\t\t MENU " << endl;
        cout << "\t\t Lista Sequencial" << endl;
        cout<< "Escolha o Arquivo" << endl;
        cout << "10 Elementos ------> 1" << endl;
        cout << "50 Elementos ------> 2" << endl;
        cout << "100 Elementos ------> 3" << endl;
        cout << "1k Elementos ------> 4" << endl;
        cout << "10k Elementos ------> 5" << endl;
        cout << "1m Elementos ------> 6" << endl;
        cout << "100m Elementos ------> 7" << endl;
        int arquivo = 0;
        cin >> arquivo;

        switch(arquivo)
        {
        case 1:
            nomeArquivo = "NomeRG10.txt";
            break;
        case 2:
            nomeArquivo = "NomeRG50.txt";
            break;
        case 3:
            nomeArquivo = "NomeRG100.txt";
            break;
        case 4:
            nomeArquivo = "NomeRG1K.txt";
            break;
        case 5:
            nomeArquivo = "NomeRG10K.txt";
            break;
        case 6:
            nomeArquivo = "NomeRG1M.txt";
            break;
        case 7:
            nomeArquivo = "NomeRG100M.txt";
            break;
        }
        tamanhoLista = retornaLinhas(nomeArquivo);
        Sequencial*lista;
        int menu = -1;
        lista = alocaLista(tamanhoLista + 10);
        armazenaLista(nomeArquivo,lista);
        cout << "Lista Armazenada !" << endl;
        cout << "1---Insere Inicio" << endl;
        cout << "2---Insere Fim" << endl;
        cout << "3---Insere N" << endl;
        cout << "4---Remove Inicio" << endl;
        cout << "5---Remove Fim" << endl;
        cout << "6---Remove N" << endl;
        cout << "7---Pesquisa" << endl;
        cout << "8---Imprime a Lista" << endl;
        cout << "0---Sair" << endl;

        do
        {
            cout << "Escolha uma opcao :::" ;
            cin >> menu;
            switch(menu)
            {
            case 1:
                insereInicio(lista,&tamanhoLista);
                break;
            case 2:
                insereFim(lista,&tamanhoLista);
                break;
            case 3:
                insereNpos(lista,&tamanhoLista);
                break;
            case 4:
                removeInicio(lista,&tamanhoLista);
                break;
            case 5:
                removeFim(lista,&tamanhoLista);
                break;
            case 6:
                removeN(lista,&tamanhoLista);
                break;
            case 7:
                pesquisa(lista,&tamanhoLista);
                break;
            case 8:
                imprimeLista(lista,&tamanhoLista);
                break;


            }

        }
        while(menu != 0);
        cout << "Saindo. ";
        writeOnFile(lista,&tamanhoLista);
    }
    else if (opc_lista == 2)
    {
        string nomeArquivo;
        cout << "\t\t\t MENU " << endl;
        cout << "\t\t Lista Sequencial" << endl;
        cout<< "Escolha o Arquivo" << endl;
        cout << "10 Elementos ------> 1" << endl;
        cout << "50 Elementos ------> 2" << endl;
        cout << "100 Elementos ------> 3" << endl;
        cout << "1k Elementos ------> 4" << endl;
        cout << "10k Elementos ------> 5" << endl;
        cout << "1m Elementos ------> 6" << endl;
        cout << "100m Elementos ------> 7" << endl;
        int arquivo = 0;
        cin >> arquivo;

        switch(arquivo)
        {
        case 1:
            nomeArquivo = "NomeRG10.txt";
            break;
        case 2:
            nomeArquivo = "NomeRG50.txt";
            break;
        case 3:
            nomeArquivo = "NomeRG100.txt";
            break;
        case 4:
            nomeArquivo = "NomeRG1K.txt";
            break;
        case 5:
            nomeArquivo = "NomeRG10K.txt";
            break;
        case 6:
            nomeArquivo = "NomeRG1M.txt";
            break;
        case 7:
            nomeArquivo = "NomeRG100M.txt";
            break;
        }
        Header *H = new(Header);
        int menu = -1;
        leArquivoEncadeada(nomeArquivo,H);
        cout << "Lista Armazenada !" << endl;
        cout << "1---Insere Inicio" << endl;
        cout << "2---Insere Fim" << endl;
        cout << "3---Insere N" << endl;
        cout << "4---Remove Inicio" << endl;
        cout << "5---Remove Fim" << endl;
        cout << "6---Remove N" << endl;
        cout << "7---Pesquisa" << endl;
        cout << "8---Imprime a Lista" << endl;
        cout << "0---Sair" << endl;
        do
        {
            cout << "Escolha uma opcao :::" ;
            cin >> menu;
            switch(menu)
            {
            case 1:
              insereIniEncadeada(H);
                break;
            case 2:
                insereFimEncadeada(H);
                break;
            case 3:
                inserePosEncadeada(H);
                break;
            case 4:
                removeIniEnc(H);
                break;
            case 5:
                removeFimEnc(H);
                break;
            case 6:
                removeNposEnc(H);
                break;
            case 7:
                pesquisaEncadeada(H);
                break;
            case 8:
                imprime(H);
                break;


            }

        }
        while(menu != 0);
        cout << "Saindo. ";
        writeOnEnc(H);

    }
    return 0;
}
