
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas.h"

void ExibirTabelaTokens();

int main(int argc, char** argv) {
	
	char nomeDoArquivo[256];
	boolean erroArquivo = FALSE;
	
	/*
	Tokens* token = NULL;
	unsigned int tamanho;
	Lexemas lexema;
	Lexemas lexemaAuxiliar;
	*/
	
	/*
	tamanho = sizeof(*token);
	printf("\n Tamanho *token = %d", tamanho);
	
	tamanho = sizeof(token);
	printf("\n Tamanho token = %d", tamanho);
	
	tamanho = sizeof(Tokens);
	printf("\n Tamanho token = %d", tamanho);
	*/
	
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
	
	/*
	lexema = CriarLexemaIdentificador("teste");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	lexema = CriarLexemaIdentificador("teste2");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	lexema = CriarLexemaIdentificador("teste3");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	lexema = CriarLexemaIdentificador("teste4");
	AdicionarLexemaListaTokens(&lexema, 1, 1);
	
	ExibirTabelaTokens();	
	
	lexema = CriarLexemaIdentificador("teste5");	
	ModificarTokenListaTokens(2, &lexema);
		
	ExibirTabelaTokens();
		
	ExcluirTokenListaTokens(3);
		
	ExibirTabelaTokens();
		
	ExcluirTokenListaTokens(1);
		
	ExibirTabelaTokens();
		
	ExcluirTokenListaTokens(4);
		
	ExibirTabelaTokens();
		
	ExcluirTokenListaTokens(2);
	
	ExibirTabelaTokens();
	
	printf("\n\n\n");
	
	*/
	
	
	
	
	
	
	
	
	
		
	/*
	printf("\n\n Digite o nome do arquivo: ");
	scanf("%s", &nomeDoArquivo);
	erroArquivo = AbrirArquivo(&nomeDoArquivo[0], MODO_LEITURA);
	*/
	
	erroArquivo = AbrirArquivo("teste.txt", MODO_LEITURA);
	if(erroArquivo == FALSE)
	{
		printf("\n\n Não foi possível Abrir o Arquivo.");
	}
	else
	{
		printf("\n\n Arquivo Aberto com Sucesso.");
	}
	
	
	
	
	RealizarAnaliseLexica();
//	RealizarAnaliseSintatica();
	//CriaArquivoTokens(listaTokens);
	//CriaArquivoTabelaSimbolos(tabelaDeSimbolos);
	ExibirTabelaTokens();
	
	
	erroArquivo = FecharArquivo();
	if(erroArquivo == TRUE)
	{
		printf("\n\n Arquivo Fechado com Sucesso.");
	}
	else
	{
		printf("\n\n Não foi possível Fechar o Arquivo.");
	}
	
	
	
	GravarTabelaDeTokensEmArquivo("teste.txt");
	
	printf("\n\n\n");
	return 0;
//	*/
	
//	LiberarMemoriaTabelaErros();
	LiberarMemoriaTabelaTokens();
//	LiberarMemoriaTabelaSimbolos();
}



void ExibirTabelaTokens()
{
	Tokens* token = NULL;
	LexemasReservados lexemaReservado;
	
	token = GetTabelaTokens();
	
	while(token)
	{
		lexemaReservado = ObterLexemaReservado(token->Lexema.LexemaId);
		
		printf("\n\n\n");
		printf("\n token->TokenId              = %d", token->TokenId);
		printf("\n token->Lexema.LexemaId      = %d", token->Lexema.LexemaId);
		printf("\n Palavra Reservada           = %s", lexemaReservado.Lexema);
		printf("\n token->Lexema.Identificador = %s", token->Lexema.Identificador);
		printf("\n Categoria Lexema            = %s", lexemaReservado.LexemaType.Name);
		printf("\n token->Linha                = %d", token->Linha);
		printf("\n token->Coluna               = %d", token->Coluna);
		printf("\n token->Anterior             = %d", token->Anterior);
		printf("\n token->Proximo              = %d", token->Proximo);
		
		token = token->Proximo;
	}
	
	printf("\n\n------------------------------------------");
	
	return;
}





