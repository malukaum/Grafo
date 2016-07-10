#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, char** argv) {
    float custo[12]={0,4,2,1,5,3,5,4,3};
    
    Grafo grafo=GGcarregaGrafo("grafo1.txt");
            
    Gcaminho(grafo,custo,1,6);
    
    GBsalvaGrafo(grafo,"arquivo2.txt");
    
    return 0;
}