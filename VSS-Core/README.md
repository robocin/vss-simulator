# VSS-Core [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3] [![Build Status](https://api.travis-ci.com/VSS-SDK/VSS-Core.svg?branch=master)][travis]

[![Trello](https://img.shields.io/badge/Trello-SDK-blue.svg)][vss-sdk-trello]
[![Slack](https://img.shields.io/badge/Slack-Channel-551a8b.svg)][slack]

O VSS-Core (C++) é uma biblioteca open-source que faz parte do VSS-SDK.
Contém interfaces de comunicação entre os projetos do SDK, modelos que representam o domínio do problema de futebol de robôs e métodos uteis. Os pacotes trafegam utilizando ZeroMQ e são serializados utilizando Protobuf.

Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

## Instalação
```
$ sudo ./configure.sh
```

## Desenvolvimento
Compilando
```
$ sudo ./configure.sh development
$ cd build
$ ./tests
```

## VSS-Samples
> Versão em C++: [VSS-SampleCpp][samplecpp]

> Versão em Python: [VSS-SamplePy][samplepy]

> Versão em Rust: [VSS-SampleRust][samplerust]

## VSS-Cores
> Versão em C++: [VSS-CoreCpp][corecpp]

>Versão em Python: [VSS-CorePy][corepy]

> Versão em Rust: [VSS-CoreRust][corerust]

# Licença

Esse código está sob licença [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], cujo uma cópia em texto pode ser encontrada em [LICENSE.txt](LICENSE.txt).

Você pode utilizar esse código. Caso o faça, nos informe.

[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[vss-sdk]: https://vss-sdk.github.io
[samplecpp]: https://github.com/VSS-SDK/VSS-SampleCpp
[samplepy]: https://github.com/VSS-SDK/VSS-SamplePy
[samplerust]: https://github.com/VSS-SDK/VSS-SampleRust
[corecpp]: https://github.com/VSS-SDK/VSS-Core
[corepy]: https://github.com/VSS-SDK/VSS-CorePy
[corerust]: https://github.com/VSS-SDK/VSS-CoreRust
[travis]: https://travis-ci.com/VSS-SDK/VSS-Core
[vss-sdk-trello]: https://trello.com/b/b4dVV6ug/vss-sdk
[slack]: https://vss-sdk.slack.com
[wiki]: https://github.com/SIRLab/VSS-Core/wiki
