
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Bibliotecas.h"


#define PRIMEIRA_LETRA_MAIUSCULA_VALIDA		65
#define ULTIMA_LETRA_MAIUSCULA_VALIDA		90

#define PRIMEIRA_LETRA_MINUSCULA_VALIDA		97
#define ULTIMA_LETRA_MINUSCULA_VALIDA		122

#define PRIMEIRO_NUMERO_VALIDO	48
#define ULTIMO_NUMERO_VALIDO	57

#define UNDERLINE	95


#define TIPO "Tipo"
#define COMPLEMENTO_TIPO "ComplementoTipo"
#define MODIFICADOR_TIPO "ModificadorTipo"
#define TIPO_PERSONALIZADO "TipoPersonalizado"
#define PALAVRA_RESERVADA "PalavraReservada"
#define DIRETIVA "Diretiva"
#define SIMBOLO "Simbolo"
#define OPERADOR "Operador"
#define COMENTARIO "Comentario"
#define INVALIDO "Invalido"
#define IDENTIFICADOR "Identificador"



LexemasReservados dicionarioPalavrasReservadas[] =
{
	// Tipos de Variáveis
	{.Lexema = "int",		.LexemaName = {.Name ="T_Inteiro",	.Id = T_Inteiro},	.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "char",		.LexemaName = {.Name ="T_Caractere",.Id = T_Caractere},	.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "void",		.LexemaName = {.Name ="T_Vazio",	.Id = T_Vazio},		.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "long",		.LexemaName = {.Name ="T_Longo", 	.Id = T_Longo},		.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "float",		.LexemaName = {.Name ="T_Decimal",	.Id = T_Decimal},	.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	{.Lexema = "double",	.LexemaName = {.Name ="T_Dobro",	.Id = T_Dobro},		.LexemaType = {.Name = TIPO, .Id = CL_Tipo}},
	
	
	// Complementos de Tipo de Variável
	{.Lexema = "short",		.LexemaName = {.Name ="T_Curto", 		.Id = T_Curto},			.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = CL_ComplementoTipo}},
	{.Lexema = "signed",	.LexemaName = {.Name ="T_Sinalizado", 	.Id = T_Sinalizado},	.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = CL_ComplementoTipo}},
	{.Lexema = "unsigned",	.LexemaName = {.Name ="T_NaoSinalizado",.Id = T_NaoSinalizado},	.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = CL_ComplementoTipo}},
	
	
	// Modificadores de Tipo de Variável
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
	// Símbolos
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
	{.Lexema = "=",		.LexemaName = {.Name ="T_Atribuicao", 	.Id = T_Atribuicao},	.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "!",		.LexemaName = {.Name ="T_Negacao", 		.Id = T_Negacao},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "&&",	.LexemaName = {.Name ="T_E_Logico", 	.Id = T_E_Logico},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	{.Lexema = "||",	.LexemaName = {.Name ="T_Ou_Logico", 	.Id = T_Ou_Logico},		.LexemaType = {.Name = OPERADOR, .Id = CL_Operador}},
	
	
	// Comentários
	{.Lexema = "//", .LexemaName = {.Name ="T_Comentario_Linha",	.Id = T_Comentario_Linha},	.LexemaType = {.Name = COMENTARIO, .Id = CL_Comentario}},
	{.Lexema = "/*", .LexemaName = {.Name ="T_Comentario_Inicio",	.Id = T_Comentario_Inicio},	.LexemaType = {.Name = COMENTARIO, .Id = CL_Comentario}},
	{.Lexema = "*/", .LexemaName = {.Name ="T_Comentario_Fim",		.Id = T_Comentario_Fim},	.LexemaType = {.Name = COMENTARIO, .Id = CL_Comentario}},
	
};


LexemasReservados LexemaInvalido = {.Lexema = "", .LexemaName = {.Name ="T_Invalido", .Id = T_Invalido}, .LexemaType = {.Name = INVALIDO, .Id = CL_Invalido}};

LexemasReservados LexemaIdentificador = {.Lexema = "", .LexemaName = {.Name ="T_Identificador", .Id = T_Identificador},	.LexemaType = {.Name = IDENTIFICADOR, .Id = CL_Identificador}};

LexemasReservados LexemaNulo = {.Lexema = NULL,	.LexemaName = {.Name ="", .Id = 0},	.LexemaType = {.Name ="", .Id = 0}};




