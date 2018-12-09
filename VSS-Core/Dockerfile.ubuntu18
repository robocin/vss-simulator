FROM ubuntu:18.04

# Instala o CMAKE
RUN apt-get update

# Copia tudo para o container
COPY . /vss-core-ubuntu18
WORKDIR /vss-core-ubuntu18

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-core-ubuntu18/configure.sh
RUN chmod +x /vss-core-ubuntu18/entrypoint.sh
RUN chmod +x /vss-core-ubuntu18/scripts/protos.sh

# Executa a instalação na criação dos containers
RUN /vss-core-ubuntu18/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-core-ubuntu18/entrypoint.sh"]