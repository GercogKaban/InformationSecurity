#include <iostream>
#include <ctime>

// шифр Цезаря
namespace CezarEncryption
{
    // шифрование
    void encrypt(char* data, const size_t dataSize, const char key)
    {
        for (size_t i = 0; i < dataSize; ++i)
            data[i]+= key;
    }

    // дешифрование
    void decrypt(char* data, const size_t dataSize, const char key)
    {
        for (size_t i = 0; i < dataSize; ++i)
            data[i]-= key;
    }
}


// шифр простой замены
namespace SimpleReplacement
{
    // длина ключа (размер char)
    const int keySize = 256;

    // генерация ключа
    char* genKey()
    {
        srand(time(0));
        // кол-во раз для перетасовывания данных ключа
        const size_t swapCount = 200;
        // создание и заполнение ключа
        char* key = new char[keySize -1];
        for (size_t i = 0; i < keySize - 1; ++i)
            key[i] = (char)i;
        for (size_t i = 0; i < swapCount; ++i)
            std::swap(key[rand() % 255], key[rand() % 255]);
        return key;
    }

    // шифрование
    void encrypt(char* data, const size_t dataSize, const char* key)
    {
        for (size_t i = 0; i < dataSize; ++i)
            data[i] = key[(int)data[i]];
    }
    // дешифрование
    void decrypt(char* data, const size_t dataSize, const char* key)
    {
        for (size_t i = 0; i < dataSize; ++i)
            data[i] = std::find(key, key + keySize -1, data[i]) - key;
    }
}

int main()
{
    // пример работы шифрований

    const char key = 3; // смещение
    char test[] = { "hello" };

    std::cout << test << std::endl;
    CezarEncryption::encrypt(test, sizeof(test)-1, key);
    std::cout << test << std::endl;
    CezarEncryption::decrypt(test, sizeof(test)-1, key);
    std::cout << test << std::endl;

    const char* key2 = SimpleReplacement::genKey();
    SimpleReplacement::encrypt(test, sizeof(test) - 1, key2);
    std::cout << test << std::endl;
    SimpleReplacement::decrypt(test, sizeof(test) - 1, key2);
    std::cout << test << std::endl;

    return 0;
    
}