unsigned int IdentificarLexema(char* string)
{
	unsigned int lexemaId = NULL;
	
	lexemaId = ProcurarPalavraReservada(string);	
	if(lexemaId != NULO) return lexemaId;
	
	lexemaId = ProcurarSimbolo(string);	
	if(lexemaId != NULO) return lexemaId;
	
	return lexemaId;	
}



unsigned int ProcurarPalavraReservada(char *string)
{
	unsigned int indice = 0;
	
	// Procura dentre as Palavras Reservadas
	while(dicionarioPalavrasReservadas[indice].Lexema != NULL)
	{
		if(strcmp (dicionarioPalavrasReservadas[indice].Lexema, string) == 0)
		{
			return dicionarioPalavrasReservadas[indice].LexemaName.Id;
		}
		
		indice++;
	}
	
	return NULO;
}



unsigned int ProcurarSimbolo(char *string)
{
	char auxiliar;
	unsigned int indice = 0;
	
	// Primeiro Procura dentre os Símbolos Compostos
	while(dicionarioSimbolosCompostos[indice].Lexema != NULL)
	{
		if(strcmp (dicionarioSimbolosCompostos[indice].Lexema, string) == 0)
		{
			return dicionarioSimbolosCompostos[indice].LexemaName.Id;
		}
		
		indice++;
	}
	
	
	// Para só então Procurar dentre os Símbolos Simples
	indice = 0;
	auxiliar = *string;
	while(dicionarioSimbolosSimples[indice].Lexema != NULL)
	{
		if(*dicionarioSimbolosSimples[indice].Lexema == auxiliar)
		{
			return dicionarioSimbolosSimples[indice].LexemaName.Id;
		}
		
		indice++;
	}
	
	return NULO;
}



Lexemas CriarLexemaIdentificador(char* string)
{
	Lexemas lexema;
	
	lexema.LexemaId = T_Identificador;
	lexema.Identificador = string;
		
	return lexema;
}



Lexemas CriarLexemaInvalido()
{
	Lexemas lexema;
	
	lexema.LexemaId = T_Invalido;
	lexema.Identificador = NULL;
		
	return lexema;
}



Lexemas CriarLexemaNulo()
{
	Lexemas lexema;
	
	lexema.LexemaId = NULO;
	lexema.Identificador = NULL;
		
	return lexema;
}



boolean VerificarIdentificador(char *string)
{
	// Verifica se o Primeiro Caractere do Identificador é válido
	if(
		!(*string >= PRIMEIRA_LETRA_MAIUSCULA_VALIDA && *string <= ULTIMA_LETRA_MAIUSCULA_VALIDA) &&
		!(*string >= PRIMEIRA_LETRA_MINUSCULA_VALIDA && *string <= ULTIMA_LETRA_MINUSCULA_VALIDA) &&
		!(*string == UNDERLINE)
	)
	{
		return FALSE;
	}
	
	string++;	
	while(*string)
	{
		if(
			(*string >= PRIMEIRA_LETRA_MAIUSCULA_VALIDA && *string <= ULTIMA_LETRA_MAIUSCULA_VALIDA) ||
			(*string >= PRIMEIRA_LETRA_MINUSCULA_VALIDA && *string <= ULTIMA_LETRA_MINUSCULA_VALIDA) ||
			(*string >= PRIMEIRO_NUMERO_VALIDO && *string <= ULTIMO_NUMERO_VALIDO) ||
			(*string == UNDERLINE)
		)
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
	while(*string)
	{
		if(*string >= PRIMEIRO_NUMERO_VALIDO && *string <= ULTIMO_NUMERO_VALIDO)
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
	
	// Verifica se é um Lexema Identificador
	if(lexemaId == T_Identificador)
	{
		return LexemaIdentificador;
	}
	
	// Verifica se é um Lexema Inválido
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
	
	
	// Procura dentre os Símbolos Compostos
	indice = 0;
	while(dicionarioSimbolosCompostos[indice].LexemaName.Id != NULO)
	{
		if(dicionarioSimbolosCompostos[indice].LexemaName.Id == lexemaId)
		{
			return dicionarioSimbolosCompostos[indice];
		}
		
		indice++;
	}
	
	
	// Procura dentre os Símbolos Simples
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






