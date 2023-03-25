FROM ubuntu:20.04

ENV SML_VERSION=110.99.2

RUN apt update \
	&& apt install -y rlwrap wget build-essential \
	&& apt clean \
	&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

WORKDIR /usr/share/smlnj

RUN wget http://smlnj.cs.uchicago.edu/dist/working/${SML_VERSION}/config.tgz \
	&& tar -xzf config.tgz \
	&& rm config.tgz \
	&& config/install.sh \
    && cp bin/sml /usr/bin

RUN echo alias rsml="'rlwrap sml'" >> /root/.bashrc

WORKDIR /root/source
