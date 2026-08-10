// Shift or Ceaser Cipher
#include <iostream>
#include <string>

using namespace std;

// fun to encrypt plain text
string encrypt(string p_text, int key){
    // if key out of range
    if (key < 0 || key > 25) return "KeyError!";

    string c_text = ""; // store encrypted text

    for(int i=0; i<size(p_text); i++){
        char ch = p_text[i];

        // shift only letters
        if(isupper(ch))
            ch = 'A' + (ch - 'A' + key) % 26;
        if(islower(ch))
            ch = 'a' + (ch - 'a' + key) % 26;
        
        // if you want to shift numbers, symbols, you can add extra checks for them

        c_text += ch; // add to result 
    }
    return c_text;
    
}

// fun to decrypt cipher text
string decrypt(string c_text, int key){
    // if key out of range
    if (key < 0 || key > 25) return "KeyError!";

    string p_text = ""; // store encrypted text

    for(int i=0; i<size(c_text); i++){
        char ch = c_text[i];

        // shift only letters
        if(isupper(ch))
            ch = 'A' + (ch - 'A' - key + 26) % 26;
        if(islower(ch))
            ch = 'a' + (ch - 'a' - key + 26) % 26;
        
        // if you want to shift numbers, symbols, you can add extra checks for them

        p_text += ch; // add to result 
    }
    return p_text;
    
}

int main(){
    string p_text = "Taskeen Raza";
    int key = 3;

    string cipher_text = encrypt(p_text, key);
    cout << "Cipher text: " << cipher_text << endl;

    cout << "Plain text: " << decrypt(cipher_text, key) << endl;
 
    return 0;
}