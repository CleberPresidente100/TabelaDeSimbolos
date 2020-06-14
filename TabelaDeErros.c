

#include "Bibliotecas.h"


Erros *listaErros = NULL;



void AdicionarLexemaListaErros(Lexemas* lexema, unsigned int linha, unsigned int coluna, char* MensagemErro)
{
	return;
}



Erros* GetTabelaErros()
{
	return listaErros;
}



void LiberarMemoriaTabelaErros()
{
	free(listaErros);	
}
	
	
	
	




