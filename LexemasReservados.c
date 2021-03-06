

#include "Bibliotecas.h"


#define PRIMEIRA_LETRA_MAIUSCULA_VALIDA		'A' // 65
#define ULTIMA_LETRA_MAIUSCULA_VALIDA		'Z' // 90

#define PRIMEIRA_LETRA_MINUSCULA_VALIDA		'a' // 97
#define ULTIMA_LETRA_MINUSCULA_VALIDA		'z' // 122

#define PRIMEIRO_NUMERO_VALIDO	'0' // 48
#define ULTIMO_NUMERO_VALIDO	'9' // 57

#define UNDERLINE	95


#define TIPO "Tipo"
#define COMPLEMENTO_TIPO "Complemento de Tipo"
#define MODIFICADOR_TIPO "Modificador de Tipo"
#define TIPO_PERSONALIZADO "Tipo Personalizado"
#define PALAVRA_RESERVADA "Palavra Reservada"
#define DIRETIVA "Diretiva"
#define SIMBOLO "Simbolo"
#define OPERADOR "Operador"
#define COMENTARIO "Comentario"
#define INVALIDO "Invalido"
#define CONSTANTE_TEXTO "Constante de Texto"
#define IDENTIFICADOR_STRING "Identificador String"
#define IDENTIFICADOR_NUMERICO "Identificador Numerico"



LexemasReservados dicionarioPalavrasReservadas[] =
{
	// Tipos de Vari�veis
	{.Lexema = "int",		.LexemaName = {.Name ="T_Inteiro",	.Id = T_Inteiro},	.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "char",		.LexemaName = {.Name ="T_Caractere",.Id = T_Caractere},	.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "void",		.LexemaName = {.Name ="T_Vazio",	.Id = T_Vazio},		.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "long",		.LexemaName = {.Name ="T_Longo", 	.Id = T_Longo},		.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "float",		.LexemaName = {.Name ="T_Decimal",	.Id = T_Decimal},	.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "double",	.LexemaName = {.Name ="T_Dobro",	.Id = T_Dobro},		.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	
	
	// Complementos de Tipo de Vari�vel
	{.Lexema = "short",		.LexemaName = {.Name ="T_Curto", 		.Id = T_Curto},			.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = CL_ComplementoTipo}},
	{.Lexema = "signed",	.LexemaName = {.Name ="T_Sinalizado", 	.Id = T_Sinalizado},	.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = CL_ComplementoTipo}},
	{.Lexema = "unsigned",	.LexemaName = {.Name ="T_NaoSinalizado",.Id = T_NaoSinalizado},	.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = CL_ComplementoTipo}},
	
	
	// Modificadores de Tipo de Vari�vel
	{.Lexema = "const",		.LexemaName = {.Name ="T_Constante",	.Id = T_Constante},		.LexemaType = {.Name = MODIFICADOR_TIPO, .Id = CL_ModificadorTipo}},
	{.Lexema = "volatile",	.LexemaName = {.Name ="T_Volatil", 		.Id = T_Volatil},		.LexemaType = {.Name = MODIFICADOR_TIPO, .Id = CL_ModificadorTipo}},
	{.Lexema = "register",	.LexemaName = {.Name ="T_Registrador",	.Id = T_Registrador},	.LexemaType = {.Name = MODIFICADOR_TIPO, .Id = CL_ModificadorTipo}},
	
	
	// Tipos Personalizados
	{.Lexema = "enum",		.LexemaName = {.Name ="T_Enumeracao", 	.Id = T_Enumeracao},	.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = CL_TipoPersonalizado}},
	{.Lexema = "union",		.LexemaName = {.Name ="T_Uniao", 		.Id = T_Uniao},			.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = CL_TipoPersonalizado}},
	{.Lexema = "struct",	.LexemaName = {.Name ="T_Estrutura", 	.Id = T_Estrutura},		.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = CL_TipoPersonalizado}},
	{.Lexema = "typedef",	.LexemaName = {.Name ="T_DefinicaoTipo",.Id = T_DefinicaoTipo},	.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = CL_TipoPersonalizado}},
	
	
	// Palavras Reservadas
	{.Lexema = "switch",	.LexemaName = {.Name ="T_Switch", 	.Id = T_Switch},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "case",		.LexemaName = {.Name ="T_Case", 	.Id = T_Case},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "default",	.LexemaName = {.Name ="T_Default",	.Id = T_Default},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "do",		.LexemaName = {.Name ="T_Do", 		.Id = T_Do},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "while",		.LexemaName = {.Name ="T_While", 	.Id = T_While},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "if",		.LexemaName = {.Name ="T_If", 		.Id = T_If},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "else",		.LexemaName = {.Name ="T_Else", 	.Id = T_Else},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "for",		.LexemaName = {.Name ="T_For", 		.Id = T_For},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "goto",		.LexemaName = {.Name ="T_Goto", 	.Id = T_Goto},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "break",		.LexemaName = {.Name ="T_Break", 	.Id = T_Break},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "continue",	.LexemaName = {.Name ="T_Continue", .Id = T_Continue},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	{.Lexema = "return",	.LexemaName = {.Name ="T_Return", 	.Id = T_Return},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = CL_PalavraReservada}},
	
	
	// Diretivas
	{.Lexema = "#define",	.LexemaName = {.Name ="T_Define",	.Id = T_Define},	.LexemaType = {.Name = DIRETIVA, .Id = CL_Diretiva}},
	{.Lexema = "#include",	.LexemaName = {.Name ="T_Include",	.Id = T_Include},	.LexemaType = {.Name = DIRETIVA, .Id = CL_Diretiva}}
	
};



