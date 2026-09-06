if __name__ == "__main__":
    x = [] or "hello"  # x 将会是 "hello" 而不是 True
    print(x)

    print(True > False)  # True

    a = True
    b = True
    print(a == b)  # True
    print(a is b)  # True

    a = "a"
    c = "a"
    print(a is c)
