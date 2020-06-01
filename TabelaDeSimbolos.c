
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas.h"


TabelaSimbolos *tabelaDeSimbolos = NULL;



TabelaSimbolos* GetTabelaSimbolos()
{
	return tabelaDeSimbolos;
}



void LiberarMemoriaTabelaSimbolos()
{
	free(tabelaDeSimbolos);
}
	
	
	
	
	
	
	
