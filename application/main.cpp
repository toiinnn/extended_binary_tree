#include "bTree.h"

int main( void )
{
    //-------------------------------------------------------------//
    //<! Inicio dos testes.
        std::cout << "\t\t\t\t --Inicio dos testes--\n";
        std::cout << "-----------------------------------------------------------------------------------------\n";
    //-------------------------------------------------------------//
    //<! Insert
        std::cout << "--Teste insert & Search--\n";
        BTree tree01;
        
        assert(tree01.search(15) == 0);
        
        tree01.insert(33);
        assert(tree01.search(33) == 1);

        tree01.insert(19);
        assert(tree01.search(19) == 1);

        tree01.insert(7);
        assert(tree01.search(7) == 1);

        tree01.insert(17);
        assert(tree01.search(17) == 1);

        tree01.insert(21);
        assert(tree01.search(21) == 1);
        
        tree01.insert(55);
        assert(tree01.search(55) == 1);
        
        tree01.insert(35);
        assert(tree01.search(35) == 1);

        tree01.insert(28);
        assert(tree01.search(28) == 1);

        tree01.insert(77);
        assert(tree01.search(77) == 1);

        std::cout << ">>>insert() && search() aprovado.\n";
    
    //-------------------------------------------------------------//
		
        std::cout << "\nPré-Ordem: \n";
        
        std::cout << "Recursivo: \n";
        tree01.pre_ordem_recursivo(); 

        std::cout << "\nIterativo: \n";
        tree01.pre_ordem_iterativo();

        std::cout << std::endl;

    //-------------------------------------------------------------//

        std::cout << "\nPós-Ordem: \n";
        
        std::cout << "Recursivo: \n";
        tree01.pos_ordem_recursivo(); 

        std::cout << "\nIterativo: \n";
        tree01.pos_ordem_iterativo();

        std::cout << std::endl;

    //-------------------------------------------------------------//

        std::cout << "\nOrdemSimétrica: \n";
        
        std::cout << "Recursivo: \n";
        tree01.ordem_simetrica_recursivo(); 

        std::cout << "\nIterativo: \n";
        tree01.ordem_simetrica_iterativo();        

        std::cout << std::endl;

        //std::cout << "Pós-Ordem: \n";
        //std::cout << "Valores:     Altura:  \n";  
        //tree01.pos_ordem_recursivo();
        //std::cout << "\n";  
    return 0;
}
