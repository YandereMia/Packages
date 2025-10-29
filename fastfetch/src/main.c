#include <stdio.h>
#include <string.h>
void check();
void ascii_art();

char buff[256];
char OS[256];
char kernel[256];
char user[256];

int main() {
    check();
    ascii_art();
}

void ascii_art() {
    printf("                  -`\n");
    printf("                 .o+`\n");
    printf("                `ooo/\n");
    printf("               `+oooo:                   %s@%s",user , buff);
    printf("              `+oooooo:                  ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("              -+oooooo+:                 ~  %s\n", OS);
    printf("            `/:-:++oooo+:                ~  Linux %s\n", kernel);
    printf("           `/++++/+++++++:               ~  1886 (pacman)\n");
    printf("          `/++++++++++++++:              ~  bash 5.3.3\n");
    printf("         `/+++ooooooooooooo/`            ~  konsole 25.8.2\n");
    printf("        ./ooosssso++osssssso+`           ~  KWin (Wayland)\n");
    printf("       .oossssso-````/ossssss+`\n");
    printf("      -osssssso.      :ssssssso.\n");
    printf("     :osssssss/        osssso+++.\n");
    printf("    /ossssssss/        +ssssooo/-\n");
    printf("  `/ossssso+/:-        -:/+osssso+-\n");
    printf(" `+sso+:-`                 `.-/+oso:\n");
    printf("`++:.                           `-/+/\n");
    printf(".`                                 `/\n");
}
void check_hostname() {
    FILE *fptr = fopen("/etc/hostname", "r");  
  
    if (fptr == NULL) {
        printf("Couldnt find/load/read hostname\n");  
        return;
    }

    while (fgets(buff, sizeof(buff), fptr) != NULL) {
    }
    fclose(fptr);
}
void check_username() {
    FILE *fp = popen("whoami 2>/dev/null", "r");
    if (!fp) {
        perror("popen");
        return;
    }

    while (fgets(user, sizeof(user), fp) != NULL) {
        user[strcspn(user, "\n")] = '\0';
    }

    pclose(fp);
}

void check_os() {
    FILE *fp = fopen("/etc/os-release", "r");
    if (!fp) {
        perror("fopen");
        OS[0] = '\0';
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        size_t keylen = strlen("PRETTY_NAME");
        if (strncmp(line, "PRETTY_NAME=", keylen + 1) == 0) {
            line[strcspn(line, "\n")] = '\0';
            char *val = line + keylen + 1;
            if (val[0] == '"' && val[strlen(val)-1] == '"') {
                val[strlen(val)-1] = '\0';
                val++;
            }
            strncpy(OS, val, sizeof(OS) - 1);
            OS[sizeof(OS) - 1] = '\0';
            break;
        }
    }

    fclose(fp);
}
void check_kernel() {
    FILE *fp = popen("uname -r 2>/dev/null", "r");
    if (!fp) {
        perror("popen");
        return;
    }

    if (fgets(kernel, sizeof(kernel), fp) != NULL) {
        kernel[strcspn(kernel, "\n")] = '\0';
    }

    pclose(fp);
}

void clean(char *s) {
    s[strcspn(s, "\n")] = '\0';

    size_t len = strlen(s);
    if (len >= 2 && s[0] == '"' && s[len-1] == '"') {
        memmove(s, s+1, len-2);
        s[len-2] = '\0';
    }
}
void check() {
    check_os();
    check_hostname();
    check_username();
    check_kernel();
}