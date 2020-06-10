

#ifndef ANALISADOR_LEXICO
	#define ANALISADOR_LEXICO 1
		
	void LimparString(char *string);
	void DeslocaVetor(char *string);
	unsigned int SizeOf(char *string);
	void RealizarAnaliseLexica();
	void ProcessaLexemaLido(char *string, unsigned int linha, unsigned int coluna);
	void AdicionaLexemaListaTokens(Lexemas lexema, Tokens *listaTokens);
	void AdicionaLexemaListaErros(Lexemas lexema, Erros *listaErros, unsigned int linha, unsigned int coluna, char* MensagemErro);
	unsigned int SizeOf(char *string);
	
#endif	


