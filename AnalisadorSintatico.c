

#include "Bibliotecas.h"

#define VALOR_INDEFINIDO "(undefined)"

#define ESTADO_INICIAL 0
#define ESTADO_FINAL ~(unsigned int)0
#define DECLARACAO_PARAMETRO (ESTADO_FINAL - 1)
#define DECLARACAO_MULTIPLAS_VARIAVEIS (ESTADO_FINAL - 2)



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
		simboloDaTabela = VerificaSeEhFuncao(&listaTokens);
		if(simboloDaTabela.Id != NULO)
		{
			AdicionarSimboloTabelaDeSimbolos(&simboloDaTabela, escopo);
			continue;
		}
		
		simboloDaTabela = VerificaSeEhVariavel(&listaTokens, FALSE);
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
		
		// Muda para o Pr�ximo Token da lista.
		listaTokens = listaTokens->Proximo;
	}
	
	// Breakpoint para Teste
	escopo = ESCOPO_GLOBAL;
	
}



TabelaSimbolos VerificaSeEhVariavel(Tokens** listaTokens, boolean EhParametro)
{
	unsigned int estado = ESTADO_INICIAL;
	
	Tokens *listaTokensAuxiliar = NULL;
	TabelaSimbolos simboloDaTabela;
	
	listaTokensAuxiliar = *listaTokens;
	simboloDaTabela = CriarSimboloNulo();
	
	while(TRUE)
	{
		switch (estado)
		{
			// INICIO DA M�QUINA DE ESTADOS
			case ESTADO_INICIAL:
							
				// Verifica se � um Modificador de Tipo
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ModificadorTipo)
				{
					estado = CL_ModificadorTipo;
					simboloDaTabela.ModificadorTipo = CL_ModificadorTipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se � um Complemento de Tipo
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ComplementoTipo)
				{
					estado = CL_ComplementoTipo;
					simboloDaTabela.ComplementoTipo = CL_ComplementoTipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se � um Tipo
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
								
				// Verifica se � o Token "Ponto e V�gula"
				if(listaTokensAuxiliar->Lexema.LexemaId == T_PontoVingula)
				{
					estado = ESTADO_FINAL;
					continue;
				}
				
				// Verifica se � o Token Atribui��o
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Atribuicao)
				{
					estado = CL_IdentificadorNumerico;
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se � o Token V�rgula
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Virgula)
				{
					estado = T_Virgula;
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se � Fim da Declara��o de Par�metros
				if(EhParametro)
				{
					if(listaTokensAuxiliar->Lexema.LexemaId == T_Parentese_Fecha)
					{
						estado = ESTADO_FINAL;
						continue;
					}
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
			
			
			// ESTADO VIRGULA
			case T_Virgula:
							
				if(EhParametro)
				{
					// A Declara��o da Vari�vel foi Conclu�da.
					// Entretento o Token para o qual este Ponteiro est� indicando ainda n�o foi Processado.
					// Portanto, o Ponteiro � Reporsicionado para que o Token seja Devidamente Processado pelo Analisador Sint�tico.
					listaTokensAuxiliar = listaTokensAuxiliar->Anterior->Anterior;
					estado = ESTADO_FINAL;
					continue;
				}
				
				estado = DECLARACAO_MULTIPLAS_VARIAVEIS;
				continue;
				
			break;
			
			
			// ESTADO DECLARACAO DE MULTIPLAS VARI�VEIS
			case DECLARACAO_MULTIPLAS_VARIAVEIS:
				
				estado = ESTADO_FINAL;
				continue;
				
			break;
			
			
			// ESTADO FINAL
			case ESTADO_FINAL:
				// Finaliza cria��o do S�mbolo
				simboloDaTabela.Id = 1;
				simboloDaTabela.Classe = CLASSE_VARIAVEL;
				
				// Atualiza Ponteiro da Tabela de Tokens
				*listaTokens = listaTokensAuxiliar->Proximo;
				
				return simboloDaTabela;
			break;
			
			
			default:
				return simboloDaTabela;
		}
		
		return simboloDaTabela;
		
	}
	
	return simboloDaTabela;
}



TabelaSimbolos VerificaSeEhFuncao(Tokens** listaTokens)
{
	unsigned int estado = ESTADO_INICIAL;
	
	Tokens *listaTokensAuxiliar = NULL;
	TabelaSimbolos simboloDaTabela;
	TabelaSimbolos parametro;
	Parametros* listaParametros;
	TabelaSimbolos* enderecoParametroTabelaSimbolos;
	
	listaTokensAuxiliar = *listaTokens;
	simboloDaTabela = CriarSimboloNulo();
	
	while(TRUE)
	{
		switch (estado)
		{
			// INICIO DA M�QUINA DE ESTADOS
			case ESTADO_INICIAL:
								
				// Verifica se � um Complemento de Tipo
				if(listaTokensAuxiliar->Lexema.LexemaTypeId == CL_ComplementoTipo)
				{
					estado = CL_ComplementoTipo;
					simboloDaTabela.ComplementoTipo = CL_ComplementoTipo;					
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
				
				// Verifica se � um Tipo
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
								
				// Verifica se � o Token "Abre Parentese"
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Parentese_Abre)
				{
					estado = T_Parentese_Abre;
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					continue;
				}
			break;
			
			
			// ESTADO ABERTURA DE PARENTESE
			case T_Parentese_Abre:
								
				// Verifica se � o Token "Fecha Parentese"
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Parentese_Fecha)
				{
					estado = ESTADO_FINAL;
					continue;
				}
								
				// Verifica se � um Par�metro
				estado = DECLARACAO_PARAMETRO;
				continue;
				
			break;
			
			
			// ESTADO DECLARA��O DE PAR�METRO
			case DECLARACAO_PARAMETRO:
				
				// Verifica se � uma Vari�vel
				parametro = VerificaSeEhVariavel(&listaTokensAuxiliar, TRUE);
				if(parametro.Id != NULO)
				{
					enderecoParametroTabelaSimbolos = AdicionarSimboloTabelaDeSimbolos(&parametro, ESCOPO_LOCAL);
					AdicionarParametroNaListaParametros(listaParametros, &parametro, enderecoParametroTabelaSimbolos);
					estado = T_Virgula;
					continue;
				}
				
				listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
				estado = T_Parentese_Abre;
				continue;
				
			break;
			
			
			// ESTADO DECLARA��O DE MULTIPLOS PAR�METROS OU FINAL DA DECLARA��O DE PAR�METROS
			case T_Virgula:
				
				// Verifica se � o Token "Ponto e V�rgula"
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Virgula)
				{
					listaTokensAuxiliar = listaTokensAuxiliar->Proximo;
					estado = DECLARACAO_PARAMETRO;
					continue;
				}
							
				// Verifica se � o Token "Fecha Parentese"
				if(listaTokensAuxiliar->Lexema.LexemaId == T_Parentese_Fecha)
				{
					estado = ESTADO_FINAL;
					continue;
				}
			break;
			
			
			// ESTADO FINAL
			case ESTADO_FINAL:
				// Finaliza cria��o do S�mbolo
				simboloDaTabela.Id = 1;
				simboloDaTabela.Classe = CLASSE_FUNCAO;
				
				// Atualiza Ponteiro da Tabela de Tokens
				*listaTokens = listaTokensAuxiliar->Proximo;
				
				return simboloDaTabela;
			break;
			
			
			default:
				return simboloDaTabela;
		}
		
		return simboloDaTabela;
		
	}
	
	return simboloDaTabela;
}



