# Utiliser Ubuntu 22.04 LTS comme image de base
FROM ubuntu:22.04

# Mettre à jour les paquets et installer les dépendances nécessaires
RUN apt-get update && apt-get install -y \
    curl \
    unzip \
    git \
    openjdk-19-jdk

# Vérifier l'installation de Java et afficher l'emplacement
RUN java -version
RUN update-alternatives --list java

# Définir les variables d'environnement pour Java et Android SDK
ENV ANDROID_HOME=/usr/local/android-sdk
ENV PATH=$PATH:$ANDROID_HOME/cmdline-tools/latest/bin:$ANDROID_HOME/platform-tools

# Télécharger et installer Android Command Line Tools
RUN mkdir -p $ANDROID_HOME/cmdline-tools \
    && curl -o cmdline-tools.zip https://dl.google.com/android/repository/commandlinetools-linux-8512546_latest.zip \
    && unzip cmdline-tools.zip -d $ANDROID_HOME/cmdline-tools \
    && mv $ANDROID_HOME/cmdline-tools/cmdline-tools $ANDROID_HOME/cmdline-tools/latest \
    && rm cmdline-tools.zip

# Installer les outils et les plateformes SDK nécessaires
RUN export JAVA_HOME=$(dirname $(dirname $(update-alternatives --list java))) \
    && yes | sdkmanager --licenses \
    && sdkmanager "platform-tools" "platforms;android-34" "build-tools;33.0.1"

# Copier le projet dans le conteneur
COPY . /app

COPY /app/keystore.jks /app/keystore.jks

# Définir le répertoire de travail
WORKDIR /app

# Donner les droits d'exécution au script Gradle
RUN chmod +x ./gradlew

# Nettoyer le projet
RUN ./gradlew clean

# Exécuter le script Gradle
RUN ./gradlew build

# Construire l'application
RUN ./gradlew assembleRelease
