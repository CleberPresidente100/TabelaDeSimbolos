
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas.h"

void ExibirTabelaTokens();

int main(int argc, char** argv) {
	
	char nomeDoArquivo[256];
	boolean erroArquivo = FALSE;
	
	Tokens* token = NULL;
	unsigned int tamanho;
	Lexemas lexema;
	Lexemas lexemaAuxiliar;
	
	tamanho = sizeof(*token);
	printf("\n Tamanho *token = %d", tamanho);
	
	tamanho = sizeof(token);
	printf("\n Tamanho token = %d", tamanho);
	
	tamanho = sizeof(Tokens);
	printf("\n Tamanho token = %d", tamanho);
	/*
	tamanho = sizeof(token.Anterior);
	printf("\n Tamanho token.Anterior = %d", tamanho);
	
	tamanho = sizeof(token.Lexema);
	printf("\n Tamanho token.Lexema = %d", tamanho);
	
	tamanho = sizeof(token.Lexema.Lexema);
	printf("\n Tamanho token.Lexema.Lexema = %d", tamanho);
	
	tamanho = sizeof(token.Lexema.LexemaName);
	printf("\n Tamanho token.Lexema.LexemaName = %d", tamanho);
	
	tamanho = sizeof(token.Lexema.LexemaName.Id);
	printf("\n Tamanho token.Lexema.LexemaName.Id = %d", tamanho);
	
	tamanho = sizeof(token.Lexema.LexemaName.Name);
	printf("\n Tamanho token.LexemaLexemaName.Name = %d", tamanho);
	*/
	
	
	lexema = CriarLexemaIdentificador("teste");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	lexema = CriarLexemaIdentificador("teste2");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	lexema = CriarLexemaIdentificador("teste3");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	
	ExibirTabelaTokens();	
	
	lexema = CriarLexemaIdentificador("teste4");	
	ModificarTokenListaTokens(2, &lexemaAuxiliar);
		
	ExibirTabelaTokens();
		
	ExcluirLexemaListaTokens(1);
		
	ExibirTabelaTokens();
		
	ExcluirLexemaListaTokens(2);
		
	ExibirTabelaTokens();
		
	ExcluirLexemaListaTokens(1);
	
	ExibirTabelaTokens();
	
	printf("\n\n\n");
	
	
	
	
	
	
	
	
	
	
	
		
	/*
	printf("\n\n Digite o nome do arquivo: ");
	scanf("%s", &nomeDoArquivo);
	erroArquivo = AbrirArquivo(&nomeDoArquivo[0]);
	erroArquivo = AbrirArquivo("teste.txt");
	if(erroArquivo == FALSE)
	{
		printf("\n\n Não foi possível Abrir o Arquivo.");
	}
	else
	{
		printf("\n\n Arquivo Aberto com Sucesso.");
	}
	
	
	
	
	RealizarAnaliseLexica();
	RealizarAnaliseSintatica();
	//CriaArquivoTokens(listaTokens);
	//CriaArquivoTabelaSimbolos(tabelaDeSimbolos);
	//ExibirTabelaSimbolos();
	
	
	
	erroArquivo = FecharArquivo();
	if(erroArquivo == TRUE)
	{
		printf("\n\n Arquivo Fechado com Sucesso.");
	}
	else
	{
		printf("\n\n Não foi possível Fechar o Arquivo.");
	}
	
	printf("\n\n\n");
	return 0;*/
	
//	LiberarMemoriaTabelaErros();
	LiberarMemoriaTabelaTokens();
//	LiberarMemoriaTabelaSimbolos();
}



void ExibirTabelaTokens()
{
	Tokens* token = NULL;
	
	token = GetTabelaTokens();
	
	while(token)
	{
		printf("\n\n\n");
		printf("\n %d", token->TokenId);
		printf("\n %d", token->Lexema.LexemaId);
		printf("\n %s", token->Lexema.Identificador);
		printf("\n %d", token->Linha);
		printf("\n %d", token->Coluna);
		printf("\n %d", token->Anterior);
		printf("\n %d", token->Proximo);
		
		token = token->Proximo;
	}
	
	printf("\n\n------------------------------------------");
	
	return;
}





