if __name__ == "__main__":
    print(any([False, True, False, False]))
    print(any([0, 1, 0, 0]))

    numbers = [1, 2, 3, 4, 5]
    print(any(item > 4 for item in numbers))