void AdicionarParametroNaListaParametros(Parametros* listaParametros, TabelaSimbolos* parametro, TabelaSimbolos* enderecoParametroTabelaSimbolos)
{
	Parametros* novoParametro;
	Parametros* listaParametrosAuxiliar;
	
	// Reserva Mem�ria para o Novo Par�metro
	novoParametro = calloc(1, sizeof(Parametros));
	
	// Carrega as Informa��es no Novo Par�metro
	novoParametro->ParametroEnderecoSimbolo = enderecoParametroTabelaSimbolos;
	novoParametro->Anterior = NULL;
	novoParametro->Proximo = NULL;
	
	// Verifica se a Lista de Par�metros j� foi iniciada
	if(listaParametros == NULL)
	{
		listaParametros = novoParametro;
		return;
	}
			
	
	// Procura pelo �ltimo Registro da Lista de Par�metros
	listaParametrosAuxiliar = listaParametros;
	while(listaParametrosAuxiliar->Proximo != NULL)
	{
		listaParametrosAuxiliar = listaParametrosAuxiliar->Proximo;
	}
	
	// Insere o Novo Par�metro na Lista de Par�metros
	listaParametrosAuxiliar->Proximo = novoParametro;
	novoParametro->Anterior = listaParametrosAuxiliar;
}





