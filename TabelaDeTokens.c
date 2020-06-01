
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Bibliotecas.h"


Tokens *listaTokens = NULL;



void AdicionarLexemaListaTokens(Lexemas lexema)
{
	Tokens *novoToken;
	
	// Aloca Espaço na Memória para o Token
	novoToken = CriaNovoToken(lexema);
	
	
	// Verifica se a Lista está Vazia.
	if(listaTokens == NULL)
	{
		
		//listaTokens = 
		return;
	}

	while(listaTokens->Proximo != NULL)
	{
		listaTokens++;
	}

	return;
}



void ProcurarLexemaListaTokens(Lexemas lexema)
{
}



void ModificarLexemaListaTokens(Lexemas lexema)
{
}



void ExcluirLexemaListaTokens(Lexemas lexema)
{
}



Tokens* GetTabelaTokens()
{
	return listaTokens;
}



void LiberarMemoriaTabelaTokens()
{
	free(listaTokens);
}



Tokens* CriaNovoToken(Lexemas lexema)
{
	Tokens* novoToken;
	
	novoToken = calloc(sizeof(Tokens));
	
	novoToken.Lexema.Lexema = calloc(SizeOf(lexema.Lexema) + 1);	
	strcpy(novoToken.Lexema.Lexema, lexema.Lexema);	
	
	novoToken.Lexema.LexemaName.Id = lexema.LexemaName.Id;
	novoToken.Lexema.LexemaName.Name = lexema.LexemaName.Name;
	
	novoToken.Lexema.LexemaType.Id = lexema.LexemaType.Id;
	novoToken.Lexema.LexemaType.Name = lexema.LexemaType.Name;
	
	novoToken.Anterior = NULL;
	novoToken.Proximo = NULL;
	
	return novoToken;
}



	
	

