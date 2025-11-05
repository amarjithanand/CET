import pandas as pd 
data ={
    'Name':['Alice','Bob','Charlie'],
    'Age': [32,31,23],
    'City': ['New york','Kochi','Bangalore']
}

df = pd.DataFrame(data)
df.to_csv(r"C:\Users\mca\Desktop\CET\S1\Python\output.csv",index=False)

print("CSV file created successfully!")
print("Reading csv file...")
readData = pd.read_csv(r"C:\Users\mca\Desktop\CET\S1\Python\output.csv")
li = readData.values.tolist()
print(li)