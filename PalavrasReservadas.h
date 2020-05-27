

#ifndef PALAVRAS_RESERVADAS
	#define PALAVRAS_RESERVADAS 1
		
	void CriarDicionario();
	TokenTypes ProcurarSimbolo(char *string);
	TokenTypes ProcurarPalavraReservada(char *string);
	TokenTypes CriarTokenIdentificador(char *string);
	boolean VerificarIdentificador(char *string);
	TokenTypes CriarTokenInvalido(char *string);

#endif


