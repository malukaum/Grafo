//=====================================================
// Arquivo: grafo.c 
//
// Autor: Otávio Augusto Chaves
// Data: 20/06/2016
// Disciplina: Algorítimo e Estrutura de Dados I
// Atividade: Implementação de TAD grafo
//=====================================================
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
//=====================================================
// Estrutura da aresta
//=====================================================
struct aresta {
    int x;
    int y;
    int id;
};
//=====================================================
// Estrutura do Grafo
//=====================================================
struct grafo {
    Aresta *aresta;
    int NumVer;
    int NumAre;
    int NumVerPrev;
    int NumArePrev;
};
//=====================================================
// Função que cria o Grafo
//=====================================================
Grafo GGcriaGrafo (int NumVerPrev, int NumArePrev){
    int i;
    Grafo grafo;
    Aresta *are = malloc(NumArePrev *sizeof(Aresta));
    grafo = (Grafo)malloc(sizeof(Grafo));
    grafo->aresta = are;
    grafo->NumArePrev=NumArePrev;
    grafo->NumVerPrev=NumVerPrev;
    grafo->NumVer=0;
    grafo->NumAre=0;
    for (i=0;i<NumArePrev-1;i++){
    	grafo->aresta[i].x=0;
        grafo->aresta[i].y=0;
        grafo->aresta[i].id=0;
    }
    return grafo;
}
//=====================================================
// Estrutura que carrega o Grafo
//=====================================================
Grafo GGcarregaGrafo(char caminho[]){
    int j, x, y, i = 0;
    Grafo grafo;
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL)
    {
        fclose(arq);
        return 0;
    }else {
        while( (fscanf(arq,"%d%d",&x,&y))!=EOF ){
            if (i==0){
                grafo=GGcriaGrafo(x,y);
                for (j=0;j<y;j++){
                    GVcriaVertice(grafo);
                }
            }else{
                GAcriaAresta(grafo,x,y);
            }
            i++;
        }
        fclose(arq);
        return grafo;
    }
    fclose(arq);
    return 0;
}
//=====================================================
// Função que destói o Grafo
//=====================================================
Grafo GGdestroiGrafo (Grafo grafo){
    free (grafo);
    grafo = NULL;
    return grafo;
}
//=====================================================
// Função que cria os vértices
///=====================================================
int GVcriaVertice (Grafo grafo){
    if (grafo->NumVer<grafo->NumVerPrev) {
        grafo->NumVer++;
        return grafo->NumVer;
    }else{
        return 0;
    }
}
//=====================================================
// Função que cria as areatas
//=====================================================
int GAcriaAresta (Grafo grafo, int x, int y){
    if (grafo->NumAre<grafo->NumArePrev) {
        grafo->aresta[grafo->NumAre].x = x;
        grafo->aresta[grafo->NumAre].y = y;
        grafo->aresta[grafo->NumAre].id = grafo->NumAre + 1;
        grafo->NumAre++;
        return grafo->aresta[grafo->NumAre-1].id;
    }else{
        return 0;
    }
}
//=====================================================
// Função que verifica a existência de um vértice por 
// seu ID
//=====================================================
int GBexisteIdVertice (Grafo grafo, int IdVertice){
    if (grafo->NumVer>=IdVertice && IdVertice>0){
        return 1;
    }else return 0;
}
//=====================================================
// Função que verifica a existência de uma aresta por 
// sua ID
//=====================================================
int GBexisteIdAresta (Grafo grafo, int IdAresta){
    if (grafo->NumAre>=IdAresta && IdAresta>0){
        return 1;
    }else return 0;
}
//=====================================================
// Função que verifica a existência de uma aresta 
// direcionada
//=====================================================
int GBexisteArestaDir (Grafo grafo, int x, int y){
    int i;
    for (i=0;i<grafo->NumAre;i++){
        if ( (grafo->aresta[i].x==x)&&(grafo->aresta[i].y==y) ){
            return 1;
        }
    }
    return 0;
}
//=====================================================
// Função que verifica a existência de uma aresta não 
// direcionada
//=====================================================
int GBexisteAresta (Grafo grafo, int x, int y){
    int i;
    for (i=0;i<grafo->NumAre;i++){
        if (((grafo->aresta[i].x==x)&&(grafo->aresta[i].y==y))||((grafo->aresta[i].x==y)&&(grafo->aresta[i].y==x))){
            return 1;
        }
    }
    return 0;
}
//=====================================================
// Função que pega a ID de uma aresta direcionada
//=====================================================
int GApegaArestaDir(Grafo grafo, int x, int y){
    int i;
    for (i=0;i<grafo->NumAre;i++){
        if ( (grafo->aresta[i].x==x)&&(grafo->aresta[i].y==y) ){
            return grafo->aresta[i].id;
        }
    }
    return 0;
}
//=====================================================
// Função que pega a ID de uma aresta não direcionada
//=====================================================
int GApegaAresta(Grafo grafo, int x, int y){
    int i;
    for (i=0;i<grafo->NumAre;i++){
        if (((grafo->aresta[i].x==x)&&(grafo->aresta[i].y==y))||((grafo->aresta[i].x==y)&&(grafo->aresta[i].y==x))){
            return grafo->aresta[i].id;
        }
    }
    return 0;
}
//=====================================================
// Função que pega o primeiro vértice
//=====================================================
int GVprimeiroVertice(Grafo grafo){
    return 1;
}
//=====================================================
// Função que pega o próximo vértice
//=====================================================
int GVproximoVertice (Grafo grafo, int IdVertice){
    if (IdVertice<grafo->NumVer){
        return IdVertice+1;
    }else return 0;
}
//=====================================================
// Função que pega o ID da primeira aresta
//=====================================================
int GAprimeiraAresta(Grafo grafo){
    return grafo->aresta[0].id;
}
//=====================================================
// Função que pega o ID da próxima aresta
//=====================================================
int GAproximaAresta(Grafo grafo, int IdAresta){
    if (IdAresta<grafo->NumAre){
        return grafo->aresta[IdAresta].id;
    }else return 0;
}
//=====================================================
// Função que pega a número de vértices
//=====================================================
int GInumeroVertices(Grafo grafo){
    return grafo->NumVer;
}
//=====================================================
// Função que retorna o número máximo de vértices que o
// grafo aceita
//=====================================================
int GInumeroVerticesMax(Grafo grafo){
    return grafo->NumVerPrev;
}
//=====================================================
// Função que pega o número de arestas
//=====================================================
int GInumeroArestas(Grafo grafo){
    return grafo->NumAre;
}
//=====================================================
// Função que pega o número máximo de arestas que o
// grafo suporta
//=====================================================
int GInumeroArestasMax(Grafo grafo){
    return grafo->NumArePrev;
}
//=====================================================
// Função que salva o grafo em um arquivo
//=====================================================
int GBsalvaGrafo(Grafo grafo, char caminho[]){
    int i;
    FILE *arq = fopen(caminho,"w");
    if (arq == NULL){
        fclose(arq);
        return 0;
    }else{
        fprintf(arq,"%d %d\n",grafo->NumVer,grafo->NumAre);
        for (i=0;i<grafo->NumAre;i++){
            fprintf(arq,"%d %d\n",grafo->aresta[i].x,grafo->aresta[i].y);
        }
        fclose(arq);
        return 1;
    }
}
//=====================================================
// Função que pega o grau do vértice
//=====================================================
int GIpegaGrau(Grafo grafo, int vertice){
    int i;
    int grau=0;
    for (i=0;i<grafo->NumAre;i++){
        if ((grafo->aresta[i].x==vertice)||(grafo->aresta[i].y==vertice)){
            grau++;
        }
	    if ((grafo->aresta[i].x==vertice)&&(grafo->aresta[i].y==vertice)){
            grau++;
        }
    }
    return grau;
}
//=====================================================
// Função que pega a pŕimeira aresta na estrela do 
// vértice
//=====================================================
int GAprimaAresta(Grafo grafo, int vertice){
    int i;
   for (i=0;i<grafo->NumAre;i++){
        if ((grafo->aresta[i].x==vertice)||(grafo->aresta[i].y==vertice)){
            return grafo->aresta[i].id;
        }
    }
   return 0;
}
//=====================================================
// Função que pega a próxima aresta na estrela do 
// vértice
//=====================================================
int GAproxAresta(Grafo grafo, int vertice, int aresta){
   int i;
   for (i=0;i<grafo->NumAre;i++){
        if (((grafo->aresta[i].x==vertice)||(grafo->aresta[i].y==vertice))&&(grafo->aresta[i].id>aresta)){
            return grafo->aresta[i].id;
        }
    }
   return 0;
}
//=====================================================
// Função que pega a primeira aresta na estrela de 
// entrada de um vértice 
//=====================================================
int GAprimaEntrada(Grafo grafo, int vertice){
    int i;
    for(i=0;i<grafo->NumAre;i++){
        if(grafo->aresta[i].y==vertice)
            return grafo->aresta[i].id;
    }
    return 0;
}
//=====================================================
// Função que pega a próxima aresta na estrela de 
// entrada de um vértice 
//=====================================================
int GAproxEntrada(Grafo grafo, int vertice, int aresta){
    int i;
    for(i=0;i<grafo->NumAre;i++){
        if((grafo->aresta[i].y==vertice)&&(grafo->aresta[i].id>aresta))
            return grafo->aresta[i].id;
    }
    return 0;
}
//=====================================================
// Função que pega a primeira aresta na estrela de 
// saída de um vértice 
//=====================================================
int GAprimaSaida(Grafo grafo, int vertice){
    int i;
    for(i=0;i<grafo->NumAre;i++){
        if(grafo->aresta[i].x==vertice)
            return grafo->aresta[i].id;
    }
    return 0;
}
//=====================================================
// Função que pega a próxima aresta na estrela de 
// saída de um vértice 
//=====================================================
int GAproxSaida(Grafo grafo, int vertice, int aresta){
    int i;
    for(i=0;i<grafo->NumAre;i++){
        if((grafo->aresta[i].x==vertice)&&(grafo->aresta[i].id>aresta))
            return grafo->aresta[i].id;
    }
    return 0;
}
//=====================================================
// Função que diz se a aresta é ou não um laço
//=====================================================
int GBarestaLaco(Grafo grafo, int aresta){
    if (grafo->aresta[aresta-1].x==grafo->aresta[aresta-1].y){
        return 1;
    }else{
        return 0;
    }
}
//=====================================================
// Função que pega o alfa de uma aresta
//=====================================================
int GValfa(Grafo grafo, int aresta){
    if (aresta>0&&aresta<=grafo->NumAre){
        return grafo->aresta[aresta-1].x;
    }else{
        return 0;
    }
}
//=====================================================
// Função que pega o ômega de uma aresta
//=====================================================
int GVomega(Grafo grafo, int aresta){
    if (aresta>0&&aresta<=grafo->NumAre){
        return grafo->aresta[aresta-1].y;
    }else{
        return 0;
    }
}
//=====================================================
// Função que pega o vértice vizinho na outra ponta da
// aresta
//=====================================================
int GVvizinho(Grafo grafo, int aresta, int vertice){
    if (aresta>0&&aresta<=grafo->NumAre){
        if (grafo->aresta[aresta-1].x==vertice){
            return grafo->aresta[aresta-1].y;        
        }else if (grafo->aresta[aresta-1].y==vertice){
            return grafo->aresta[aresta-1].x; 
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}