

#ifndef ANALISADOR_LEXICO
	#define ANALISADOR_LEXICO 1
	
	
	void RealizarAnaliseLexica();
	void LimparString(char *string);
	void DeslocaVetor(char *string);
	unsigned int SizeOf(char *string);
	void ProcessaTokenLido(char *string);
	void ProcessaTokenSimboloLido(TokenTypes *token);
	
#endif	


