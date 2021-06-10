FROM nvcr.io/nvidia/l4t-pytorch:r32.4.4-pth1.6-py3

ENV TZ=Asia/Hong_Kong
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update \
        && apt-get install -y tzdata

RUN apt-get update && apt-get install -y \
        build-essential \
        git \
        cmake \
	python3-dev \
	qtcreator \
	qt5-default \
	curl\
        && rm -rf /var/lib/apt/lists/*

RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
RUN python3 get-pip.py
RUN pip install --upgrade pip
RUN pip install opencv-python
RUN pip install numpy==1.19.4
RUN pip install torch
RUN pip install torchvision
RUN pip install pandas
RUN pip install pyqt5
RUN pip install lxml

WORKDIR /Learning_Computer_Vision
COPY . .


