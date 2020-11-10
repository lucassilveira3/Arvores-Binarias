#ifndef arvorebinaria_h
#define arvorebinaria_h

#include "tipono.h"

class ArvoreBinaria
{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(TipoItem item);
        TipoItem Pesquisa(TipoChave chave);
        void Remove(TipoChave chave);
        void Limpa();
        void Encriptacao(TipoChave chave, int* cont);
        void Desencriptacao(int palavra_crip, int* cont);
        TipoNo* GetRaiz();
    private:
        void InsereRecursivo(TipoNo* &p, TipoItem item);
        void ApagaRecursivo(TipoNo* p);
        TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave);
        void Antecessor(TipoNo* q, TipoNo* &r);
        void RemoveRecursivo(TipoNo* &p, TipoChave chave);
        void EncriptaRecursivo(TipoNo* p, TipoChave chave, int* cont);
        void DesencriptaRecursivo(TipoNo* p, int palavra_crip, int* cont);

        TipoNo *raiz;
};

#endif