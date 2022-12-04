import platform
import os

# Compile func
def compile():
    if platform.system() == 'Windows':
        os.system("gcc main.c -o main.exe -w")
    else:
        os.system("gcc main.c -o main -w")

# Run func
def runit():
    if platform.system() == 'Windows':
        os.system(".\\main.exe")
    else:
        os.system("./main")

# Compilar & Correr
compile(), runit()