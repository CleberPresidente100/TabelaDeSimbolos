
#ifndef ESTRUTURAS_TIPOS
	#define ESTRUTURAS_TIPOS 1
		
	typedef char boolean;
	
	typedef struct KEY_VALUE_PAIR KeyValuePair;
	typedef struct LEXEMAS_RESERVADOS LexemasReservados;
	typedef struct LEXEMAS Lexemas;
	typedef struct TOKENS Tokens;
	typedef struct ERROS Erros;
	typedef struct TABELA_SIMBOLOS TabelaSimbolos;
	typedef struct PARAMETROS Parametros;
	
	
	
	// ESTRUTURA PAR DE CHAVE-VALOR	
	struct KEY_VALUE_PAIR
	{
		char* Name;
		unsigned int Id;
	};
	
	
	// Estrutura dos Lexemas Reservados
	struct LEXEMAS_RESERVADOS
	{
		char* Lexema;
		KeyValuePair LexemaName;
		KeyValuePair LexemaType;
	};	
	
	
	// Estrutura do Lexema que será armazenado no Token.
	struct LEXEMAS
	{
		unsigned int LexemaId;
		unsigned int LexemaTypeId;
		
		// O Campo abaixo é utilizado apenas quando o Lexema for um Identificador/Constante		
		char* Identificador; // Armazena o ponteiro da String do Identificador/Constante.
	};
	
	
	// Estrutura da Lista de Tokens
	struct TOKENS
	{
		Lexemas Lexema;
		unsigned int Linha;
		unsigned int Coluna;
		unsigned int TokenId;
		struct TOKENS* Anterior;
		struct TOKENS* Proximo;
	};
	
	
	// Estrutura da Lista de Erros
	struct ERROS
	{
		Lexemas Lexema;
		char*	MensagemErro;
		unsigned int Linha;
		unsigned int Coluna;
		struct ERROS* Anterior;
		struct ERROS* Proximo;
	};
		
	
	// Estrutura da Tabela de Símbolos
	struct TABELA_SIMBOLOS
	{
		unsigned int Id;
		unsigned int Tipo;
		unsigned int ComplementoTipo;
		unsigned int ModificadorTipo;
		char* Identificador;
		long int Endereco;
		char Classe; // Função, Variável, Prototipo de Função
		char Escopo;
		Parametros* ListaParametros;
		boolean Ativa;
		
		struct TABELA_SIMBOLOS* Proximo;
		struct TABELA_SIMBOLOS* Anterior;
		
	};
	
	
	// Estrutura da Lista de Parâmetros
	struct PARAMETROS
	{
		TabelaSimbolos* ParametroEnderecoSimbolo;
		
		struct PARAMETROS* Anterior;
		struct PARAMETROS* Proximo;
	};

#endif




