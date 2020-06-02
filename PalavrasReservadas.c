
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



Lexemas dicionario[] =
{
	// Tipos de Variáveis
	{.Lexema = "int",		.LexemaName = {.Name ="T_Inteiro",	.Id = T_Inteiro},	.LexemaType = {.Name = TIPO, .Id = Tipo}},
	{.Lexema = "char",		.LexemaName = {.Name ="T_Caractere",.Id = T_Caractere},	.LexemaType = {.Name = TIPO, .Id = Tipo}},
	{.Lexema = "void",		.LexemaName = {.Name ="T_Vazio",	.Id = T_Vazio},		.LexemaType = {.Name = TIPO, .Id = Tipo}},
	{.Lexema = "long",		.LexemaName = {.Name ="T_Longo", 	.Id = T_Longo},		.LexemaType = {.Name = TIPO, .Id = Tipo}},
	{.Lexema = "float",		.LexemaName = {.Name ="T_Decimal",	.Id = T_Decimal},	.LexemaType = {.Name = TIPO, .Id = Tipo}},
	{.Lexema = "double",	.LexemaName = {.Name ="T_Dobro",	.Id = T_Dobro},		.LexemaType = {.Name = TIPO, .Id = Tipo}},
	
	
	// Complementos de Tipo de Variável
	{.Lexema = "short",		.LexemaName = {.Name ="T_Curto", 		.Id = T_Curto},			.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = ComplementoTipo}},
	{.Lexema = "signed",	.LexemaName = {.Name ="T_Sinalizado", 	.Id = T_Sinalizado},	.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = ComplementoTipo}},
	{.Lexema = "unsigned",	.LexemaName = {.Name ="T_NaoSinalizado",.Id = T_NaoSinalizado},	.LexemaType = {.Name = COMPLEMENTO_TIPO, .Id = ComplementoTipo}},
	
	
	// Modificadores de Tipo de Variável
	{.Lexema = "const",		.LexemaName = {.Name ="T_Constante",	.Id = T_Constante},		.LexemaType = {.Name = MODIFICADOR_TIPO, .Id = ModificadorTipo}},
	{.Lexema = "volatile",	.LexemaName = {.Name ="T_Volatil", 		.Id = T_Volatil},		.LexemaType = {.Name = MODIFICADOR_TIPO, .Id = ModificadorTipo}},
	{.Lexema = "register",	.LexemaName = {.Name ="T_Registrador",	.Id = T_Registrador},	.LexemaType = {.Name = MODIFICADOR_TIPO, .Id = ModificadorTipo}},
	
	
	// Tipos Personalizados
	{.Lexema = "enum",		.LexemaName = {.Name ="T_Enumeracao", 	.Id = T_Enumeracao},	.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	{.Lexema = "union",		.LexemaName = {.Name ="T_Uniao", 		.Id = T_Uniao},			.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	{.Lexema = "struct",	.LexemaName = {.Name ="T_Estrutura", 	.Id = T_Estrutura},		.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	{.Lexema = "typedef",	.LexemaName = {.Name ="T_DefinicaoTipo",.Id = T_DefinicaoTipo},	.LexemaType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	
	
	// Palavras Reservadas
	{.Lexema = "switch",	.LexemaName = {.Name ="T_Switch", 	.Id = T_Switch},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "case",		.LexemaName = {.Name ="T_Case", 	.Id = T_Case},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "default",	.LexemaName = {.Name ="T_Default",	.Id = T_Default},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "do",		.LexemaName = {.Name ="T_Do", 		.Id = T_Do},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "while",		.LexemaName = {.Name ="T_While", 	.Id = T_While},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "if",		.LexemaName = {.Name ="T_If", 		.Id = T_If},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "else",		.LexemaName = {.Name ="T_Else", 	.Id = T_Else},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "for",		.LexemaName = {.Name ="T_For", 		.Id = T_For},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "goto",		.LexemaName = {.Name ="T_Goto", 	.Id = T_Goto},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "break",		.LexemaName = {.Name ="T_Break", 	.Id = T_Break},		.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "continue",	.LexemaName = {.Name ="T_Continue", .Id = T_Continue},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Lexema = "return",	.LexemaName = {.Name ="T_Return", 	.Id = T_Return},	.LexemaType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	
	
	// Diretivas
	{.Lexema = "#define",	.LexemaName = {.Name ="T_Define",	.Id = T_Define},	.LexemaType = {.Name = DIRETIVA, .Id = Diretiva}},
	{.Lexema = "#include",	.LexemaName = {.Name ="T_Include",	.Id = T_Include},	.LexemaType = {.Name = DIRETIVA, .Id = Diretiva}}
	
};



Lexemas dicionarioSimbolosSimples[] =
{	
	// Símbolos
	{.Lexema = "{",		.LexemaName = {.Name ="T_Chave_Abre", 		.Id = T_Chave_Abre},		.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "}",		.LexemaName = {.Name ="T_Chave_Fecha", 		.Id = T_Chave_Fecha},		.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "(",		.LexemaName = {.Name ="T_Parentese_Abre", 	.Id = T_Parentese_Abre},	.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = ")",		.LexemaName = {.Name ="T_Parentese_Fecha",	.Id = T_Parentese_Fecha},	.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "[",		.LexemaName = {.Name ="T_Colchete_Abre", 	.Id = T_Colchete_Abre},		.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "]",		.LexemaName = {.Name ="T_Colchete_Fecha", 	.Id = T_Colchete_Fecha},	.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "\"",	.LexemaName = {.Name ="T_AspaDupla", 		.Id = T_AspaDupla},			.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "\'",	.LexemaName = {.Name ="T_AspaSimples", 		.Id = T_AspaSimples},		.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = ".",		.LexemaName = {.Name ="T_Ponto", 			.Id = T_Ponto},				.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = ",",		.LexemaName = {.Name ="T_Virgula", 			.Id = T_Virgula},			.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = ";",		.LexemaName = {.Name ="T_PontoVingula", 	.Id = T_PontoVingula},		.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Lexema = "\\",	.LexemaName = {.Name ="T_Barra", 			.Id = T_Barra},				.LexemaType = {.Name = SIMBOLO, .Id = Simbolos}},
	
	
	// Operadores
	{.Lexema = "*",	.LexemaName = {.Name ="T_Multiplicacao",.Id = T_Multiplicacao},	.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "+",	.LexemaName = {.Name ="T_Soma", 		.Id = T_Soma},			.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "/",	.LexemaName = {.Name ="T_Divisao", 		.Id = T_Divisao},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "-",	.LexemaName = {.Name ="T_Subtracao", 	.Id = T_Subtracao},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "%",	.LexemaName = {.Name ="T_Modulo", 		.Id = T_Modulo},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = ">",	.LexemaName = {.Name ="T_MaiorQ", 		.Id = T_MaiorQ},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "<",	.LexemaName = {.Name ="T_MenorQ", 		.Id = T_MenorQ},		.LexemaType = {.Name = OPERADOR, .Id = Operador}}
	
};



Lexemas dicionarioSimbolosCompostos[] =
{
	// Operadores	
	{.Lexema = ">=",	.LexemaName = {.Name ="T_MaiorIgualQ", 	.Id = T_MaiorIgualQ},	.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "<=",	.LexemaName = {.Name ="T_MenorIgualQ", 	.Id = T_MenorIgualQ},	.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "==",	.LexemaName = {.Name ="T_Igual", 		.Id = T_Igual},			.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "!=",	.LexemaName = {.Name ="T_Diferente", 	.Id = T_Diferente},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "=",		.LexemaName = {.Name ="T_Atribuicao", 	.Id = T_Atribuicao},	.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "!",		.LexemaName = {.Name ="T_Negacao", 		.Id = T_Negacao},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "&&",	.LexemaName = {.Name ="T_E_Logico", 	.Id = T_E_Logico},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	{.Lexema = "||",	.LexemaName = {.Name ="T_Ou_Logico", 	.Id = T_Ou_Logico},		.LexemaType = {.Name = OPERADOR, .Id = Operador}},
	
	
	// Comentários
	{.Lexema = "//", .LexemaName = {.Name ="T_Comentario_Linha",	.Id = T_Comentario_Linha},	.LexemaType = {.Name = COMENTARIO, .Id = Comentario}},
	{.Lexema = "/*", .LexemaName = {.Name ="T_Comentario_Inicio",	.Id = T_Comentario_Inicio},	.LexemaType = {.Name = COMENTARIO, .Id = Comentario}},
	{.Lexema = "*/", .LexemaName = {.Name ="T_Comentario_Fim",		.Id = T_Comentario_Fim},	.LexemaType = {.Name = COMENTARIO, .Id = Comentario}},
	
};


Lexemas LexemaInvalido = {.Lexema = "", .LexemaName = {.Name ="T_Invalido", .Id = T_Invalido}, .LexemaType = {.Name = INVALIDO, .Id = Invalido}};

Lexemas LexemaIdentificador = {.Lexema = "", .LexemaName = {.Name ="T_Identificador", .Id = T_Identificador},	.LexemaType = {.Name = IDENTIFICADOR, .Id = Identificador}};

Lexemas LexemaNulo = {.Lexema = NULL,	.LexemaName = {.Name ="", .Id = 0},	.LexemaType = {.Name ="", .Id = 0}};




void CriarDicionario()
{
	// int x = 0;
		
	// while(dicionario[x].Token)
	// {
	// 	printf("\n %s - %s - %s", dicionario[x].Token, dicionario[x].LexemaName.Name, dicionario[x].LexemaType.Name);
	// 	x++;
	// }
	
}



Lexemas ProcurarPalavraReservada(char *string)
{
	unsigned int indice = 0;
	
	// Procura dentre as Palavras Reservadas
	while(dicionario[indice].Lexema != NULL)
	{
		if(strcmp (dicionario[indice].Lexema, string) == 0)
		{
			return dicionario[indice];
		}
		
		indice++;
	}
	
	return LexemaNulo;
}



Lexemas ProcurarSimbolo(char *string)
{
	char auxiliar;
	unsigned int indice = 0;
	
	// Primeiro Procura dentre os Símbolos Compostos
	while(dicionarioSimbolosCompostos[indice].Lexema != NULL)
	{
		if(strcmp (dicionarioSimbolosCompostos[indice].Lexema, string) == 0)
		{
			return dicionarioSimbolosCompostos[indice];
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
			return dicionarioSimbolosSimples[indice];
		}
		
		indice++;
	}
	
	return LexemaNulo;
}



Lexemas CriarLexemaIdentificador(char *string)
{
	Lexemas lexema;
	
	lexema = LexemaIdentificador;
	
	lexema.Lexema = string;
	
	return lexema;
}



Lexemas CriarLexemaInvalido()
{
	return LexemaInvalido;
}



Lexemas CriarLexemaNulo()
{
	return LexemaNulo;
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



boolean VerificarIdentificadorNumerico(char *string)
{
	// Verifica se o Primeiro Caractere do Identificador Numérico é um Número
	if(!(*string >= PRIMEIRO_NUMERO_VALIDO && *string <= ULTIMO_NUMERO_VALIDO))
	{
		return FALSE;
	}
	
	string++;
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






