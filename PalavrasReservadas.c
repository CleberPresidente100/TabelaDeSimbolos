
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constantes.h"
#include "EstruturasTipos.h"

#include "Arquivos.h"
#include "AnalisadorLexico.h"
#include "PalavrasReservadas.h"


TokenTypes dicionario[] =
{
	// Tipos de Variáveis
	{.Token = "int",	.TokenName = "T_Inteiro",	.TokenType = "Tipo"},
	{.Token = "char",	.TokenName = "T_Caractere",	.TokenType = "Tipo"},
	{.Token = "void",	.TokenName = "T_Vazio",		.TokenType = "Tipo"},
	{.Token = "long",	.TokenName = "T_Longo",		.TokenType = "Tipo"},
	{.Token = "float",	.TokenName = "T_Decimal",	.TokenType = "Tipo"},
	{.Token = "double",	.TokenName = "T_Dobro",		.TokenType = "Tipo"},
	
	
	// Complementos dos Tipos de Variáveis
	{.Token = "const",		.TokenName = "T_Constante",		.TokenType = "ComplementoTipo"},
	{.Token = "short",		.TokenName = "T_Curto",			.TokenType = "ComplementoTipo"},
	{.Token = "static",		.TokenName = "T_Estatico",		.TokenType = "ComplementoTipo"},
	{.Token = "signed",		.TokenName = "T_Sinalizado",	.TokenType = "ComplementoTipo"},
	{.Token = "unsigned",	.TokenName = "T_NaoSinalizado",	.TokenType = "ComplementoTipo"},
	{.Token = "volatile",	.TokenName = "T_Volatil",		.TokenType = "ComplementoTipo"},
	{.Token = "register",	.TokenName = "T_Registrador",	.TokenType = "ComplementoTipo"},
	
	
	// Tipos Personalizados
	{.Token = "enum",		.TokenName = "T_Enumeracao",	.TokenType = "TipoPersonalizado"},
	{.Token = "union",		.TokenName = "T_Uniao",			.TokenType = "TipoPersonalizado"},
	{.Token = "struct",		.TokenName = "T_Estrutura",		.TokenType = "TipoPersonalizado"},
	{.Token = "typedef",	.TokenName = "T_DefinicaoTipo",	.TokenType = "TipoPersonalizado"},
	
	
	// Palavras Reservadas
	{.Token = "switch",		.TokenName = "T_Switch",	.TokenType = "PalavraReservada"},
	{.Token = "case",		.TokenName = "T_Case",		.TokenType = "PalavraReservada"},
	{.Token = "default",	.TokenName = "T_Default",	.TokenType = "PalavraReservada"},
	{.Token = "do",			.TokenName = "T_Do",		.TokenType = "PalavraReservada"},
	{.Token = "while",		.TokenName = "T_While",		.TokenType = "PalavraReservada"},
	{.Token = "if",			.TokenName = "T_If",		.TokenType = "PalavraReservada"},
	{.Token = "else",		.TokenName = "T_Else",		.TokenType = "PalavraReservada"},
	{.Token = "for",		.TokenName = "T_For",		.TokenType = "PalavraReservada"},
	{.Token = "goto",		.TokenName = "T_Goto",		.TokenType = "PalavraReservada"},
	{.Token = "break",		.TokenName = "T_Break",		.TokenType = "PalavraReservada"},
	{.Token = "continue",	.TokenName = "T_Continue",	.TokenType = "PalavraReservada"},
	{.Token = "return",		.TokenName = "T_Return",	.TokenType = "PalavraReservada"},
	
	
	// Diretivas
	{.Token = "#define",	.TokenName = "T_Define",	.TokenType = "Diretiva"},
	{.Token = "#include",	.TokenName = "T_Include",	.TokenType = "Diretiva"},
	
};



TokenTypes dicionarioSimbolosSimples[] =
{	
	// Símbolos
	{.Token = "{",	.TokenName = "T_Chave_Abre",		.TokenType = "Simbolos"},
	{.Token = "}",	.TokenName = "T_Chave_Fecha",		.TokenType = "Simbolos"},
	{.Token = "(",	.TokenName = "T_Parentese_Abre",	.TokenType = "Simbolos"},
	{.Token = ")",	.TokenName = "T_Parentese_Fecha",	.TokenType = "Simbolos"},
	{.Token = "[",	.TokenName = "T_Colchete_Abre",		.TokenType = "Simbolos"},
	{.Token = "]",	.TokenName = "T_Colchete_Fecha",	.TokenType = "Simbolos"},
	{.Token = "\"",	.TokenName = "T_AspaDupla",			.TokenType = "Simbolos"},
	{.Token = "\'",	.TokenName = "T_AspaSimples",		.TokenType = "Simbolos"},
	{.Token = ".",	.TokenName = "T_Ponto",				.TokenType = "Simbolos"},
	{.Token = ",",	.TokenName = "T_Virgula",			.TokenType = "Simbolos"},
	{.Token = ";",	.TokenName = "T_PentoVingula",		.TokenType = "Simbolos"},
	
	
	// Operadores
	{.Token = "*",	.TokenName = "T_Multiplicacao",	.TokenType = "Operador"},
	{.Token = "+",	.TokenName = "T_Soma",			.TokenType = "Operador"},
	{.Token = "/",	.TokenName = "T_Divisao",		.TokenType = "Operador"},
	{.Token = "-",	.TokenName = "T_Subtracao",		.TokenType = "Operador"},
	{.Token = "%",	.TokenName = "T_Modulo",		.TokenType = "Operador"},
	{.Token = ">",	.TokenName = "T_MaiorQ",		.TokenType = "Operador"},
	{.Token = "<",	.TokenName = "T_MenorQ",		.TokenType = "Operador"},
	
};



TokenTypes dicionarioSimbolosCompostos[] =
{
	// Operadores	
	{.Token = ">=",	.TokenName = "T_MaiorIgualQ",	.TokenType = "Operador"},
	{.Token = "<=",	.TokenName = "T_MenorIgualQ",	.TokenType = "Operador"},
	{.Token = "==",	.TokenName = "T_Igual",			.TokenType = "Operador"},
	{.Token = "!=",	.TokenName = "T_Diferente",		.TokenType = "Operador"},
	{.Token = "=",	.TokenName = "T_Atribuicao",	.TokenType = "Operador"},
	{.Token = "!",	.TokenName = "T_Negacao",		.TokenType = "Operador"},
	{.Token = "&&",	.TokenName = "T_E_Logico",		.TokenType = "Operador"},
	{.Token = "||",	.TokenName = "T_Ou_Logico",		.TokenType = "Operador"},
	
	
	// Comentários
	{.Token = "//", .TokenName = "T_Comentario_Linha",	.TokenType = "Comentario"},
	{.Token = "/*", .TokenName = "T_Comentario_Inicio",	.TokenType = "Comentario"},
	{.Token = "*/", .TokenName = "T_Comentario_Fim",	.TokenType = "Comentario"},
	
};



TokenTypes TokenNulo = {.Token = NULL,	.TokenName = NULL,	.TokenType = NULL};




void CriarDicionario()
{
	int x = 0;
	
	while(dicionario[x].Token)
	{
		printf("\n %s - %s - %s", dicionario[x].Token, dicionario[x].TokenName, dicionario[x].TokenType);
		x++;
	}
	
}



TokenTypes ProcurarPalavraReservada(char *string)
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



TokenTypes ProcurarSimbolo(char *string)
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






