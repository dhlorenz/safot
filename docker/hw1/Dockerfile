FROM ubuntu:20.04

SHELL ["/bin/bash", "-c"]

RUN apt update
RUN apt install -y bash bash-completion build-essential binutils python3.8

COPY fpc-3.2.0-x86_64-linux.tar fpc.tar

RUN tar xf "fpc.tar" && \
    cd fpc-3.2.0-x86_64-linux && \
    source ./install.sh && \
    cd .. && \
    rm -r fpc-3.2.0-x86_64-linux

RUN ln -s /usr/bin/python3.8 /usr/bin/python

WORKDIR /source