#include<iostream>
#include<set>

using namespace std;
 
bool is_group_word(char *word)
{
    char alphabet = *word;
    set<char> alphabets { alphabet };
    
    while (*++word) {
        if (alphabet == *word) {
            continue;
        }

        alphabet = *word;

        if (alphabets.find(alphabet) != alphabets.end()) {
            return false;
        }

        alphabets.insert(alphabet);
    }

    return true;
}

int main(void)
{
    int n, group_words_count = 0;

    cin >> n;

    while (n) {
        char word[100];
        cin >> word;
        if (is_group_word(word)) {
            group_words_count++;
        }
        n--;
    }

    cout << group_words_count << endl;

    return 0;
}
