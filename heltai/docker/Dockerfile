FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update && \
  apt-get install -y texlive-base texlive-latex-base && \
  apt-get clean && rm -rf /var/lib/apt/lists/*

COPY log.txt /app/log.txt