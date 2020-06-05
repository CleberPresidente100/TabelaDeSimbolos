
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Bibliotecas.h"

#define INICIO_CONTAGEM_TOKEN_ID 1


Tokens *listaTokens = NULL;
unsigned int TokenID = INICIO_CONTAGEM_TOKEN_ID;
unsigned int TamanhoListaTokens = 0;



void AdicionarLexemaListaTokens(Lexemas* lexema, unsigned int linha, unsigned int coluna)
{
	Tokens* novoToken;
	Tokens* listaTokensAuxiliar;
	
	// Aloca Espaço na Memória para o Token
	novoToken = CriaNovoToken(lexema);
	
	
	// Verifica se a Lista está Vazia.
	if(listaTokens == NULL)
	{		
		listaTokens = novoToken;
		return;
	}
	
	listaTokensAuxiliar = listaTokens;

	while(listaTokensAuxiliar->Proximo != NULL)
	{
		listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
	}
		
	novoToken->Anterior = listaTokensAuxiliar;
	listaTokensAuxiliar->Proximo = novoToken;

	return;
}



Tokens* ProcurarTokenListaTokens(unsigned int tokenId)
{
	Tokens* listaTokensAuxiliar;
	
	// Verifica se a Lista está Vazia.
	if(listaTokens != NULL)
	{		
		listaTokensAuxiliar = listaTokens;
		
		while(listaTokensAuxiliar)
		{
			if(listaTokensAuxiliar->TokenId == tokenId)
			{
				return listaTokensAuxiliar;
			}
			
			listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
		}
	}

	return NULL;
}



void ModificarLexemaListaTokens(unsigned int idTokenAModificar, Lexemas* lexemaNovo)
{
	unsigned int tamanhoString = 0;	
	Tokens* token;
	
	token = ProcurarTokenListaTokens(idTokenAModificar);
	
	if(token != NULL)
	{
		token->Lexema.LexemaId = lexemaNovo->LexemaId;
		
		// Caso exista uma String de Identificador, adiciona a mesma no Token
		tamanhoString = SizeOf(lexemaNovo->Identificador);
		if(tamanhoString > 0)
		{
			free(token->Lexema.Identificador);
			token->Lexema.Identificador = calloc(1, tamanhoString + sizeof(char));	
			strcpy(token->Lexema.Identificador, lexemaNovo->Identificador);
		}
		
		return;
	}
	
	return;
}



void ExcluirTokenListaTokens(unsigned int tokenId)
{
	Tokens* token;
	
	token = ProcurarTokenListaTokens(tokenId);
	
	if(token != NULL)
	{		
		if(token->Anterior)
		{
			token->Anterior->Proximo = token->Proximo;			
		}
		// Caso o Token a ser Excluído seja o Primeiro da Lista
		else
		{
			listaTokens = token->Proximo;
		}
		
		
		if(token->Proximo)
		{
			token->Proximo->Anterior = token->Anterior;
		}
		
		// Caso o Token a ser Excluído seja o Último da Lista
		else
		{
			// Verifica se ele é o Único item da Lista.
			if(token->Anterior->Proximo)
			{
				token->Anterior->Proximo = NULL;
			}			
		}
		
		free(token);
		TamanhoListaTokens--;
		
		return;
	}
	
	return;
}



Tokens* GetTabelaTokens()
{
	return listaTokens;
}



void LiberarMemoriaTabelaTokens()
{
	free(listaTokens);
}



Tokens* CriaNovoToken(Lexemas* lexema)
{
	unsigned int tamanhoString = 0;
	Tokens* novoToken;
	
	TamanhoListaTokens++;
	
	novoToken = calloc(1, sizeof(Tokens));
	
	novoToken->Anterior = NULL;
	novoToken->Proximo = NULL;	
	novoToken->TokenId = TokenID++;
	novoToken->Lexema.LexemaId = lexema->LexemaId;
	
	// Caso exista uma String de Identificador, adiciona a mesma no Token
	tamanhoString = SizeOf(lexema->Identificador);	
	if(tamanhoString > 0)
	{
		novoToken->Lexema.Identificador = calloc(1, tamanhoString + sizeof(char));	
		strcpy(novoToken->Lexema.Identificador, lexema->Identificador);
	}
	
	return novoToken;
}



	
	

