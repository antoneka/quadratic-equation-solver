#include "common.h"

int flag_parser(int argc, char *argv[], Flags *flags) {
    int flag_err = 0;

    opterr = 0;
    static const struct option long_options[] = 
    {
        {"test", 0, NULL, 't'},
        {"help", 0, NULL, 'h'},
        { 0    , 0, 0   ,  0 },
    };

    int c = 0, option_index = 0;
    while ((c = getopt_long(argc, argv, "th", long_options, &option_index)) != -1) 
    {
        switch (c) 
        {
            case 't':
                flags->is_test = IS_ENABLED;
                break;

            case 'h':
                flags->is_help = IS_ENABLED;
                break;

            case '?':
                fprintf(stderr, "quadratic_equation_solver: illegal option\n"
                                "usage: quadratic_equation_solver [-th]\n");
                flag_err = 1;
                return flag_err;

            default:
                assert(0 && "Invalid flag input");
        }
    }

    return flag_err;
}
