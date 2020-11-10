#ifndef tipono_h
#define tipono_h

#include "tipoitem.h"

class TipoNo{
    public:
        TipoNo();
    private:
        TipoItem item;
        TipoNo *esq;
        TipoNo *dir;
        
    friend class ArvoreBinaria;
};

#endif