#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "eval.h"

#define GRAY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define CLEAR_PREVIOUS_LINE "\033[1A\033[2K\r"

static const char *current_test = NULL;

void testing(const char *name) {
    current_test = name;
    printf(GRAY "[" YELLOW "testing" GRAY "]" RESET " %s\n", name);
    fflush(stdout);
}

void test_ok(void) {
    printf(CLEAR_PREVIOUS_LINE GRAY "[" GREEN "ok" GRAY "]" RESET " %s\n",
           current_test);
}

void test_failed(void) {
    printf(CLEAR_PREVIOUS_LINE GRAY "[" RED "failed" GRAY "]" RESET " %s\n",
           current_test);
}

void test_value_impl(char *call, unsigned long result, unsigned long expected) {
    if (result == expected) return;

    test_failed();
    printf("Wrong answer: %s\n", call);
    printf("  Return value: %lu\n", result);
    printf("  Expected value: %lu\n", expected);
    exit(1);
}

#define test_value(call, expected) test_value_impl(#call, call, expected)

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("set 1");
    test_value(eval("0"), 0);
    test_value(eval("1"), 1);
    test_value(eval("42"), 42);
    test_value(eval("1337"), 1337);
    test_value(eval("123456789"), 123456789);
    test_value(eval("13371337133713371337"), 13371337133713371337UL);
    test_value(eval("18446744073709551615"), 18446744073709551615UL);
    test_ok();

    testing("set 2");
    test_value(eval("1+1"), 2);
    test_value(eval("2*3"), 6);
    test_value(eval("0*0"), 0);
    test_value(eval("42+1337"), 1379);
    test_value(eval("42*1337"), 56154);
    test_value(eval("1337+42"), 1379);
    test_value(eval("1337*42"), 56154);
    test_value(eval("123456789*123456789"), 15241578750190521UL);
    test_value(eval("2222222222*7777777777"), 17283950613827160494UL);
    test_value(eval("18446744073709551615*0"), 0);
    test_value(eval("18446744073709551615+0"), 18446744073709551615UL);
    test_ok();

    testing("set 3");
    test_value(eval("1+2+3+4+5"), 15);
    test_value(eval("1*2*3*4*5"), 120);
    test_value(eval("123+456+789"), 1368);
    test_value(eval("123*456*789"), 44253432);
    test_value(eval("3*5*17*257*641*65537*6700417"), 18446744073709551615UL);
    test_value(eval("42*1337+13"), 56167);
    test_value(eval("42+1337*13"), 17423);
    test_value(eval("123+234+345*456+567*678*789"), 303469791);
    test_value(eval("2*3+5*7*11+13*17*19*23+29*31*37*41*43*47"), 2756302411);
    test_ok();

    testing("set 4");
    test_value(eval("(42)"), 42);
    test_value(eval("((42))"), 42);
    test_value(eval("((((((((((42))))))))))"), 42);
    test_value(eval("(1+1)"), 2);
    test_value(eval("42*(13+37)"), 2100);
    test_value(eval("(13+37)*42"), 2100);
    test_value(eval("1+(2+(3+(4+(5))))"), 15);
    test_value(eval("((((1)+2)+3)+4)+5"), 15);
    test_value(eval("((2+3)*5+7*(11+13+17))*19*23+((29+31)*37)*41+43*47"), 229385);
    test_value(eval("(((((((2+3)*5+7)*11+(13+17)*19)*23+(29*31+37)*41)*43+(47+53)*(59+61))*67+(71+73)*79)*83*89+((((97+101)*103+107)*109+113)*127+131)*137*139)*149*151+(((157+163)*167+173)*179+181)*191*193"), 150262954674345963UL);
    test_value(eval("9*1*(121+(32763*(18721+5212)+18276)+32876*(12*(512+31298))+(4712))+373*(23+(5+(1+(23765))))*275+0*0+(((3+(((3+(((42*1337)))+3)))+3)))"), 122442826088);
    test_value(eval("(2+1)*(2*2+1)*(2*2*2*2+1)*(2*2*2*2*2*2*2*2+1)*641*(2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2+1)*6700417"), 18446744073709551615UL);
    test_ok();

    testing("set 5");
    test_value(eval(""), 0);
    test_value(eval("+"), 0);
    test_value(eval("*"), 0);
    test_value(eval("("), 0);
    test_value(eval(")"), 0);
    test_value(eval("()"), 0);
    test_value(eval("13(37"), 0);
    test_value(eval("13)37"), 0);
    test_value(eval("1+(2*3"), 0);
    test_value(eval("1+2)*3"), 0);
    test_value(eval("1++2"), 0);
    test_value(eval("1**2"), 0);
    test_value(eval("1+*2"), 0);
    test_value(eval("1*+2"), 0);
    test_value(eval("-1"), 0);
    test_value(eval("-1337"), 0);
    test_value(eval("1337-42"), 0);
    test_value(eval("10/2"), 0);
    test_value(eval("1337/42"), 0);
    test_value(eval("aybabtu"), 0);
    test_value(eval("1 + 2"), 0);
    test_value(eval("(1+2)(3+4)"), 0);
    test_value(eval("1+"), 0);
    test_value(eval("1*"), 0);
    test_value(eval("+1"), 0);
    test_value(eval("*1"), 0);
    test_value(eval("(+42)"), 0);
    test_value(eval("(42+)"), 0);
    test_value(eval("(*42)"), 0);
    test_value(eval("(42*)"), 0);
    test_value(eval("(1+2))+((3+4)"), 0);
    test_value(eval("(((((((((("), 0);
    test_value(eval("))))))))))"), 0);
    test_value(eval("((((((((((42)))))))))"), 0);
    test_value(eval("(((((((((42))))))))))"), 0);
    test_value(eval("01"), 0);
    test_value(eval("0421337"), 0);
    test_value(eval("000000000000000000000000000000001"), 0);
    test_value(eval("1+00"), 0);
    test_value(eval("(13)37"), 0);
    test_value(eval("13(37)"), 0);
    test_value(eval("42*(3+042)+1337"), 0);
    test_value(eval("18446744073709551617"), 0);
    test_value(eval("99999999999999999999"), 0);
    test_value(eval("40000000000000000000"), 0);
    test_value(eval("4242424242424242424242424242424242424242424242424242"), 0);
    test_value(eval("18446744073709551615+2"), 0);
    test_value(eval("9223372036854775809*2"), 0);
    test_value(eval("0*((((1337*1337*1337*1337*1337*1337*1337))))+1"), 0);
    test_value(eval("3*5*17*257*641*65537*6700417+1"), 0);
    test_value(eval("3*5*17*257*641*65537*6700417+2"), 0);
    test_value(eval("3*5*17*257*641*65537*6700417*2"), 0);
    test_ok();

    printf("Set 10 OK\n");

    return 0;
}
