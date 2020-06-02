
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Bibliotecas.h"


Tokens *listaTokens = NULL;



void AdicionarLexemaListaTokens(Lexemas* lexema)
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



Tokens* ProcurarLexemaListaTokens(Lexemas* lexema)
{
	Tokens* listaTokensAuxiliar;
	
	// Verifica se a Lista está Vazia.
	if(listaTokens != NULL)
	{		
		listaTokensAuxiliar = listaTokens;
		
		while(listaTokensAuxiliar)
		{
			if(listaTokensAuxiliar->Lexema.LexemaId == lexema->LexemaId)
			{
				return listaTokensAuxiliar;
			}
			
			listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
		}
	}

	return NULL;
}



void ModificarLexemaListaTokens(Lexemas* lexemaAModificar, Lexemas* lexemaNovo)
{
	Tokens* token;
	
	token = ProcurarLexemaListaTokens(lexemaAModificar);
	
	if(token != NULL)
	{
		token->Lexema.Lexema = lexemaNovo->Lexema;
		token->Lexema.LexemaId = lexemaNovo->LexemaId;
		token->Lexema.LexemaName.Id = lexemaNovo->LexemaName.Id;
		token->Lexema.LexemaName.Name = lexemaNovo->LexemaName.Name;
		token->Lexema.LexemaType.Id = lexemaNovo->LexemaType.Id;
		token->Lexema.LexemaType.Name = lexemaNovo->LexemaType.Name;
		return;
	}
	
	return;
}



void ExcluirLexemaListaTokens(Lexemas* lexema)
{
	Tokens* token;
	
	token = ProcurarLexemaListaTokens(lexema);
	
	if(token != NULL)
	{
		if(token->Anterior)
		{
			token->Anterior->Proximo = token->Proximo;
			listaTokens = token;
		}
		
		if(token->Proximo)
		{
			token->Proximo->Anterior = token->Anterior;
		}
		
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
	Tokens* novoToken;
	
	novoToken = calloc(1, sizeof(Tokens));
	
	novoToken->Lexema.Lexema = calloc(1, SizeOf(lexema->Lexema) + sizeof(char));	
	strcpy(novoToken->Lexema.Lexema, lexema->Lexema);	
	
	novoToken->Lexema.LexemaName.Id = lexema->LexemaName.Id;
	novoToken->Lexema.LexemaName.Name = lexema->LexemaName.Name;
	
	novoToken->Lexema.LexemaType.Id = lexema->LexemaType.Id;
	novoToken->Lexema.LexemaType.Name = lexema->LexemaType.Name;
	
	novoToken->Anterior = NULL;
	novoToken->Proximo = NULL;
	
	return novoToken;
}



	
	

