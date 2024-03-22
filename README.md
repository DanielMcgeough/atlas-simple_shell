# atlas-simple_shell
Simple Shell project for Atlas Jan2024 Cohort.
This project is primarily written, tested and coded by Nathan Rhys and Danny McGeough.
The aim of this project is to create a simple shell interface capable of handling certain commands issued by a user and utilize input in ways that closesly mirror other shells like bash.
We are going to handle most built in commands such as cd or ls and also handle errors in user input and have edge cases and fail states.
The technologies used will be VSCode and the Terminal. We will also utilize certain functions contained within certain libraries (see man page for explicit mention of libraries).

commands:
break
cat
cd
chmod
chown
cmp
cp
dir
exit
find
file
grep
head
kill
ls
mkdir
mkfile
mv
nl
open
printenv
printf
pwd
read
rename
rm
rmdir
sort
ssh
stat
tail
tty
type
until
vi
write
wait
which
while
.
!!

#include <stdio.h>
#include <string.h>

int is_valid_command(const char *input) {
    // List of known commands
    const char *commands[] = {"break", "cat", "cd", "chmod", "chown", "cmp"
                                "cp", "dir", "exit", "find", "file", "grep"
                                , "head", "kill", "ls", "mkdir", "mkfile",
                                 "mv", "nl", "open", "printenv", "printf",
                                  "pwd", "read", "rename", "rm", "rmdir", 
                                  "sort", "ssh", "stat", "tail", "tty", 
                                  "type", "until", "vi", "write", "wait",
                                   "which", "while", ".", "!!"}
    // Number of known commands
    const int num_commands = sizeof(commands) / sizeof(commands[0]);

    // Check if the input matches any known command
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(input, commands[i]) == 0) {
            return 1; // Return true if input matches a command
        }
    }
    return 0; // Return false if input does not match any command
}

int main() {
    char input[100];

    printf("Enter a command: ");
    scanf("%s", input);

    if (is_valid_command(input)) {
        printf("Valid command.\n");
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
