
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas.h"


#define TAMANHO_DO_BUFFER 100

#define LINHA_INICIAL 1
#define COLUNA_INICIAL 0



void RealizarAnaliseLexica()
{
	unsigned int contador;
	
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
	
	
	LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Inicializa Vetor	
	lexemaSimbolo = CriarLexemaNulo(); // Inicializa Estrutura
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
			
			// Caso o Símbolo seja um PONTO é necessário verificar se o Lexema é um Número
			if(lexemaSimbolo.LexemaId == T_Ponto)
			{
				if(EhUmNumero(&lexemaLido[0]) && EhUmNumero(&caractereLido[1]))
				{
					lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Lexema Lido
					DeslocaVetor(&caractereLido[0]);
					indice++;
					continue;
				}
			}
			
			
			// Caso o Símbolo seja uma ASPA DUPLA significa que o Lexema é uma CONSTANTE TEXTO
			if(lexemaSimbolo.LexemaId == T_AspaDupla)
			{
				ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Processa o Lexema existente antes do Símbolo.
				AdicionarLexemaListaTokens(&lexemaSimbolo, linha, coluna); // Agora, Processa o Símbolo.								
				LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Limpa Lexema Lido
				indice = 0;
				
				lexemaLido[indice++] = caractereLido[0];
				DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
				
				// Efetua a Leitura da Constante Texto Inteira
				for(contador = 0; contador < TAMANHO_DO_BUFFER; contador++)
				{
					coluna++;
					caractereLido[1] = LerCaractereDoArquivo(); // Efetua a Leitura do Próximo Caractere do Arquivo
					
					lexemaSimbolo.LexemaId = ProcurarSimbolo(&caractereLido[0]);					
					if(lexemaSimbolo.LexemaId == T_AspaDupla)
					{
						ProcessaLexemaLido(&lexemaLido[0], linha, coluna);
						AdicionarLexemaListaTokens(&lexemaSimbolo, linha, coluna);
						LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER);
						DeslocaVetor(&caractereLido[0]);
						indice = 0;
						break;
					}
					
					lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Lexema Lido
					DeslocaVetor(&caractereLido[0]);
					indice++; // Incrementa Índice
				}
				
				continue;
			}
			
			
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Se for um Símbolo, Processa o Lexema existente antes do Símbolo.
			AdicionarLexemaListaTokens(&lexemaSimbolo, linha, coluna); // Agora, Processa o Símbolo.
			LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Limpa Lexema Lido					
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
			(caractereLido[0] == '\t') ||
			(caractereLido[0] == '\n') ||
			(caractereLido[0] == '\r') ||
			(caractereLido[0] == NULO) ||
			(caractereLido[0] == EOF)
		  )
		{
			// Caso Nova Linha, Atualiza Contadores de Linha e Coluna
			if(
				(caractereLido[0] == '\n') && (caractereLido[1] == '\r') ||
				(caractereLido[0] == '\r') && (caractereLido[1] == '\n')
			)
			{
				linha++;
				coluna = COLUNA_INICIAL;
				DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura				
			}
			else if (caractereLido[0] == '\n')
			{
				linha++;
				coluna = COLUNA_INICIAL;			
			}
			
			
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Processa o Lexema			
			LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Limpa Lexema Lido
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
			indice = 0; // Reinicia Índice
			continue; // Continua Processo de Leitura
		}
						
		
		lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Lexema Lido
		DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
		indice++; // Incrementa Índice
		
	} while(caractereLido[0] != EOF && caractereLido[1] != EOF);
	
}



void ProcessaLexemaLido(char *string, unsigned int linha, unsigned int coluna)
{
	Lexemas lexema;
	
	lexema = CriarLexemaNulo(); // Inicializa Lexema
		
	// Verifica se a String é uma string vazia.
	if(SizeOf(string) > 0)
	{		
		// Verifica se o Lexema é uma Palavra Reservada
		lexema.LexemaId = ProcurarPalavraReservada(string);
		if(lexema.LexemaId != NULO)
		{
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
			
		// Verifica se o Lexema é uma Constante de Texto
		if(EhConstanteTexto(string))
		{
			string++; // Remove Aspa Dupla
			lexema = CriarLexemaConstanteTexto(string); // Cria um Lexema Constante de Texto
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
			
		// Verifica se o Lexema é um Identificador Válido
		if(EhIdentificadorString(string))
		{
			lexema = CriarLexemaIdentificadorString(string); // Cria um Lexema Identificador String
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Verifica se o Lexema é um Número
		if(EhIdentificadorNumerico(string))
		{
			lexema = CriarLexemaIdentificadorNumerico(string); // Cria um Lexema Identificador Numerico
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Se chegou aqui é porque o Lexema Não é Reconhecido pela Gramática (Lexema Inválido)
		lexema = CriarLexemaInvalido(string); // Cria um Lexema Identificador Invalido
		AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
		AdicionarLexemaListaErros(&lexema, linha, coluna, "Erro -> Lexema Inválido"); // Adiciona um Erro na Tabela de Erros
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
	
	if(string != NULL)
	{
		while(*string != 0)
		{
			string++;
			contador++;
		}
	}
	
	return contador;
}



void LimparString(char *string, unsigned int tamanho)
{
	unsigned int contador;
	
	if(string != NULL)
	{
		if(tamanho > 0)
		{
			for(contador = 0; contador < tamanho; contador++)
			{
				*string = 0;
				string++;
			}
			
			return;
		}
		
		
		while(*string != 0)
		{
			*string = 0;
			string++;
		}
	}
	
}









