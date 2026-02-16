
create database Employee;
use Employee;

CREATE TABLE regions (
    region_id INT PRIMARY KEY,
    region_name VARCHAR(50)
);
CREATE TABLE countries (
    country_id CHAR(2) PRIMARY KEY,
    country_name VARCHAR(50),
    region_id INT,
    FOREIGN KEY (region_id) REFERENCES regions(region_id)
);
CREATE TABLE locations (
    location_id INT PRIMARY KEY,
    street_address VARCHAR(100),
    postal_code VARCHAR(20),
    city VARCHAR(50),
    state_province VARCHAR(50),
    country_id CHAR(2),
    FOREIGN KEY (country_id) REFERENCES countries(country_id)
);
CREATE TABLE Departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50),
    manager_id INT,
    location_id INT,
    FOREIGN KEY (location_id) REFERENCES locations(location_id)
);
CREATE TABLE jobs (
    job_id VARCHAR(10) PRIMARY KEY,
    job_title VARCHAR(50),
    min_salary INT,
    max_salary INT
);
CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    phone_number VARCHAR(20),
    hire_date DATE,
    job_id VARCHAR(10),
    salary INT,
    manager_id INT,
    department_id INT,
    FOREIGN KEY (job_id) REFERENCES jobs(job_id),
    FOREIGN KEY (department_id) REFERENCES Departments(department_id)
);
CREATE TABLE job_history (
    employee_id INT,
    start_date DATE,
    end_date DATE,
    job_id VARCHAR(10),
    department_id INT,
    PRIMARY KEY (employee_id, start_date),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id),
    FOREIGN KEY (job_id) REFERENCES jobs(job_id),
    FOREIGN KEY (department_id) REFERENCES Departments(department_id)
);
rename TABLE Departments to Depts;

alter table employees modify salary smallint;

alter table employees ADD commission decimal(5,2);

INSERT INTO regions(region_id,region_name) VALUES (1,'Europe');
INSERT INTO regions(region_id,region_name) VALUES (2,'Americas');
INSERT INTO regions(region_id,region_name) VALUES (3,'Asia');
INSERT INTO regions(region_id,region_name) VALUES (4,'Middle East and Africa');

INSERT INTO countries(country_id,country_name,region_id) VALUES ('AR','Argentina',2);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('AU','Australia',3);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('BE','Belgium',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('BR','Brazil',2);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('CA','Canada',2);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('CH','Switzerland',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('CN','China',3);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('DE','Germany',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('DK','Denmark',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('EG','Egypt',4);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('FR','France',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('HK','HongKong',3);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('IL','Israel',4);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('IN','India',3);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('IT','Italy',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('JP','Japan',3);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('KW','Kuwait',4);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('MX','Mexico',2);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('NG','Nigeria',4);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('NL','Netherlands',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('SG','Singapore',3);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('UK','United Kingdom',1);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('US','United States of America',2);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('ZM','Zambia',4);
INSERT INTO countries(country_id,country_name,region_id) VALUES ('ZW','Zimbabwe',4);






INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (1400,'2014 Jabberwocky Rd','26192','Southlake','Texas','US');

INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (1500,'2011 Interiors Blvd','99236','South San Francisco','California','US');

INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (1700,'2004 Charade Rd','98199','Seattle','Washington','US');

INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (1800,'147 Spadina Ave','M5V 2L7','Toronto','Ontario','CA');

INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (2400,'8204 Arthur St',NULL,'London',NULL,'UK');

INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (2500,'Magdalen Centre, The Oxford Science Park','OX9 9ZB','Oxford','Oxford','UK');

INSERT INTO locations(location_id,street_address,postal_code,city,state_province,country_id)
VALUES (2700,'Schwanthalerstr. 7031','80925','Munich','Bavaria','DE');




INSERT INTO jobs VALUES (1,'Public Accountant',4200,9000);
INSERT INTO jobs VALUES (2,'Accounting Manager',8200,16000);
INSERT INTO jobs VALUES (3,'Administration Assistant',3000,6000);
INSERT INTO jobs VALUES (4,'President',20000,40000);
INSERT INTO jobs VALUES (5,'Administration Vice President',15000,30000);
INSERT INTO jobs VALUES (6,'Accountant',4200,9000);
INSERT INTO jobs VALUES (7,'Finance Manager',8200,16000);
INSERT INTO jobs VALUES (8,'Human Resources Representative',4000,9000);
INSERT INTO jobs VALUES (9,'Programmer',4000,10000);
INSERT INTO jobs VALUES (10,'Marketing Manager',9000,15000);
INSERT INTO jobs VALUES (11,'Marketing Representative',4000,9000);
INSERT INTO jobs VALUES (12,'Public Relations Representative',4500,10500);
INSERT INTO jobs VALUES (13,'Purchasing Clerk',2500,5500);
INSERT INTO jobs VALUES (14,'Purchasing Manager',8000,15000);
INSERT INTO jobs VALUES (15,'Sales Manager',10000,20000);
INSERT INTO jobs VALUES (16,'Sales Representative',6000,12000);
INSERT INTO jobs VALUES (17,'Shipping Clerk',2500,5500);
INSERT INTO jobs VALUES (18,'Stock Clerk',2000,5000);
INSERT INTO jobs VALUES (19,'Stock Manager',5500,8500);



INSERT INTO Depts(department_id,department_name,location_id) VALUES (1,'Administration',1700);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (2,'Marketing',1800);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (3,'Purchasing',1700);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (4,'Human Resources',2400);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (5,'Shipping',1500);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (6,'IT',1400);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (7,'Public Relations',2700);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (8,'Sales',2500);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (9,'Executive',1700);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (10,'Finance',1700);
INSERT INTO Depts(department_id,department_name,location_id) VALUES (11,'Accounting',1700);