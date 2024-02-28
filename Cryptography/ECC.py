class EllipticCurve:
    def __init__(self, a, b, p):
        self.a = a
        self.b = b
        self.p = p

    def point_addition(self, P, Q):
        if P is None:
            return Q
        if Q is None:
            return P

        x1, y1 = P
        x2, y2 = Q

        if P == Q:
            s = ((3 * x1**2 + self.a) * self.mod_inverse(2 * y1, self.p)) % self.p
        else:
            s = ((y2 - y1) * self.mod_inverse(x2 - x1, self.p)) % self.p

        x3 = (s**2 - x1 - x2) % self.p
        y3 = (s * (x1 - x3) - y1) % self.p

        return x3, y3

    def point_multiply(self, k, P):
        R = None
        for i in range(k.bit_length()):
            if (k >> i) & 1:
                R = self.point_addition(R, P)
            P = self.point_addition(P, P)
        return R

    def mod_inverse(self, a, m):
        m0, x0, x1 = m, 0, 1
        while a > 1:
            q = a // m
            m, a = a % m, m
            x0, x1 = x1 - q * x0, x0
        return x1 + m0 if x1 < 0 else x1

# Example curve parameters (secp256k1 used in Bitcoin)
a = 0
b = 7
p = 2**256 - 2**32 - 977

# Create elliptic curve instance
curve = EllipticCurve(a, b, p)

# Base point (generator point) for secp256k1
Gx = 0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798
Gy = 0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8
G = (Gx, Gy)

# Example private key
private_key = 123456789

# Generate public key (point) by multiplying base point by private key
public_key = curve.point_multiply(private_key, G)

print("Public key (x, y):", public_key)

# Message to encrypt
message = "Bokachoda Mara Kha"

# Encrypt message with recipient's public key
encrypted_message = []
for char in message:
    # Convert character to its ASCII value
    char_value = ord(char)
    # Encode character as a point on the elliptic curve
    encoded_point = curve.point_multiply(char_value, G)
    # Add recipient's public key to the encoded point
    encrypted_point = curve.point_addition(encoded_point, public_key)
    encrypted_message.append(encrypted_point)

print("Encrypted message:", encrypted_message)

# Decrypt message with recipient's private key
decrypted_message = ""
for point in encrypted_message:
    # Subtract recipient's private key from the received point
    decrypted_point = curve.point_addition(point, (-private_key, -private_key))
    # Decode point to ASCII value and convert to character
    decrypted_char = chr(decrypted_point[0])
    decrypted_message += decrypted_char

print("Decrypted message:", decrypted_message)
