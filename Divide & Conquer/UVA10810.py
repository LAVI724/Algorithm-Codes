# 全域陣列 arr buf
# 初始化陣列 buf[100] = 0
arr = []
buf = [0]*100

# 逆序數對
def count_inversions(lef, rig):
    # 如果右邊界跟左邊界的差值只有 1 以下就回傳
    if rig - lef <= 1:
        return 0
    mid = (lef + rig) >> 1
    # 遞迴 從左邊界到中值 + 中值到右邊界的值給 res 
    res = count_inversions(lef, mid) + count_inversions(mid, rig)
    i = int(lef)
    j = int(mid)
    k = int(lef)
    # 判斷 i 從左界到中值 j 從中直到右邊界
    while i < mid or j < rig:
        # 當 i 大於中界 改放 arr[j] 進 buf[k]
        if i >= mid:
            buf[k] = arr[j]
            j += 1
        # 當 j 大於右界 改放 arr[i] 進 buf[k]
        elif j >= rig:
            buf[k] = arr[i]
            i += 1
        else:
            # 如果不用交換 buf[k] 就放 arr[i]
            if arr[i] <= arr[j]:
                buf[k] = arr[i]
                i += 1   
            else:
                # 如果是要交換的狀況 buf[k] 放 arr[j]
                buf[k] = arr[j]
                j += 1
                res += mid - i
        k += 1
    #  因為 buf[num] 通常都是 0，只有有更新數字會被轉成 arr[num]
    for k in range (int(lef), int(rig), 1):
        arr[k] = buf[k]
    return res

# python 重複讀取輸入
ca = 1
while True:

    # 讀取輸入之數列長度
    n = int(input())

    if n == 0:
        break

    arr = list(map(int, input().split()))

    ans = count_inversions(0, n)
    print(f"Case {ca}: {ans}")

    ca += 1
