FROM ubuntu:16.04

# Instala o CMAKE
RUN apt-get update

# Copia tudo para o container
COPY . /vss-viewer
WORKDIR /vss-viewer

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-viewer/configure.sh
RUN chmod +x /vss-viewer/entrypoint.sh
RUN chmod +x /vss-viewer/install_core.sh

# Executa a instalação na criação dos containers
RUN /vss-viewer/install_core.sh
RUN /vss-viewer/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-viewer/entrypoint.sh"]