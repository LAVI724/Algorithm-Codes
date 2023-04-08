# 2022.06.03

'''
解題思維:
Mod

解題觀念:
Mod 用 python 寫快的跟鬼一樣。

pow(x, y, z) = x^y 趴 z
'''

# python 如何讀取直到 EOF 用 try except
try:
    while True:
        
        # zerojudge 是一行三個數字
        # input().split() 用空格切開讀取一整行
        # map (型態, input().split()) 才能把值一口氣讀成 int 不然 input 預設是 str
        # B, P, M = map(int, input().split())

        # vjudge
        B = int(input())
        P = int(input())
        M = int(input())

        print(pow(B, P, M))

        # 吃換行
        # line = input()
except EOFError:
    exit 

