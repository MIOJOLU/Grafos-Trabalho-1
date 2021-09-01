#include <iostream>
using namespace std;

class vertice{
public:
    int valor;
    vertice *proximo;
    vertice(){
        vertice(0);
    }
    vertice(int valor){
        this->valor = valor;
        this->proximo = nullptr;
    }
};

class grafoNaoPonderado{
public:
    int quantidadeVertices;
    vertice* nos[10*sizeof(vertice)];

    grafoNaoPonderado(int tam){
        quantidadeVertices = tam;
        for(int i = 0; i < quantidadeVertices; i++)
            nos[i] = new vertice(i);    
    }

    void print(){
        for(int i = 0; i < quantidadeVertices; i++){
            for(vertice* j = nos[i]; j != nullptr; j = j->proximo){
                if(j != nullptr)
                    cout << j->valor << " ";
            }
        }
    }

    void addVertice(int v_inicio, int v_final){
        if(nos[v_inicio]->proximo == nullptr){
             nos[v_inicio]-> proximo = new vertice(v_final);
        }else{
            vertice *i = nos[v_inicio] -> proximo;
            for(i = nos[v_inicio] -> proximo; i->proximo != nullptr; i = i->proximo);
            
            vertice* tmp = new vertice(v_final);
            tmp->proximo = i->proximo;
            i->proximo = tmp;
            tmp = i = nullptr;
        }
    }

    void removeVertice(int v_remover){
        for(int i = 0; i < quantidadeVertices; i++){
            if (i == v_remover){
                nos[i] = nullptr;
            }else{
                for(vertice* j = nos[i]; j != nullptr; j = j->proximo){
                    vertice* tmp = j -> proximo;
                    if(tmp != nullptr && tmp -> valor == v_remover){
                        if(tmp -> proximo == nullptr){
                            cout << j->valor << "if\n";
                            j -> proximo = tmp = nullptr;
                        }else{
                            cout << j->valor << "\n";
                            j -> proximo = tmp -> proximo;
                            tmp = nullptr;
                        }
                    }
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    grafoNaoPonderado* exemplo = new grafoNaoPonderado(4);
    exemplo->addVertice(0,1);
    exemplo->addVertice(0,2);
    exemplo->addVertice(1,2);
    exemplo->addVertice(1,3);
    exemplo->addVertice(2,1);
    exemplo->removeVertice(2);
    exemplo->print();
    return 0;
}
