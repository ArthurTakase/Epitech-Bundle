# Websocket

## What ?

Simple websocket which look at the serial port to transmet message to clients

## Launch

To launch WebSocket

```
npm run server
```

## Generate SSL files
Commands for localhost
- Private Key:
```sh
openssl genpkey -algorithm RSA -out localhost.key -aes256
```

- Certificate Signing Request (CSR):
```sh
openssl req -new -key localhost.key -out localhost.csr
```
You will be prompted to enter information about your organization. For local development, you can use placeholder information, but make sure to set the "Common Name" to localhost:
```
Country Name (2 letter code) [AU]:US
State or Province Name (full name) [Some-State]:California
Locality Name (eg, city) []:San Francisco
Organization Name (eg, company) [Internet Widgits Pty Ltd]:My Company
Organizational Unit Name (eg, section) []:IT
Common Name (e.g. server FQDN or YOUR name) []:localhost
Email Address []:admin@example.com
```

- Self-Signed Certificate:
Create a self-signed certificate using the CSR and the private key. This certificate will be valid for 365 days (1 year):
```
openssl x509 -req -days 365 -in localhost.csr -signkey localhost.key -out localhost.crt
```

- Combine the Private Key and Certificate (Optional):
Some servers might require the private key and certificate to be combined into a single file. You can do this if necessary
```
cat localhost.key localhost.crt > localhost.pem
```

### Summary of Generated Files
- localhost.key: Your private key (keep this secure and do not share it).
- localhost.csr: Your certificate signing request.
- localhost.crt: Your self-signed certificate.
- localhost.pem: Combined private key and certificate (optional, depending on your server's requirements).
