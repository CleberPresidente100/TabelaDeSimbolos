
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constantes.h"
#include "EstruturasTipos.h"

#include "Arquivos.h"
#include "AnalisadorLexico.h"
#include "PalavrasReservadas.h"

#define TAMANHO_DO_BUFFER 100


void RealizarAnaliseLexica()
{
	int indice = 0;
	char caractereLido[] = {0, 0, 0};
	char tokenLido[TAMANHO_DO_BUFFER];
	TokenTypes tokenSimbolo;
	
	// Inicializa Vetor
	LimparString(&tokenLido[0]);
	
	// Efetua a Leitura dos Dois Próximos Caracteres do Arquivo
	caractereLido[0] = LerCaractereDoArquivo();
	
	// Efetua a Leitura do Arquivo até chegar ao seu fim.
	do
	{
		// Efetua a Leitura do Próximo Caractere do Arquivo
		caractereLido[1] = LerCaractereDoArquivo();			
		
		
		// Verifica se o Caractere é um Símbolo
		tokenSimbolo = AnalisaSimbolo(&caractereLido[0]);		
		if(tokenSimbolo.Token != NULL)
		{
			// Se for um Símbolo, Processa o Token existente antes do Símbolo.
			AnalisaTokenLido(&tokenLido[0]);
			
			// Agora, Processa o Símbolo
			// Envia o tokenSimbolo para algum lugar.
			
			// Limpa Token Lido
			LimparString(&tokenLido[0]);
		
			// Efetua o Deslocamento para a Esquerda no Vetor
			DeslocaVetor(&caractereLido[0]);
			
			// Caso o Símbolo seja Composto é necessário Apagar o Segundo Caractere também.
			if(SizeOf(tokenSimbolo.Token) > 1)
			{
				DeslocaVetor(&caractereLido[0]);
			}
			
			// Reinicia Índice
			indice = 0;
			
			// Continua Processo de Leitura
			continue;
			
			
		}
		
		
		// Verifica se chegou ao final de um Token
		if(
			(caractereLido[0] == ' ')  ||
			(caractereLido[0] == '\n') ||
			(caractereLido[0] == '\r') ||
			(caractereLido[0] == EOF)
		  )
		{
			// Processa o Token
			AnalisaTokenLido(&tokenLido[0]);
			
			// Limpa Token Lido
			LimparString(&tokenLido[0]);
		
			// Efetua o Deslocamento para a Esquerda no Vetor
			DeslocaVetor(&caractereLido[0]);
			
			// Reinicia Índice
			indice = 0;
			
			// Continua Processo de Leitura
			continue;	
		}
		
		
		// Verifica se o Caractere é um Token Símbolo.
		// Pois isto também indica o final de um Token.
		/*if()
		{
		}*/
		
		
		
		
		
		// Adiciona Caractere ao Token Lido
		tokenLido[indice] = caractereLido[0];
		
		// Efetua o Deslocamento para a Esquerda no Vetor
		DeslocaVetor(&caractereLido[0]);
		
		// Incrementa indice
		indice++;
		
	} while(caractereLido[0] != EOF);
	
}



void LimparString(char *string)
{
	int indice = 0;
	
	for(indice = 0; indice < TAMANHO_DO_BUFFER; indice++)
	{
		*string = 0;
		string++;
	}
	
}



void AnalisaTokenLido(char *string)
{
	TokenTypes token;
	
	token = ProcurarPalavraReservada(string);
	
	if(token.Token == NULL)
		printf("\n\n Token não Encontrado ! \n\n");
	else
		printf("\n\n Token = %s | TokenName = %s | TokenType = %s \n\n", token.Token, token.TokenName, token.TokenType);
}



TokenTypes AnalisaSimbolo(char *string)
{
	TokenTypes token;
	
	token = ProcurarSimbolo(string);
	
	if(token.Token == NULL)
		printf("\n\n Token não Encontrado ! \n\n");
	else
		printf("\n\n Token = %s | TokenName = %s | TokenType = %s \n\n", token.Token, token.TokenName, token.TokenType);
	
	return token;
}



void DeslocaVetor(char *string)
{
	*string = *(string + 1);
	*(string + 1) = 0;
}



unsigned int SizeOf(char *string)
{
	unsigned int contador = 0;
	
	while(*string != 0)
	{
		string++;
		contador++;
	}
	
	return contador;
}





