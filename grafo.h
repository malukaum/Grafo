//=====================================================
// Arquivo: grafo.h 
//
// Autor: Otávio Augusto Chaves
// Data: 20/06/2016
// Disciplina: Algorítimo e Estrutura de Dados I
// Atividade: Implementação de TAD grafo
//=====================================================
#ifndef GRAFO_H
#define GRAFO_H
typedef struct aresta Aresta;
typedef struct grafo *Grafo;
Grafo GGcriaGrafo (int NumArePrev, int NumVerPrev);
Grafo GGdestroiGrafo (Grafo grafo);
int GVcriaVertice (Grafo grafo);
int GAcriaAresta (Grafo grafo, int x, int y);
int GBexisteIdVertice (Grafo grafo, int IdVertice);
int GBexisteIdAresta (Grafo grafo, int IdAresta);
int GBexisteArestaDir (Grafo grafo, int x, int y);
int GBexisteAresta (Grafo grafo, int x, int y);
int GApegaArestaDir(Grafo grafo, int x, int y);
int GApegaAresta(Grafo grafo, int x, int y);
int GVprimeiroVertice(Grafo grafo);
int GVproximoVertice (Grafo grafo, int IdVertice);
int GAprimeiraAresta(Grafo grafo);
int GAproximaAresta(Grafo grafo, int IdAresta);
int GInumeroVertices(Grafo grafo);
int GInumeroVerticesMax(Grafo grafo);
int GInumeroArestas(Grafo grafo);
int GInumeroArestasMax(Grafo grafo);
Grafo GGcarregaGrafo(char caminho[]);
int GBsalvaGrafo(Grafo grafo, char caminho[]);
int GIpegaGrau(Grafo grafo, int vertice);
int GAprimaAresta(Grafo grafo, int vertice);
int GAproxAresta(Grafo grafo, int vertice, int aresta);
int GAprimaEntrada(Grafo grafo, int vertice);
int GAproxEntrada(Grafo grafo, int vertice, int aresta);
int GAprimaSaida(Grafo grafo, int vertice);
int GAproxSaida(Grafo grafo, int vertice, int aresta);
int GBarestaLaco(Grafo grafo, int aresta);
int GValfa(Grafo grafo, int aresta);
int GVomega(Grafo grafo, int aresta);
int GVvizinho(Grafo grafo, int aresta, int vertice);
void Gcaminho( Grafo grafo, float custo[], int s, int f);
#endif	// GRAFO_H

