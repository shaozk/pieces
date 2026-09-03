if __name__ == "__main__":
    li = [1, 2, 3, 4, 5, 6]
    result = all(item > 0 for item in li)
    print(result)

    def expensive_function():
        return True

    checks = [lambda: False, expensive_function, expensive_function]
    result = all(check() for check in checks)
    print(result)

    result = all([])
    print(result)
