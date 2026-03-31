import pymongo

# Create a database named college and then create a collection named studlist. Insert some values into it(manually using test.json)
conn = pymongo.MongoClient("mongodb://localhost:27017")
db = conn["college"]
col = db["studlist"]

# 1. Display the names (include fname & lname) and marks of all female of MCA course

for doc in col.find({"course": "MCA","gender":"female"}):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])

# 2 Display the details of students who secure highest mark in course MCA

print("\n\nHighest Mark:")
for doc in col.find({"course": "MCA"}).sort("mark",-1).limit(1):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])

# 3 Display all male students who secured A+ Grade

print("\n\nMale Students of A+ Grade:")
for doc in col.find({"gender": "male","grade":"A+"}):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])

# 4 Display details of top 3 students of mechanical department

print("\n\nTop 3 Students in Mechanical department")
for doc in col.find({"course":"Mechanical"}).sort("mark",-1).limit(3):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])
    
# 5 Display all female students with mark >= 90

print("\n\nFemale Students of mark >= 90:")
for doc in col.find({"gender": "female","mark":{"$gte":90}}):
    print(doc["name"]["fname"],doc["name"]["lname"],"\n",doc["grade"],"\n",doc["mark"],"\n",doc["phone"]["no"],"\n\n")
   
# 6 Display students with mark >80 and <90 (FIXED)

print("\n\nStudents with mark between 80 and 90:")
for doc in col.find({"mark":{"$gt":80,"$lt":90}}):
    print(doc["name"]["fname"],doc["name"]["lname"],"\n",doc["grade"],"\n",doc["mark"],"\n",doc["phone"]["no"],"\n\n")

# 7 Display students whose name starts with 'V'

print("\n\nStudents whose name starts with 'V':")
for doc in col.find({"name.fname":{"$regex":"^V"}}):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])

# 8 Display all students from Kollam

print("\n\nStudents from Kollam:")
for doc in col.find({"place":"Kollam"}):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])

# 9 Display students not from Kollam or Thiruvananthapuram

print("\n\nStudents NOT from Kollam or Thiruvananthapuram:")
for doc in col.find({"place":{"$nin":["Kollam","Thiruvananthapuram"]}}):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])

# 10 Display female students from Kollam or Thiruvananthapuram

print("\n\nFemale Students from Kollam or Thiruvananthapuram:")
for doc in col.find({
    "gender":"female",
    "place":{"$in":["Kollam","Thiruvananthapuram"]}
}):
    print(doc["name"]["fname"],doc["name"]["lname"],"-",doc["mark"])
