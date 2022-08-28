# Simple trie

Constructors:
    Trie(int N = 26, char ALPHABET_FIRST = 'a');
    /* N is alphabet size; ALPHABET_FIRST is the smallest character in ANSII;
    so N = 26 and ALPHABET_FIRST = 'a' mean that all possible characters in trie are {'a', 'b', 'c', ..., 'z'} */

C++:
    Trie example;

1. Add word to the trie with
    example.insert(word);
2. Remove word from the trie with
    example.remove(word);
3. Check is word in the trie with
    example.find(word);
