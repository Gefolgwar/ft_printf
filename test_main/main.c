#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int main(void)
{
        int output_OG;
        int output_FT;

/////////////////////////////////
//        NO SPECIFIERS        //
/////////////////////////////////
        ft_printf("----------------NO SPECIFIERS---------------\n");
        output_OG = printf("OG -> Test String \t TEeeEEEeEEsT String\n");
        output_FT = ft_printf("FT -> Test String \t TEeeEEEeEEsT String\n");
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");

        output_OG = printf("OG -> T \t t \n");
        output_FT = ft_printf("FT -> T \t t \n");
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//            %c               //
/////////////////////////////////
        ft_printf("\n------------%%c------------\n");
        char    ltr = 'C';
        output_OG = printf("OG -> I love %c\n", ltr);
        output_FT = ft_printf("FT -> I love %c\n", ltr);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");

        ltr = '\0';
        output_OG = printf("OG -> %c\n", ltr);
        output_FT = ft_printf("FT -> %c\n", ltr);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");

        output_OG = printf("OG -> %c %c %c \n", '1', '2', '3');
        output_FT = ft_printf("FT -> %c %c %c \n", '1', '2', '3');
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");

        output_OG = printf("OG -> %c %c %c \n", '2', '1', 0);
        output_FT = ft_printf("FT -> %c %c %c \n", '2', '1', 0);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//             %s              //
/////////////////////////////////
        ft_printf("\n------------%%s------------\n");
        char    *str = "Nuno";
        output_OG = printf("OG -> Hi I'm %s\n", str);
        output_FT = ft_printf("FT -> Hi I'm %s\n", str);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");

        char    *dummy = NULL;
        output_OG = printf("OG -> This should be NULL: %s\n", dummy);
        output_FT = ft_printf("FT -> This should be NULL: %s\n", dummy);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//              %p             //
/////////////////////////////////
        ft_printf("\n------------%%p------------\n");
        char    *ptr = "c";
        output_OG = printf("OG -> %p\n", ptr);
        output_FT = ft_printf("FT -> %p\n", ptr);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");
        
        void *dummy_ptr = NULL;
        output_OG = printf("OG -> Null pointer: %p\n", dummy_ptr);
        output_FT = ft_printf("FT -> Null pointer: %p\n", dummy_ptr);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//             %d / %i         //
/////////////////////////////////
        ft_printf("\n------------%%d / %%i------------\n");
        int             nbr_pos = 42;
        int             nbr_neg = -42;
        
        ft_printf("Basic positive/negative:\n");
        output_OG = printf("OG -> Pos %d, Neg %i\n", nbr_pos, nbr_neg);
        output_FT = ft_printf("FT -> Pos %d, Neg %i\n", nbr_pos, nbr_neg);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");
        
        ft_printf("Min/Max Limits:\n");
        output_OG = printf("OG -> MAX %d, MIN %d\n", INT_MAX, INT_MIN);
        output_FT = ft_printf("FT -> MAX %d, MIN %d\n", INT_MAX, INT_MIN);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//              %u             //
/////////////////////////////////
        ft_printf("\n------------%%u------------\n");
        unsigned nbr_u = 42;
        
        ft_printf("Basic unsigned:\n");
        output_OG = printf("OG -> %u\n", nbr_u);
        output_FT = ft_printf("FT -> %u\n", nbr_u);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");
        
        ft_printf("Overflow (negative as unsigned):\n");
        nbr_u = -16;
        output_OG = printf("OG -> -16 as u: %u\n", nbr_u);
        output_FT = ft_printf("FT -> -16 as u: %u\n", nbr_u);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//             %x / %X         //
/////////////////////////////////
        ft_printf("\n------------%%x / %%X------------\n");
        unsigned nbr_x = 255;
        
        ft_printf("Basic Hex:\n");
        output_OG = printf("OG -> Lower %x, Upper %X\n", nbr_x, nbr_x);
        output_FT = ft_printf("FT -> Lower %x, Upper %X\n", nbr_x, nbr_x);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        ft_printf("Zero:\n");
        output_OG = printf("OG -> %x\n", 0);
        output_FT = ft_printf("FT -> %x\n", 0);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//              %%             //
/////////////////////////////////
        ft_printf("\n------------%%%%------------\n");
        output_OG = printf("OG -> %% %% %%\n");
        output_FT = ft_printf("FT -> %% %% %%\n");
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//              width          //
/////////////////////////////////
	int test_num = 42;
        ft_printf("\n------------WIDTH 10------------\n");
        output_OG = printf("OG (Width 10): |%10d|\n", test_num);
        output_FT = ft_printf("FT (Width 10): |%10d|\n", test_num);
        printf("OUTPUT OG (Length) = %d\n", output_OG);
        ft_printf("OUTPUT FT (Length) = %d\n", output_FT);

        ft_printf("\n");

//========================================================//
//             NEW: FLAGS & PRECISION TESTS               //
//========================================================//

        ft_printf("\n=========================================\n");
        ft_printf("      NEW: FLAGS & PRECISION TESTS       \n");
        ft_printf("=========================================\n");

        ft_printf("\n------------ FLAGS (d/i) ------------\n");
        int num = 100;
        int neg_num = -100;
        
        // + Flag (Plus) - Requires ft_handle_nbrs and ft_print_nbrs logic
        ft_printf("FLAG: + (Plus)\n");
        output_OG = printf("OG -> Positive: %+d | Negative: %+d\n", num, neg_num);
        output_FT = ft_printf("FT -> Positive: %+d | Negative: %+d\n", num, neg_num);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");
        
        // ' ' Flag (Space) - Requires ft_handle_nbrs and ft_print_nbrs logic
        ft_printf("FLAG: ' ' (Space)\n");
        output_OG = printf("OG -> Positive: % d | Negative: % d\n", num, neg_num);
        output_FT = ft_printf("FT -> Positive: % d | Negative: % d\n", num, neg_num);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");
        
        // Width and Zero Padding (0) - Requires ft_parse_utils and ft_print_nbrs logic
        ft_printf("FLAG: 0 (Zero Padding) with width 8\n");
        output_OG = printf("OG -> Positive: %08d | Negative: %08d\n", num, neg_num);
        output_FT = ft_printf("FT -> Positive: %08d | Negative: %08d\n", num, neg_num);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");
        
        // Width and Left Justification (-) - Requires ft_parse_utils and ft_print_nbrs logic
        ft_printf("FLAG: - (Left Justification) with width 8\n");
        output_OG = printf("OG -> Positive: %-8d | Negative: %-8d\n", num, neg_num);
        output_FT = ft_printf("FT -> Positive: %-8d | Negative: %-8d\n", num, neg_num);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);


        ft_printf("\n------------ FLAGS (x/X) ------------\n");
        unsigned int hex_num = 4095; // FFF
        
        // # Flag (Sharp) - Requires ft_print_hex_x logic
        ft_printf("FLAG: # (Sharp) for Hex\n");
        output_OG = printf("OG -> Lower: %#x | Upper: %#X\n", hex_num, hex_num);
        output_FT = ft_printf("FT -> Lower: %#x | Upper: %#X\n", hex_num, hex_num);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");

        // # Flag with Zero - should output just '0'
        ft_printf("FLAG: # with Zero\n");
        output_OG = printf("OG -> %#x\n", 0);
        output_FT = ft_printf("FT -> %#x\n", 0);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        // Width and 0 Padding for Hex
        ft_printf("Width and Zero Padding for Hex (08x)\n");
        output_OG = printf("OG -> %08x\n", hex_num);
        output_FT = ft_printf("FT -> %08x\n", hex_num);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n------------ PRECISION ------------\n");

        // Precision for String (%s) - Requires ft_print_chars logic
        char *s_str = "Long string to be cut";
        ft_printf("PRECISION for String (.7s)\n");
        output_OG = printf("OG -> %.7s\n", s_str);
        output_FT = ft_printf("FT -> %.7s\n", s_str);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        // Precision for d/i (fills with zeros, overrides '0' flag) - Requires ft_print_nbrs logic
        int p_num = 42;
        ft_printf("PRECISION for Integers (.5d)\n");
        output_OG = printf("OG -> %.5d | %.5d\n", p_num, -42);
        output_FT = ft_printf("FT -> %.5d | %.5d\n", p_num, -42);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        // Precision for Hex (.5x) - Requires ft_print_hex_x logic
        ft_printf("PRECISION for Hex (.5x)\n");
        output_OG = printf("OG -> %.5x\n", 0xabc);
        output_FT = ft_printf("FT -> %.5x\n", 0xabc);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        // Precision with zero value (%d) - The output should be empty string
        ft_printf("PRECISION on zero value (.0d)\n");
        output_OG = printf("OG -> num is [%.0d]\n", 0);
        output_FT = ft_printf("FT -> num is [%.0d]\n", 0);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        
        ft_printf("\n------------ MIXED FLAGS & WIDTH ------------\n");

        // Combined Flags (Width, Zero, Sharp, Minus, Precision, Plus)
        
        ft_printf("MIXED: Width, Minus, Precision, and String\n");
        output_OG = printf("OG -> [%-10.5s]\n", "hello world"); // Should be left justified, padded with spaces, cut to 5 chars
        output_FT = ft_printf("FT -> [%-10.5s]\n", "hello world");
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        ft_printf("MIXED: Width, Plus, Precision, and Integer\n");
        output_OG = printf("OG -> [%+10.5d]\n", 42); // Should be right justified, padded with spaces, sign included, 5 zero padding
        output_FT = ft_printf("FT -> [%+10.5d]\n", 42);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);
        
        ft_printf("\n");

        ft_printf("MIXED: Width, Sharp, Precision, and Hex\n");
        output_OG = printf("OG -> [%#10.3x]\n", 0x42); // Should include 0x, right justified, 3 zero padding
        output_FT = ft_printf("FT -> [%#10.3x]\n", 0x42);
        printf("OUTPUT OG = %d\n", output_OG);
        ft_printf("OUTPUT FT = %d\n", output_FT);

        ft_printf("\n");
        return (0);
}