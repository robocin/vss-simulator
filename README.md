## VSS Simulator
- Simulador para Very Small Soccer Sizer Soccer League [by Rodetas](https://vss-sdk.github.io/book/general.html)
- API para controle dos robôs. [by RobôCIn](www.cin.ufpe.br/~robocin)

# Instalação

O simulador é divido em vários softwares. Para instalar, é necessário estar em um computador **Ubuntu** e executar os seguintes comandos em ordem a partir da pasta base desse projeto (VSS-Projeto).

~~~~
cd VSS-Core
sudo ./configure.sh
~~~~

~~~~
cd VSS-Simulator
sudo ./configure.sh
~~~~

~~~~
cd VSS-Viewer
sudo ./configure.sh
~~~~

# Executando o simulador

Para utilizar o simulador, você deve executar os softwares instalados em ordem. Para cada software, a execução se dá chamando o binário presente na pasta build. Um exemplo para execução do projeto pode ser conferida abaixo.

Abra dois terminais cada bloco de comando abaixo em um terminal diferente, seguindo a ordem.

~~~~
cd VSS-Simulator
./build/vss-simulator
~~~~

~~~~
cd VSS-Viewer
./build/vss-viewer
~~~~

Ao terminar de executar os comandos, uma tela semelhante a de baixo deve aparecer:

![Simulador](/simulador.jpg)

**Você pode mover os robôs e a bola com o mouse. É aconselhável que você retire os robôs que não estiver utilizando.** 

## Executando o código base 

Para compilar e executar o código base, você deve executar os seguintes comando em um novo terminal.

~~~~
cd VSS-SampleCpp
sudo ./configure.sh
./build/vss-sample -t TEAM
~~~~

onde TEAM é uma flag que informa qual time você irá controlar. Você pode atribuir dois valores possíveis para essa tag:

- blue 
- yellow

Caso essa tag não seja passada para o programa, o código irá atribuir o time amarelo por padrão.

Dessa forma, seu terminal deve informar que você está conectado. Agora, para iniciar o jogo, você deve ir na tela do simulador como à acima e apertar **espaço** para iniciar o jogo. 


### Controles do simulador

- **Espaço** : Inicia/Pausa o jogo no simulador
- **c** : Muda a pespectiva da câmera

## Editando o código

Cada robô é controlado por uma das classes `generic_playerX.hpp`, onde X simboliza o ID do jogador. O código padrão movimenta os 3 robos para que os mesmos fiquem alinhados na linha do centro do campo, semelhante à imagem abaixo:

![Position](/positioned.jpg)


Para modificar o comportamento dos jogadores, você deve editar um dos arquivos `generic_playerX.hpp`. Para o projeto é necessário modificar somente uma das classes. 

A função principal das classes Generic Player é a seguinte função.

```c++

    vss::WheelsCommand update(vss::State state, int index) {
        Posture objective = defineObjective(state, index);
        return motionControl(state, objective, index);
    }
``` 

A função update tem como entrada um objeto `vss::State`, que contém informações sobre as posições e velocidades de todos os robôs e da bola. Ela é chamada a cada iteração do simulador com as informações atualizadas e retorna a velocidade que devem ser mandadas para as rodas do robô de índice `index`.

A função `defineObjetive` define o ponto que o robo deve ir na iteração atual de acordo com o estado de jogo atual. Para modificar onde o robô deve ir, você deve modificar essa função.

Já a função motionControl verifica o objetivo atual e a posição do robô e calcula as velocidades das rodas necessárias para fazer com que o robô vá para o ponto desejado.

**Não é necessário modificar a função motionControl, É aconselhável que se modifique somente a função `defineObjetive`** 

Sempre que o código for modificado, é necessário recompilar o VSS-SampleCpp através do comando:

~~~
sudo ./configure.sh
~~~

Antes de executar o código novamente, é necessário reiniciar o VSS Simulator, ou o código poderá apresentar comportamentos estranhos.

Contato: José Nilton <jnolj@cin.ufpe.br> e RobôCIn <robocin@cin.ufpe.br>