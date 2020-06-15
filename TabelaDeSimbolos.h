

#ifndef TABELA_DE_SIMBOLOS
	#define TABELA_DE_SIMBOLOS 1
	
	TabelaSimbolos* GetTabelaSimbolos();	
	void LiberarMemoriaTabelaSimbolos();
	TabelaSimbolos CriarSimboloNulo();
	TabelaSimbolos* AdicionarSimboloTabelaDeSimbolos(TabelaSimbolos *tabelaDeSimbolos, char escopo);
	TabelaSimbolos* CriaNovoSimbolo(TabelaSimbolos *simbolo);
	
#endif


