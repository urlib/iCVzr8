T = int(input())
for _ in range(T):
    s = input()
    if s[-2] == "p":
        print("FILIPINO")
    elif s[-2] == "s":
        print("JAPANESE")
    else:
        print("KOREAN")
