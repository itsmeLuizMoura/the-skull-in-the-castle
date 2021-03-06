#include <iostream>
#include <clocale>
#include <stdlib.h>
#include "bibItens.h"
#include "bibNPC.h"
#include "bibDado.h"
#include "bibGame.h"
#include <time.h>


using namespace std;

//Cria uma lista para armazenar itens do jogador
void criaListaItens(TListaItens &itens){
    itens.primeiro = new TItem;
    itens.ultimo = itens.primeiro;
    itens.primeiro->proximo = NULL;
}

bool eVazia(TListaItens &itens){
    return (itens.primeiro == itens.ultimo);//Verifica se o jogador possui itens
}

void inserirItens(TPocao n, TListaItens &itens){
    itens.ultimo->proximo = new TItem;              //Cria uma nova celula TItem
    itens.ultimo = itens.ultimo->proximo;           //Define proximo do anterior com o criado
    itens.ultimo->item = n;                         //Atribui valor a novo item
    itens.ultimo->proximo = NULL;                   //Proximo recebe NULL
}

void mostrarListaItens(TListaItens itens){
    TItem *pCelAux;                                 //Cria uma variavel auxiliar
    int i = 1;                                      //Utilizada para numerar os itens
    pCelAux = itens.primeiro->proximo;              //Auxiliar recebe o Primeiro item da lista
    cout << "\n>> BOLSA " << endl;
    while (pCelAux != NULL){                        //Enquanto apontado Aux nao for vazia
        cout << i <<": Poção " << pCelAux->item.nomeItem << " | ";
        pCelAux = pCelAux->proximo;                 //Exibe o Item
        i++;
    }
}

TItem *pegaAnteriorDoItem(int id, TListaItens itens){   //Pega o anterior do item para excluir da lista
    TItem *pCelAux;                                     //Cria uma variavel Aux
    pCelAux = itens.primeiro;

    while (pCelAux->proximo != NULL){
        if (pCelAux->proximo->item.id == id){
            return pCelAux;
        }else{
            pCelAux = pCelAux->proximo;
        }
    }
    return pCelAux;
}


void retirarItem(TItem *antItemRet, TListaItens &itens){
    TItem *pCelAux;                 //Cria uma auxiliar
    if ((eVazia(itens))||(antItemRet==NULL)||(antItemRet->proximo==NULL)){
        return;
    }else{
        pCelAux = antItemRet->proximo;
        antItemRet->proximo = pCelAux->proximo;
        if (antItemRet->proximo == NULL){
            itens.ultimo = antItemRet;
        }
        delete pCelAux;
    }
}

//determinas os itens iniciais do jogador
void listaItens(TListaItens &itens){
    TPocao n;                                  //Insere na Bolsa do personage os itens
    int pVida = 2, pMana = 2, x;               //pVida e pMana definem quantidade de itens iniciais
    for( x = 0; x < pVida ; x++){
        n.nomeItem= "Vida";                     //Nome do item
        n.id = 1;                               //ID de utilização
        n.bonus = 15;                           //Quantidade restaurar
        inserirItens(n, itens);
    }
    for(x = 0; x < pVida ; x++){
        n.nomeItem = "Mana";
        n.id = 2;
        n.bonus = 15;
        inserirItens(n, itens);
    }
}
