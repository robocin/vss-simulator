FROM ubuntu:16.04

# Instala o CMAKE
RUN apt-get update

# Copia tudo para o container
COPY . /vss-core-ubuntu16
WORKDIR /vss-core-ubuntu16

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-core-ubuntu16/configure.sh
RUN chmod +x /vss-core-ubuntu16/entrypoint.sh
RUN chmod +x /vss-core-ubuntu16/scripts/protos.sh

# Executa a instalação na criação dos containers
RUN /vss-core-ubuntu16/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-core-ubuntu16/entrypoint.sh"]