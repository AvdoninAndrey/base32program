#include <UnitTest++/UnitTest++.h>
#include "/home/student/kursovyu/base32_variant3/Encoder.h"
#include "/home/student/kursovyu/base32_variant3/Decoder.h"
#include "/home/student/kursovyu/base32_variant3/Encoder.cpp"
#include "/home/student/kursovyu/base32_variant3/Decoder.cpp"
#include "/home/student/kursovyu/base32_variant3/ExceptionDecodeStroka.h"
#include "/home/student/kursovyu/base32_variant3/ExceptionDecodStroka.cpp"
SUITE(Encode)
{

    TEST(Encode_EnglishLetters) {                                                   // английские буквы с пробелами
        Encoder correct_result("IFBEGRCFEBDEOSBAJFFEWTCNJZHVAUKSKNKFKVSXEBMFSIC2");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("ABCDE FGH IJKLMNOPQRSTUVW XY Z"));
    }

    TEST(Encode_RussianLetters) {                                       // русские буквы
        Encoder correct_result("2CINBEOQSLIJHUEU2CK5BAOQS3IJPUEY2CM5BGWQTPIJZUE52CPNBH6QUDIKDUFC2CR5BJGQUXIKNUFH2CUNBKOQVLIKXUFM2CW5BLWQV4======");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"));
    }

    TEST(Encode_SpecialCharacters) {                                                // спец. символы
        Encoder correct_result("IARSIJK6HITD6KRIL4WT2K33PVNV27DAPY7DYOZP");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("@#$%^:&?*(_-=+{}[]|`~><;/"));
    }

    TEST(Encode_Numbers) {                                             
        Encoder correct_result("GAYTEMZUGU3DOOBZ");                     //цифры
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("0123456789"));
    }
    TEST(Encode_AllCharacters) {                                                    // смесь всех символом
        Encoder correct_result("JBSWY3DPEDIL7UMA2C4NBMWQWXIYEIBRGIZTINJAFIUCSIK7HU======");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("Hello привет 12345 *()!_="));
    }
    // Нетипичные ситуации:
    TEST(Encode_EmptyString) {                                                    //пустая строка
        Encoder correct_result("");
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode(""));
    }
    TEST(Encode_aStringOfSpaces) { 
        Encoder correct_result("EAQCAIBA");             //строка из пробелов
        Encoder test;
        CHECK_EQUAL(correct_result,test.base32Encode("     "));
    }

}

SUITE(Decode)
{

    TEST(Decode_EnglishLetters) {
        Decoder correct_result("ABCDE FGH IJKLMNOPQRSTUVW XY Z");           // английские буквы с пробелами
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("IFBEGRCFEBDEOSBAJFFEWTCNJZHVAUKSKNKFKVSXEBMFSIC2"));
    }

    TEST(Decode_RussianLetters) {
        Decoder correct_result("русские буквы");                // русские буквы (слова)
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("2GANDA6RQHIYDUF22C4NBNJA2CY5DA6QXLILFUML"));
    }

    TEST(Decode_SpecialCharacters) {
        Decoder correct_result("@#$%^:&?*(_-=+{}[]|`~><;/");          // спец. символы
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("IARSIJK6HITD6KRIL4WT2K33PVNV27DAPY7DYOZP"));
    }

    TEST(Decode_Numbers) {
        Decoder correct_result("0123456789");            //цифры
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("GAYTEMZUGU3DOOBZ"));
    }
    TEST(Decode_AllCharacters) {
        Decoder correct_result("URA я пишу тесты 123 ?)(!");    // смесь всех символом
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("KVJECIGRR4QNBP6QXDIYRUMDEDIYFUFV2GA5DAWRRMQDCMRTEA7SSKBB"));
    }
    // Нетипичные ситуации:
    TEST(Decode_EmptyString) {                                                    
        Decoder correct_result("");                                     //пустая строка
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode(""));
    }
    TEST(Decode_aStringOfSpaces) {                                                    
        Decoder correct_result("     ");                                    //декодирование строки из пробелов
        Decoder test;
        CHECK_EQUAL(correct_result,test.base32Decode("EAQCAIBA"));
    }

}

SUITE(ExceptionDecodeStrokaTest)
{
    TEST(ExceptionDecodeStroka_one) {
        ExceptionDecodeStroka test;
        CHECK_THROW(test.checking_the_Decod_str("АBCDEFGHIJKLMNOPQRSTUVWXYZ234567=ъ"),ExceptionDecodeStroka); // недопустимый символ в конце строки
    }

    TEST(ExceptionDecodeStroka_two) {
        ExceptionDecodeStroka test;
        CHECK_EQUAL(true, test.checking_the_Decod_str("ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=")); // все возможные символы алфавита
    }
    TEST(ExceptionDecodeStroka_three) {
         ExceptionDecodeStroka test;
         CHECK_THROW(test.checking_the_Decod_str("АBCDEFGHIJKLMNOPdQRSTUVWXYZ234567="),ExceptionDecodeStroka); // недопустимый символ в серидине строки
    }

    TEST(ExceptionDecodeStroka_four) {
        ExceptionDecodeStroka test;
         CHECK_THROW(test.checking_the_Decod_str("фАBCDEFGHIJKLMNOPQRSTUVWXYZ234567="),ExceptionDecodeStroka); // недопустимый символ в начале строки
    }
    TEST(ExceptionDecodeStroka_five) {
         ExceptionDecodeStroka test;
         CHECK_THROW(test.checking_the_Decod_str("фАBCDEFGHIJKLMNOPQфRSTUVWXYZ234567=ф"),ExceptionDecodeStroka); // недопустимый символ во всех местах строки
    }
    TEST(ExceptionDecodeStroka_six) {
         ExceptionDecodeStroka test;
         CHECK_THROW(test.checking_the_Decod_str("АBCDEFGHIJKLMNOPQ RSTUVWXYZ234567="),ExceptionDecodeStroka); // недопустимый символ(пробел)
    }
    TEST(ExceptionDecodeStroka_seven) {
         ExceptionDecodeStroka test;
         CHECK_THROW(test.checking_the_Decod_str("=ABCDEFGHIJKLMNOP"),ExceptionDecodeStroka); // символ "=" в начале строки
    }
    TEST(ExceptionDecodeStroka_eight) {
         ExceptionDecodeStroka test;
         CHECK_THROW( test.checking_the_Decod_str("ABCDEFGHI=JKLMNOP"),ExceptionDecodeStroka); // символ "=" в середине строки
    }

}
int main()
{
    return UnitTest::RunAllTests();
}
