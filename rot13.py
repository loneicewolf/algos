def rot13(string, length, alphabet):
    ciphertext = ""

    #alphabet = alphabet = alphabet[26:] if string.isupper() else alphabet[:26]
    alphabet = alphabet[0] if string.isupper() else alphabet[1]

    for i in range(length):
        output += alphabet[(alphabet.find(string[i]) + 13) % 26]
        
    return ciphertext

#alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHJIKLMNOPQRSTUVWXYZ"
alphabet = ["ABCDEFGHJIKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz"]

string = "string"
length = len(string)

print(f'Original String: {string}')
rotated1 = rot13(string, length, alphabet)
print(f'First rotation: {rotated1}')
rotated2 = rot13(rotated1, len(rotated1), alphabet)
print(f'Second rotation: {rotated2}')
