# LI2
links importantes, 
https://typst.app/project/rxbrgj547KczgA3QrmkJRi  guiao
## COMO PROGRAMAR
Aqui voces vao ter um mini tutorial para compilar, projetar e resolver isto, simao nao estragues tudo.

As tarefas vou dividilas no trello e cada grupo de funcoes devem ser feitas num ficheiro que nao o main.
Ate a primeira avaliacao vamos escrevelas na funcoes1.c e depois cria-se o 2 e assim diante (NADA NO MAIN POR AGORA, so para configurar printf e scanf).
Cada funcao que irao usar tem de ser definida a base dela em funcao1.h como por exemplo:

### No .c esta:

int soma(int x,int y){
    return x + y;
}

### No .h tem de a definir como:

int soma(int x,int y);

### Para compilar:

Para compilar o ficheiro para "exec" colem isto na consola (o -lm pode desaparecer se nao usarmos as funcoes math):

gcc main.c -o exec -lm

Para executar:

./exec

## PARA TRABALHAR COM O GITHUB

Só fazer uma vez(Na pasta que voces querem guardar o trabalho):

git clone git@github.com:Herculano-Esteves/LI2.git

Criem a vossa branch:

git checkout -b <vosso nome>

git switch <a tua branch> (vais ter à tua branch, em principio vais lá dar direto)

git push --set-upstream origin <vosso nome>


### Funcoes que se vao cansar de usar

para dar push usem

git add .
git commit -m "<as alteracoes que fizeram TEXTO PEQUENO>"
git push

LEMBREM-SE DE FAZER ISTO NA VOSSA BRANCH NAO NOUTRA

### PARA DAR PULL AO MERGE

depois de me avisarem de tudo eu dou merge ao que voces fazem e apos isso tem de atualizar a vossa branch do vosso pc, para isso facam:

git pull


(só para mim para nao me esquecer nao presisam de ler mais)
git switch <nome>
git pull
git switch <minha>
git merge <nome>
git push