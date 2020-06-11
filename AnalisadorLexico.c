
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
	char caractereLido[] = {0, 0, 0}; // Este � o Buffer de Leitura.
	// A primeira posi��o serve para efetuar a leitura de caracteres simples.
	// A segunda posi��o serve �nica e exclusivamente para identificar S�mbolos Compostos (formados por dois caracteres).
	//		Logo, a primeira posi��o armazena o primeiro caractere do S�mbolo Composto,
	//		e a segunda posi��o armazena o segundo caractere do S�mbolo Composto.
	// A terceira posi��o � apenas um caractere "Fim de String".
	
	Lexemas lexemaSimbolo;	
	char lexemaLido[TAMANHO_DO_BUFFER];
	
	
	LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Inicializa Vetor	
	lexemaSimbolo = CriarLexemaNulo(); // Inicializa Estrutura
	caractereLido[0] = LerCaractereDoArquivo(); // Efetua a Leitura do Primeiro Caractere do Arquivo
	
	
	// Looping para Ler o Arquivo at� chegar ao seu fim.
	do
	{
		coluna++;		
		caractereLido[1] = LerCaractereDoArquivo(); // Efetua a Leitura do Pr�ximo Caractere do Arquivo
		
				
		// Verifica se o Caractere � um S�mbolo		
		lexemaSimbolo.LexemaId = ProcurarSimbolo(&caractereLido[0]); 
		if(lexemaSimbolo.LexemaId != NULO)
		{
			
			// Caso o S�mbolo seja um PONTO � necess�rio verificar se o Lexema � um N�mero
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
			
			
			// Caso o S�mbolo seja uma ASPA DUPLA significa que o Lexema � uma CONSTANTE TEXTO
			if(lexemaSimbolo.LexemaId == T_AspaDupla)
			{
				ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Processa o Lexema existente antes do S�mbolo.
				AdicionarLexemaListaTokens(&lexemaSimbolo, linha, coluna); // Agora, Processa o S�mbolo.								
				LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Limpa Lexema Lido
				indice = 0;
				
				lexemaLido[indice++] = caractereLido[0];
				DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
				
				// Efetua a Leitura da Constante Texto Inteira
				for(contador = 0; contador < TAMANHO_DO_BUFFER; contador++)
				{
					coluna++;
					caractereLido[1] = LerCaractereDoArquivo(); // Efetua a Leitura do Pr�ximo Caractere do Arquivo
					
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
					indice++; // Incrementa �ndice
				}
				
				continue;
			}
			
			
			ProcessaLexemaLido(&lexemaLido[0], linha, coluna); // Se for um S�mbolo, Processa o Lexema existente antes do S�mbolo.
			AdicionarLexemaListaTokens(&lexemaSimbolo, linha, coluna); // Agora, Processa o S�mbolo.
			LimparString(&lexemaLido[0], TAMANHO_DO_BUFFER); // Limpa Lexema Lido					
			DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
			
			// Caso o S�mbolo seja Composto � necess�rio Apagar o Segundo Caractere tamb�m.
			if(EhUmSimboloComposto(lexemaSimbolo.LexemaId))
			{
				coluna++;
				DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
			}
			
			indice = 0; // Reinicia �ndice
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
			indice = 0; // Reinicia �ndice
			continue; // Continua Processo de Leitura
		}
						
		
		lexemaLido[indice] = caractereLido[0]; // Adiciona Caractere ao Lexema Lido
		DeslocaVetor(&caractereLido[0]); // Efetua o Deslocamento para a Esquerda do Buffer de Leitura
		indice++; // Incrementa �ndice
		
	} while(caractereLido[0] != EOF && caractereLido[1] != EOF);
	
}



void ProcessaLexemaLido(char *string, unsigned int linha, unsigned int coluna)
{
	Lexemas lexema;
	
	lexema = CriarLexemaNulo(); // Inicializa Lexema
		
	// Verifica se a String � uma string vazia.
	if(SizeOf(string) > 0)
	{		
		// Verifica se o Lexema � uma Palavra Reservada
		lexema.LexemaId = ProcurarPalavraReservada(string);
		if(lexema.LexemaId != NULO)
		{
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
			
		// Verifica se o Lexema � uma Constante de Texto
		if(EhConstanteTexto(string))
		{
			string++; // Remove Aspa Dupla
			lexema = CriarLexemaConstanteTexto(string); // Cria um Lexema Constante de Texto
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
			
		// Verifica se o Lexema � um Identificador V�lido
		if(EhIdentificadorString(string))
		{
			lexema = CriarLexemaIdentificadorString(string); // Cria um Lexema Identificador String
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Verifica se o Lexema � um N�mero
		if(EhIdentificadorNumerico(string))
		{
			lexema = CriarLexemaIdentificadorNumerico(string); // Cria um Lexema Identificador Numerico
			AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
			return;
		}
		
		// Se chegou aqui � porque o Lexema N�o � Reconhecido pela Gram�tica (Lexema Inv�lido)
		lexema = CriarLexemaInvalido(string); // Cria um Lexema Identificador Invalido
		AdicionarLexemaListaTokens(&lexema, linha, coluna); // Adiciona o Lexema na Tabela de Tokens
		AdicionarLexemaListaErros(&lexema, linha, coluna, "Erro -> Lexema Inv�lido"); // Adiciona um Erro na Tabela de Erros
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









