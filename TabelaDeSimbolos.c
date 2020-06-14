

#include "Bibliotecas.h"

#define INICIO_CONTAGEM_SIMBOLO_ID 1


TabelaSimbolos *tabelaDeSimbolos = NULL;
unsigned int SimboloID = INICIO_CONTAGEM_SIMBOLO_ID;
unsigned int TamanhoListaSimbolos = 0;



TabelaSimbolos* GetTabelaSimbolos()
{
	return tabelaDeSimbolos;
}



void LiberarMemoriaTabelaSimbolos()
{
	free(tabelaDeSimbolos);
}



TabelaSimbolos CriarSimboloNulo()
{
	TabelaSimbolos tabelaSimbolos;
	
	tabelaSimbolos.Id = NULO;
	tabelaSimbolos.Tipo = NULO;
	tabelaSimbolos.ComplementoTipo = NULO;
	tabelaSimbolos.ModificadorTipo = NULO;
	tabelaSimbolos.Identificador = NULL;
	tabelaSimbolos.Endereco = NULO; //
	tabelaSimbolos.Classe = NULO;
	tabelaSimbolos.Escopo = NULO; //
	tabelaSimbolos.Parametros = NULL; //
	tabelaSimbolos.Ativa = FALSE; //
	tabelaSimbolos.Anterior = NULL;
	tabelaSimbolos.Proximo = NULL;
		
	return tabelaSimbolos;
}



void AdicionarSimboloTabelaDeSimbolos(TabelaSimbolos *simbolo, char escopo)
{
	TabelaSimbolos* novoSimbolo;
	TabelaSimbolos* tabelaDeSimbolosAuxiliar;
	
	// Aloca Espaço na Memória para o Símbolo
	novoSimbolo = CriaNovoSimbolo(simbolo);
	
	
	// Verifica se a Lista está Vazia.
	if(tabelaDeSimbolos == NULL)
	{		
		tabelaDeSimbolos = novoSimbolo;
		return;
	}
	
	tabelaDeSimbolosAuxiliar = tabelaDeSimbolos;

	while(tabelaDeSimbolosAuxiliar->Proximo != NULL)
	{
		tabelaDeSimbolosAuxiliar = tabelaDeSimbolosAuxiliar->Proximo;
	}
	
		
	novoSimbolo->Anterior = tabelaDeSimbolosAuxiliar;
	tabelaDeSimbolosAuxiliar->Proximo = novoSimbolo;

	return;
	
}



TabelaSimbolos* CriaNovoSimbolo(TabelaSimbolos *simbolo)
{
	unsigned int tamanhoString = 0;
	TabelaSimbolos* novoSimbolo;
	
	TamanhoListaSimbolos++;
	
	novoSimbolo = calloc(1, sizeof(TabelaSimbolos));
	
	novoSimbolo->Anterior = NULL;
	novoSimbolo->Proximo = NULL;	
	novoSimbolo->Id = SimboloID++;
	
	novoSimbolo->Tipo = simbolo->Tipo;
	novoSimbolo->ComplementoTipo = simbolo->ComplementoTipo;
	novoSimbolo->ModificadorTipo = simbolo->ModificadorTipo;
	novoSimbolo->Identificador = simbolo->Identificador;	
	novoSimbolo->Escopo = simbolo->Escopo;
	novoSimbolo->Classe = simbolo->Classe;
	novoSimbolo->Ativa = simbolo->Ativa;
	novoSimbolo->Parametros = simbolo->Parametros;
	
	
	//novoSimbolo->Endereco
	
		
	// Caso existam Parâmetros, adiciona os mesmos no Símbolo
//	tamanhoString = SizeOf(novoSimbolo->Parametros);
//	if(tamanhoString > 0)
//	{
//		novoSimbolo->Parametros = calloc(1, tamanhoString + sizeof(char));	
//		strcpy(novoSimbolo->Parametros, simbolo->Parametros);
//	}
	
	return novoSimbolo;
}
	
	
	
	
	
	
	
