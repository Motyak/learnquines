#include <includes.h>

int main()
{
    std::string boilerplate_str = "#include <includes.h>\n\nint main()\n{\n";
    #define define_str_var [](std::string name, std::string val){return "    std::string " + name + " = " + val + ";\n";}
    #define define_str_lambda [](std::string name, std::string val){return "    #define " + name + " " + val + "\n";}
    #define print [](std::string rhs){return "    std::cout << " + rhs + ";\n";}

    std::cout << boilerplate_str;
    std::cout << define_str_var("boilerplate_str", quote(boilerplate_str));
    std::cout << define_str_lambda("define_str_var", QUOTE(define_str_var));
    std::cout << define_str_lambda("define_str_lambda", QUOTE(define_str_lambda));
    std::cout << define_str_lambda("print", QUOTE(print));
    std::cout << "\n";

    std::string end[] = {
        "boilerplate_str",
        "define_str_var(\"boilerplate_str\", quote(boilerplate_str))",
        "define_str_lambda(\"define_str_var\", QUOTE(define_str_var))",
        "define_str_lambda(\"define_str_lambda\", QUOTE(define_str_lambda))",
        "define_str_lambda(\"print\", QUOTE(print))",
        "\"\\n\"",
        "",
        "    int i, j;",
        "    for (i = 0;; ++i) {",
        "        if (end[i] == \"\") {",
        "            std::cout << \"\\n\";",
        "            std::cout << \"    std::string end[] = {\\n\";",
        "            break;",
        "        }",
        "        std::cout << print(end[i]);",
        "    }",
        "    for (j = 0; j < sizeof(end)/sizeof(end[0]); ++j) {",
        "        std::cout << \"        \" + quote(end[j]) + \",\\n\";",
        "    }",
        "    std::cout << \"    };\\n\";",
        "    for (j = i; j < sizeof(end)/sizeof(end[0]); ++j) {",
        "        std::cout << end[j] << \"\\n\";",
        "    }",
        "}",
    };

    int i, j;
    for (i = 0;; ++i) {
        if (end[i] == "") {
            std::cout << "\n";
            std::cout << "    std::string end[] = {\n";
            break;
        }
        std::cout << print(end[i]);
    }
    for (j = 0; j < sizeof(end)/sizeof(end[0]); ++j) {
        std::cout << "        " + quote(end[j]) + ",\n";
    }
    std::cout << "    };\n";
    for (j = i; j < sizeof(end)/sizeof(end[0]); ++j) {
        std::cout << end[j] << "\n";
    }
}
