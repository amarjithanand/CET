import pymongo
conn = pymongo.MongoClient("mongodb://localhost:27017")
db = conn["students"]
col = db["mark"]
data  = {
    "rollno":4,
    "name":"Amarjith",
    "marks" : 97
}
col.insert_one(data)
for doc in col.find({"marks": {"$gt":95}}):
    print(doc["name"])

