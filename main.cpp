#include <iostream>
#include <string>
#include <cstring>
#include "arvore-binaria.h"
#include "tipono.h"

main(){
    ArvoreBinaria A;
    TipoItem x;
    char operador;
    std::string palavra;
    int i, n;
    
    while(scanf("%c", &operador) != EOF){
        switch(operador){
            case 'i':{
                std::cin >> palavra;
                x.SetChave(palavra);
                A.Insere(x);
                break;
            }
            case 's':{
                std::string aux;
                std::cin >> palavra >> aux;
                A.Pesquisa(palavra);
                A.Remove(palavra);
                x.SetChave(aux);
                A.Insere(x);
                break;
            }
            case 'e':{
                std::cin >> i;
                for(int j = 0;j < i;j++){ 
                    n = 0;   
                    std::cin >> palavra;
                    A.Encriptacao(palavra, &n);
                }
                std::cout << std::endl;
                break;
            }
            case 'd':{
                std::cin >> i;

                int palavra_crip;
                for(int j = 0;j < i;j++){
                    n = 0;
                    std::cin >> palavra_crip;
                    A.Desencriptacao(palavra_crip, &n);
                }
                std::cout << std::endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}