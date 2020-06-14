

#ifndef ARQUIVO_LEXEMAS_RESERVADOS
	#define ARQUIVO_LEXEMAS_RESERVADOS 1
		
	Lexemas IdentificarLexema(char* string);
	Lexemas ProcurarSimbolo(char *string);
	Lexemas ProcurarPalavraReservada(char *string);
	Lexemas CriarLexemaIdentificadorString(char *string);
	Lexemas CriarLexemaIdentificadorNumerico(char *string);
	Lexemas CriarLexemaInvalido(char *string);
	Lexemas CriarLexemaNulo();
	boolean EhIdentificadorString(char *string);
	boolean EhIdentificadorNumerico(char *string);
	boolean EhUmSimboloComposto(unsigned int lexemaId);
	boolean EhUmNumero(char* string);
	LexemasReservados ObterLexemaReservado(unsigned int lexemaId);
	boolean EhConstanteTexto(char *string);
	Lexemas CriarLexemaConstanteTexto(char* string);

#endif


