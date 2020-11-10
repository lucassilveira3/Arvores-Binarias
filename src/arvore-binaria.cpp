#include "arvore-binaria.h"
#include "fila-arranjo.h"

#include <iostream>

ArvoreBinaria::ArvoreBinaria(){
    raiz = 0;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::Insere(TipoItem item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
    if(p==0){
        p = new TipoNo();
        p->item = item;
    }
    else{
        if(item.GetChave() < p->item.GetChave()){
            InsereRecursivo(p->esq, item);
        }
        else{
            InsereRecursivo(p->dir, item);
        }
    }
}

void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = 0;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p!=0){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

TipoNo* ArvoreBinaria::GetRaiz(){
    return raiz;
}

TipoItem ArvoreBinaria::Pesquisa(TipoChave chave){
    return PesquisaRecursivo(raiz, chave);
}

TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo* p, TipoChave chave){
    TipoItem aux;

    if(p == NULL){
        aux.SetChave("-1");
        return aux;
    }

    if(chave < p->item.GetChave())
        return PesquisaRecursivo(p->esq, chave);
    else if(chave > p->item.GetChave())
        return PesquisaRecursivo(p->dir, chave);
    else
        return p->item;
}

void ArvoreBinaria::Remove(TipoChave chave){
    return RemoveRecursivo(raiz, chave);
}

void ArvoreBinaria::Antecessor(TipoNo* q, TipoNo* &r){
    if(r->dir == NULL){
        Antecessor(q, r->dir);
        return;
    }

    q->item = r->item;
    q = r;
    r = r->esq;
    delete q;
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &p, TipoChave chave){
    TipoNo* aux;

    if(p == NULL){
        throw("Item nao esta presente");
    }

    if(chave < p->item.GetChave())
        return RemoveRecursivo(p->esq, chave);
    else if(chave > p->item.GetChave())
        return RemoveRecursivo(p->dir, chave);
    else{
        if(p->dir == NULL){
            aux = p;
            p = p->esq;
            delete aux;
        }
        else if(p->esq == NULL){
            aux = p;
            p = p->dir;
            delete aux;
        }
        else
            Antecessor(p, p->esq);
    }
}

void ArvoreBinaria::Encriptacao(TipoChave chave, int* cont){
    return EncriptaRecursivo(raiz, chave, cont);
}

void ArvoreBinaria::EncriptaRecursivo(TipoNo* p, TipoChave chave, int* cont){
    if(p != NULL){
        *cont += 1;

        if(p->item.GetChave() == chave)
            std::cout << *cont << " ";

        EncriptaRecursivo(p->esq, chave, cont);
        EncriptaRecursivo(p->dir, chave, cont);
    }
}

void ArvoreBinaria::Desencriptacao(int palavra_crip, int* cont){
    return DesencriptaRecursivo(raiz, palavra_crip, cont);
}

void ArvoreBinaria::DesencriptaRecursivo(TipoNo* p, int palavra_crip, int* cont){
    if(p != NULL){
        *cont += 1;

        if(*cont == palavra_crip)
            std::cout << p->item.GetChave() << " ";

        DesencriptaRecursivo(p->esq, palavra_crip, cont);
        DesencriptaRecursivo(p->dir, palavra_crip, cont);
    }
}