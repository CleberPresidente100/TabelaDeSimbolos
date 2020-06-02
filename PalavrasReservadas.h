

#ifndef PALAVRAS_RESERVADAS
	#define PALAVRAS_RESERVADAS 1
		
	void CriarDicionario();
	Lexemas ProcurarSimbolo(char *string);
	Lexemas ProcurarPalavraReservada(char *string);
	Lexemas CriarLexemaIdentificador(char *string);
	boolean VerificarIdentificador(char *string);
	Lexemas CriarLexemaInvalido();
	Lexemas CriarLexemaNulo();

#endif


