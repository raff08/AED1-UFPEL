
# Trabalho Agenda <h1>
**Nome: Rafael Freitas** ---
**Mátricula: 20201917**

Exercicio: Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.
Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
Implementar a base de dados da agenda usando lista duplamente ligada 

- Link para o repositório no github: https://github.com/raff08/AED1-UFPEL

- Link para vídeo de demonstração: https://drive.google.com/file/d/1Q9KgQtP1Ob76dbMvxuFVdFhU685wNoWK/view?usp=share_link

##

Abra o terminal onde está localizado o arquivo .c.
Compile:
gcc nomeArquivo.c -o nomeArquivo.exe

E depois execute o programa:
.\nomeArquivo.exe

Para utilizar os arquivos teste.txt presente em algumas das pastas, baixe-os se não tiver feito, coloque na mesma pasta do arquivo .c e execute o programa (após compilação):
.\nomeArquivo.exe < teste.txt
