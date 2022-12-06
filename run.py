import platform
import os
import time

# Compile func
def compile():
        os.system("gcc main.c -o main -w && ./main")

# Compilar & Correr
compile()