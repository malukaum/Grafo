//=====================================================
// Arquivo: caminho.h 
//
// Autor: Otávio Augusto Chaves
// Data: 20/06/2016
// Disciplina: Algorítimo e Estrutura de Dados I
// Atividade: Implementação de TAD grafo
//=====================================================
#ifndef CAMINHO_H
#define CAMINHO_H
typedef struct aresta Aresta;
typedef struct grafo *Grafo;
void Gcaminho( Grafo grafo, float custo[], int s, int f);
#endif	// CAMINHO_H

