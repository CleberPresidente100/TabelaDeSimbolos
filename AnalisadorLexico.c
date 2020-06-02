
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas.h"


#define TAMANHO_DO_BUFFER 100

#define LINHA_INICIAL 1
#define COLUNA_INICIAL 0



void RealizarAnaliseLexica()
{
	unsigned int linha = LINHA_INICIAL;
	unsigned int coluna = COLUNA_INICIAL;
	
	int indice = 0;
	char caractereLido[] = {0, 0, 0};
	
	Lexemas lexemaSimbolo;
	char lexemaLido[TAMANHO_DO_BUFFER];
	
	
	LimparString(&lexemaLido[0]); // Inicializa Vetor	
	caractereLido[0] = LerCaractereDoArquivo(); // Efetua a Leitura do Primeiro Caractere do Arquivo
	
	
	// Looping para Ler o Arquivo at� chegar ao seu fim.
	do
	{
		coluna++;		
		caractereLido[1] = LerCaractereDoArquivo(); // Efetua a Leitura do Pr�ximo Caractere do Arquivo		
		
		// Verifica se o Caractere � um S�mbolo		
		lexemaSimbolo = ProcurarSimbolo(&caractereLido[0]); 
		if(lexemaSimbolo.Lexema != NULL)
		{
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Se for um S�mbolo, Processa o Lexema existente antes do S�mbolo.
			AdicionarLexemaListaTokens(&lexemaSimbolo); // Agora, Processa o S�mbolo.
			
			LimparString(&lexemaLido[0]); // Limpa Lexema Lido					
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor
			
			// Caso o S�mbolo seja Composto � necess�rio Apagar o Segundo Caractere tamb�m.
			if(SizeOf(lexemaSimbolo.Lexema) > 1)
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
			
			
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Processa o Token
			
			LimparString(&lexemaLido[0]); // Limpa Token Lido
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor						
			indice = 0; // Reinicia �ndice
			continue; // Continua Processo de Leitura
		}
		
		
		lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Token Lido
		DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda no Vetor
		indice++; // Incrementa �ndice
		
	} while(caractereLido[0] != EOF && caractereLido[1] != EOF);
	
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



void ProcessaLexemaLido(char *string, unsigned int linha, unsigned int coluna)
{
	Lexemas lexema;
		
	// Verifica se a String � uma string vazia.
	if(SizeOf(string) > 0)
	{
		// Verifica se o Token � uma Palavra Reservada
		lexema = ProcurarPalavraReservada(string);
		if(lexema.Lexema == NULL)
		{	
			// Verifica se o Token � um Identificador V�lido
			if(VerificarIdentificador(string))
			{				
				lexema = CriarLexemaIdentificador(string); // Cria um Token Identificador
			}
			else
			{
				lexema = CriarLexemaInvalido(); // Cria um Token Inv�lido				
				AdicionarLexemaListaErros(lexema, linha, coluna, "Erro"); // N�o sendo, Adiciona um Erro na Tabela de Erros
			}
		}
				
		AdicionarLexemaListaTokens(&lexema); // Adiciona o Lexema na Tabela de Tokens
	}	
	
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









