import hashlib

with open('mark.txt', 'r') as f:
    text = f.read()
    hash = hashlib.sha256(text.encode()).hexdigest()
    print(hash)
