# NAS

1. Placer le dossier `ansible` dans le dossier `/etc/` de la VM d'origine.
2. Executer les playbooks dans l'ordre suivant:
    - `sudo ansible-playbook /etc/ansible/setup_back.yml`
    - `sudo ansible-playbook /etc/ansible/setup_front.yml`
