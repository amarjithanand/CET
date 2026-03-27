import pymongo
conn = pymongo.MongoClient("mongodb://localhost:27017")
db = conn["student"]
col = db["marks"]
data = {
    "rollno":5,
    "name":"Irshad",
    "marks" : 94
}
col.insert_one(data)
for doc in col.find({},{"name"}).sort("marks",-1).limit(1):
    print(doc["name"])

