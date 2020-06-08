
#ifndef ENUMERACOES
	#define ENUMERACOES 1
	
	enum Enums {

		// Tipos de Variáveis
		T_Inteiro = 1,
		T_Caractere,
		T_Vazio,
		T_Longo,
		T_Decimal,
		T_Dobro,	
	
		// Complementos de Tipo de Variável
		T_Curto,
		T_Sinalizado,
		T_NaoSinalizado,	
	
		// Modificadores de Tipo de Variável
		T_Constante,
		T_Volatil,
		T_Registrador,	
	
		// Tipos Personalizados
		T_Enumeracao,
		T_Uniao,
		T_Estrutura,
		T_DefinicaoTipo,	
	
		// Palavras Reservadas
		T_Switch,
		T_Case,
		T_Default,
		T_Do,
		T_While,
		T_If,
		T_Else,
		T_For,
		T_Goto,
		T_Break,
		T_Continue,
		T_Return,	
	
		// Diretivas
		T_Define,
		T_Include,

		// Símbolos
		T_Chave_Abre,
		T_Chave_Fecha,
		T_Parentese_Abre,
		T_Parentese_Fecha,
		T_Colchete_Abre,
		T_Colchete_Fecha,
		T_AspaDupla,
		T_AspaSimples,
		T_Ponto,
		T_Virgula,
		T_PontoVingula,	
		T_Barra,	
		
		// Operadores
		T_Multiplicacao,
		T_Soma,
		T_Divisao,
		T_Subtracao,
		T_Modulo,
		T_MaiorQ,
		T_MenorQ,
		T_MaiorIgualQ,
		T_MenorIgualQ,
		T_Igual,
		T_Diferente,
		T_Atribuicao,
		T_Negacao,
		T_E_Logico,
		T_Ou_Logico,		
		
		// Comentários
		T_Comentario_Linha,
		T_Comentario_Inicio,
		T_Comentario_Fim,
		
		// Extras
		T_Invalido,
		T_Identificador,

		// Categorias de Lexemas
		CL_Tipo,
		CL_ComplementoTipo,
		CL_ModificadorTipo,
		CL_TipoPersonalizado,
		CL_PalavraReservada,
		CL_Diretiva,
		CL_Simbolos,
		CL_Operador,
		CL_Comentario,
		CL_Invalido,
		CL_Identificador,
		
	};
	
#endif






