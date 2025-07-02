FROM python:3.10

WORKDIR /app

COPY requirements.txt ./

RUN apt-get update && apt-get install -y \
    gcc \
    python3-dev \
    libffi-dev \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-ttf-dev \
    libfreetype6-dev \
    libpng-dev \
    pkg-config \
    libgl1-mesa-dev \
    && rm -rf /var/lib/apt/lists/*

RUN pip install --no-cache-dir -r requirements.txt

COPY . .

CMD ["./main"]