LexemasReservados dicionarioSimbolosSimples[] =
{	
	// S�mbolos
	{.Lexema = "{",		.LexemaName = {.Name ="T_Chave_Abre", 		.Id = T_Chave_Abre},		.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "}",		.LexemaName = {.Name ="T_Chave_Fecha", 		.Id = T_Chave_Fecha},		.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "(",		.LexemaName = {.Name ="T_Parentese_Abre", 	.Id = T_Parentese_Abre},	.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = ")",		.LexemaName = {.Name ="T_Parentese_Fecha",	.Id = T_Parentese_Fecha},	.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "[",		.LexemaName = {.Name ="T_Colchete_Abre", 	.Id = T_Colchete_Abre},		.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "]",		.LexemaName = {.Name ="T_Colchete_Fecha", 	.Id = T_Colchete_Fecha},	.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "\"",	.LexemaName = {.Name ="T_AspaDupla", 		.Id = T_AspaDupla},			.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "\'",	.LexemaName = {.Name ="T_AspaSimples", 		.Id = T_AspaSimples},		.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = ".",		.LexemaName = {.Name ="T_Ponto", 			.Id = T_Ponto},				.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = ",",		.LexemaName = {.Name ="T_Virgula", 			.Id = T_Virgula},			.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = ";",		.LexemaName = {.Name ="T_PontoVingula", 	.Id = T_PontoVingula},		.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	{.Lexema = "\\",	.LexemaName = {.Name ="T_Barra", 			.Id = T_Barra},				.LexemaType = {.Name = SIMBOLO, .Id = CL_Simbolos}},
	
	
	// Operadores
	{.Lexema = "=",	.LexemaName = {.Name ="T_Atribuicao", 	.Id = T_Atribuicao},	.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "!",	.LexemaName = {.Name ="T_Negacao", 		.Id = T_Negacao},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "*",	.LexemaName = {.Name ="T_Multiplicacao",.Id = T_Multiplicacao},	.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "+",	.LexemaName = {.Name ="T_Soma", 		.Id = T_Soma},			.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "/",	.LexemaName = {.Name ="T_Divisao", 		.Id = T_Divisao},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "-",	.LexemaName = {.Name ="T_Subtracao", 	.Id = T_Subtracao},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "%",	.LexemaName = {.Name ="T_Modulo", 		.Id = T_Modulo},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = ">",	.LexemaName = {.Name ="T_MaiorQ", 		.Id = T_MaiorQ},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "<",	.LexemaName = {.Name ="T_MenorQ", 		.Id = T_MenorQ},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}}
	
};



