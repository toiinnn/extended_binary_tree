#include <iostream>  // cout, endl
#include <cassert>   // assert()
#include <cstddef>   // std::ptrdiff_t
//#include <queue>     // std::queue
//#include <list>      // std::list
#include <stack>     // std::stack
#include <limits>    // interger min value
#include <iomanip>   // setw

#ifndef _BTREE_H_
#define _BTREE_H_

class BTree
{
    public:
        struct node_t
        {
            int key_value; // Tipo de informação armazenada no container
            int altura;  
            node_t* left;
            node_t* right;
        
            node_t ( const int & k_,node_t* l_ = nullptr, node_t* r_ = nullptr)
                : key_value ( k_ )
                , left ( l_ )
                , right ( r_ )
                , altura(0)
            { /*empty*/ }
        };

    public:
        BTree();
        ~BTree();

        void insert(int key);
        int search(int key);

        void pre_ordem_recursivo();
        void ordem_simetrica_recursivo();
        void pos_ordem_recursivo();
	
        void pre_ordem_iterativo();
        void ordem_simetrica_iterativo();
        void pos_ordem_iterativo();
        
        //void prettyPrint();

        //TO_DO: 
        //Algorítmos de pré-ordem, pós-ordem e ordem simétrica, interativos
        //Algorítmo de de percurso em nível em árvore binária
        //Algorítmo de remoção de um nó específico considerando os diferentes casos
        //Dada uma lista com n chaves, construir uma árvore de busca binária de altura mínima usando o algorítmo de inserção 

    // Private members.
    private:
        
        node_t* m_root;

        void insert(int key, node_t* pt, int *f);
        node_t* search(int key, node_t* pt, int *f);		

        void pre_ordem_recursivo(node_t* pt);
        void ordem_simetrica_recursivo(node_t* pt);
        void pos_ordem_recursivo(node_t* pt);
		
        void pre_ordem_iterativo(node_t* pt);
        void ordem_simetrica_iterativo(node_t* pt);
        void pos_ordem_iterativo(node_t* pt);

    	//Auxiliar functions to calc the tree's height 
        void visita(node_t* pt);

        void percEmNivel(node_t* pt);

		//Auxiliar functions to print the Tree
		//void prettyPrint(node_t *pt);
		//void printRow(node_t *pt, int heigth, int depth);
		//void getLine(node_t *root, int depth, std::vector<int> &vals);
};

#include "bTree.inl"
#endif