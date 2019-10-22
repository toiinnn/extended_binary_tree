#include "bTree.h"

//Default Constructor
BTree::BTree( )
    : m_root()
{/*empty*/}

//Destructor
BTree::~BTree()
{/*empty*/}

//Public Members-------------------------------------

void BTree::insert(int key)
{
    int f = 0;
    insert(key, m_root, &f);
}

int BTree::search(int key)
{
    int f = 0;
    search(key, m_root, &f);
    return f;
}

void BTree::pre_ordem_recursivo()
{
    pre_ordem_recursivo(m_root);
}

void BTree::ordem_simetrica_recursivo()
{
    ordem_simetrica_recursivo(m_root);
}

void BTree::pos_ordem_recursivo()
{
    pos_ordem_recursivo(m_root);
}

void BTree::pre_ordem_iterativo()
{
    pre_ordem_iterativo(m_root);
}
void BTree::ordem_simetrica_iterativo()
{
    ordem_simetrica_iterativo(m_root);
}
void BTree::pos_ordem_iterativo()
{
    pos_ordem_iterativo(m_root);
}

//Private Members -----------------------------------
BTree::node_t* BTree::search(int key, node_t* pt, int* f)
{
    if(pt != nullptr)
    {
        if(pt->key_value == key)
            *f = 1;
        else
        {
            if(key < pt->key_value)
            {
                if(pt->left == nullptr)
                {
                    *f = 2;
                    return pt;
                }
                else
                    pt = pt->left;
            }
            else
            {
                if(pt->right == nullptr)
                {
                    *f = 3;
                    return pt;
                }
                else
                    pt = pt->right;
            }
            if(*f < 1)
                return search(key,pt,f);
        }
    }
    else
    {
        return nullptr;
    }
}

void BTree::insert(int key, node_t* pt, int* f)
{
    auto pt1 = search(key, pt, f);
    if( *f == 1 )
        std::cout << "Elemento "<<  key <<" já existe na árvore" << std::endl;
    else
    {
        node_t *new_(nullptr);
        try 
        {
            new_ = new node_t( key, nullptr, nullptr );
        }
        catch ( std::bad_alloc & e )
        {
            std::cout << "Má alocação de memória";
        }
        
        if(*f == 0) {
            m_root = new_;
        }
        else
        {
            if(*f == 2)
            {
                pt1->left = new_;
            }
            else
            {
                pt1->right = new_;
            }
        }
    }
}

void BTree::pre_ordem_recursivo(node_t* pt)
{
    if(pt == nullptr) // end the recursion if node == nullptr
       return;

    std::cout << pt->key_value << " ";
    pre_ordem_recursivo(pt->left);
    pre_ordem_recursivo(pt->right);

}

void BTree::ordem_simetrica_recursivo(node_t* pt)
{
    if(pt != nullptr)
    {
        ordem_simetrica_recursivo(pt->left);
        std::cout << pt->key_value << " ";
        ordem_simetrica_recursivo(pt->right);
    }
    else
        return;
}

void BTree::pos_ordem_recursivo(node_t* pt)
{
    if(pt != nullptr)
    {
        pos_ordem_recursivo(pt->left);
        pos_ordem_recursivo(pt->right);
        visita(pt);
        std::cout << pt->key_value << " ";
        //std::cout << "     " << pt->key_value << "          " << pt->altura << "\n";        
    }
    else
        return;
}

void BTree::pre_ordem_iterativo(node_t* pt)
{
    std::stack<BTree::node_t*> stackNodes;
    bool end = false;

    do
    {
        if(pt != nullptr)
        {
            std::cout << pt->key_value << " ";
            if(pt->right != nullptr)
                stackNodes.push(pt->right);
            pt = pt->left;
        }
        else if(stackNodes.empty())
            end = true;
        else
        {
            pt = stackNodes.top();
            stackNodes.pop();
        }
    }
    while(!end);
}

void BTree::ordem_simetrica_iterativo(node_t* pt)
{
    std::stack<BTree::node_t*> stackNodes;
    bool end = false;

    do
    {
        while(pt != nullptr)
        {
            stackNodes.push(pt);
            pt = pt->left;
        }
        if(!stackNodes.empty())
        {
            pt = stackNodes.top();
            stackNodes.pop();
            
            std::cout << pt->key_value << " ";

            pt = pt->right;
        }
        else
            end = true;
    }
    while(!end);
}

void BTree::pos_ordem_iterativo(node_t* pt)
{
    //These stacks are incremented together. 
    std::stack<BTree::node_t*> stackNodes;
    std::stack<int> status;
    
    int aux;
    
    do
    {
        while(pt != nullptr) 
        {
            stackNodes.push(pt);
            status.push(1);
            pt = pt->left;
        }
        bool up = true;
        
        while(up && !stackNodes.empty())
        {
            aux = status.top();
            pt = stackNodes.top();

            status.pop();
            stackNodes.pop();

            switch(aux)
            {
                case 1:

                    stackNodes.push(pt);    
                    status.push(2);
                    pt = pt->right;
                    up = false;
                    break;
                
                case 2:                  
                    std::cout << pt->key_value << " ";
            } 
        } 
    }while(!stackNodes.empty());
}

void BTree::visita(node_t* pt)
{
    int alt1;
    int alt2; 
    if(pt->left == nullptr)
        alt1 = 0;
    else
        alt1 = pt->left->altura;
    
    if(pt->right == nullptr)
        alt2 = 0;
    else
        alt2 = pt->right->altura;
    
    if(alt1 > alt2)
        pt->altura = alt1 + 1;
    else
        pt->altura = alt2 + 1;
}