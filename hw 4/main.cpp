//  Safa Mohammed
//  Hw 4 - Tongue Twisters
//  Purpose: This program takes an input file with sentences (in this case tongue twisters) and processes them to report various details specific to each sentence such as string length, longest word, number of vowels, consonants, etc. The program also outputs the sentence in different formats such as title case, spongebob case, etc.
//  Change Log:
//  3/26/22 - added ability to read sentences into a vector, added ability to read the words from a sentence into a 2D vector
//  3/27/22 - added ability to report string length, number of words, longest word, number of vowels, consonants, spaces, punctuation, other chars,
//          - added ability to print sentence in title case, toggle case, spongebob case
//  3/29/22 - added ability to print sentence in sentence case, added comments
//  note: included comment block with logic for leet speak but was not able to fully complete it due to lack of time

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

void readInput (ifstream &inputFile, vector<string> &sentences, vector<vector<string> > &words) {
    string str;
    vector<string> rows;
    
    while (inputFile) {
        
        getline(inputFile, str);
        sentences.push_back(str);
        
        string word;
        for (int x = 0; x < str.length(); x++)
            {
                //if there is a space then put the word that was created into a vector
                if (str[x] == ' ')
                {
                    rows.push_back(word);
                    
                    // make the word string empty
                    word = "";
                }
                
                // if there isn't a space then continue to read and combine the characters into a string
                else {
                    word = word + str[x];
                }
            }
        
        //the last word is put into the vector bc there is no space after
        rows.push_back(word);
        
        // insert the words of the current sentence into the words vector
        words.push_back(rows);
        
        // clear the rows vector for the new row/sentence
        rows.clear();
        
    }
    
    /* print contents of sentences (testing)
    for (int num = 0; num < sentences.size(); num++) {
        cout << sentences[num] << endl;
        
    }
    
    print contents of words (testing)
    for (int num2 = 0; num2 < words.size(); num2++) {
        for (int num3 = 0; num3 < words[num2].size(); num3++ ) {
            cout << words[num2][num3] << endl;
        }
    }*/
    
    
}

void readCharFile (ifstream &leetCharFile, vector<string> &leetCharString, vector<vector<string> > &leetCharLetters) {
    string str;
    vector<string> rows;
    
    while (leetCharFile) {
        
        getline(leetCharFile, str);
        leetCharString.push_back(str);
        
        string word;
        for (int x = 0; x < str.length(); x++)
            {
                //if there is a space then put the word that was created into a vector
                if (str[x] == ' ')
                {
                    rows.push_back(word);
                    
                    // make the word string empty
                    word = "";
                }
                
                // if there isn't a space then continue to read and combine the characters into a string
                else {
                    word = word + str[x];
                }
            }
        
        //the last word is put into the vector bc there is no space after
        rows.push_back(word);
        
        // insert the words into the leetcharletters vector
        leetCharLetters.push_back(rows);
        
        // clear the rows vector for the new row/sentence
        rows.clear();
        
    }
    
   /* for (int num2 = 0; num2 < leetCharLetters.size(); num2++) {
        for (int num3 = 0; num3 < leetCharLetters[num2].size(); num3++ ) {
            cout << leetCharLetters[num2][num3] << endl;
        }
    }*/
}

int longestWord (vector<vector<string> > words, int sentNum) {
    int count = 0;
    int wordNumber = 0;
    string word;
    
    for (int wordNum = 0; wordNum < words[sentNum].size(); wordNum++) {
        word = words[sentNum][wordNum];
        
        int length = words[sentNum][wordNum].size();
        // if the last character of the word is a punctuation, ignore it from the length of the word
        if (ispunct(word[length-1])) {
            length = length - 1;
        }
        // find the word with the largest length
        if (count < length) {
            count = length;
            wordNumber = wordNum;
        }
    }
    // return the location of the longest word
    return wordNumber;
}

int numVowels (string sentence, vector<vector<string> > words, int sentNum) {
    char vowels[10] = {'a', 'A', 'e', 'E', 'I', 'i', 'O', 'o', 'U', 'u'};
    
    int count = 0;
    for (int n = 0; n < 10; n++) {
        int searchPosition = 0;
        int vowelPosition;
        do {
            // find the vowel in the sentence
            vowelPosition = sentence.find(vowels[n], searchPosition);
            
            // if there is a vowel increase count
            if (vowelPosition != string::npos) {
                count++;
            }
            // search after the position where the vowel was found for duplicates
            searchPosition = vowelPosition + 1;
            
        } while (vowelPosition != string::npos);
    }
    // return the number of vowels found in the sentence
    return count;
}

