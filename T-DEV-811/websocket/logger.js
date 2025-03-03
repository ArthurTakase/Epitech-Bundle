import { appendFileSync, mkdirSync, existsSync } from 'fs';
import { join } from 'path';

const logDir = './logs';
const sessionLogFile = join(logDir, `session_${new Date().toISOString().replace(/[:.]/g, '-')}.log`);

if (!existsSync(logDir)) {
    mkdirSync(logDir);
}

export function writeLog(message) {
    const timestamp = new Date().toISOString();
    appendFileSync(sessionLogFile, `${timestamp} - ${message}\n`);
}
