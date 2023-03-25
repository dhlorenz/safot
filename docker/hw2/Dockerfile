FROM twyair/safot-smlnj:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update \
	&& apt install -y python3 git jupyter python3-pip \
	&& pip3 install jupyter-server jupyterlab \
	&& git clone https://github.com/twyair/simple-ismlnj.git \
	&& mv simple-ismlnj /usr/share/jupyter/kernels/smlnj

EXPOSE 16788

COPY start-jupyter /

WORKDIR /source

RUN pip3 install markupsafe==2.0.1