int numConsonants (string sentence, vector<vector<string> > words, int sentNum) {
    char consonants[42] = {'b', 'B', 'c', 'C', 'd', 'D', 'g', 'G', 'f', 'F',
                            'h', 'H', 'J', 'j', 'k', 'K', 'l', 'L', 'm', 'M',
                            'N', 'n', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S',
                            't', 'T', 'V', 'v', 'W', 'w', 'x', 'X', 'y', 'Y', 'z', 'Z'};
    
    int count = 0;
    for (int n = 0; n < 42; n++) {
        int searchPosition = 0;
        int consonantPosition;
        do {
            // find the consonant in the sentence
            consonantPosition = sentence.find(consonants[n], searchPosition);
            
            // if there is a consonant increase count
            if (consonantPosition != string::npos) {
                count++;
            }
            // search after the position where the consonant was found for duplicates
            searchPosition = consonantPosition + 1;
            
        } while (consonantPosition != string::npos);
    }
    // return the number of consonants found in the sentence
    return count;
}

int numSpaces (string sentence) {
    int searchPosition = 0;
    int count = 0;
    int spacePosition;
    do {
        // find the space in the sentence
        spacePosition = sentence.find(' ', searchPosition);
        
        // if there is a space increase count
        if (spacePosition != string::npos) {
            count++;
        }
        // search after the position where the space was found for duplicates
        searchPosition = spacePosition + 1;
        
    } while (spacePosition != string::npos);
    
    // return the number of spaces found in the sentence
    return count;
}

int numPunctuation (string sentence) {
    char punct[32] = {'!', '"', '#', '$', '%',
                       '&', '\'', '(', ')', '*',
                       '+', ',', '-', '.', '/',
                       ':', ';', '<', '=', '>',
                       '?', '@', '[', ']', '^',
                       '_', '`', '{', '|', '}',
                       '~', '\\'};
    
    int count = 0;
    for (int n = 0; n < 32; n++) {
        int searchPosition = 0;
        int punctPosition;
        do {
            // find the punctuation in the sentence
            punctPosition = sentence.find(punct[n], searchPosition);
            
            // if there is a punctuation increase count
            if (punctPosition != string::npos) {
                count++;
            }
            // search after the position where the punctuation was found for duplicates
            searchPosition = punctPosition + 1;
            
        } while (punctPosition != string::npos);
    }
    // return the number of punctuation found in the sentence
    return count;
}

void titleCase (string sentence, int sentNum, vector<vector<string> > words) {
    string sent = "";
    for (int wordNum = 0; wordNum < words[sentNum].size(); wordNum++) {
        string str = words[sentNum][wordNum];
        
        // change first char of the word into uppercase
        str[0] = toupper(str[0]);
        
        // create a sentence by adding the words together
        sent = sent + ' ' + str;
    }
    
    // print the sentence with title case
    cout << "Title Case: " << sent << endl;
}

void sentenceCase (string sentence, int sentNum, vector<vector<string> > words) {
    string sent = "";
    string str;

    string properNouns[16] = {"henry", "higgins", "amy", "spain", "billy",
                              "becky's", "suzy", "dan's", "fred's", "fritos",
                              "friday's", "rudolph", "hertford,", "hereford,", "hampshire,",
                              "cockney"};
    
        
        for (int wordNum = 0; wordNum < words[sentNum].size(); wordNum++) {
            
            str = words[sentNum][wordNum];
            
            //make the whole word lower case in case there is a capital letter somewhere
            for (int z = 0; z < str.length(); z++) {
                str[z] = tolower(str[z]);
            }
            
            // the first letter of the first word is capitalized or if the word is a proper noun
            for (int n = 0; n < 16; n++) {
                if (wordNum == 0 || str == properNouns[n] ) {
                    str[0] = toupper(str[0]);
                    break;
            }
        }
            
        // combine words to make the sentence
        sent = sent + ' ' + str;
    }
    
    cout << "Sentence Case: " << sent << endl;
}

