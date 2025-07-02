# T-AIA-902-BDX_4

## Docker

### Install

```bash
sudo docker compose build
```

### Usage

- Run without arguments:

    ```bash
    sudo docker compose up
    ```

- Run with arguments:

    ```bash
    docker compose run taxi-app ./main [args]
    ```

### Export logs

1. Get the container ID:

    ```bash
    docker ps -a
    ```

2. Export the logs of the container:

    ```bash
    sudo ./getLogs.sh {container_id}
    ```

## Venv

### Install

1. Set up a Python virtual environment:

    ```bash
    python3 -m venv .venv
    source .venv/bin/activate  # On Windows use `venv\Scripts\activate`
    ```

2. Install the required dependencies:

    ```bash
    pip install -r requirements.txt
    ```

### Usage

```shell
./main
```
