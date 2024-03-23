#include <iostream>
#include <vector>

class Rc4 {
public:

    std::vector<int> IdentityPermutation() {
        std::vector<int> S(256);
        for(int i = 0; i < 256; i++)
            S[i] = i;
        return S;
    }

    std::vector<int> KeyScheduling(const std::vector<int>& S, const std::vector<int>& key) {
        std::vector<int> scrambled_S = S;
        int j = 0;
        for(int i = 0; i < 256; i++){
            j = (j + scrambled_S[i] + key[i % key.size()]) % 256;
            std::swap(scrambled_S[i], scrambled_S[j]);
        }
        return scrambled_S;
    }

    char PRGA(std::vector<int>& S, int& i, int& j) {
        (++i) % 256;
        j = (j + S[i]) % 256;
        std::swap(S[i], S[j]);
        return S[(S[i] + S[j]) % 256];
    }

};

std::string Encrypt(Rc4& rc4, std::string plaintext, std::vector<int> key){

    std::vector<int> S = rc4.IdentityPermutation();
    S = rc4.KeyScheduling(S, key);

    int i = 0, j = 0;
    std::string ciphertext;

    for(char c : plaintext) {
        ciphertext += rc4.PRGA(S, i, j) ^ c;
    }

    return ciphertext;
}

int main (int argc, char *argv[]) {

    Rc4 rc4;
    std::vector<int> key = {1, 2, 3, 4, 5};
    std::string message = "arcfour";

    std::string ciphertext = Encrypt(rc4, message, key);

    // RC4 is an involution.
    std::cout << "Message: " << message << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::cout << "Plaintext: " << Encrypt(rc4, ciphertext, key) << std::endl;

    return 0;
}
