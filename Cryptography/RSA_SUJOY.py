import math
#function for encryption
def encrypt ( text,  e, n):
    ciphr=""
    for i in text:
        m=ord(i)
        print(m)
        ciphr+=chr(pow(m,e)%n)
    print("cipher text: ",ciphr)
    return ciphr

#function for decryption
def decrypt(cipher,d,n):
    plain=""
    for i in cipher:
        plain+=chr(pow(ord(i),d)%n)
    print(plain)


text=input("Input text: ")
print(text)

#function for key generation
def key_generation(p,q):


    totient=(p-1)*(q-1)
    n=p*q
    for i in range(2,n-1):
        if(math.gcd(i,totient)==1):
            e=i
            break
        else:
            continue
    print("e= ",e)

    for i in range(2,n):
        if (i*e)%totient==1:
            d=i
            break
    print("d= ",d)

    public=[e,n]
    print("pu= ",public)
    private=[d,n]
    return e,d


#p=int(input("enter p: "))
#q=int(input("enter q: "))
p=int(139)
q=int(1117)
n=p*q

e,d=key_generation(p,q)
#encryption
cipher=encrypt(text,e,n)

#decryption
decrypt(cipher,d,n)

