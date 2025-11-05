import pandas as pd
col_Name = input("Enter the column name to read :")
try:
    df = pd.read_csv(r"C:\Users\mca\Desktop\CET\S1\Python\file.csv",usecols=[col_Name])
    li = df.values.tolist()
    for i in range(100):
        print(li[i],"\n\n")
except Exception as e:
    print(f"An error occured {e}")