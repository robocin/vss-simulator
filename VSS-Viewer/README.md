# VSS-Viewer [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3] [![Build Status](https://api.travis-ci.com/VSS-SDK/VSS-Viewer.svg?branch=master)][travis]

[![Trello](https://img.shields.io/badge/Trello-SDK-blue.svg)][vss-sdk-trello]
[![Slack](https://img.shields.io/badge/Slack-Channel-551a8b.svg)][slack]

O VSS-Viewer é um visualizador de estados de jogo. Esse projeto obtém dados do VSS-Simulator, VSS-Vision
e estratégias. Esse projeto utiliza o [VSS-Core][vss-core] como interface de comunicação.

Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

## Instalação
```
$ sudo ./configure.sh
```

## Desenvolvimento
```
$ sudo ./configure.sh development
```

## Exemplos
Exemplo em C++: [VSS-SampleCpp][samplecpp]

# Licença

Esse código está sob licença [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], cujo uma cópia em texto pode ser encontrada em [LICENSE.txt](LICENSE.txt).

Você pode utilizar esse código. Caso o faça, nos informe.

[vss-sdk]: http://sirlab.github.io/VSS-SDK
[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[travis]: https://travis-ci.com/VSS-SDK/VSS-Viewer
[vss-sdk-trello]: https://trello.com/b/b4dVV6ug/vss-sdk
[slack]: https://vss-sdk.slack.com
[vss-core]: https://github.com/SIRLab/VSS-Core
[samplecpp]: https://github.com/SIRLab/VSS-SampleCpp
