CREATE DATABASE `Trigger`;
USE `Trigger`;

CREATE TABLE Product (
	PdtId INT PRIMARY KEY,
    Pname VARCHAR(50),
    Price FLOAT,
    QtyInStock INT
);

CREATE TABLE Sale (
	SaleId INT PRIMARY KEY,
    DeliveryAddress VARCHAR(50)
);

CREATE TABLE Saleitem (
	SaleId INT,
    PdtId INT,
    Qty INT,
    PRIMARY KEY (SaleId, PdtId),
    FOREIGN KEY (SaleId) REFERENCES Sale(SaleId),
    FOREIGN KEY (PdtId)  REFERENCES Product(PdtId)
);


CREATE TRIGGER updateAvailableQuantity
AFTER INSERT
ON Saleitem
FOR EACH ROW
UPDATE Product
SET QtyInStock = QtyInStock - NEW.Qty
WHERE PdtId = NEW.PdtId;


INSERT INTO Product VALUES (3, 'Orange', 100, 50);
INSERT INTO Sale VALUES (3, 'Kollam');
INSERT INTO Saleitem VALUES (2, 3, 10);

SELECT * FROM Product;
SELECT * FROM Sale;
SELECT * FROM Saleitem;

SHOW triggers;