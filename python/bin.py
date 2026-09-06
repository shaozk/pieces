if __name__ == "__main__":
    print(bin(10))
    print(bin(1))
    print(bin(65535))
    print(bin(-1))
    print(bin(2**20))

    value = 2**10
    digits = len(bin(value)) - 2
    assert digits == value.bit_length()
