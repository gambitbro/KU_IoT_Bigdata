def asterisk_test(a, b, *args):
    print(a)
    print(b)
    for i in args:
        print(i)
    return a + b + sum(args)

def asterisk_test2(a, b, *args):
    x, y, *z = args             # z는 packing되어 들어감 
    return x, y, z

def main():
    print(asterisk_test(1,2,3,4,5))

    print(asterisk_test2(1,2,3,4,5))

    a, b, c = asterisk_test2(1,2,3,4,5)
    print(type(c))      #c의 타입을 보려구 -> list 타입으로 들어감을 보여줌

if __name__ == "__main__":
    main()