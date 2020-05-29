
#include <stdio.h>
#include <stdlib.h>

#include "Constantes.h"
#include "EstruturasTipos.h"

#include "Arquivos.h"
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"
#include "PalavrasReservadas.h"



FILE *ponteiroArquivo = NULL;

 boolean AbrirArquivo(char* nomeDoArquivo)
 {
 	ponteiroArquivo = fopen(nomeDoArquivo, "r");
 	 	
 	if(ponteiroArquivo != NULL)
 		return TRUE;
 	return FALSE;
 }
 
 
 boolean FecharArquivo()
 {
 	if(fclose(ponteiroArquivo) == 0)
 	{
 		ponteiroArquivo = NULL;
 		return TRUE;
	}
 	return FALSE;
 }
 
 
 char LerCaractereDoArquivo()
 {
 	return fgetc(ponteiroArquivo);
 }
