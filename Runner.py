import subprocess
from os import path
from sys import argv

def main():
    if(len(argv) == 1):
        execName = input("program name: ")
    elif len(argv) != 2:
        print("Invalid Syntax. Instead do: ")
        print("python Runner.py <FIle To Be Ran>")
        return
    else:
        execName = argv[1]
    if " " in execName or (not execName.endswith(".exe") and "." in execName):
        print("Anti Comand Injection. Terminating...")
        print("Enter a valid executable in build/Debug")
        return
    
    workingDir = path.dirname(__file__)

    cmd = path.join(workingDir,"build", "Debug", execName)

    print(cmd)
        
    try:
        subprocess.run(cmd, check=True, cwd=workingDir)
    except FileNotFoundError:
        print(f"{execName} not found")
    except subprocess.CalledProcessError as e:
        print(f"Error, Program returned with exit code {e.returncode}")
    else:
        print("Program exited with code 0x0");

    _ = input("Press Enter to Continue")

if __name__ == "__main__":
    main()