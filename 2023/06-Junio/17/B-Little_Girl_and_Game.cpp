#include <iostream>
#include <string>
#include <array>

const int NUM_LETTERS = 26;

std::array<int, NUM_LETTERS> alphabet;

bool is_palindrome()
{
    int oddCount = 0;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (alphabet[i] % 2 != 0)
        {
            oddCount++;
        }
    }
    return oddCount <= 1;
}

void removeLetter()
{
    bool found = false;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (alphabet[i] % 2 == 0 && alphabet[i] > 1)
        {
            alphabet[i]--;
            found = true;
            break;
        }
    }

    if (!found)
    {
        for (int i = 0; i < NUM_LETTERS; i++)
        {
            if (alphabet[i] % 2 != 0)
            {
                alphabet[i]--;
                break;
            }
        }
    }
}

int main()
{
    std::string cad;
    std::cin >> cad;

    std::fill(alphabet.begin(), alphabet.end(), 0);

    for (char c : cad)
    {
        alphabet[c - 'a']++;
    }

    bool player = true;

    while (!is_palindrome())
    {
        removeLetter();
        player = !player;
    }

    std::cout << (player ? "First" : "Second") << std::endl;

    return 0;
}
