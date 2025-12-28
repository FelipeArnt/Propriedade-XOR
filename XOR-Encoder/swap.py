

def hello():

    print("Propriedade XOR -> a^b^b == a")
    print([(a, b) for a in range(2) for b in range(2)])
    print([a ^ b ^ b == a for a in range(2) for b in range(2)])
    print("\n")

def xorEncoder(m,k):
    n = [chr(ord(a)) for a in m]

    print("Texto pleno: \n")
    print(n)

    print("\nCriptografado: ")

    cript = [chr(ord(a) ^ k) for a in m]
    print(cript)

if __name__ == "__main__":
    hello()
    xorEncoder(m="hello", k=256)
