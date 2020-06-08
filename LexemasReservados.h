

#ifndef ARQUIVO_LEXEMAS_RESERVADOS
	#define ARQUIVO_LEXEMAS_RESERVADOS 1
		
	unsigned int IdentificarLexema(char* string);
	unsigned int ProcurarSimbolo(char *string);
	unsigned int ProcurarPalavraReservada(char *string);
	Lexemas CriarLexemaIdentificador(char *string);
	Lexemas CriarLexemaInvalido();
	Lexemas CriarLexemaNulo();
	boolean VerificarIdentificador(char *string);
	boolean EhUmSimboloComposto(unsigned int lexemaId);
	boolean EhUmNumero(char* string);
	LexemasReservados ObterLexemaReservado(unsigned int lexemaId);

#endif


