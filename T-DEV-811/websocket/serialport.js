import { SerialPort as NodeSerialPort } from "serialport";
import { ReadlineParser } from "@serialport/parser-readline";
import { writeLog } from "./logger.js";

export class SerialPort {
    constructor(path, parserCallback) {
        this.portName = path;
        this.port = undefined;
        this.parser = undefined;

        this.port = new NodeSerialPort({
            path,
            baudRate: 9600,
        });

        this.parser = this.port.pipe(new ReadlineParser({ delimiter: "\n" }));

        this.port.on("open", () => {
            console.log("Port open");
            writeLog("Port open");
        });

        this.port.on("error", (err) => {
            console.error(`SerialPort error: ${err.message}`);
            writeLog(`SerialPort error: ${err.message}`);
        });

        this.parser.on("data", (data) => {
            console.log(`Data: ${data}`);
            writeLog(`Data: ${data}`);
            parserCallback(data);
        });
    }

    sendMessage(message) {
        if (this.port === undefined) return;
        this.port.write(`${message}\r\n`);
        writeLog(`Sent message: ${message}`);
    }
}
