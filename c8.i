//bin/true; gcc "$0" -o "$(mktemp "/tmp/${0##*/}_XXX.elf")"; "$_"; exit $(($? $(rm "$_")))
char prog[] =
"//bin/true; gcc \"$0\" -o \"$(mktemp \"/tmp/${0##*/}_XXX.elf\")\"; \"$_\"; exit $(($? $(rm \"$_\")))\n"
"char prog[] =\n"
"%\n"
";\n"
"\n"
"int putchar(int);\n"
"\n"
"void quotchar(char c) {\n"
"    static int start_of_quote = 1;\n"
"\n"
"    if (start_of_quote) {\n"
"        putchar('\"');\n"
"        start_of_quote = 0;\n"
"    }\n"
"\n"
"    if (c == '\\\\') {\n"
"        putchar('\\\\');\n"
"        putchar('\\\\');\n"
"    }\n"
"    else if (c == '\"') {\n"
"        putchar('\\\\');\n"
"        putchar('\"');\n"
"    }\n"
"    else if (c == '\\n') {\n"
"        putchar('\\\\');\n"
"        putchar('n');\n"
"        putchar('\"');\n"
"        putchar('\\n');\n"
"        start_of_quote = 1;\n"
"    }\n"
"    else {\n"
"        putchar(c);\n"
"    }\n"
"}\n"
"\n"
"int main()\n"
"{\n"
"    int i = 0;\n"
"    while (prog[i] != '%') {\n"
"        putchar(prog[i++]);\n"
"    }\n"
"\n"
"    int j = 0;\n"
"    while (j < sizeof(prog)/sizeof(prog[0]) - 1) {\n"
"        quotchar(prog[j++]);\n"
"    }\n"
"\n"
"    i += 2;\n"
"    while (i < sizeof(prog)/sizeof(prog[0]) - 1) {\n"
"        putchar(prog[i++]);\n"
"    }\n"
"}\n"
;

int putchar(int);

void quotchar(char c) {
    static int start_of_quote = 1;

    if (start_of_quote) {
        putchar('"');
        start_of_quote = 0;
    }

    if (c == '\\') {
        putchar('\\');
        putchar('\\');
    }
    else if (c == '"') {
        putchar('\\');
        putchar('"');
    }
    else if (c == '\n') {
        putchar('\\');
        putchar('n');
        putchar('"');
        putchar('\n');
        start_of_quote = 1;
    }
    else {
        putchar(c);
    }
}

int main()
{
    int i = 0;
    while (prog[i] != '%') {
        putchar(prog[i++]);
    }

    int j = 0;
    while (j < sizeof(prog)/sizeof(prog[0]) - 1) {
        quotchar(prog[j++]);
    }

    i += 2;
    while (i < sizeof(prog)/sizeof(prog[0]) - 1) {
        putchar(prog[i++]);
    }
}
