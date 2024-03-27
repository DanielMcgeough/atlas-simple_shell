## atlas-simple_shell
Simple Shell project for the Atlas Jan2024 Cohort.
This project is primarily written, tested and coded by Nathan Rhys and Danny McGeough.
The aim of this project is to create a simple shell interface capable of handling certain commands issued by a user and utilize input in ways that closesly mirror other shells like bash.
The Shell is designed to perform operations both in interactive mode and non interactive mode.In interactive mode the shell is designed to recieve commands input by the user and perform the specified option. For instance, if someone were to enter the "ls" command into the interactive mode portion of our shell, it would perform as expected and display a list of all files in the current directory. If one were to add flags to ls, once again it would perform as expected. In non interactive mode, our shell is designed to accept the environment variable full path, tokenize the PATH and perform the necessary operation.
The Shell is compiled through the use of the "gcc Wall Werror Wextra -pedantic -std=gnu89 *.c" command. From there, running a.out will grant you entry into the shell where it awaits user input. The project aim is to create a useful and nearly indistinguishable copy of a simple version of any shell currently in use today.
ENTER EXAMPLE HERE
The project will be coded in VSCode and Terminal. The functions used are
