#include"Encadeada.h"
void leArquivoEncadeada(string arquivo,Header*H)
{
    string line;
    int tamanho;
    int auxRg = 0;
    int auxPos = 0;
    ifstream myfile (arquivo);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            auxRg = retornaRgEncadeada(line);
            insereGen(H,line,auxRg,auxPos);
            tamanho++;
            auxPos++;
        }
        myfile.close();
        H->tamanho = tamanho;
    }

    else
        cout << "Unable to open file";

}
void insereGen(Header *H,string line, int rg, int pos)
{
    if(H->primero == NULL && pos == 0)
    {
        Encadeada *novoNode;
        novoNode = new(Encadeada);
        novoNode->nome = line;
        novoNode->rg = rg;
        novoNode->prox = NULL;
        novoNode->anterior = NULL;
        novoNode->posicao = pos;
        H->primero = novoNode;
        H->atual = novoNode;
    }
    else
    {
        Encadeada * aux;
        aux = H->atual;
        Encadeada *novoNode = new(Encadeada);
        novoNode->nome = line;
        novoNode->rg = rg;
        novoNode->prox = NULL;
        novoNode->anterior = NULL;
        novoNode->posicao = pos;
        aux->prox = novoNode;
        novoNode->anterior = aux;
        H->atual = novoNode;
    }
}

void imprime(Header *H)
{
    Encadeada * aux;
    for(aux = H->primero; aux != NULL; aux = aux->prox)
    {
        cout << aux->nome << " \t "<< aux->posicao << endl;
        //  cout << aux->rg << endl;
    }
}
int retornaRgEncadeada(string line)
{
    string auxLinha;
    string auxRG;
    int finalRG = 0;
    auxLinha = line;
    int posVirgula = 0;

    posVirgula = auxLinha.find(',');
    posVirgula++;
    auxRG = auxLinha.substr(posVirgula);
    finalRG = stoi(auxRG);
    return finalRG;
}
void insereIniEncadeada(Header *H)
{
    Encadeada* aux;
    Encadeada *novoNode = new(Encadeada);
    int c = 0, m = 0;
    string fullName;
    cout << "Digite o nome e o RG separado por virgula :::";
    cin >> fullName;
    novoNode->nome = fullName;
    novoNode->rg = retornaRgEncadeada(fullName);

    aux = H->primero;
    m++;
    novoNode->prox = aux;
    m++;
    aux->anterior = novoNode;
    m++;
    H->primero = novoNode;
    m++;
    H->tamanho++;

    cout << fullName << "Inserido !" << "C(n) ::: " << c << "M(n) ::: " << m << endl;

}

void insereFimEncadeada(Header*H)
{
    Encadeada* aux;
    Encadeada* novoNode = new(Encadeada);
    int c = 0, m = 0;
    string fullName;
    cout << "Insira um nome  e um RG separado por virgula ::: "<< endl;
    cin >> fullName;
    novoNode->nome = fullName;
    novoNode->rg = retornaRgEncadeada(fullName);
    novoNode->prox = NULL;
    novoNode->anterior = NULL;

    aux = H->atual;
    m++;
    novoNode->anterior = aux;
    m++;
    aux->prox = novoNode;
    m++;
    H->atual = novoNode;
    m++;
    H->tamanho++;
    cout << fullName << "Inserido !" << "C(n) ::: " << c << "M(n) ::: " << m << endl;

}

void inserePosEncadeada(Header*H)
{
    Encadeada* auxAnterior;
    Encadeada*auxPos = H->primero;
    Encadeada*auxPosterior;
    int c = 0, m = 0;
    int pos = 0;
    cout << "Digite a Posicao que deseja inserir ::" << endl;
    cin >> pos;
    if(pos == 1)
    {
        insereIniEncadeada(H);
    }
    else if (pos == H->tamanho)
    {
        insereFimEncadeada(H);
    }
    else
    {
        string fullName;
        cout << "Digite o nome e o RG separados por virgula" << endl;
        cin >> fullName;
        for(int i = 0; i < (pos - 1); i++)
        {
            auxPos = auxPos->prox;
            c++;
        }
        auxAnterior = auxPos->anterior;
        auxPosterior = auxPos->prox;
        Encadeada *novoNode = new(Encadeada);
        novoNode->anterior = NULL;
        novoNode->prox = NULL;
        novoNode->nome = fullName;
        novoNode->rg = retornaRgEncadeada(fullName);

        auxAnterior->prox = novoNode;
        m++;
        novoNode->anterior = auxAnterior;
        m++;
        auxPos->anterior = novoNode;
        m++;
        novoNode->prox = auxPos;
        m++;
        cout << fullName << " Inserido !" << " C(n) = " << c << " M(n) = " << m << endl;
        H->tamanho++;

    }


}
void removeIniEnc(Header*H)
{
    Encadeada* auxRemove;
    int c = 0, m = 0;
    auxRemove = H->primero;
    m++;
    H->primero = auxRemove->prox;
    m++;
    auxRemove->prox->anterior = NULL;
    m++;
    auxRemove->prox = NULL;
    m++;
    H->tamanho --;
    cout << auxRemove->nome << " Removido " << "C(n) = " << c << " M(n) = " << m << endl;

    delete auxRemove;

}
void removeFimEnc(Header *H)
{
    Encadeada *aux1,*aux2;
    int c = 0, m = 0;
    aux1 = H->atual;
    m++;
    aux2 = aux1->anterior;
    m++;
    aux2->prox = NULL;
    m++;
    H->atual = aux1->anterior;
    m++;
    aux1->anterior = NULL;
    m++;
    cout << aux1->nome << " Removido " << "C(n) :: " << c << " M(n) :: " << m << endl;
    delete aux1;

}
void removeNposEnc(Header *H)
{
    int pos = 0, c = 0, m = 0;
    cout << "Digite a posicao que deseja remover :: ";
    cin >> pos;
    if(pos == 1)
    {
        removeIniEnc(H);
    }
    else if(pos == H->tamanho)
    {
        removeFimEnc(H);
    }
    else
    {
        Encadeada *aux_remove,*aux_ant, *aux_pos;
        aux_remove = H->primero;
        for(int i = 0; i < (pos - 1); i++)
        {
            aux_remove = aux_remove->prox;
            c++;
        }
        aux_ant = aux_remove->anterior;
        m++;
        aux_pos = aux_remove->prox;
        m++;
        aux_remove->anterior = NULL;
        m++;
        aux_remove->prox = NULL;
        m++;
        aux_ant->prox = aux_pos;
        m++;
        aux_pos->anterior = aux_ant;
        m++;
        cout << aux_remove->nome << " Removido " << "C(n) :: " << c << " M(n) :: " << m << endl;
        delete aux_remove;
    }

}

void pesquisaEncadeada(Header*H)
{
    int rg = 0 ;
    int c = 0, m = 0;
    Encadeada* aux;
    cout << "Digite o RG que deseja :: ";
    cin >> rg;
    aux = H->primero;
    while(rg != aux->rg)
    {
        aux = aux->prox;
    }
    cout << aux->nome << " C(n) = " << c << " M(n) = " << m << endl;
}
void writeOnEnc(Header*H)
{
    ofstream myfile;
    myfile.open("novaListaEncadeada.txt");
    for(Encadeada* aux = H->primero; aux != NULL; aux = aux->prox)
    {
        myfile << aux->nome << endl;

    }
    myfile.close();
}


