//=====================================================
// Arquivo: main.c 
//
// Autores: Mário Luiz Rodrigues Oliveira 
//          Walace de Almeida Rodrigues
// Data: 01/06/2016
// Disciplina: Programacao II
// Atividade: Gabarito trabalho1
//=====================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"
#include "caminho.h"

typedef struct entrada
{
	char linha[181], comando[21], nome_arq[121];
	int par1, par2;
} *Entrada;

void pega_linha (Entrada);
void pega_comando(Entrada); 
void pega_parametros(Entrada, int);
void pega_nome_arquivo (Entrada);

//============================
// Main
//============================
int main ()
{
	Entrada dados = (Entrada) malloc (sizeof (struct entrada));
	Grafo G;
	int v, a, cont;
	
	pega_linha(dados);
	pega_comando (dados);
	
	while (strcmp("SAIR",dados->comando)!= 0)
	{
		if (strcmp("LER",dados->comando) == 0)
		{
			pega_nome_arquivo (dados);
			G = GGcarregaGrafo(dados->nome_arq);
		}
		else if (strcmp("IMPRIMIR",dados->comando)== 0)
		{
			printf ("G(V,A)::= { \n");
			printf ("V= { ");
			cont=0;
			for (v=GVprimeiroVertice(G); v!=0; v=GVproximoVertice(G,v))
			{
				if (cont==0)
				{
					printf ("%d", v);
				}	
				else if (cont == 5)
				{
					printf (",\n     ");
					printf ("%d", v);
					cont = 0;
				}
				else
				{
					printf (", %d", v);
				}
				cont++;
				
			}
			printf (" }\n");
			
			printf ("A= { ");
			cont=0;
			for (a=GAprimeiraAresta(G); a!=0; a=GAproximaAresta(G,a))
			{
				if (cont==0)
				{
					printf ("(%d,%d)", GValfa(G,a), GVomega(G,a));
				}	
				else if (cont == 5)
				{
					printf (",\n     ");
					printf ("(%d,%d)", GValfa(G,a), GVomega(G,a));
					cont = 0;
				}
				else
				{
					printf (", (%d,%d)", GValfa(G,a), GVomega(G,a));
				}
				cont++;
			}
			printf (" }\n");
			printf (" }\n");
		}
		else if (strcmp("EXISTEIDVERT",dados->comando)== 0) 
		{
			pega_parametros(dados, 1);
			if (GBexisteIdVertice(G, dados->par1))
				printf ("SIM \n");
			else
				printf ("NAO \n");
		}
		
		else if (strcmp("EXISTEIDAREST",dados->comando)== 0) 
		{
			pega_parametros(dados, 1);
			if (GBexisteIdAresta(G, dados->par1))
				printf ("SIM \n");
			else
				printf ("NAO \n");
		}
		
		else if (strcmp("EXISTEIDARESTDIR",dados->comando)== 0) 
		{
			pega_parametros(dados, 2);
			if (GBexisteArestaDir(G, dados->par1, dados->par2))
				printf ("SIM \n");
			else
				printf ("NAO \n");
		}
		
		else if (strcmp("PEGAARESTA",dados->comando)== 0) 
		{
			pega_parametros(dados, 2);
			printf ("%d\n",GApegaAresta(G, dados->par1, dados->par2));
					
		}
		
		
		else if (strcmp("NUMEROVERT",dados->comando)== 0) 
		{
			printf ("%d\n",GInumeroVertices(G));
					
		}
		
		else if (strcmp("NUMEROARESTA",dados->comando)== 0) 
		{
			printf ("%d\n",GInumeroArestas(G));
					
		}
		
		else if (strcmp("ELACO",dados->comando)== 0) 
		{
			pega_parametros(dados, 1);
			if (GBarestaLaco(G, dados->par1))
				printf ("SIM \n");
			else
				printf ("NAO \n");
		}
		
		
		else if (strcmp("VIZINHO",dados->comando)== 0) 
		{
			pega_parametros(dados, 2);
			printf ("%d\n",GVvizinho(G, dados->par1, dados->par2));
					
		}
		
		else if (strcmp("PEGAGRAU",dados->comando)== 0) 
		{
			pega_parametros(dados, 1);
			printf ("%d\n", GIpegaGrau(G, dados->par1));
		}
		
		else if (strcmp("PRIMAENTRADA",dados->comando)== 0) 
		{
			pega_parametros(dados, 1);
			printf ("%d\n", GAprimaEntrada(G, dados->par1));
		}
		
		else if (strcmp("PRIMASAIDA",dados->comando)== 0) 
		{
			pega_parametros(dados, 1);
			printf ("%d\n", GAprimaSaida(G, dados->par1));
		}
		
		else if (strcmp("COM",dados->comando)== 0) 
		{
			//elimina comentario
		}
		
		else
		{
			printf ("ERRO!");
			exit(1);
		}
		pega_linha(dados);
		pega_comando (dados);
	}
	
	//GGdestroiGrafo(G);
	return 0;
}

//============================
// PegaLinha
//============================

void pega_linha(Entrada dados)
{
	if (fgets(dados->linha, 181, stdin)==NULL)
		strcpy (dados->linha, "SAIR");
}

//============================
// PegaComando
//============================
void pega_comando(Entrada dados)
{
	sscanf (dados->linha,"%s", dados->comando); //trata comando com no maximo 20 caracteres
}


//============================
// PegaParametros
//============================
void pega_parametros(Entrada dados, int i)
{
	switch (i)
	{
		case 1: sscanf (dados->linha, "%s%d", dados->comando, &(dados->par1));
				break;
		case 2: sscanf (dados->linha, "%s%d%d", dados->comando,&(dados->par1), &(dados->par2));
				break;
	}

}	


//============================
// PegaNomeArquivo
//============================
void pega_nome_arquivo (Entrada dados)
{
	sscanf(dados->linha, "%s%s", dados->comando, dados->nome_arq);
}