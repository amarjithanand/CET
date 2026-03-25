import pymongo
conn = pymongo.MongoClient("mongodb://localhost:27017")
db = conn["student"]
col = db["marks"]
data = {
    "rollno":1,
    "name":"Ajmal",
    "marks" : 99
}
col.insert_one(data)