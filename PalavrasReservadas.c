
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constantes.h"
#include "EstruturasTipos.h"

#include "Arquivos.h"
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"
#include "PalavrasReservadas.h"

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



Tokens dicionario[] =
{
	// Tipos de Variáveis
	{.Token = "int",	.TokenName = {.Name ="T_Inteiro",	.Id = T_Inteiro},	.TokenType = {.Name = TIPO, .Id = Tipo}},
	{.Token = "char",	.TokenName = {.Name ="T_Caractere",	.Id = T_Caractere},	.TokenType = {.Name = TIPO, .Id = Tipo}},
	{.Token = "void",	.TokenName = {.Name ="T_Vazio",		.Id = T_Vazio},		.TokenType = {.Name = TIPO, .Id = Tipo}},
	{.Token = "long",	.TokenName = {.Name ="T_Longo", 	.Id = T_Longo},		.TokenType = {.Name = TIPO, .Id = Tipo}},
	{.Token = "float",	.TokenName = {.Name ="T_Decimal",	.Id = T_Decimal},	.TokenType = {.Name = TIPO, .Id = Tipo}},
	{.Token = "double",	.TokenName = {.Name ="T_Dobro",		.Id = T_Dobro},		.TokenType = {.Name = TIPO, .Id = Tipo}},
	
	
	// Complementos de Tipo de Variável
	{.Token = "short",		.TokenName = {.Name ="T_Curto", 		.Id = T_Curto},			.TokenType = {.Name = COMPLEMENTO_TIPO, .Id = ComplementoTipo}},
	{.Token = "signed",		.TokenName = {.Name ="T_Sinalizado", 	.Id = T_Sinalizado},	.TokenType = {.Name = COMPLEMENTO_TIPO, .Id = ComplementoTipo}},
	{.Token = "unsigned",	.TokenName = {.Name ="T_NaoSinalizado", .Id = T_NaoSinalizado},	.TokenType = {.Name = COMPLEMENTO_TIPO, .Id = ComplementoTipo}},
	
	
	// Modificadores de Tipo de Variável
	{.Token = "const",		.TokenName = {.Name ="T_Constante",		.Id = T_Constante},		.TokenType = {.Name = MODIFICADOR_TIPO, .Id = ModificadorTipo}},
	{.Token = "volatile",	.TokenName = {.Name ="T_Volatil", 		.Id = T_Volatil},		.TokenType = {.Name = MODIFICADOR_TIPO, .Id = ModificadorTipo}},
	{.Token = "register",	.TokenName = {.Name ="T_Registrador",	.Id = T_Registrador},	.TokenType = {.Name = MODIFICADOR_TIPO, .Id = ModificadorTipo}},
	
	
	// Tipos Personalizados
	{.Token = "enum",		.TokenName = {.Name ="T_Enumeracao", 	.Id = T_Enumeracao},	.TokenType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	{.Token = "union",		.TokenName = {.Name ="T_Uniao", 		.Id = T_Uniao},			.TokenType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	{.Token = "struct",		.TokenName = {.Name ="T_Estrutura", 	.Id = T_Estrutura},		.TokenType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	{.Token = "typedef",	.TokenName = {.Name ="T_DefinicaoTipo", .Id = T_DefinicaoTipo},	.TokenType = {.Name = TIPO_PERSONALIZADO, .Id = TipoPersonalizado}},
	
	
	// Palavras Reservadas
	{.Token = "switch",		.TokenName = {.Name ="T_Switch", 	.Id = T_Switch},	.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "case",		.TokenName = {.Name ="T_Case", 		.Id = T_Case},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "default",	.TokenName = {.Name ="T_Default",	.Id = T_Default},	.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "do",			.TokenName = {.Name ="T_Do", 		.Id = T_Do},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "while",		.TokenName = {.Name ="T_While", 	.Id = T_While},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "if",			.TokenName = {.Name ="T_If", 		.Id = T_If},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "else",		.TokenName = {.Name ="T_Else", 		.Id = T_Else},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "for",		.TokenName = {.Name ="T_For", 		.Id = T_For},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "goto",		.TokenName = {.Name ="T_Goto", 		.Id = T_Goto},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "break",		.TokenName = {.Name ="T_Break", 	.Id = T_Break},		.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "continue",	.TokenName = {.Name ="T_Continue", 	.Id = T_Continue},	.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	{.Token = "return",		.TokenName = {.Name ="T_Return", 	.Id = T_Return},	.TokenType = {.Name = PALAVRA_RESERVADA, .Id = PalavraReservada}},
	
	
	// Diretivas
	{.Token = "#define",	.TokenName = {.Name ="T_Define",	.Id = T_Define},	.TokenType = {.Name = DIRETIVA, .Id = Diretiva}},
	{.Token = "#include",	.TokenName = {.Name ="T_Include",	.Id = T_Include},	.TokenType = {.Name = DIRETIVA, .Id = Diretiva}}
	
};



Tokens dicionarioSimbolosSimples[] =
{	
	// Símbolos
	{.Token = "{",	.TokenName = {.Name ="T_Chave_Abre", 		.Id = T_Chave_Abre},		.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "}",	.TokenName = {.Name ="T_Chave_Fecha", 		.Id = T_Chave_Fecha},		.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "(",	.TokenName = {.Name ="T_Parentese_Abre", 	.Id = T_Parentese_Abre},	.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = ")",	.TokenName = {.Name ="T_Parentese_Fecha",	.Id = T_Parentese_Fecha},	.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "[",	.TokenName = {.Name ="T_Colchete_Abre", 	.Id = T_Colchete_Abre},		.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "]",	.TokenName = {.Name ="T_Colchete_Fecha", 	.Id = T_Colchete_Fecha},	.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "\"",	.TokenName = {.Name ="T_AspaDupla", 		.Id = T_AspaDupla},			.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "\'",	.TokenName = {.Name ="T_AspaSimples", 		.Id = T_AspaSimples},		.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = ".",	.TokenName = {.Name ="T_Ponto", 			.Id = T_Ponto},				.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = ",",	.TokenName = {.Name ="T_Virgula", 			.Id = T_Virgula},			.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = ";",	.TokenName = {.Name ="T_PontoVingula", 		.Id = T_PontoVingula},		.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	{.Token = "\\",	.TokenName = {.Name ="T_Barra", 			.Id = T_Barra},				.TokenType = {.Name = SIMBOLO, .Id = Simbolos}},
	
	
	// Operadores
	{.Token = "*",	.TokenName = {.Name ="T_Multiplicacao", .Id = T_Multiplicacao},	.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "+",	.TokenName = {.Name ="T_Soma", 			.Id = T_Soma},			.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "/",	.TokenName = {.Name ="T_Divisao", 		.Id = T_Divisao},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "-",	.TokenName = {.Name ="T_Subtracao", 	.Id = T_Subtracao},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "%",	.TokenName = {.Name ="T_Modulo", 		.Id = T_Modulo},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = ">",	.TokenName = {.Name ="T_MaiorQ", 		.Id = T_MaiorQ},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "<",	.TokenName = {.Name ="T_MenorQ", 		.Id = T_MenorQ},		.TokenType = {.Name = OPERADOR, .Id = Operador}}
	
};



Tokens dicionarioSimbolosCompostos[] =
{
	// Operadores	
	{.Token = ">=",	.TokenName = {.Name ="T_MaiorIgualQ", 	.Id = T_MaiorIgualQ},	.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "<=",	.TokenName = {.Name ="T_MenorIgualQ", 	.Id = T_MenorIgualQ},	.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "==",	.TokenName = {.Name ="T_Igual", 		.Id = T_Igual},			.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "!=",	.TokenName = {.Name ="T_Diferente", 	.Id = T_Diferente},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "=",	.TokenName = {.Name ="T_Atribuicao", 	.Id = T_Atribuicao},	.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "!",	.TokenName = {.Name ="T_Negacao", 		.Id = T_Negacao},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "&&",	.TokenName = {.Name ="T_E_Logico", 		.Id = T_E_Logico},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	{.Token = "||",	.TokenName = {.Name ="T_Ou_Logico", 	.Id = T_Ou_Logico},		.TokenType = {.Name = OPERADOR, .Id = Operador}},
	
	
	// Comentários
	{.Token = "//", .TokenName = {.Name ="T_Comentario_Linha",	.Id = T_Comentario_Linha},	.TokenType = {.Name = COMENTARIO, .Id = Comentario}},
	{.Token = "/*", .TokenName = {.Name ="T_Comentario_Inicio", .Id = T_Comentario_Inicio},	.TokenType = {.Name = COMENTARIO, .Id = Comentario}},
	{.Token = "*/", .TokenName = {.Name ="T_Comentario_Fim",	.Id = T_Comentario_Fim},	.TokenType = {.Name = COMENTARIO, .Id = Comentario}},
	
};


Tokens TokenInvalido = {.Token = "", .TokenName = {.Name ="T_Invalido", .Id = T_Invalido}, .TokenType = {.Name = INVALIDO, .Id = Invalido}};

Tokens TokenIdentificador = {.Token = "", .TokenName = {.Name ="T_Identificador", .Id = T_Identificador},	.TokenType = {.Name = IDENTIFICADOR, .Id = Identificador}};

Tokens TokenNulo = {.Token = NULL,	.TokenName = {.Name ="", .Id = 0},	.TokenType = {.Name ="", .Id = 0}};




void CriarDicionario()
{
	int x = 0;
		
	while(dicionario[x].Token)
	{
		printf("\n %s - %s - %s", dicionario[x].Token, dicionario[x].TokenName.Name, dicionario[x].TokenType.Name);
		x++;
	}
	
}



Tokens ProcurarPalavraReservada(char *string)
{
	unsigned int indice = 0;
	
	// Procura dentre as Palavras Reservadas
	while(dicionario[indice].Token != NULL)
	{
		if(strcmp (dicionario[indice].Token, string) == 0)
		{
			return dicionario[indice];
		}
		
		indice++;
	}
	
	return TokenNulo;
}



Tokens ProcurarSimbolo(char *string)
{
	char auxiliar;
	unsigned int indice = 0;
	
	// Primeiro Procura dentre os Símbolos Compostos
	while(dicionarioSimbolosCompostos[indice].Token != NULL)
	{
		if(strcmp (dicionarioSimbolosCompostos[indice].Token, string) == 0)
		{
			return dicionarioSimbolosCompostos[indice];
		}
		
		indice++;
	}
	
	
	// Para só então Procurar dentre os Símbolos Simples
	indice = 0;
	auxiliar = *string;
	while(dicionarioSimbolosSimples[indice].Token != NULL)
	{
		if(*dicionarioSimbolosSimples[indice].Token == auxiliar)
		{
			return dicionarioSimbolosSimples[indice];
		}
		
		indice++;
	}
	
	return TokenNulo;
}



Tokens CriarTokenIdentificador(char *string)
{
	Tokens token;
	
	token = TokenIdentificador;
	
	while(*string)
	{
		strcpy (token.Token, string);
		string++;
	}
	
	return token;
}



Tokens CriarTokenInvalido(char *string)
{
	Tokens token;
	
	token = TokenInvalido;
	
	while(*string)
	{
		strcpy (token.Token, string);
		string++;
	}
	
	return token;
}



boolean VerificarIdentificador(char *string)
{
	while(*string)
	{
		if(
			(*string >= PRIMEIRA_LETRA_MAIUSCULA_VALIDA) && (*string <= ULTIMA_LETRA_MAIUSCULA_VALIDA) ||
			(*string >= PRIMEIRA_LETRA_MINUSCULA_VALIDA) && (*string <= ULTIMA_LETRA_MINUSCULA_VALIDA) ||
			(*string >= PRIMEIRO_NUMERO_VALIDO) && (*string <= ULTIMO_NUMERO_VALIDO) ||
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






