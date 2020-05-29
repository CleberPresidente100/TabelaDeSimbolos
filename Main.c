
#include <stdio.h>
#include <stdlib.h>

#include "Constantes.h"
#include "EstruturasTipos.h"

#include "Arquivos.h"
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"
#include "PalavrasReservadas.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	char nomeDoArquivo[256];
	boolean erroArquivo = FALSE;
	
	
	printf("\n Inicio\n");
	CriarDicionario();
	printf("\n\n Fim\n");
	
	
	/*printf("\n\n Digite o nome do arquivo: ");
	scanf("%s", &nomeDoArquivo);
	erroArquivo = AbrirArquivo(&nomeDoArquivo[0]);*/
	erroArquivo = AbrirArquivo("teste.txt");
	if(erroArquivo == FALSE)
	{
		printf("\n\n Não foi possível Abrir o Arquivo.");
	}
	else
	{
		printf("\n\n Arquivo Aberto com Sucesso.");
	}
	
	
	
	
	
	RealizarAnaliseLexica();
	
	
	
	
	
	
	erroArquivo = FecharArquivo();
	if(erroArquivo == TRUE)
	{
		printf("\n\n Arquivo Fechado com Sucesso.");
	}
	else
	{
		printf("\n\n Não foi possível Fechar o Arquivo.");
	}
	
	printf("\n\n\n");
	return 0;
}
