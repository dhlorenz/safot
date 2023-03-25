FROM alpine:3.7

RUN apk add --no-cache bash bash-doc bash-completion
RUN apk add --no-cache build-base
RUN apk add --no-cache binutils

COPY fpc-3.2.0-x86_64-linux.tar fpc.tar

RUN tar xf "fpc.tar" && \
    cd fpc-3.2.0-x86_64-linux && \
    source ./install.sh && \
    cd .. && \
    rm -r fpc-3.2.0-x86_64-linux

WORKDIR /source
