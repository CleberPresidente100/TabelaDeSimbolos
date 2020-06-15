

#ifndef ANALISADOR_SINTATICO
	#define ANALISADOR_SINTATICO 1
		
	void RealizarAnaliseSintatica();
	TabelaSimbolos VerificaSeEhFuncao(Tokens** listaTokens);
	TabelaSimbolos VerificaSeEhVariavel(Tokens** listaTokens, boolean EhParametro);
	void AdicionarParametroNaListaParametros(Parametros* listaParametros, TabelaSimbolos* parametroTipo, TabelaSimbolos* enderecoParametroTabelaSimbolos);
	
#endif	


