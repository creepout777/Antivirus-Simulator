#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sig.h"
#include "utils.h"

Sig *create_sig(const char *pattern) {
    Sig *s = malloc(sizeof(Sig));
    if (!s) return

