

#include "Bibliotecas.h"




FILE *ponteiroArquivo = NULL;

boolean AbrirArquivo(char* nomeDoArquivo, char* modoDeAbertura)
{
	ponteiroArquivo = fopen(nomeDoArquivo, modoDeAbertura);
		
	if(ponteiroArquivo != NULL)
		return TRUE;
	return FALSE;
}



boolean FecharArquivo()
{
	if(ponteiroArquivo != NULL)
	{		
		if(fclose(ponteiroArquivo) == 0)
		{
			ponteiroArquivo = NULL;
			return TRUE;
		}
	}
	
	return FALSE;
}



char LerCaractereDoArquivo()
{
	return fgetc(ponteiroArquivo);
}



void GravarStringNoArquivo(char* string)
{
	
}







