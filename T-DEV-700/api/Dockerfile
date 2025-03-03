# Utilisez une image de base Java
FROM openjdk:22-slim-bullseye

COPY . /app

WORKDIR /app

RUN ./gradlew build

EXPOSE 8080

CMD ["./gradlew", "run"]
