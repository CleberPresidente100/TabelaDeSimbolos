

#ifndef TABELA_TOKENS
	#define TABELA_TOKENS 1
		
	void AdicionarLexemaListaTokens(Lexemas* lexema);
	Tokens* ProcurarLexemaListaTokens(Lexemas* lexema);
	void ModificarLexemaListaTokens(Lexemas* lexemaAModificar, Lexemas* lexemaNovo);
	void ExcluirLexemaListaTokens(Lexemas* lexema);
	void LiberarMemoriaTabelaTokens();
	Tokens* GetTabelaTokens();
	Tokens* CriaNovoToken(Lexemas* lexema);
	
#endif	


