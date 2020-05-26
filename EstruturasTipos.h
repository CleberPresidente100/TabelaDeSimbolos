
#ifndef ESTRUTURAS_TIPOS
	#define ESTRUTURAS_TIPOS 1
		
	typedef char boolean;
	
	
	
	struct KEY_VALUE_PAIR
	{
		int Key;
		char* Value;
		
	};
	typedef struct KEY_VALUE_PAIR KeyValuePair;
	
	// Lista de Tokens V�lidos
	struct TOKEN_TYPES
	{
		char* Token;
		char* TokenName;
		char* TokenType;
	};
	typedef struct TOKEN_TYPES TokenTypes;
	
	// Tabela de S�mbolos � Criada utilizando-se algor�tmos de �rvores N-�rias
	struct TABELA_SIMBOLOS
	{
		char* Identificador;
		long int Endereco;
		KeyValuePair Tipo;
		KeyValuePair ComplementoTipo;
		char* Classe;
		KeyValuePair Escopo;
		char* Parametros;
		boolean Ativa;
		boolean Utilizada;
		
		struct TABELA_SIMBOLOS* Proximo;
		struct TABELA_SIMBOLOS* Anterior;
		
	};
	typedef struct TABELA_SIMBOLOS TabelaSimbolos;

#endif
