#include "siglist.h"

int main() {
    Sig *list = NULL;

    // Create and insert signatures
    list = insert_sig(list, create_sig(1, "virus123"));
    list = insert_sig(list, create_sig(2, "trojanA"));
    list = insert_sig(list, create_sig(3, "worm_beta"));

    // Display all
    print_sigs(list);

    // Delete one
    list = delete_sig(list, 2);
    printf("\nAfter deletion:\n");
    print_sigs(list);

    // Free memory
    free_sigs(list);
    return 0;
}
