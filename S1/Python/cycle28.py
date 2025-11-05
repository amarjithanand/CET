import pandas as pd
df = pd.read_csv(r"C:\Users\mca\Desktop\CET\S1\Python\file.csv")
li = df.values.tolist()
for i in range(100):
    print(li[i],"\n\n")