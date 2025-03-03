FROM node:20-alpine

#set un working directory
WORKDIR /app

#add dependencies
COPY package.json /
COPY package-lock.json /

#installer les dépendances
RUN npm install

#copy the build in the docker image
COPY . .

#expose port
EXPOSE 8080

#lancer l'app
CMD ["npm", "run", "dev"]