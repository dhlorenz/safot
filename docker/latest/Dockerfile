FROM twyair/safot-revealjs:base

WORKDIR /root

ENV DEBIAN_FRONTEND=noninteractive

COPY start.sh /root

RUN git clone https://github.com/OpenUniversity/safot.git \
    && cd safot/reveal.js \
    && npm install --omit=dev
