import { WebSocketServer, WebSocket } from "ws";
import { createServer } from "https";
import { readFileSync } from "fs";
import { SerialPort } from "./serialport.js";
import { writeLog } from "./logger.js";

const server = createServer({
    cert: readFileSync("./localhost.crt"),
    key: readFileSync("./localhost.key"),
    passphrase: "passphrase",
});

const wss = new WebSocketServer({ server }, () => {
    console.log("WebSocket server is running");
    writeLog("WebSocket server is running");
});

wss.on("connection", (ws) => {
    console.log("Client connected");
    writeLog("Client connected");

    ws.on("message", (message) => {
        console.log(`Received: ${message}`);
        writeLog(`Received: ${message}`);

        if (Buffer.isBuffer(message)) {
            message = message.toString();
        }

        serialPort.sendMessage(message.trim());
    });
});

wss.on("listening", () => {
    console.log("WebSocket server is listening");
    writeLog("WebSocket server is listening");
});

wss.on("close", () => {
    console.log("Websocket closed");
    writeLog("Websocket closed");
});

const serialPort = new SerialPort("/dev/ttyACM0", (data) => {
    wss.clients.forEach((client) => {
        if (isClientOpen(client)) {
            client.send(data);
        }
    });
    writeLog(`Data sent to clients: ${data}`);
});

function isClientOpen(client) {
    return client.readyState === WebSocket.OPEN;
}

function sendMessageToClient(ws, id, status) {
    const message = JSON.stringify({ id, status });
    ws.send(message);
    writeLog(`Sent to client: ${message}`);
}

server.listen(8081, () => {
    console.log("Server is listening on port 8081");
    writeLog("Server is listening on port 8081");
});
