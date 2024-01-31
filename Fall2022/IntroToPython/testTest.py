for x in range(1, 5,):
    for y in range(1, 5):
        if (y == 4 and x == 1) or (y == 3 and x == 2) or (y == 2 and x == 3) or (y == 1 and x == 4):
            print('x', end='')
        else:
            print('o', end='')
    print()
