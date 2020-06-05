

#ifndef PALAVRAS_RESERVADAS
	#define PALAVRAS_RESERVADAS 1
		
	unsigned int IdentificarLexema(char* string);
	unsigned int ProcurarSimbolo(char *string);
	unsigned int ProcurarPalavraReservada(char *string);
	Lexemas CriarLexemaIdentificador(char *string);
	unsigned int CriarLexemaInvalido();
	unsigned int CriarLexemaNulo();
	boolean VerificarIdentificador(char *string);
	boolean EhUmSimboloComposto(unsigned int lexemaId);

#endif


