
typedef bool char



struct KEY_VALUE_PAIR
{
	char* Key;
	char* Value;
};
typedef struct KeyValuePair;

// Tabela de S�mbolos � Criada utilizando-se algor�tmos de �rvores N-�rias
struct TABELA_DE_SIMBOLOS
{
	char* Identificador;
	long int Endere�o;
	KeyValuePair Tipo;
	KeyValuePair ComplementoTipo;
	char* Classe;
	KeyValuePair Escopo;
	char* Parametros;
	bool Ativa;
	bool Utilizada;
	TABELA_DE_SIMBOLOS* Proximo;
	TABELA_DE_SIMBOLOS* Anterior;
};
typedef struct TabelaSimbolos;
