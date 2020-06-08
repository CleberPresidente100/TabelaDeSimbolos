

#ifndef TABELA_TOKENS
	#define TABELA_TOKENS 1
		
	void AdicionarLexemaListaTokens(Lexemas* lexema, unsigned int linha, unsigned int coluna);
	Tokens* ProcurarTokenListaTokens(unsigned int tokenId);
	void ModificarTokenListaTokens(unsigned int idTokenAModificar, Lexemas* lexemaNovo);
	void ExcluirTokenListaTokens(unsigned int tokenId);
	void LiberarMemoriaTabelaTokens();
	Tokens* GetTabelaTokens();
	Tokens* CriaNovoToken(Lexemas* lexema);
	
#endif	


