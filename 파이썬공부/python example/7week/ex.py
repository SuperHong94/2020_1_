SHIFT=1
def encrypt(raw):
    ret=''
    for ch in raw:
        ret+=chr(ord(ch)+SHIFT)
    return ret

def decrypt(raw):
    ret=""
    for ch in raw:
        ret += chr(ord(ch)-SHIFT)
    return ret

if __name__=="__main__":
    raw=input("input: ")
    encrypted=encrypt(raw)
    print("encrypted:"+encrypted)
    decrypted=decrypt(encrypted)
    print("decrypted:"+decrypted)