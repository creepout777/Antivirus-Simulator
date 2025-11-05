#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filelist.h"
#include "../include/siglist.h"
#include "../include/scan.h"
#include "../include/cleanup.h"

// Simple helper to clear input buffer
void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    char command[50];
    char arg1[100];
    unsigned char fake_data[] = "example file content";

    printf("=== 🛡️  Antivirus Simulator ===\n");
    printf("Type HELP for available commands.\n\n");

    while (1) {
        printf("> ");
        if (scanf("%49s", command) != 1) break;

        // Command: ADD_SIG <pattern>
        if (strcmp(command, "ADD_SIG") == 0) {
            if (scanf("%99s", arg1) == 1) {
                Sig *s = create_sig(arg1);
                insert_sig(&Signatures, s);
                printf("Signature '%s' added.\n", arg1);
            } else {
                printf("Usage: ADD_SIG <pattern>\n");
                clear_input();
            }
        }

        // Command: DEL_SIG <pattern>
        else if (strcmp(command, "DEL_SIG") == 0) {
            if (scanf("%99s", arg1) == 1) {
                delete_sig(&Signatures, arg1);
                printf("Signature '%s' deleted (if it existed).\n", arg1);
            } else {
                printf("Usage: DEL_SIG <pattern>\n");
                clear_input();
            }
        }

        // Command: LOAD <filename>
        else if (strcmp(command, "LOAD") == 0) {
            if (scanf("%99s", arg1) == 1) {
                FileRec *f = create_file(arg1, fake_data, strlen((char*)fake_data));
                insert_file(&Clean, f);
                printf("File '%s' loaded into Clean list.\n", arg1);
            } else {
                printf("Usage: LOAD <filename>\n");
                clear_input();
            }
        }

        // Command: SCAN
        else if (strcmp(command, "SCAN") == 0) {
            scan_files(&Clean, &Suspect, Signatures);
        }

        // Command: QUAR <filename>
        else if (strcmp(command, "QUAR") == 0) {
            if (scanf("%99s", arg1) == 1) {
                move_file(&Suspect, &Quarantine, arg1);
                printf("File '%s' moved to Quarantine.\n", arg1);
            } else {
                printf("Usage: QUAR <filename>\n");
                clear_input();
            }
        }

        // Command: RESTORE <filename>
        else if (strcmp(command, "RESTORE") == 0) {
            if (scanf("%99s", arg1) == 1) {
                move_file(&Quarantine, &Clean, arg1);
                printf("File '%s' restored to Clean.\n", arg1);
            } else {
                printf("Usage: RESTORE <filename>\n");
                clear_input();
            }
        }

        // Command: REPORT
        else if (strcmp(command, "REPORT") == 0) {
            printf("\n=== Current Lists ===\n");
            print_list("Clean", Clean);
            print_list("Suspect", Suspect);
            print_list("Quarantine", Quarantine);
            printf("\nSignatures:\n");
            print_sigs(Signatures);
            printf("\n");
        }

        // Command: PURGE (cleanup)
        else if (strcmp(command, "PURGE") == 0) {
            purge_all();
            printf("All lists cleared.\n");
        }

        // Command: HELP
        else if (strcmp(command, "HELP") == 0) {
            printf("\nAvailable commands:\n");
            printf("  ADD_SIG <pattern>   - Add a new signature\n");
            printf("  DEL_SIG <pattern>   - Delete a signature\n");
            printf("  LOAD <name>         - Load file by path\n");
            printf("  SCAN                - Scan Clean list for infected files\n");
            printf("  QUAR <name>         - Move file to Quarantine\n");
            printf("  RESTORE <name>      - Move file back to Clean\n");
            printf("  REPORT              - Show all lists and stats\n");
            printf("  PURGE               - Free all lists\n");
            printf("  EXIT                - Quit the program\n\n");
        }

        // Command: EXIT
        else if (strcmp(command, "EXIT") == 0) {
            printf("Exiting...\n");
            break;
        }

        // Unknown command
        else {
            printf("Unknown command. Type HELP for help.\n");
            clear_input();
        }
    }

    // Cleanup before exit
    purge_all();
    printf("Memory freed. Goodbye!\n");

    return 0;
}

