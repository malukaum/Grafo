//=====================================================
// Arquivo: caminho.c 
//
// Autor: Otávio Augusto Chaves
// Data: 20/06/2016
// Disciplina: Algorítimo e Estrutura de Dados I
// Atividade: Implementação de TAD grafo
//=====================================================
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"
#include "caminho.h"
//============================
// Estrutura da aresta
//============================
struct aresta {
    int x;
    int y;
    int id;
};
//============================
// Estrutura do Grafo
//============================
struct grafo {
    Aresta *aresta;
    int NumVer;
    int NumAre;
    int NumVerPrev;
    int NumArePrev;
};
//============================
// Função que procura o menor 
// caminho através do 
// Algorítimo de Dijkstra
//============================
void Gcaminho( Grafo grafo, float custo[], int s, int f){
    int i, v, v0, w0, parent[grafo->NumVer+1], caminho[grafo->NumVer+1],auxCaminho[grafo->NumVer+1]; 
    float dist[grafo->NumVer+1];
    float INFINITO =999999;
    for (i = 0; i < grafo->NumVer+1; i++) 
        parent[i] = -1, dist[i] = INFINITO, caminho[i]=0, auxCaminho[i]=0;
    parent[s] = s; 
    dist[s] = 0.0; 
    //Aqui inicia o a busca pelo menores caminhos
    while (1) {
        float mindist = INFINITO;
        for (v = 1; v < grafo->NumVer+1; v++){
            if (parent[v] != -1){
                for (i=0;i<grafo->NumAre;i++){
                    if (grafo->aresta[i].x==v){
                        if (parent[grafo->aresta[i].y] == -1 && mindist > dist[v] + custo[grafo->aresta[i].id]){
                            mindist = dist[v] + custo[grafo->aresta[i].id];
                            v0 = v;
                            w0 = grafo->aresta[i].y;
                        }
                    }
                }
            }
        }
        if (mindist == INFINITO) break;
        parent[w0] = v0;
        dist[w0] = mindist;
        caminho[w0]=v0;
    }
    //Após encontrar todos os menores caminhos, o resultado é filtrado
    if (caminho[f]==0) {
        printf("%d\n",s);
    }else{
        printf("%d->",s);
        i=0;
        while (f!=s){
            auxCaminho[i]=f;
            f=caminho[f];
            i++;
        }
        i--;
        while(i>0){
            printf("%d->",auxCaminho[i]);
            i--;
        }
        printf("%d\n",auxCaminho[0]);
    }
}