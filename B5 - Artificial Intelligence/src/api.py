from sys import exit, stdin, stdout
from typing import List


class API:
    def __init__(self) -> None:
        pass

    def send_command(self, command: str) -> None:
        print(command)
        stdout.flush()

    def send_error(self, message: str) -> None:
        self.send_command(f"ERROR message - {message}")
        exit(84)

    def get_command(self) -> List[str]:
        cmd: str = stdin.readline()
        command: List[str] = cmd.strip().split()

        return command
