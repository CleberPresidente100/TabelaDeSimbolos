

#ifndef PALAVRAS_RESERVADAS
	#define PALAVRAS_RESERVADAS 1
		
	void CriarDicionario();
	Tokens ProcurarSimbolo(char *string);
	Tokens ProcurarPalavraReservada(char *string);
	Tokens CriarTokenIdentificador(char *string);
	boolean VerificarIdentificador(char *string);
	Tokens CriarTokenInvalido(char *string);

#endif


