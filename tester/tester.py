
import os
from test_command import test_command, run_command
from setup import SHELL, MINISHELL_EXECUTABLE
import shutil
import os

file_src = "../minishell"
dossier_testeur = "."
fichier_destination = os.path.join(dossier_testeur, "minishell")
shutil.copy(file_src, fichier_destination)

def run_tests(minishell_executable):
    for filename in os.listdir(test_folder):
        if filename.endswith(".txt"):
            filepath = os.path.join(test_folder, filename)
            run_test_file(filepath, minishell_executable)

def run_test_file(filepath, minishell_executable):
    with open(filepath, "r") as file:
        for line in file:
            command = line.strip()
            test_command(command, minishell_executable)

test_folder = "TESTS"
minishell_executable = "./minishell"

run_tests(MINISHELL_EXECUTABLE)
# # Basique
# test_command("ls -l", minishell_executable)
# test_command("echo Hello, World!", minishell_executable)