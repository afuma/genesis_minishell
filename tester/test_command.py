
import subprocess

# ---------------------------------------------------------------------------------------------

def color_text(text, color_code):
    return f"\033[{color_code}m{text}\033[0m"

def success_text(text):
    return color_text(text, "92")

def error_text(text):
    return color_text(text, "91")

# ---------------------------------------------------------------------------------------------

def run_command(command):
    try:
        result = subprocess.check_output(command, shell=True, executable='/bin/bash', stderr=subprocess.STDOUT, text=True)
        return result.strip()
    except subprocess.CalledProcessError as e:
        return e.output.strip()

def test_command(command, minishell_executable):
    bash_result = run_command(command)
    minishell_result = run_command(f"{minishell_executable} {command}")

    if bash_result == minishell_result:
        print(success_text("-------------------------------------------------"))
        print(success_text(f"Test for command '{command}' passed!"))
    else:
        print(error_text(f"Test for command '{command}' failed:"))
        print(error_text(f"  Bash result: {bash_result}"))
        print(error_text(f"  Minishell result: {minishell_result}"))
        print(success_text("-------------------------------------------------"))


# minishell_executable = "./minishell"
# test_command("ls -l", minishell_executable)