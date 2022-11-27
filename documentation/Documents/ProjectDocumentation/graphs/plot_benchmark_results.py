import pandas as pd
from matplotlib import pyplot as plt

results = """1,1,2569
1,2,1718
1,3,1125
1,4,908
1,5,670
1,6,619
1,7,562
1,8,474
1,9,449
1,10,419
1,11,405
1,12,404
1,13,379
1,14,387
1,15,390
1,16,379
2,1,2531
2,2,1439
2,3,1059
2,4,889
2,5,766
2,6,645
2,7,578
2,8,499
2,9,471
2,10,464
2,11,409
2,12,406
2,13,397
2,14,372
2,15,383
2,16,413
3,1,2522
3,2,1524
3,3,1053
3,4,900
3,5,781
3,6,658
3,7,565
3,8,515
3,9,481
3,10,477
3,11,407
3,12,404
3,13,401
3,14,378
3,15,384
3,16,410
4,1,2530
4,2,1433
4,3,1121
4,4,904
4,5,709
4,6,647
4,7,577
4,8,524
4,9,450
4,10,451
4,11,432
4,12,400
4,13,407
4,14,390
4,15,367
4,16,413
5,1,2519
5,2,1615
5,3,1088
5,4,893
5,5,704
5,6,629
5,7,562
5,8,486
5,9,487
5,10,440
5,11,421
5,12,387
5,13,378
5,14,423
5,15,368
5,16,372"""


df = pd.DataFrame(
    [x.strip().split(',') for x in results.split('\n')],
    columns='Run Threads Time'.split()
)
df = df.astype(int)
# print(df)
df_time = df.groupby('Threads')['Time'].mean()
threads = df_time.index
time = df_time.values
plt.title(
    "A plot of the average time taken over 5 runs\n"
    "based on the number of threads"
)
plt.plot(threads, time)
plt.xlabel('Threads')
plt.ylabel('Time')
plt.ylim(bottom=0)
