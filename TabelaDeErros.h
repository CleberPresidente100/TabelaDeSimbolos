

#ifndef TABELA_DE_ERROS
	#define TABELA_DE_ERROS 1
		
	void AdicionarLexemaListaErros(Lexemas* lexema, unsigned int linha, unsigned int coluna, char* MensagemErro);
	Erros* GetTabelaErros();
	void LiberarMemoriaTabelaErros();

#endif


