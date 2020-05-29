
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constantes.h"
#include "EstruturasTipos.h"

#include "Arquivos.h"
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"
#include "PalavrasReservadas.h"

#define TAMANHO_DO_BUFFER 100

#define LINHA_INICIAL 1
#define COLUNA_INICIAL 0



void RealizarAnaliseLexica()
{
	unsigned int linha = LINHA_INICIAL;
	unsigned int coluna = COLUNA_INICIAL;
	
	int indice = 0;
	char caractereLido[] = {0, 0, 0};
	
	Tokens tokenSimbolo;
	char tokenLido[TAMANHO_DO_BUFFER];
	
	
	LimparString(&tokenLido[0]); // Inicializa Vetor	
	caractereLido[0] = LerCaractereDoArquivo(); // Efetua a Leitura do Primeiro Caractere do Arquivo
	
	
	// Looping para Ler o Arquivo at� chegar ao seu fim.
	do
	{
		coluna++;		
		caractereLido[1] = LerCaractereDoArquivo(); // Efetua a Leitura do Pr�ximo Caractere do Arquivo		
		
		// Verifica se o Caractere � um S�mbolo		
		tokenSimbolo = ProcurarSimbolo(&caractereLido[0]); 
		if(tokenSimbolo.Token != NULL)
		{
			ProcessaTokenLido(&tokenLido[0]); // Se for um S�mbolo, Processa o Token existente antes do S�mbolo.
			ProcessaTokenSimboloLido(tokenSimbolo); // Agora, Processa o S�mbolo.
			
			LimparString(&tokenLido[0]); // Limpa Token Lido					
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor
			
			// Caso o S�mbolo seja Composto � necess�rio Apagar o Segundo Caractere tamb�m.
			if(SizeOf(tokenSimbolo.Token) > 1)
			{
				coluna++;
				DeslocaVetor(&caractereLido[0]);
			}
			
			indice = 0; // Reinicia �ndice
			continue; // Continua Processo de Leitura
		}
				
		
		// Verifica se chegou ao final de um Token
		if(
			(caractereLido[0] == ' ')  ||
			(caractereLido[0] == '\n') ||
			(caractereLido[0] == '\r') ||
			(caractereLido[0] == EOF)
		  )
		{
			// Caso Nova Linha, Atualiza Contadores de Linha e Coluna
			if(
				(caractereLido[0] == '\n') ||
				(caractereLido[0] == '\r')
			)
			{
				linha++;
				coluna = COLUNA_INICIAL;
				
				// Limpa Buffer de Caractere Lido
				if(
					(caractereLido[1] == '\n') ||
					(caractereLido[1] == '\r')
				)
				{
					DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor
				}
			}
			
			
			ProcessaTokenLido(&tokenLido[0]); // Processa o Token
			
			LimparString(&tokenLido[0]); // Limpa Token Lido
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor						
			indice = 0; // Reinicia �ndice
			continue; // Continua Processo de Leitura
		}
		
		
		tokenLido[indice] = caractereLido[0]; // Adiciona Caractere ao Token Lido
		DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor
		indice++; // Incrementa indice
		
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
	Tokens token;
	
	token = ProcurarPalavraReservada(string);
	
	if(token.Token == NULL)
		printf("\n\n Token n�o Encontrado ! \n\n");
	else
		printf("\n\n Token = %s | TokenName = %s | TokenType = %s \n\n", token.Token, token.TokenName.Name, token.TokenType.Name);
}



void ProcessaTokenLido(char *string)
{
	Tokens token;
		
	// Verifica se a String é uma string vazia.
	if(SizeOf(string) > 0)
	{
		// Verifica se o Token é uma Palavra Reservada
		token = ProcurarPalavraReservada(string);
		if(token.Token == NULL)
		{	
			// Verifica se o Token é um Identificador Válido
			if(VerificarIdentificador(string))
			{				
				token = CriarTokenIdentificador(string); // Cria um Token Identificador
			}
			else
			{
				token = CriarTokenInvalido(string); // Cria um Token Inválido
				// Não sendo, Adiciona um Erro na Tabela de Erros
			}
		}
		
		// Adiciona o Token na Tabela de Tokens
	}
	
	
	return;
}



void ProcessaTokenSimboloLido(Tokens token)
{
		
	// Adiciona o Token na Tabela de Tokens
	
	
	return;
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









