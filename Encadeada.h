#ifndef ENCADEADA_H_INCLUDED
#define ENCADEADA_H_INCLUDED
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
typedef struct encadeada{
    string nome;
    int rg;
    int posicao;
    struct encadeada *prox;
    struct encadeada *anterior;

}Encadeada;
typedef struct header{
    int tamanho;
    Encadeada *primero;
    Encadeada *atual;
}Header;
void leArquivoEncadeada(string arquivo,Header*H);
void insereGen(Header*H,string line, int rg, int pos);
void imprime(Header *H);
int retornaRgEncadeada(string line);
void insereIniEncadeada(Header*H);
void insereFimEncadeada(Header*H);
void inserePosEncadeada(Header*H);
void removeIniEnc(Header *H);
void removeFimEnc(Header*H);
void removeNposEnc(Header *H);
void pesquisaEncadeada(Header *H);
void writeOnEnc(Header *H);





#endif // ENCADEADA_H_INCLUDED
