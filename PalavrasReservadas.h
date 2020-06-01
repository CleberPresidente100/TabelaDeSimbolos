

#ifndef PALAVRAS_RESERVADAS
	#define PALAVRAS_RESERVADAS 1
		
	void CriarDicionario();
	Lexemas ProcurarSimbolo(char *string);
	Lexemas ProcurarPalavraReservada(char *string);
	Lexemas CriarTokenIdentificador(char *string);
	boolean VerificarIdentificador(char *string);
	Lexemas CriarTokenInvalido();

#endif


