FROM ubuntu:22.04

RUN export TERM="xterm-256color"

RUN apt-get -y update && \
    apt-get -y upgrade

RUN apt-get install socat -y
    
RUN useradd -m ctf
RUN echo "ctf:ctf" | chpasswd
WORKDIR /home/ctf

COPY chall .
COPY flag.txt .

RUN chown -R root:root /home/ctf
RUN chmod -R 555 /home/ctf

USER ctf
EXPOSE 1338
CMD socat TCP-LISTEN:1338,reuseaddr,fork EXEC:"./chall",pty,rawer,echo=0