void toggleCase (string sentence, int sentNum, vector<vector<string> > words) {
    string sent = "";
    
    for (int wordNum = 0; wordNum < words[sentNum].size(); wordNum++) {
        string str = words[sentNum][wordNum];
        
        // change first char of the word into lowercase
        str[0] = tolower(str[0]);
        
        // change the rest of the letters in the word to uppercase
        for (int let = 1; let < str.length(); let++) {
            str[let] = toupper(str[let]);
        }
        
        // create a sentence by adding the words together
        sent = sent + ' ' + str;
    }
    
    // print the sentence with toggle case
    cout << "Toggle Case: " << sent << endl;
}

void spongebobCase (string sentence, int sentNum, vector<vector<string> > words) {
    
    // generate a random number between 1 and 10
    int chance = rand() % 10 + 1;
    
    for (int x = 0; x < sentence.length(); x++) {
        
        // 50% chance of the number being even and therefore uppercase
        if (chance % 2 == 0) {
            sentence[x] = toupper(sentence[x]);
        }
        
        //generate new random number
        chance = rand() % 10 + 1;
    }
    
    cout << "Spongebob Case: " << sentence << endl;
}

/*void leetSpeak (string sentence, int sentNum, vector<vector<string> > words, vector<vector<string> > leetCharLetters) {
    int chance = rand() % 10 + 1;
    
 for (int x = 0; x < sentence.length(); x++) {
     
    if (chance % 2 == 0) {
        
    for (int num2 = 0; num2 < leetCharLetters.size(); num2++) {
         //for (int num3 = 0; num3 < leetCharLetters[num2].size(); num3++ ) {
            // if the letter at position x = the letter in the first column of leetChars then insert/replace that letter in the sentence with its equivalent in leet speak
            if (leetCharLetters[num2][1] == sentence[x]) {
                string str = leetCharLetters[num2][2];
                sentence.insert(x, str);
                }
           //  }
         }
    }
        chance = rand() % 10 + 1;
}

    cout << "Leet Speak: " << endl;
}*/

void processSentence (string sentence, int sentNum, vector<vector<string> > words, vector<vector<string> > leetCharLetters) {
    cout << "The sentence is: " << sentence << endl << endl;
    
    cout << "Length of string: " << sentence.length() << endl;
    cout << "Number of words: " << words[sentNum].size() << endl;
    
    int wordNumber = longestWord(words, sentNum);
    cout << "Longest word: " << words[sentNum][wordNumber] << endl;
    
    int vowels = numVowels (sentence, words, sentNum);
    cout << "Number of Vowels: " << vowels << endl;
    
    int consonants = numConsonants (sentence, words, sentNum);
    cout << "Number of Consonants: " << consonants << endl;
    
    int spaces = numSpaces (sentence);
    cout << "Number of Spaces: " << spaces << endl;
    
    int punct = numPunctuation (sentence);
    cout << "Number of Punctuation: " << punct << endl;
    
    int otherChar = sentence.length() - vowels - consonants - spaces - punct;
    cout << "Number of Other Characters: " << otherChar << endl << endl;
    
    titleCase (sentence, sentNum, words);
    sentenceCase (sentence, sentNum, words);
    toggleCase (sentence, sentNum, words);
    spongebobCase (sentence, sentNum, words);
    
    //leetSpeak (sentence, sentNum, words, leetCharLetters);
    
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;
}

int main() {
   
    ifstream inputFile;
    inputFile.open("Tongue-Twisters.txt");
    
    ifstream leetCharFile;
    leetCharFile.open("LeetChars-Small.txt");
    
    vector<string> sentences;
    vector<vector<string> > words;
    
    vector<string> leetCharString;
    vector<vector<string> > leetCharLetters;

    if (inputFile) {
       //cout << "file opened" << endl; (testing)
        readInput (inputFile, sentences, words);
        
        if (leetCharFile) {
            readCharFile (leetCharFile, leetCharString, leetCharLetters);
        }
        else {
            cout << "Leet Char file did not open" << endl;
        }
        
        // for each sentence do the tasks
        for (int sentNum = 0; sentNum < sentences.size() - 1; sentNum++) {
            processSentence (sentences[sentNum], sentNum, words, leetCharLetters);
        }
    }
    else {
        cout << "Error: the file did not open" << endl;
    }
    
    return 0;
}
