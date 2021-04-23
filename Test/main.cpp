#include <UnitTest++/UnitTest++.h>
#include "/home/student/kursovyu/base32_variant3/Encoder.h"
#include "/home/student/kursovyu/base32_variant3/Decoder.h"
#include "/home/student/kursovyu/base32_variant3/Encoder.cpp"
#include "/home/student/kursovyu/base32_variant3/Decoder.cpp"
#include "/home/student/kursovyu/base32_variant3/ExceptionAlphabet.h"
#include "/home/student/kursovyu/base32_variant3/ExceptionAlphabet.cpp"
SUITE(Encode)
{

    TEST(Encode_EnglishLetters) {
        Encoder correct_result("IFBEGRCFIZDUQSKKJNGE2TSPKBIVEU2UKVLFOWCZLI======");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    }

    TEST(Encode_RussianLetters) {
        Encoder correct_result("2CINBEOQSLIJHUEU2CK5BAOQS3IJPUEY2CM5BGWQTPIJZUE52CPNBH6QUDIKDUFC2CR5BJGQUXIKNUFH2CUNBKOQVLIKXUFM2CW5BLWQV4======");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"));
    }

    TEST(Encode_SpecialCharacters) {
        Encoder correct_result("IARSIJK6HITD6XBKFBPS2PJLPN6VWXL4LRQH4PR4HMXQ====");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("@#$%^:&?\*(_-=+{}[]|\`~><;/"));
    }

    TEST(Encode_Numbers) {
        Encoder correct_result("GAYTEMZUGU3DOOBZ");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("0123456789"));
    }
    TEST(Encode_AllCharacters) {
        Encoder correct_result("JBSWY3DPEDIL7UMA2C4NBMWQWXIYEIBRGIZTINJAFIUCSIK7HU======");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("Hello привет 12345 *()!_="));
    }
}

SUITE(Decode)
{

    TEST(Decode_EnglishLetters) {
        Decoder correct_result("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("IFBEGRCFIZDUQSKKJNGE2TSPKBIVEU2UKVLFOWCZLI======"));
    }

    TEST(Decode_RussianLetters) {
        Decoder correct_result("русские буквы");
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("2GANDA6RQHIYDUF22C4NBNJA2CY5DA6QXLILFUML"));
    }

    TEST(Decode_SpecialCharacters) {
        Decoder correct_result("@#$%^:&?\*(_-=+{}[]|\`~><;/");
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("IARSIJK6HITD6XBKFBPS2PJLPN6VWXL4LRQH4PR4HMXQ===="));
    }

    TEST(Decode_Numbers) {
        Decoder correct_result("0123456789");
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("GAYTEMZUGU3DOOBZ"));
    }
    TEST(Decode_AllCharacters) {
        Decoder correct_result("Hello привет 12345 *()!_=");
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("JBSWY3DPEDIL7UMA2C4NBMWQWXIYEIBRGIZTINJAFIUCSIK7HU======"));
    }
}

SUITE(ExceptionAlphabet)
{
    TEST(ExceptionAlphabet_one) {
        ExceptionAlphabet test;
        CHECK_EQUAL(false, test.checking_the_alphabetB32("АBCDEFGHIJKLMNOPQRSTUVWXYZ234567=ъ")); // недопустимый символ в конце строки
    }

    TEST(ExceptionAlphabet_two) {
        ExceptionAlphabet test;
        CHECK_EQUAL(true, test.checking_the_alphabetB32("ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=")); // все возможные символы алфавита
    }
    TEST(ExceptionAlphabet_three) {
        ExceptionAlphabet test;
        CHECK_EQUAL(false, test.checking_the_alphabetB32("АBCDEFGHIJKLMNOPdQRSTUVWXYZ234567=")); // недопустимый символ в серидине строки
    }
    
    TEST(ExceptionAlphabet_four) {
        ExceptionAlphabet test;
        CHECK_EQUAL(false, test.checking_the_alphabetB32("фАBCDEFGHIJKLMNOPQRSTUVWXYZ234567=")); // недопустимый символ в начале строки
    }
    TEST(ExceptionAlphabet_five) {
        ExceptionAlphabet test;
        CHECK_EQUAL(false, test.checking_the_alphabetB32("фАBCDEFGHIJKLMNOPQфRSTUVWXYZ234567=ф")); // недопустимый символ во всех местах строки
    }

}
int main()
{
    return UnitTest::RunAllTests();
}