LexemasReservados dicionarioSimbolosCompostos[] =
{
	// Operadores
	{.Lexema = ">=",	.LexemaName = {.Name ="T_MaiorIgualQ", 	.Id = T_MaiorIgualQ},	.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "<=",	.LexemaName = {.Name ="T_MenorIgualQ", 	.Id = T_MenorIgualQ},	.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "==",	.LexemaName = {.Name ="T_Igual", 		.Id = T_Igual},			.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "!=",	.LexemaName = {.Name ="T_Diferente", 	.Id = T_Diferente},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},	
	{.Lexema = "&&",	.LexemaName = {.Name ="T_E_Logico", 	.Id = T_E_Logico},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "||",	.LexemaName = {.Name ="T_Ou_Logico", 	.Id = T_Ou_Logico},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	
	
	// Coment�rios
	{.Lexema = "//", .LexemaName = {.Name ="T_Comentario_Linha",	.Id = T_Comentario_Linha},	.LexemaType = {.Name = COMENTARIO, .Id = CL_Comentario}},
	{.Lexema = "/*", .LexemaName = {.Name ="T_Comentario_Inicio",	.Id = T_Comentario_Inicio},	.LexemaType = {.Name = COMENTARIO, .Id = CL_Comentario}},
	{.Lexema = "*/", .LexemaName = {.Name ="T_Comentario_Fim",		.Id = T_Comentario_Fim},	.LexemaType = {.Name = COMENTARIO, .Id = CL_Comentario}},
	
};



LexemasReservados LexemaNulo = {.Lexema = NULL,	.LexemaName = {.Name ="", .Id = 0}, .LexemaType = {.Name ="", .Id = 0}};

LexemasReservados LexemaInvalido				= {.Lexema = "",	.LexemaName = {.Name ="T_Invalido",				.Id = T_Invalido},				.LexemaType = {.Name = INVALIDO,				.Id = CL_Invalido}};

LexemasReservados LexemaConstanteTexto			= {.Lexema = "",	.LexemaName = {.Name ="T_ConstanteTexto",		.Id = T_ConstanteTexto},		.LexemaType = {.Name = CONSTANTE_TEXTO,			.Id = CL_ConstanteTexto}};

LexemasReservados LexemaIdentificadorString		= {.Lexema = "",	.LexemaName = {.Name ="T_IdentificadorString",	.Id = T_IdentificadorString},	.LexemaType = {.Name = IDENTIFICADOR_STRING,	.Id = CL_IdentificadorString}};

LexemasReservados LexemaIdentificadorNumerico	= {.Lexema = "",	.LexemaName = {.Name ="T_IdentificadorNumerico",.Id = T_IdentificadorNumerico},	.LexemaType = {.Name = IDENTIFICADOR_NUMERICO,	.Id = CL_IdentificadorNumerico}};






Lexemas IdentificarLexema(char* string)
{	
	Lexemas lexema;
	
	lexema = ProcurarPalavraReservada(string);
	if(lexema.LexemaId != NULO) return lexema;
	
	lexema = ProcurarSimbolo(string);	
	if(lexema.LexemaId != NULO) return lexema;
	
	return lexema;
}



Lexemas ProcurarPalavraReservada(char *string)
{
	unsigned int indice = 0;
	Lexemas lexema = CriarLexemaNulo();
	
	// Procura dentre as Palavras Reservadas
	while(dicionarioPalavrasReservadas[indice].Lexema != NULL)
	{
		if(strcmp (dicionarioPalavrasReservadas[indice].Lexema, string) == 0)
		{
			lexema.LexemaId = dicionarioPalavrasReservadas[indice].LexemaName.Id;
			lexema.LexemaTypeId = dicionarioPalavrasReservadas[indice].LexemaType.Id;
			return lexema;
		}
		
		indice++;
	}
	
	return lexema;
}



//unsigned int ProcurarSimbolo(char *string)
Lexemas ProcurarSimbolo(char *string)
{
	char auxiliar;
	unsigned int indice = 0;
	Lexemas lexema = CriarLexemaNulo();
	
	
	// Primeiro Procura dentre os S�mbolos Compostos
	while(dicionarioSimbolosCompostos[indice].Lexema != NULL)
	{
		if(strcmp (dicionarioSimbolosCompostos[indice].Lexema, string) == 0)
		{
			lexema.LexemaId = dicionarioSimbolosCompostos[indice].LexemaName.Id;
			lexema.LexemaTypeId = dicionarioSimbolosCompostos[indice].LexemaType.Id;
			return lexema;
		}
		
		indice++;
	}
	
	
	// Para s� ent�o Procurar dentre os S�mbolos Simples
	indice = 0;
	//auxiliar = (char)*string;
	while(dicionarioSimbolosSimples[indice].Lexema != NULL)
	{
		if(*dicionarioSimbolosSimples[indice].Lexema == (char)*string)
		{
			lexema.LexemaId = dicionarioSimbolosSimples[indice].LexemaName.Id;
			lexema.LexemaTypeId = dicionarioSimbolosSimples[indice].LexemaType.Id;
			return lexema;
		}
		
		indice++;
	}
	
	return lexema;
}



Lexemas CriarLexemaIdentificadorString(char* string)
{
	Lexemas lexema;
	
	lexema.LexemaId = T_IdentificadorString;
	lexema.LexemaTypeId = T_IdentificadorString;
	lexema.Identificador = string;
		
	return lexema;
}



Lexemas CriarLexemaConstanteTexto(char* string)
{
	Lexemas lexema;
	
	lexema.LexemaId = T_ConstanteTexto;
	lexema.LexemaTypeId = T_ConstanteTexto;
	lexema.Identificador = string;
		
	return lexema;
}



Lexemas CriarLexemaIdentificadorNumerico(char* string)
{
	Lexemas lexema;
	
	lexema.LexemaId = T_IdentificadorNumerico;
	lexema.LexemaTypeId = T_IdentificadorNumerico;
	lexema.Identificador = string;
		
	return lexema;
}



Lexemas CriarLexemaInvalido(char* string)
{
	Lexemas lexema;
	
	lexema.LexemaId = T_Invalido;
	lexema.LexemaTypeId = T_Invalido;
	lexema.Identificador = string;
		
	return lexema;
}



Lexemas CriarLexemaNulo()
{
	Lexemas lexema;
	
	lexema.LexemaId = NULO;
	lexema.LexemaTypeId = NULO;
	lexema.Identificador = NULL;
		
	return lexema;
}



boolean EhIdentificadorString(char *string)
{
	// Verifica se o Primeiro Caractere do Identificador � v�lido
	if(
		!((char)*string >= PRIMEIRA_LETRA_MAIUSCULA_VALIDA && (char)*string <= ULTIMA_LETRA_MAIUSCULA_VALIDA) &&
		!((char)*string >= PRIMEIRA_LETRA_MINUSCULA_VALIDA && (char)*string <= ULTIMA_LETRA_MINUSCULA_VALIDA) &&
		!((char)*string == UNDERLINE)
	)
	{
		return FALSE;
	}
	
	string++;	
	while((char)*string)
	{
		if(
			((char)*string >= PRIMEIRA_LETRA_MAIUSCULA_VALIDA && (char)*string <= ULTIMA_LETRA_MAIUSCULA_VALIDA) ||
			((char)*string >= PRIMEIRA_LETRA_MINUSCULA_VALIDA && (char)*string <= ULTIMA_LETRA_MINUSCULA_VALIDA) ||
			((char)*string >= PRIMEIRO_NUMERO_VALIDO && (char)*string <= ULTIMO_NUMERO_VALIDO) ||
			((char)*string == UNDERLINE)
		)
		{
			string++;
			continue;
		}
		
		return FALSE;
	}

	return TRUE;
}



boolean EhConstanteTexto(char *string)
{
	// Verifica se o Primeiro Caractere � Aspa Dupla
	if((char)*string == '\"')
	{
		return TRUE;
	}
	
	return FALSE;
}



boolean EhIdentificadorNumerico(char *string)
{
	while((char)*string)
	{
		if(((char)*string >= PRIMEIRO_NUMERO_VALIDO && (char)*string <= ULTIMO_NUMERO_VALIDO) || (char)*string == '.')
		{
			string++;
			continue;
		}
		
		return FALSE;
	}

	return TRUE;
}



boolean EhUmNumero(char* string)
{
	while((char)*string)
	{
		if((char)*string >= PRIMEIRO_NUMERO_VALIDO && (char)*string <= ULTIMO_NUMERO_VALIDO)
		{
			string++;
			continue;
		}
		
		return FALSE;
	}

	return TRUE;
}



boolean EhUmSimboloComposto(unsigned int lexemaId)
{
	unsigned int indice = 0;
	
	while(dicionarioSimbolosCompostos[indice].LexemaName.Id)
	{
		if(dicionarioSimbolosCompostos[indice].LexemaName.Id == lexemaId)
		{
			return TRUE;
		}
		
		indice++;
	}
	
	return FALSE;
}



LexemasReservados ObterLexemaReservado(unsigned int lexemaId)
{	
	unsigned int indice = 0;
	
	// Verifica se � um Lexema Constante de Texto
	if(lexemaId == T_ConstanteTexto)
	{
		return LexemaConstanteTexto;
	}
	
	// Verifica se � um Lexema Identificador String
	if(lexemaId == T_IdentificadorString)
	{
		return LexemaIdentificadorString;
	}
	
	// Verifica se � um Lexema Identificador Numerico
	if(lexemaId == T_IdentificadorNumerico)
	{
		return LexemaIdentificadorNumerico;
	}
	
	// Verifica se � um Lexema Inv�lido
	if(lexemaId == T_Invalido)
	{
		return LexemaInvalido;
	}

	
	// Procura dentre as Palavras Reservadas
	while(dicionarioPalavrasReservadas[indice].LexemaName.Id != NULO)
	{
		if(dicionarioPalavrasReservadas[indice].LexemaName.Id == lexemaId)
		{
			return dicionarioPalavrasReservadas[indice];
		}
		
		indice++;
	}	
	
	
	// Procura dentre os S�mbolos Compostos
	indice = 0;
	while(dicionarioSimbolosCompostos[indice].LexemaName.Id != NULO)
	{
		if(dicionarioSimbolosCompostos[indice].LexemaName.Id == lexemaId)
		{
			return dicionarioSimbolosCompostos[indice];
		}
		
		indice++;
	}
	
	
	// Procura dentre os S�mbolos Simples
	indice = 0;
	while(dicionarioSimbolosSimples[indice].LexemaName.Id != NULO)
	{
		if(dicionarioSimbolosSimples[indice].LexemaName.Id == lexemaId)
		{
			return dicionarioSimbolosSimples[indice];
		}
		
		indice++;
	}
	
	return LexemaNulo;	
}






