# TabelaDeSimbolos

Proposta:

Projeto da Disciplina Compiladores, ministrada pelo professor André, cujo objetivo é criar um programa em Linguagem C que faça a leitura de um código fonte escrito na linguagem C e Crie uma Tabela de Símbolos que seja capaz de listar Funções e Variáveis e exibir as seguintes informações sobre as mesmas: Identificador, Endereço, Tipo, Classe, Escopo, Parâmetro, Ativa.
Entretanto esta disciplina está sendo ministrada no semestre em que o Corona Vírus chegou ao Brasil, logo a qualidade da mesma foi comprometida, já que ela foi planejada para ser presencial e teve que ser adaptada as pressas para um modelo de vídeo conferência.
Consequentemente, devido ao tempo perdido para se adaptar de Aulas Presenciais para Aulas Virtuais e a não exitência de um Laboratório onde o professor poderia nos auxiliar com a construção do compilador durante cada aula . . . invés de um compilador completo, estamos desenvolvendo apenas uma Tabela de Símbolos.
Outro ponto é que como temos apenas 1 mês para pesquisa e desenvolvimento desta tabela, o professor nos autorizou a utilizar quaisquer meios para se chegar nesta Tabela, invés de utilizarmos as técnicas de compiladores, as quais exigiriam um estudo mais profundo sobre autômatos e algorítimos. E, infelizmente, o suporte necessário para estes estudos extras se tornou um luxo que não temos.

O projeto foi criado utilizando-se a linguagem C no ambiente Dev C++.


Desenvolvimento:

Inicialmente, a minha ideia era fazer um programa que gerasse diretamente a Tabela de Símbolos sem precisar passar pelas três fases da Etapa Analítica (Análise Léxica, Análise Sintática e Análise Semantica).
E logo após as primeiras tentativas de desenhar o sistema desta forma, eu percebi que a forma mais simples e fácil seria executando todas as três fases da Etapa Analítica.
Consequentemente, eu comecei a estudar e desenvolver os primeiros racunhos da Análise Lexica. Com os estudos, percebi que não havia tempo hábil para se estudar e desenvolver por completo um Analisador Léxico da Linguagem C, menos ainda para se desenvolver um Analisador Sintático e que um Analisador Semântico estava totalmente fora de questão.
Portanto eu cheguei a conclusão que eu deveria fazer um Analisador Léxico (Lexer) com regras suficientes apenas para se categorizar e gerar os Tokens fazendo assim que os mesmos pudessem ser utilizados pela Análise Sintática (Parser). E no Parser, existiria uma lógica suficiente apenas para se identificar as Funções e as Variáveis existentes no código e nada além disto, pois, como já dito, não haveria tempo suficiente para se estudar as lógicas e algoritmos necessários para se criar um Lexer e um Parser completos.
Decidi então iniciar pela construção do Lexer.
Criar o Lexer foi a parte mais complexa e a que demandou mais tempo de estudo, pois foi necessário entender todas as outras três fases da Análise para saber quais são os limites do Lexer e quais informações ele deve e quais ele não deve extrair do texto que está sendo analisado e quais informações ele deve inserir no Token para que o mesmo possa ser processado pelo Parser.
Já o Parser, para criá-lo eu decidi por utilizar simples máquinas de estado para ler os Tokens e identificar as sequências de Tokens que formavam variáveis e funções e adicionar as mesmas na Tabela de Símbolos (que era o objetivo do projeto).
Exibir as informações de Erro geradas pelo Lexer, a Tabela de Tokens e a Tabela de Símbolos, foram um outro desafio. Devido a limitação visual do console, a melhor alternativa em que consequi chegar foi exibir as informações através de arquivos texto.


Conclusão:

Foi realmente um desafio realizar esta tarefa sem um suporte mais enfático, no mesmo nível do que é conseguido através de aulas presenciais. Principalmente pelo fato de não ter tido uma base de Autômatos (que nada mais é do que a base de toda a teoria de Compiladores).
O tempo também foi outro fator importante. Apesar de 1 mês parecer muito, na verdade é pouco para se estudar um assunto tão abstrato quanto Autômatos e Compiladores e com um suporte na internet tão fraco (falo sobre pesquisas realizadas em inglês, pois em português este material é quase inexistente).
Por fim, apesar do projeto não ter sido concluído, eu atingi um sucesso razoável. Para medir o sucesso do projeto, eu o dividi nas seguintes partes:

1) Construir um Analisador Léxico;
2) Construir uma Tabela de Erros Léxicos;
3) Construir uma Tabela de Tokens;
4) Construir um Analisador Sintático;
5) Construir uma Tabela de Símbolos;
6) Criar um Arquivo para armazenar a Tabela de Tokens;
7) Criar um Arquivo para armazenar a Tabela de Erros;
8) Criar um Arquivo para armazenar a Tabela de Símbolos;

O Lexer(1), a Tabela de Tokens(3) e o Arquivo com a Tabela de Tokens foram concluídos(6).
A Tabela de Erros Léxicos(2 e 7) não foi populada, entretanto a sua estrutura e lógica para se determinar o que é um erro e popular a mesma foram criadas com sucesso. Logo popular a tabela e a salvar em um arquivo seria somente uma questão de copiar a lógica que preenche a Tabela de Tokens e a coloca em um arquivo.
O Parser(4) está cerca de 98% pronto e a Tabela de Símbolos(5) está sendo populada corretamente, logo também foi concluída. O que nos deixa apenas com a criação do arquivo da Tabela de Símbolos(8). O que, seria apenas uma questão de copiar a lógica utilizada para se salvar a Tabela de Tokens em arquivo.

Consequentemente, apesar do projeto ainda não ter sido concluído, ele está muito próximo de sua conclusão, restando apenas detalhes no Parser e copiar a lógica de partes do código para se gerar a Tabela de Erros Léxicos e os arquivos para se armazenar a Tabela de Erros Léxicos e a Tabela de Símbolos.






