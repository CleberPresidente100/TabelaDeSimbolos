

#ifndef TABELA_TOKENS
	#define TABELA_TOKENS 1
		
	void AdicionarLexemaListaTokens(Lexemas lexema);
	void ProcurarLexemaListaTokens(Lexemas lexema);
	void ModificarLexemaListaTokens(Lexemas lexema);
	void ExcluirLexemaListaTokens(Lexemas lexema);
	void LiberarMemoriaTabelaTokens();
	Tokens* GetTabelaTokens();
	Tokens* CriaNovoToken(Lexemas lexema);
	
#endif	


