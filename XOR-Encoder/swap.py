print("Propriedade XOR -> a^b^b == a")

print([(a, b) for a in range(2) for b in range(2)])

print([a ^ b ^ b == a for a in range(2) for b in range(2)])

print("\n")

m = "Felipe Arnt"
k = 256

n = [chr(ord(a)) for a in m]

print("Texto pleno: \n")
print(n)

print("\nCriptografado: ")


cript = [chr(ord(a) ^ k) for a in m]
print(cript)
