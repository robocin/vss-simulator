FROM ubuntu:16.04

# Instala o CMAKE
RUN apt-get update

# Copia tudo para o container
COPY . /vss-simulator
WORKDIR /vss-simulator

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-simulator/configure.sh
RUN chmod +x /vss-simulator/entrypoint.sh
RUN chmod +x /vss-simulator/install_core.sh

# Executa a instalação na criação dos containers
RUN /vss-simulator/install_core.sh
RUN /vss-simulator/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-simulator/entrypoint.sh"]