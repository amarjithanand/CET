CREATE DATABASE STORE;

CREATE TABLE Product (
	PdtId INT PRIMARY KEY,
    PName VARCHAR(50),
    Price FLOAT,
    Quantity INT
);

CALL Insertproduct(100000, 'Apple', 29.99, 10);
CALL Insertproduct(100001, 'Orange', 29.99, 0);
CALL Insertproduct(100002, 'Coconut', 0, 5);

SELECT * FROM Product;

