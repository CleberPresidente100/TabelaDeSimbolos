
typedef bool char



struct KEY_VALUE_PAIR
{
	char* Key;
	char* Value;
};
typedef struct KeyValuePair;

// Tabela de Símbolos é Criada utilizando-se algorítmos de Árvores N-árias
struct TABELA_DE_SIMBOLOS
{
	char* Identificador;
	long int Endereço;
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
