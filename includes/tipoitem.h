#ifndef tipoitem_h
#define tipoitem_h

#include <string>

typedef std::string TipoChave;
class TipoItem{
    private:
        TipoChave chave;
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();    
};

#endif