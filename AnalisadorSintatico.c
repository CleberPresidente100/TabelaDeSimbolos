

#include "Bibliotecas.h"

#define VALOR_INDEFINIDO "(undefined)"

#define ESTADO_INICIAL 0
#define ESTADO_FINAL ~(unsigned int)0

#define CLASSE_FUNCAO 1
#define CLASSE_VARIAVEL 2
#define CLASSE_PROTOTIPO_FUNCAO 3




void RealizarAnaliseSintatica()
{
	char escopo = ESCOPO_GLOBAL;
	unsigned int contadorEscopo = 0;
	
	Tokens *listaTokens = NULL;
	TabelaSimbolos simboloDaTabela;
	unsigned int estado = ESTADO_INICIAL;
	
	
	listaTokens = GetTabelaTokens();
	
	while(listaTokens != NULL)
	{
		simboloDaTabela = VerificaSeEhFuncao(listaTokens);
		if(simboloDaTabela.Id != NULO)
		{
			AdicionarSimboloTabelaDeSimbolos(&simboloDaTabela, escopo);
			continue;
		}
		
		simboloDaTabela = VerificaSeEhVariavel(listaTokens);
		if(simboloDaTabela.Id != NULO)
		{
			AdicionarSimboloTabelaDeSimbolos(&simboloDaTabela, escopo);
			continue;
		}
		
		
		
		// Contabiliza Abertura de Escopos
		if(listaTokens->Lexema.LexemaId == T_Chave_Abre)
		{
			contadorEscopo++;
			escopo = ESCOPO_LOCAL;
		}
		
		// Contabiliza Fechamento de Escopos
		if(listaTokens->Lexema.LexemaId == T_Chave_Fecha)
		{
			if(contadorEscopo > 1)
			{
				contadorEscopo--;
			}
			else
			{				
				contadorEscopo = 0;
				escopo = ESCOPO_GLOBAL;
			}
		}
		
		// Muda para o Próximo Token da lista.
		listaTokens = listaTokens->Proximo;		
	} 
	
}



TabelaSimbolos VerificaSeEhVariavel(Tokens *listaTokens)
{
	unsigned int estado = ESTADO_INICIAL;
	
	Tokens *listaTokensAuxiliar = NULL;
	TabelaSimbolos simboloDaTabela;
	
	listaTokensAuxiliar = listaTokens;
	simboloDaTabela = CriarSimboloNulo();
	
	while(TRUE)
	{
		switch (estado)
		{
			// INICIO DA MÁQUINA DE ESTADOS
			case ESTADO_INICIAL:
							
				// Verifica se é um Modificador de Tipo
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ModificadorTipo)
				{
					estado = CL_ModificadorTipo;
					simboloDaTabela.ModificadorTipo = CL_ModificadorTipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se é um Complemento de Tipo
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ComplementoTipo)
				{
					estado = CL_ComplementoTipo;
					simboloDaTabela.ComplementoTipo = CL_ComplementoTipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se é um Tipo
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_Tipo)
				{
					estado = CL_Tipo;
					simboloDaTabela.Tipo = CL_Tipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}				
			break;
			
			
			// ESTADO MODIFICADOR DE TIPOS
			case CL_ModificadorTipo:
								
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ComplementoTipo)
				{
					estado = CL_ComplementoTipo;
					simboloDaTabela.ComplementoTipo = CL_ComplementoTipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_Tipo)
				{
					estado = CL_Tipo;
					simboloDaTabela.Tipo = CL_Tipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
			break;
			
			
			// ESTADO COMPLEMENTO DE TIPOS
			case CL_ComplementoTipo:
							
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_Tipo)
				{
					estado = CL_Tipo;
					simboloDaTabela.Tipo = CL_Tipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
			break;
			
			
			// ESTADO TIPO
			case CL_Tipo:
							
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == T_IdentificadorString)
				{
					estado = T_IdentificadorString;
					simboloDaTabela.Identificador = listaTokensAuxiliar->Lexema.Identificador;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
			break;
			
			
			// ESTADO IDENTIFICADOR STRING
			case T_IdentificadorString:
								
				// Verifica se é o Símbolo "Ponto e Vígula"
				if(listaTokensAuxiliar->Lexema.LexemaId == T_PontoVingula)
				{
					estado = ESTADO_FINAL;
					continue;
				}
				
				// Verifica se é o Símbolo Atribuição
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Atribuicao)
				{
					estado = CL_IdentificadorNumerico;
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
			break;
			
			
			// ESTADO IDENTIFICADOR NUMERICO OU CONSTANTE STRING
			case CL_ConstanteTexto:
			case CL_IdentificadorNumerico:
							
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ConstanteTexto)
				{
					estado = T_PontoVingula;
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
							
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_IdentificadorNumerico)
				{
					estado = T_PontoVingula;
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
			break;
			
			
			// ESTADO PONTO E VIRGULA
			case T_PontoVingula:
							
				if(listaTokensAuxiliar->Lexema.LexemaId == T_PontoVingula)
				{
					estado = ESTADO_FINAL;
					continue;
				}
			break;
			
			
			// ESTADO FINAL
			case ESTADO_FINAL:
				// Finaliza criação do Símbolo
				simboloDaTabela.Id = 1;
				simboloDaTabela.Classe = CLASSE_VARIAVEL;
				
				// Atualiza Ponteiro da Tabela de Tokens
				listaTokens = listaTokensAuxiliar;
				
				return simboloDaTabela;
			break;
			
			
			default:
				return simboloDaTabela;
		}
		
		return simboloDaTabela;
		
	}
	
	return simboloDaTabela;
}



TabelaSimbolos VerificaSeEhFuncao(Tokens *listaTokens)
{
	Tokens *listaAuxiliar = NULL;
	TabelaSimbolos simboloDaTabela;
	
	simboloDaTabela = CriarSimboloNulo();
	
	
	
	
	
	
	
		// Caso existam parâmetros
		simboloDaTabela = VerificaSeEhVariavel(listaTokens);
		if(simboloDaTabela.Id != NULO) AdicionarSimboloTabelaDeSimbolos(&simboloDaTabela, ESCOPO_LOCAL);
	
	
	
	
	return simboloDaTabela;
}





