#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int contains(char *array[], int size, const char *value) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], value) == 0) {
            return 1;
        }
    }
    return 0;
}

void sleep_seconds(int seconds) {
    sleep(seconds);
}
 
void clear_screen() {
    system("cls");
}

void execute_command(const char *cmd) {
    system(cmd);
}

// Main function
int main() {
    execute_command("color 0B");
    clear_screen();
    printf("made by jenohohjen on discord.\n");

    char *command[][2] = {
        {"install", "            Install package in the list."},
        {"install list", "       List package."},
        {"exit", "               Exit tool."},
        {"shutdown", "           Shutdown and enter time in second."},
        {"status", "             Just neofetch."},
        {"help", "               List valid command in case you don't know."},
        {"reboot", "             Reboot Pc now."},
        {"cls", "                Clear terminal."},
        {"ls", "                 Show current directory."}
    };
    int command_count = sizeof(command) / sizeof(command[0]);

    char *valid_commands[command_count];
    for (int i = 0; i < command_count; i++) {
        valid_commands[i] = command[i][0];
    }

    char *misspelled_commands[] = {"restart", "exit tool", "clear", "clr", "dir", ""};
    int misspelled_count = sizeof(misspelled_commands) / sizeof(misspelled_commands[0]);
    printf("This tool only works on Windows-based OS and requires internet for it to work properly.\n")
    while (1) {
        char input[256];
        printf("Korza: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        for (int i = 0; input[i]; i++) {
            input[i] = tolower((unsigned char) input[i]);
        }
        if (!contains(misspelled_commands, misspelled_count, input)) {
            if (!contains(valid_commands, command_count, input)) {
                printf("Invalid input: \"%s\". Try running \"%s\"?\n", input, "help");
            } else {
                if (strcmp(input, "install") == 0) {
                    printf("installing ");
                    execute_command("pause");
                    execute_command("winget install -e --id Google.Chrome");
                    execute_command("winget install -e --id KDE.Krita");
                    execute_command("winget install -e --id BlenderFoundation.Blender.LTS.3.6");
                    execute_command("winget install -e --id Discord.Discord");
                    execute_command("winget install -e --id Microsoft.VisualStudioCode");
                    execute_command("winget install -e --id Python.Python.3.11");
                    execute_command("winget install -e --id Microsoft.VCRedist.2015+.x64");
                    execute_command("winget install -e --id Microsoft.DotNet.Framework.DeveloperPack_4");
                    execute_command("winget install -e --id Git.Git");
                } else if (strcmp(input, "install list") == 0) {
                    printf("list: Google Chrome\n    Krita\n    Blender(LTS)\n    Discord\n    Visual Studio Code\n    Python3.11\n");
                } else if (strcmp(input, "exit") == 0) {
                    break;
                } else if (strcmp(input, "shutdown") == 0) {
                    printf("Time (in seconds): ");
                    int t;
                    if (scanf("%d", &t) != 1) {
                        printf("Invalid number\n");
                    } else {
                        sleep_seconds(t);
                        execute_command("shutdown /s");
                    }
                } else if (strcmp(input, "status") == 0) {
                    execute_command("winget install -e --id nepnep.neofetch-win");
                    clear_screen();
                    execute_command("neofetch");
                } else if (strcmp(input, "help") == 0) {
                    printf("Here are valid commands:\n");
                    for (int i = 0; i < command_count; i++) {
                        printf("                        %s%s\n", command[i][0], command[i][1]);
                    }           
                } else if (strcmp(input, "reboot") == 0) {
                    execute_command("shutdown /r");
                } else if (strcmp(input, "cls") == 0) {
                    clear_screen();
                } else if (strcmp(input, "ls") == 0) {
                    execute_command("dir");
                }
            }
        } else if (strcmp(input, "restart") == 0) {
            printf("There is no \"restart\", do you mean \"reboot\"?\n");
        } else if (strcmp(input, "exit tool") == 0) {
            printf("There is no \"exit tool\", do you mean \"exit\"?\n");
        } else if (strcmp(input, "dir") == 0) {
            printf("There is no \"%s\", do you mean \"ls\"?\n", input);
        } else if (strcmp(input, "clear") == 0 || strcmp(input, "clr") == 0) {
            printf("There is no \"%s\", do you mean \"cls\"?\n", input);
        } else if (strcmp(input, "") == 0) {
            printf("");
        }
    }
    return 0;
}
