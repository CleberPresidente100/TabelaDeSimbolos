
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
	char caractereLido[] = {0, 0, 0}; // Este é o Buffer de Leitura.
	// A primeira posição serve para efetuar a leitura de caracteres simples.
	// A segunda posição serve única e exclusivamente para identificar Símbolos Compostos (formados por dois caracteres).
	//		Logo, a primeira posição armazena o primeiro caractere do Símbolo Composto,
	//		e a segunda posição armazena o segundo caractere do Símbolo Composto.
	// A terceira posição é apenas um caractere "Fim de String".
	
	Lexemas lexemaSimbolo;
	char lexemaLido[TAMANHO_DO_BUFFER];
	
	
	LimparString(&lexemaLido[0]); // Inicializa Vetor	
	caractereLido[0] = LerCaractereDoArquivo(); // Efetua a Leitura do Primeiro Caractere do Arquivo
	
	
	// Looping para Ler o Arquivo até chegar ao seu fim.
	do
	{
		coluna++;		
		caractereLido[1] = LerCaractereDoArquivo(); // Efetua a Leitura do Próximo Caractere do Arquivo		
		
		// Verifica se o Caractere é um Símbolo		
		lexemaSimbolo.LexemaId = ProcurarSimbolo(&caractereLido[0]); 
		if(lexemaSimbolo.LexemaId != NULO)
		{
			
			// Caso o Símbolo seja um PONTO é necessário verificar se o Lexema é um Número Decimal
			if(lexemaSimbolo.LexemaId == T_Ponto)
			{
				if(EhUmNumero(&lexemaLido[0]))
				{
					lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Lexema Lido
					DeslocaVetor(&caractereLido[0]);
					continue;
				}
			}
			
			
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Se for um Símbolo, Processa o Lexema existente antes do Símbolo.
			AdicionarLexemaListaTokens(&lexemaSimbolo, linha, coluna); // Agora, Processa o Símbolo.
			
			LimparString(&lexemaLido[0]); // Limpa Lexema Lido					
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
			
			// Caso o Símbolo seja Composto é necessário Apagar o Segundo Caractere também.
			if(EhUmSimboloComposto(lexemaSimbolo.LexemaId))
			{
				coluna++;
				DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
			}
			
			indice = 0; // Reinicia Índice
			continue; // Continua Processo de Leitura
		}
				
		
		// Verifica se chegou ao final de um Lexema
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
					DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
				}
			}
			
			
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Processa o Lexema
			
			LimparString(&lexemaLido[0]); // Limpa Lexema Lido
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
			indice = 0; // Reinicia Índice
			continue; // Continua Processo de Leitura
		}
		
		
		lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Lexema Lido
		DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
		indice++; // Incrementa Índice
		
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
		
	// Verifica se a String é uma string vazia.
	if(SizeOf(string) > 0)
	{
		// Verifica se o Lexema é uma Palavra Reservada
		lexema.LexemaId = ProcurarPalavraReservada(string);
		if(lexema.LexemaId == NULO)
		{
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Verifica se o Lexema é um Identificador Válido
		if(VerificarIdentificador(string))
		{
			lexema = CriarLexemaIdentificador(string); // Cria um Lexema Identificador
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Verifica se o Lexema é um Número
		if(VerificarIdentificador(string))
		{
			lexema = CriarLexemaIdentificador(string); // Cria um Lexema Identificador
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Verifica se o Lexema é uma Constante
		if(VerificarIdentificador(string))
		{				
			lexema = CriarLexemaIdentificador(string); // Cria um Lexema Identificador
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
		AdicionarLexemaListaErros(&lexema, linha, coluna, "Erro -> Lexema Inválido"); // Não sendo, Adiciona um Erro na Tabela de Erros
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









